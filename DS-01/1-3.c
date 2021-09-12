/* 2021_0907 remind
자료구조응용 01. 배열과 포인터
1. 다음 각 경우에 대해 배열을 선언하고 배열이름 ary 및 배열 포인터 p를 이용하여 
배열요 소를 출력하는 프로그램을 작성하라. 이때, ary와 p를 사용한 여러 가지 주소표현 및 역참 조를 테스트하라.

(3) 3차원 배열과 배열포인터
*/

#include <stdio.h>

int main(void)
{
    int ary[2][2][3] = {
        {{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9}, {10, 11, 12}}
    };
    int (*p)[2][3] = ary, i, j, k;

    int sec_size = sizeof(ary) / sizeof(ary[0]);
    int row_size = sizeof(ary[0]) / sizeof(ary[0][0]);
    int col_size = sizeof(ary[0][0]) / sizeof(ary[0][0][0]);
    printf("ary를 이용한 출력\n");
    for(i = 0; i < sec_size; i ++) {
        for(j = 0; j < row_size; j++) {
            for(k = 0; k < col_size; k++) {
                printf("%4d ", ary[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("p를 이용한 출력\n");
    for(i = 0; i < sec_size; i ++) {
        for(j = 0; j < row_size; j++) {
            for(k = 0; k < col_size; k++) {
                printf("%4d ", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
/*
ary를 이용한 출력
   1    2    3 
   4    5    6 

   7    8    9 
  10   11   12 

p를 이용한 출력
   1    2    3 
   4    5    6 
*/