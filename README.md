# set-associative-cache-in-C-language
A simple set-associative cache in C language I wrote to learn and train myself for interviews

## How to compile it
gcc set-associative-cache-emulation.c -o set-associative-cache-emulation

## How to use it
```
> ./set-associative-cache-emulation 
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
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Hex dump of tag:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: FF FF FF FF
Hex dump of RAM:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 67 C6 69 73 51 FF 4A EC 29 CD BA AB F2 FB E3 46
  10: 7C C2 54 F8 1B E8 E7 8D 76 5A 2E 63 33 9F C9 9A
  20: 66 32 0D B7 31 58 A3 5A 25 5D 05 17 58 E9 5E D4
  30: AB B2 CD C6 9B B4 54 11 0E 82 74 41 21 3D DC 87
  40: 70 E9 3E A1 41 E1 FC 67 3E 01 7E 97 EA DC 6B 96
  50: 8F 38 5C 2A EC B0 3B FB 32 AF 3C 54 EC 18 DB 5C
  60: 02 1A FE 43 FB FA AA 3A FB 29 D1 E6 05 3C 7C 94
  70: 75 D8 BE 61 89 F9 5C BB A8 99 0F 95 B1 EB F1 B3
  80: 05 EF F7 00 E9 A1 3A E5 CA 0B CB D0 48 47 64 BD
  90: 1F 23 1E A8 1C 7B 64 C5 14 73 5A C5 5E 4B 79 63
  A0: 3B 70 64 24 11 9E 09 DC AA D4 AC F2 1B 10 AF 3B
  B0: 33 CD E3 50 48 47 15 5C BB 6F 22 19 BA 9B 7D F5
  C0: 0B E1 1A 1C 7F 23 F8 29 F8 A4 1B 13 B5 CA 4E E8
  D0: 98 32 38 E0 79 4D 3D 34 BC 5F 4E 77 FA CB 6C 05
  E0: AC 86 21 2B AA 1A 55 A2 BE 70 B5 73 3B 04 5C D3
  F0: 36 94 B3 AF E2 F0 E4 9E 4F 32 15 49 FD 82 4E A9
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
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 00 00 00 00 00 00 00 00 AA D4 AC F2 1B 10 AF 3B
  10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Hex dump of tag:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: FF FF 0A FF
The cache worked for address 0xAB
        RAM   data = 0xF2
        Cache data = 0xF2
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
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 00 00 00 00 00 00 00 00 AA D4 AC F2 1B 10 AF 3B
  10: 00 00 00 00 00 00 00 00 4F 32 15 49 FD 82 4E A9
Hex dump of tag:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: FF FF 0A 0F
The cache worked for address 0xFF
        RAM   data = 0xA9
        Cache data = 0xA9
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
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 67 C6 69 73 51 FF 4A EC AA D4 AC F2 1B 10 AF 3B
  10: 00 00 00 00 00 00 00 00 4F 32 15 49 FD 82 4E A9
Hex dump of tag:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 00 FF 0A 0F
The cache worked for address 0x01
        RAM   data = 0xC6
        Cache data = 0xC6
CPU   address: 171 = 0xAB = 10101011
        HIT
Hex dump of CAM:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 67 C6 69 73 51 FF 4A EC AA D4 AC F2 1B 10 AF 3B
  10: 00 00 00 00 00 00 00 00 4F 32 15 49 FD 82 4E A9
Hex dump of tag:
       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
   0: 00 FF 0A 0F
The cache worked for address 0xAB
        RAM   data = 0xF2
        Cache data = 0xF2
```