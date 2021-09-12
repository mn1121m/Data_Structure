//remind 3-1 다시(ok) 
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