/* remind
자료구조응용 02. 배열과 포인터

3. 다음은 3차원 배열에 대해 배열원소의 합을 구하는 프로그램의 일부이다. 
형식매개변수가 다른 세 가지 버전의 함수를 각각 정의하고 실행되도록 작성하라. 
각 함수는 배열 파라미 터 혹은 배열 포인터를 매개변수에 사용하여야 하고 인자의 개수는 4개이다.

*/

#include <stdio.h>

int sumAry3D_f1(int ary[][2][3], int SEC, int ROW, int COL); // 배열파라미터 //권장 
int sumAry3D_f2(int (*ary)[2][3], int SEC, int ROW, int COL); // 배열포인터
int sumAry3D_f3(int ary[2][2][3], int SEC, int ROW, int COL);


int main(void) 
{
    int ary3D[ ][2][3] = {
        {
             {1, 2, 3},
             {4, 5, 6} 
        },{
            {7, 8, 9},
            {10, 11, 12}
        }};

    int sec_size = sizeof(ary3D) / sizeof(ary3D[0]);
    int row_size = sizeof(ary3D[0]) / sizeof(ary3D[0][0]);
    int col_size = sizeof(ary3D[0][0]) / sizeof(ary3D[0][0][0]);

    printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D, sec_size, row_size, col_size)); 
    printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D, sec_size, row_size, col_size)); 
    printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D, sec_size, row_size, col_size));

    return 0; 
}
int sumAry3D_f1(int ary[][2][3], int SEC, int ROW, int COL)
{
    int i, j, k, sum = 0;

    for(i = 0; i < SEC; i++) {
        for(j = 0; j < ROW; j++) {
            for(k = 0; k < COL; k++) {
                sum += ary[i][j][k];
            }
        }
    }
    return sum;
}
int sumAry3D_f2(int (*ary)[2][3], int SEC, int ROW, int COL)
{
    int i, j, k, sum = 0;

    for(i = 0; i < SEC; i++) {
        for(j = 0; j < ROW; j++) {
            for(k = 0; k < COL; k++) {
                sum += ary[i][j][k];
            }
        }
    }
    return sum;
}
int sumAry3D_f3(int ary[2][2][3], int SEC, int ROW, int COL)
{
    int i, j, k, sum = 0;

    for(i = 0; i < SEC; i++) {
        for(j = 0; j < ROW; j++) {
            for(k = 0; k < COL; k++) {
                sum += ary[i][j][k];
            }
        }
    }
    return sum;
}
/*
sumAry3D_f1() 78
sumAry3D_f2() 78
sumAry3D_f3() 78
*/