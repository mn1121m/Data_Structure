//다시
#include <stdio.h>

void f1()
{
	int x1 = 0;
    int x2;
	printf("%d %d\n", x1++, x2++);
}

int main()
{
	int i =0;

	for(i=0; i<5; i++)
		f1();

	return 0;
}