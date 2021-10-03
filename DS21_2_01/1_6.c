#include <stdio.h>

struct STR1{

	int sx1;
};

struct STR2{

    struct STR1 str1;
	int sx2;
};

int main(){
	struct STR2 str2 = {{99},100};
	printf("%d %d\n", str2.str1.sx1, str2.sx2);
	return 0;
}
										
				