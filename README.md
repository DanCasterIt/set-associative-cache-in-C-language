# set-associative-cache-in-C-language
A simple set-associative cache in C language I wrote to learn and train myself for interviews

## How to compile it
gcc set-associative-cache-emulation.c -o set-associative-cache-emulation

## How to use it
```
> set-associative-cache-emulation
RAM_size             = 256
RAM_ADDRESS_BITS     = 8
LINE_INDEX_BITS      = 3
SET_INDEX_BITS       = 1
TAG_INDEX_BITS       = 4

CAM_size             = 32
CAM_ADDRESS_BITS     = 5
CAM_LINE_INDEX_BITS  = 3
CAM_SET_INDEX_BITS   = 1
CAM_BLOCK_INDEX_BITS = 1

Hex dump of CAM:
0000 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
000F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
001E 00 00
Hex dump of tag:
0000 FF FF FF FF
Hex dump of RAM:
0000 29 23 BE 84 E1 6C D6 AE 52 90 49 F1 F1 BB E9
000F EB B3 A6 DB 3C 87 0C 3E 99 24 5E 0D 1C 06 B7
001E 47 DE B3 12 4D C8 43 BB 8B A6 1F 03 5A 7D 09
002D 38 25 1F 5D D4 CB FC 96 F5 45 3B 13 0D 89 0A
003C 1C DB AE 32 20 9A 50 EE 40 78 36 FD 12 49 32
004B F6 9E 7D 49 DC AD 4F 14 F2 44 40 66 D0 6B C4
005A 30 B7 32 3B A1 22 F6 22 91 9D E1 8B 1F DA B0
0069 CA 99 02 B9 72 9D 49 2C 80 7E C5 99 D5 E9 80
0078 B2 EA C9 CC 53 BF 67 D6 BF 14 D6 7E 2D DC 8E
0087 66 83 EF 57 49 61 FF 69 8F 61 CD D1 1E 9D 9C
0096 16 72 72 E6 1D F0 84 4F 4A 77 02 D7 E8 39 2C
00A5 53 CB C9 12 1E 33 74 9E 0C F4 D5 D4 9F D4 A4
00B4 59 7E 35 CF 32 22 F4 CC CF D3 90 2D 48 D3 8F
00C3 75 E6 D9 1D 2A E5 C0 F7 2B 78 81 87 44 0E 5F
00D2 50 00 D4 61 8D BE 7B 05 15 07 3B 33 82 1F 18
00E1 70 92 DA 64 54 CE B1 85 3E 69 15 F8 46 6A 04
00F0 96 73 0E D9 16 2F 67 68 D4 F7 4A 4A D0 57 68
00FF 76
CPU   address: 171 = 0xAB = 10101011
        MISS
Set number = 1
Block number = 0
Fetching the following lines/bytes from RAM:
CAM address: 008 = 0x08 = 00001000, RAM address: 168 = 0xA8 = 10101000
CAM address: 009 = 0x09 = 00001001, RAM address: 169 = 0xA9 = 10101001
CAM address: 010 = 0x0A = 00001010, RAM address: 170 = 0xAA = 10101010
CAM address: 011 = 0x0B = 00001011, RAM address: 171 = 0xAB = 10101011
CAM address: 012 = 0x0C = 00001100, RAM address: 172 = 0xAC = 10101100
CAM address: 013 = 0x0D = 00001101, RAM address: 173 = 0xAD = 10101101
CAM address: 014 = 0x0E = 00001110, RAM address: 174 = 0xAE = 10101110
CAM address: 015 = 0x0F = 00001111, RAM address: 175 = 0xAF = 10101111
        HIT
Hex dump of CAM:
0000 00 00 00 00 00 00 00 00 12 1E 33 74 9E 0C F4
000F D5 00 00 00 00 00 00 00 00 00 00 00 00 00 00
001E 00 00
Hex dump of tag:
0000 FF FF 0A FF
The cache worked for address 0xAB
        RAM   data = 0x74
        Cache data = 0x74
CPU   address: 255 = 0xFF = 11111111
        MISS
Set number = 1
Block number = 1
Fetching the following lines/bytes from RAM:
CAM address: 024 = 0x18 = 00011000, RAM address: 248 = 0xF8 = 11111000
CAM address: 025 = 0x19 = 00011001, RAM address: 249 = 0xF9 = 11111001
CAM address: 026 = 0x1A = 00011010, RAM address: 250 = 0xFA = 11111010
CAM address: 027 = 0x1B = 00011011, RAM address: 251 = 0xFB = 11111011
CAM address: 028 = 0x1C = 00011100, RAM address: 252 = 0xFC = 11111100
CAM address: 029 = 0x1D = 00011101, RAM address: 253 = 0xFD = 11111101
CAM address: 030 = 0x1E = 00011110, RAM address: 254 = 0xFE = 11111110
CAM address: 031 = 0x1F = 00011111, RAM address: 255 = 0xFF = 11111111
        HIT
Hex dump of CAM:
0000 00 00 00 00 00 00 00 00 12 1E 33 74 9E 0C F4
000F D5 00 00 00 00 00 00 00 00 D4 F7 4A 4A D0 57
001E 68 76
Hex dump of tag:
0000 FF FF 0A 0F
The cache worked for address 0xFF
        RAM   data = 0x76
        Cache data = 0x76
CPU   address: 001 = 0x01 = 00000001
        MISS
Set number = 0
Block number = 0
Fetching the following lines/bytes from RAM:
CAM address: 000 = 0x00 = 00000000, RAM address: 000 = 0x00 = 00000000
CAM address: 001 = 0x01 = 00000001, RAM address: 001 = 0x01 = 00000001
CAM address: 002 = 0x02 = 00000010, RAM address: 002 = 0x02 = 00000010
CAM address: 003 = 0x03 = 00000011, RAM address: 003 = 0x03 = 00000011
CAM address: 004 = 0x04 = 00000100, RAM address: 004 = 0x04 = 00000100
CAM address: 005 = 0x05 = 00000101, RAM address: 005 = 0x05 = 00000101
CAM address: 006 = 0x06 = 00000110, RAM address: 006 = 0x06 = 00000110
CAM address: 007 = 0x07 = 00000111, RAM address: 007 = 0x07 = 00000111
        HIT
Hex dump of CAM:
0000 29 23 BE 84 E1 6C D6 AE 12 1E 33 74 9E 0C F4
000F D5 00 00 00 00 00 00 00 00 D4 F7 4A 4A D0 57
001E 68 76
Hex dump of tag:
0000 00 FF 0A 0F
The cache worked for address 0x01
        RAM   data = 0x23
        Cache data = 0x23
CPU   address: 171 = 0xAB = 10101011
        HIT
Hex dump of CAM:
0000 29 23 BE 84 E1 6C D6 AE 12 1E 33 74 9E 0C F4
000F D5 00 00 00 00 00 00 00 00 D4 F7 4A 4A D0 57
001E 68 76
Hex dump of tag:
0000 00 FF 0A 0F
The cache worked for address 0xAB
        RAM   data = 0x74
        Cache data = 0x74
```