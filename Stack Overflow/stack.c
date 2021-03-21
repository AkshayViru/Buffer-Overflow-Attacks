#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str){
	char buffer[64];

	strcpy(buffer, str);
	return 1;
}

int main(int argc, char **argv){
	
	if(argc != 2){
		printf("Provide badfile name as argument\n");
		exit(0);
	}	
	
	char str[517];
	FILE *badfile;

	badfile = fopen(argv[1], "r");
	fread(str, sizeof(char), 517, badfile);
	bof(str);

	printf("Returned Properly\n");
	return 1;
}

