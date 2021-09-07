//0907 remind
// 1 (1) 1차원 배열과 배열포인터
#include <stdio.h>

int main(void)
{
    int ary[] = {8, 2, 8}, i;
    int *p = ary;
    int ary_length;

    printf("ary를 이용한 출력\n");
    ary_length = sizeof(ary) / sizeof(ary[0]);

    for(i = 0; i < ary_length; i ++) {
        printf("%d ", ary[i]);
    }
    printf("\n\n");
    
    printf("p를 이용한 출력\n");
    for(i = 0; i < ary_length; i ++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}
/* result
ary를 이용한 출력
8 2 8 

p를 이용한 출력
8 2 8 
*/
