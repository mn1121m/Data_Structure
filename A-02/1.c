/* remind
data structure
02. 배열과 포인터

1. 다음은 1차원 배열에 대해 배열원소의 합을 구하는 프로그램의 일부이다. 
형식매개변수가 다른 세 가지 버전의 함수를 각각 정의하고 실행되도록 작성하라. 
각 함수는 배열 파라미 터 혹은 배열 포인터를 매개변수에 사용하여야 하고 인자의 개수는 2개이다.

*/
#include <stdio.h>

int sumAry1D_f1(int ary[], int size); // 배열파라미터, 배열크기 // 권장
int sumAry1D_f2(int *ary, int size); // 배열포인터, 배열크기
int sumAry1D_f3(int ary[6], int size);

int main(void)
{
    int ary1D[] = {1, 2, 3, 4, 5, 6};
    int arySize = sizeof(ary1D) / sizeof(*ary1D); // 24 / 4 = 6, *ary1D = 4바이트
    
    printf("sumAry1D_f1() %d\n", sumAry1D_f1(ary1D, arySize)); 
    printf("sumAry1D_f2() %d\n", sumAry1D_f2(ary1D, arySize)); 
    printf("sumAry1D_f3() %d\n", sumAry1D_f3(ary1D, arySize));

    return 0;
}
int sumAry1D_f1(int ary[], int size)
{
    int i, sum = 0;

    for(i = 0 ; i < size; i ++) {
        sum += ary[i];
    }  
    return sum; 
}
int sumAry1D_f2(int *ary, int size)
{
    int i, sum = 0;
    
    for(i = 0; i < size; i ++) {
        sum += ary[i];
    }
    return sum;
}
int sumAry1D_f3(int ary[6], int size)
{
    int i, sum = 0;

    for(i = 0; i < size; i++) {
        sum += ary[i];
    }
    return sum;
}
/*
sumAry1D_f1() 21
sumAry1D_f2() 21
sumAry1D_f3() 21
*/