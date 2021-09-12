//remind 2-1

#include <stdio.h>

int sumAry2D_f1( int ary[][3], int ROW, int COL ); // 배열파라미터
int sumAry2D_f2( int (*ary)[3], int ROW, int COL ); // 배열포인터
int sumAry2D_f3( int ary[2][3], int ROW, int COL );

int main(void)
{
    int ary2D[][3] = { {1,2,3}, {4,5,6} };
    int row, col;

    row = sizeof(ary2D) / sizeof(ary2D[0]);
    col = sizeof(ary2D[0]) / sizeof(ary2D[0][0]);

    printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, row, col));
    printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, row, col));
    printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, row, col));

    return 0;
}
int sumAry2D_f1( int ary[][3], int ROW, int COL )
{
    int i, j, sum = 0;

    for(i =0 ; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f2( int (*ary)[3], int ROW, int COL )
{
    int i, j, sum = 0;

    for(i =0 ; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f3( int ary[2][3], int ROW, int COL )
{
    int i, j, sum = 0;

    for(i =0 ; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}