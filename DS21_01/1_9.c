#include <stdio.h>

struct STR1{
	int x1;
};

int main()
{
	int i=0;
	struct STR1 str1[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};

	for(i = 0; i < 10; i += 2){
        printf("%d\n", str1[i].x1);
	}

	return 0;
}
