#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str){
    char buffer[64];

    strcpy(buffer, str);

    return 1;
}

int main(int argc, char **argv){

    char str[517];
    FILE* badfile = fopen("badfile_1.txt", "r");

    fread(str, sizeof(char), 517, badfile);
    bof(str);

    printf("Returned Properly");
    return 1; 
}
