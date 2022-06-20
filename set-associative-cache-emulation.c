#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define RAM_size				0xFF + 1
#define CAM_size				0x1F + 1

#define SET_number				2
#define BLOCKS_per_set			2
#define LINES_per_block			8 // lines(bytes)

#define RAM_ADDRESS_BITS		(int)(log(RAM_size)/log(2))

#define LINE_INDEX_BITS			(int)(log(LINES_per_block)/log(2))
#define SET_INDEX_BITS			(int)(log(SET_number)/log(2))
#define TAG_INDEX_BITS			(int)(RAM_ADDRESS_BITS - (LINE_INDEX_BITS + SET_INDEX_BITS))

#define CAM_LINE_INDEX_BITS		LINE_INDEX_BITS
#define CAM_SET_INDEX_BITS		SET_INDEX_BITS
#define CAM_BLOCK_INDEX_BITS	(int)(log(BLOCKS_per_set)/log(2))

#define CAM_ADDRESS_BITS		CAM_LINE_INDEX_BITS + CAM_SET_INDEX_BITS + CAM_BLOCK_INDEX_BITS
//#define CAM_size				(int)(pow(2, CAM_ADDRESS_BITS))

// RAM address partitions
typedef struct address_partitions_l	{
	uint8_t line_index	: LINE_INDEX_BITS;
	uint8_t set_index	: SET_INDEX_BITS;
	uint8_t tag_bits	: TAG_INDEX_BITS;
} address_partitions_t;

typedef union address_l	{
	uint8_t address;
	address_partitions_t address_partitions_v;
} address_t;

// CAM address partitions
typedef struct cam_address_partitions_l	{
	uint8_t line_index	: CAM_LINE_INDEX_BITS;
	uint8_t set_index	: CAM_SET_INDEX_BITS;
	uint8_t block_index	: CAM_BLOCK_INDEX_BITS;
} cam_address_partitions_t;

typedef union cam_address_l	{
	uint8_t address;
	cam_address_partitions_t cam_address_partitions_v;
} cam_address_t;

uint8_t RAM[RAM_size];
uint8_t CAM[CAM_size];

uint8_t tag[SET_number][BLOCKS_per_set];
uint8_t block_count[SET_number];

void to_bin (void * number, unsigned char num_size, char *string)	{
	int i, e, f;
	unsigned char *num;
	for(f = 0, e = 8 * num_size -1; f < num_size;  f++)	{
		num = number + f;
		for(i = 0; i < 8; i++, e--)	string[e] = ((*num >> i) & 1) ? '1' : '0';
	}
	string[8 * num_size] = '\0';
}

void print_binary_byte(uint8_t byte)	{
	char string[8 * sizeof(uint8_t) + 1];
	to_bin((void*) &byte, sizeof(uint8_t), string);
	printf("%s", string);
}

void dump(void **ptr, int size, char name[])	{
    int i;
    char str[0x10 * 3] = {'\0'};

    printf("Hex dump of %s:\n", name);
    printf("       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    for(i = 0; i < size; i++)      {
        if(i % 0x10 == 0 && i != 0)      printf("%s\n", str);
        if(i % 0x10 == 0)	printf("%*X:", 4, (unsigned int)i);
        sprintf(&str[(i % 0x10) * 3], " %02X", (unsigned int)(((uint8_t*)(&*ptr))[i]));
    }
    printf("%s\n", str);
}

void dump_CAM(void)	{
	dump((void **)&CAM, sizeof(CAM), "CAM");
}

void dump_tag(void)	{
	dump((void **)&tag, sizeof(tag), "tag");
}

void dump_RAM(void)	{
	dump((void **)&RAM, sizeof(RAM), "RAM");
}

void dump_CAM_RAM_and_tag(void)	{
	dump_CAM();
	dump_tag();
	dump_RAM();
}

uint8_t cache(uint8_t address)	{
	address_t address_v;
	address_v.address = address;
	cam_address_t cam_address_v;
	cam_address_v.address = 0;
	int i, block_index, hit = 0;
	uint8_t cache_address;
	//printf("tag_bits = %u\n", address_v.address_partitions_v.tag_bits);
	//printf("line_index = %u\n", address_v.address_partitions_v.line_index);
	for(hit = 0, block_index = 0; block_index < BLOCKS_per_set; block_index++)	{
		if(tag[address_v.address_partitions_v.set_index][block_index] == address_v.address_partitions_v.tag_bits)	{
			hit = 1;
			break;
		}
	}
	if(hit == 1) {
		printf("\tHIT\n");
		cam_address_v.cam_address_partitions_v.set_index = address_v.address_partitions_v.set_index;
		cam_address_v.cam_address_partitions_v.block_index = block_index;
		cam_address_v.cam_address_partitions_v.line_index = address_v.address_partitions_v.line_index;
		cache_address = cam_address_v.address;
		//printf("cache address: %03u = 0x%02X = ", cache_address, cache_address);
		//print_binary_byte(cache_address);
		return CAM[cache_address];
	}
	else	{
		printf("\tMISS\n");
		//replacement policy
		if(block_count[address_v.address_partitions_v.set_index] < BLOCKS_per_set - 1) block_count[address_v.address_partitions_v.set_index]++;
		else block_count[address_v.address_partitions_v.set_index] = 0;
		printf("Set number = %d\n", address_v.address_partitions_v.set_index);
		printf("Block number = %d\n", block_count[address_v.address_partitions_v.set_index]);
		//fetch from RAM
		printf("Fetching the following lines/bytes from RAM:\n");
		address_v.address_partitions_v.line_index = 0;
		for(i = 0; i < LINES_per_block; i++)	{
			cam_address_v.cam_address_partitions_v.set_index = address_v.address_partitions_v.set_index;
			cam_address_v.cam_address_partitions_v.block_index = block_count[address_v.address_partitions_v.set_index];
			cam_address_v.cam_address_partitions_v.line_index = address_v.address_partitions_v.line_index;
			cache_address = cam_address_v.address;
			printf("CAM address: %03u = 0x%02X = ", cache_address, cache_address);
			print_binary_byte(cache_address);
			printf(", RAM address: %03u = 0x%02X = ", address_v.address, address_v.address);
			print_binary_byte(address_v.address);
			printf("\n");
			CAM[cache_address] = RAM[address_v.address];
			address_v.address_partitions_v.line_index++;
			tag[address_v.address_partitions_v.set_index][block_count[address_v.address_partitions_v.set_index]] = address_v.address_partitions_v.tag_bits;
		}
		return cache(address);
	}
}

int main(int argc, char *argv[])	{
	int i, e;
	//uint8_t tests[] = {0x01};
	uint8_t tests[] = {0xAB, 0xFF, 0x01, 0xAB};
	//uint8_t tests[] = {0xAB, 0xFF, 0x0F, 0xAB};
	uint8_t address;
	uint8_t data;
	for(i = 0; i < SET_number; i++) block_count[i] = 0xFF;
	for(i = 0; i < SET_number; i++)	{
		for(e = 0; e < BLOCKS_per_set; e++) tag[i][e] = 0xFF;
	}
	for(i = 0; i < RAM_size; i++)	RAM[i] = rand() % 0x100;
	for(i = 0; i < CAM_size; i++)	CAM[i] = 0x00;
	
	printf("RAM_size             = %d\n", RAM_size);
	printf("RAM_ADDRESS_BITS     = %d\n", RAM_ADDRESS_BITS);
	printf("LINE_INDEX_BITS      = %d\n", LINE_INDEX_BITS);
	printf("SET_INDEX_BITS       = %d\n", SET_INDEX_BITS);
	printf("TAG_INDEX_BITS       = %d\n\n", TAG_INDEX_BITS);

	printf("CAM_size             = %d\n", CAM_size);
	printf("CAM_ADDRESS_BITS     = %d\n", CAM_ADDRESS_BITS);
	printf("CAM_LINE_INDEX_BITS  = %d\n", CAM_LINE_INDEX_BITS);
	printf("CAM_SET_INDEX_BITS   = %d\n", CAM_SET_INDEX_BITS);
	printf("CAM_BLOCK_INDEX_BITS = %d\n\n", CAM_BLOCK_INDEX_BITS);
	
	dump_CAM_RAM_and_tag();

	for(i = 0; i < sizeof(tests); i++)	{
		//Test the cache
		address = tests[i];
		printf("CPU   address: %03u = 0x%02X = ", address, address);
		print_binary_byte(address);
		printf("\n");
		data = cache(address);
		dump_CAM();
		dump_tag();
		if( data == RAM[address])	printf("The cache worked for address 0x%02X\n", address);
		else	printf("The cache did NOT work for address 0x%02X\n", address);
		printf("\tRAM   data = 0x%02X\n\tCache data = 0x%02X\n", data, RAM[address]);
	}
	
	return 0;
}
