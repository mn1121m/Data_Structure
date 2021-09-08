#include <stdio.h>

typedef struct STR1_ {
	int sx1;
	int sx2;
} STR1;


int main(){
	STR1 str1 = {11, 22};

	printf("%d %d\n", str1.sx1, str1.sx2);

	return 0;
}
