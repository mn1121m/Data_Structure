//다시(ok)()
#include <stdio.h>

int main()
{
	int a2[3][2] = { 11, 22, 33, 44, 55, 66};
    int *p2 = a2[2];

	printf("%d %d\n", a2[2][1], *(p2+1));
    putchar('\n');
	//output : 66 66

	return 0;
}