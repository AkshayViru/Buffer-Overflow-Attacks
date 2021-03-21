#include <stdio.h>
#include <string.h>
 
char *shellcode = "";

int main(void)
{
(*(void(*)()) shellcode)();
return 0;
}
