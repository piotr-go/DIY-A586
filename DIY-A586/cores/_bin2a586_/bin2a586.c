#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>


unsigned int crc32(unsigned char *data, unsigned int size){
	unsigned int crc = 0xffffffff;
	unsigned char i;
	while(size--){
		crc ^= *data++ << 24;
		for(i=0; i<8; i++){
			if(crc & 0x80000000) crc = (crc << 1) ^ 0x04C11DB7;
			else crc <<= 1;
		}
	}
	return crc;
}


void ch_exp(char *buffer, char *text, char fill, unsigned short cnt){
	while(*text != 0 && cnt){
		*buffer++ = *text++;
		cnt--;
	}
	while(cnt){
		*buffer++ = fill;
		cnt--;
	}
}


void ch_exp2(char *buffer, char *text, char fill, unsigned short cnt){
	while(*text != 0 && cnt){
		if(*text == '\\'){
			text++;
			if(*text == 0) break;
			else if(*text == 'n') *buffer = 0x01;
			else if(*text == 't') *buffer = 0x1F;
			else if(*text == '0') *buffer = 0x02;
			else if(*text == '1') *buffer = 0x03;
			else if(*text == '2') *buffer = 0x05;
			else if(*text == '3') *buffer = 0x06;
			else if(*text == '4') *buffer = 0x07;
			else if(*text == '5') *buffer = 0x08;
			else if(*text == '6') *buffer = 0x11;
			else if(*text == '7') *buffer = 0x12;
			else *buffer = *text;
			text++;
			buffer++;
			cnt--;
		}
		else{
			*buffer++ = *text++;
			cnt--;
		}
	}
	while(cnt){
		*buffer++ = fill;
		cnt--;
	}
}


int main(int argc, char *argv[]){
	int i, cnt, ptr;
	unsigned char bufor[340*1024];
	unsigned int tmp;

	if(argc<5) {
		printf("bin2a586 by Piotr Gozdur <piotr_go>\n");
		printf("Usage: bin2a586 <file.bin> <file.a586> parameters\n");
		printf("	 -n <MENU NAME>\n");
		printf("	-rn <ROM NAME>\n");
		printf("	-fl <little endian FLASH FILE> <HEX ADDRESS>\n");
		printf("	-fb <big endian FLASH FILE> <HEX ADDRESS>\n");
		printf("	-sl <little endian SD FILE> <HEX ADDRESS>\n");
		printf("	-sb <big endian SD FILE> <HEX ADDRESS>\n");
		printf("	 -d <description>\n");
		printf("	 -v <version>\n");
		printf("	 -auto		auto boot\n");
		exit(-1);
	}

	FILE *source;
	source = fopen(argv[1], "rb");
	if(source == NULL) return -1;

	FILE *dest;
	dest = fopen(argv[2], "wb");
	if(dest == NULL) return -1;


	memset(bufor, 0xFF, sizeof(bufor));


	cnt = fread(bufor,1,336*1024,source);

	if(cnt>(336*1024)-1152){
		printf("ERROR: file too long\n");
		return -1;
	}


	memset(bufor+(336*1024)-1152, 0, 1152);

	struct stat filestat;
	stat(argv[1], &filestat);
	strftime((char *)bufor+(336*1024)-48, 17, "%Y-%m-%d %H:%M", localtime(&filestat.st_mtime));


	int main_core = 0;
	int auto_core = 0;

	i=3;
	ptr = 336*1024;
	while(i < argc){
		if(strcmp(argv[i], "-main") == 0){
			main_core = 1;
			i += 1;
		}
		else if(strcmp(argv[i], "-auto") == 0){
			auto_core = 1;
			i += 1;
		}
		else if(strcmp(argv[i], "-n") == 0 && i+1 < argc){
			bufor[ptr+0] = 0x01;
			ch_exp((char *)bufor+ptr+1, argv[i+1], ' ', 30);
			bufor[ptr+31] = 0;
			i += 2;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-rn") == 0 && i+1 < argc){
			bufor[ptr+0] = 0x02;
			ch_exp((char *)bufor+ptr+1, argv[i+1], 0, 30);
			bufor[ptr+31] = 0;
			i += 2;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-fl") == 0 && i+2 < argc){
			bufor[ptr+0] = 0x03;
			ch_exp((char *)bufor+ptr+1, argv[i+1], 0, 26);
			sscanf(argv[i+2],"%x", &tmp);
			bufor[ptr+28] = tmp>>24;
			bufor[ptr+29] = tmp>>16;
			bufor[ptr+30] = tmp>>8;
			bufor[ptr+31] = tmp>>0;
			i += 3;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-fb") == 0 && i+2 < argc){
			bufor[ptr+0] = 0x04;
			ch_exp((char *)bufor+ptr+1, argv[i+1], 0, 26);
			sscanf(argv[i+2],"%x", &tmp);
			bufor[ptr+28] = tmp>>24;
			bufor[ptr+29] = tmp>>16;
			bufor[ptr+30] = tmp>>8;
			bufor[ptr+31] = tmp>>0;
			i += 3;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-sl") == 0 && i+2 < argc){
			bufor[ptr+0] = 0x05;
			ch_exp((char *)bufor+ptr+1, argv[i+1], 0, 26);
			sscanf(argv[i+2],"%x", &tmp);
			bufor[ptr+28] = tmp>>24;
			bufor[ptr+29] = tmp>>16;
			bufor[ptr+30] = tmp>>8;
			bufor[ptr+31] = tmp>>0;
			i += 3;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-sb") == 0 && i+2 < argc){
			bufor[ptr+0] = 0x06;
			ch_exp((char *)bufor+ptr+1, argv[i+1], 0, 26);
			sscanf(argv[i+2],"%x", &tmp);
			bufor[ptr+28] = tmp>>24;
			bufor[ptr+29] = tmp>>16;
			bufor[ptr+30] = tmp>>8;
			bufor[ptr+31] = tmp>>0;
			i += 3;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-d") == 0 && i+1 < argc){
			ch_exp2((char *)bufor+(336*1024)-1152, argv[i+1], 0, 1088);
			i += 2;
			ptr += 32;
		}
		else if(strcmp(argv[i], "-v") == 0 && i+1 < argc){
			ch_exp((char *)bufor+(336*1024)-64, argv[i+1], 0, 16);
			i += 2;
			ptr += 32;
		}
	}

	bufor[(336*1024)-12] = 0x29;
	bufor[(336*1024)-11] = 0x04;
	bufor[(336*1024)-10] = 0x29;
	bufor[(336*1024)- 9] = 0x68;

	if(main_core){
		memset(bufor+(336*1024), 0xff, 4096);

		bufor[(336*1024)-8] = 'M';
		bufor[(336*1024)-7] = 'A';
		bufor[(336*1024)-6] = 'I';
		bufor[(336*1024)-5] = 'N';

		bufor[(336*1024)+0] = 0x01;
		strftime((char *)bufor+(336*1024)+1, 31, "MAIN (%Y-%m-%d %H:%M)       ", localtime(&filestat.st_mtime));
	}
	else if(auto_core){
		bufor[(336*1024)-8] = 'A';
		bufor[(336*1024)-7] = 'U';
		bufor[(336*1024)-6] = 'T';
		bufor[(336*1024)-5] = 'O';
	}
	else{
		bufor[(336*1024)-8] = 'C';
		bufor[(336*1024)-7] = 'O';
		bufor[(336*1024)-6] = 'R';
		bufor[(336*1024)-5] = 'E';
	}


	tmp = crc32(bufor, (336*1024)-4);
	bufor[(336*1024)-4] = tmp>>24;
	bufor[(336*1024)-3] = tmp>>16;
	bufor[(336*1024)-2] = tmp>>8;
	bufor[(336*1024)-1] = tmp>>0;
/*
	tmp = crc32(bufor+(336*1024), (4*1024)-4);
	bufor[(340*1024)-4] = tmp>>24;
	bufor[(340*1024)-3] = tmp>>16;
	bufor[(340*1024)-2] = tmp>>8;
	bufor[(340*1024)-1] = tmp>>0;
*/

	fwrite(bufor,1,sizeof(bufor),dest);


	return 0;
}