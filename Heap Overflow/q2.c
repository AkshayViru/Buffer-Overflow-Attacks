#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void executeShell()
{
	char *name[2];

	name[0] = "/bin/sh";
	name[1] = NULL;
	execve(name[0], name, NULL);
}

int main(int argc, char **argv)
{
	char *a, *b, *c;

	a = malloc(32);
	b = malloc(32);
	c = malloc(32);

	strcpy(a, argv[1]);
	strcpy(b, argv[2]);
	strcpy(c, argv[3]);

	free(c);
	free(b);
	free(a);

	printf("You failed\n");
}
