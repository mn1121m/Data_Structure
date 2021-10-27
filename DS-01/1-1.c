/* 2021_0907 => remind
자료구조응용 01. 배열과 포인터

1. 다음 각 경우에 대해 배열을 선언하고 배열이름 ary 및 배열 포인터 p를 이용하여 
배열요 소를 출력하는 프로그램을 작성하라. 이때, ary와 p를 사용한 여러 가지 주소표현 및 역참 조를 테스트하라.
(1) 1차원 배열과 배열포인터
*/

#include <stdio.h>

int main(void)
{  
    int ary[3] = {8, 2, 8}, i, ary_len;
    int *p = ary;

    ary_len = sizeof(ary) / sizeof(ary[0]);
    printf("ary를 이용한 출력\n");
    for(i = 0; i < ary_len; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n\np를 이용한 출력\n");
    for(i = 0 ; i < ary_len; i++) {
        printf("%d ", p[i]);
    }
    
    return 0;
}
/*
ary를 이용한 출력
8 2 8 

p를 이용한 출력
8 2 8 %   
*/