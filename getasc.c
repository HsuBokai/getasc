#include <stdio.h>
#include <stdlib.h>

static unsigned char change(char c){
			switch(c){
				case 'a':
				case 'A': return 0x0A; break;
				case 'b':
				case 'B': return 0x0B; break;
				case 'c':
				case 'C': return 0x0C; break;
				case 'd':
				case 'D': return 0x0D; break;
				case 'e':
				case 'E': return 0x0E; break;
				case 'f':
				case 'F': return 0x0F; break;
				default: return (c & 0x0F); break;
			}
}

int main (int argc, char *argv[])
{
		if(argc < 3){
			printf("Usage: %s <2*length> <string (hex)>\n", argv[0]);
			return -1;
		}
		
		int length = atoi(argv[1]);
		length = length/2;
		char* str_hex = argv[2];
		unsigned char c = 0;
		int i = 0;
		for(i=0; i<length; ++i) {
			c = (change(str_hex[2*i]) << 4) | change(str_hex[2*i+1]);
			printf("%c",c);
		}
		return 0;
}
