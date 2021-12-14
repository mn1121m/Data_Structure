/* remind
data structure
02. 배열과 포인터

2. 다음은 2차원 배열에 대해 배열원소의 합을 구하는 프로그램의 일부이다. 
형식매개변수가 다른 세 가지 버전의 함수를 각각 정의하고 실행되도록 작성하라. 
각 함수는 배열 파라미 터 혹은 배열 포인터를 매개변수에 사용하여야 하고 인자의 개수는 3개이다.

*/
#include <stdio.h>

int sumAry2D_f1(int ary[][3], int row, int col); // 배열파라미터 // 권장
int sumAry2D_f2(int (*ary)[3], int row, int col); // 배열포인터
int sumAry2D_f3(int ary[2][3], int row, int col);

int main(void) 
{
    int ary2D[ ][3] = { {1, 2, 3}, {4, 5, 6}};

    int row_size = sizeof(ary2D) / sizeof(*ary2D);      //*ary2D == ary2D[0]
    int col_size = sizeof(*ary2D) / sizeof(**ary2D);  //**ary2D == ary2D[0][0]

    printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, row_size, col_size)); 
    printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, row_size, col_size)); 
    printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, row_size, col_size));

    return 0; 
}
int sumAry2D_f1(int ary[][3], int row, int col)
{
    int i, j, sum = 0;

    for(i = 0; i < row; i++) {
        for(j = 0; j< col; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f2(int (*ary)[3], int row, int col)
{
    int i, j, sum = 0;

    for(i = 0; i < row; i++) {
        for(j = 0; j< col; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f3(int ary[2][3], int row, int col)
{
    int i, j, sum = 0;

    for(i = 0; i < row; i++) {
        for(j = 0; j< col; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
/*
sumAry2D_f1() 21
sumAry2D_f2() 21
sumAry2D_f3() 21
*/