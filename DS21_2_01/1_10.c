
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int main()
{

	char s1[100];
	char *sp1;

	scanf("%s", s1);
    sp1 = (char* )malloc(sizeof(char*));
	strcpy(sp1, s1);

	printf("%s\n", sp1);

	free(sp1);

	return 0;
}