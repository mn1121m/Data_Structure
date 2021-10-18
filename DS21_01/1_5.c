#include <stdio.h>

int *f2(int *a3) {

    int *fp = a3;
	return fp+2;
}

int main(){

	int a3[3] = { 11, 22, 33 };

	printf("%d \n", *(f2(a3)));

	return 0;
}

		