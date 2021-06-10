/*
자료구조응용 01. 배열과 포인터
1. 다음 각 경우에 대해 배열을 선언하고 배열이름 ary 및 배열 포인터 p를 이용하여 
배열요 소를 출력하는 프로그램을 작성하라. 이때, ary와 p를 사용한 여러 가지 주소표현 및 역참 조를 테스트하라.

(2) 2차원 배열과 배열포인터 다시()
*/

#include <stdio.h>

int main(void)
{
    int ary[][3] = {4, 2, 3, 5, 2, 3}, i , j;
    int (*p)[3] = ary;

    int row_size = sizeof(ary) / sizeof(ary[0]);
    int col_size = sizeof(ary[0]) / sizeof(ary[0][0]);

    printf("ary를 이용한 출력\n");
    for(i = 0; i < row_size; i ++) {
        for(j = 0 ; j < col_size; j++) {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }

    printf("\np를 이용한 출력\n");
    for(i = 0; i < row_size; i ++) {
        for(j = 0 ; j < col_size; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
ary를 이용한 출력
4 2 3 
5 2 3 

p를 이용한 출력
4 2 3 
5 2 3 
*/