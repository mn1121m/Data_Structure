#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!((p) = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define ROWS 2
#define COLS 3

// Functions
// 정적배열 전달, 첫 번째 파라미터 타입은 모두 int [3]*
int sumAry2D_f1( int ary[][3], int rows, int cols ); // 배열 파라미터
int sumAry2D_f2( int (*ary)[3], int rows, int cols ); // 배열 포인터
int sumAry2D_f3( int ary[2][3], int rows, int cols );

// 동적배열 전달
int sumAry2D_f4( int **ary, int rows, int cols ); // int **
int sumAry2D_f5( int ***ary, int rows, int cols ); // int ***
void freeAry2D(int **ary, int rows);

// Main
int main(void)
{
    // 정적배열(2행 3열)
    int ary2D[][3] = { {1, 2, 3}, {4, 5, 6} };

    // 동적배열(2행 3열)
    int i, j;
    int **ary;

    // MALLOC
    MALLOC(ary, sizeof(*ary) * ROWS);
    for(i = 0; i < ROWS; i++) {
        MALLOC(ary[i], sizeof(*ary[i]) * COLS);
    }
    
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++)
            ary[i][j] = i + j;
    }
    
    // 정적배열
    printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, ROWS, COLS));
    printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, ROWS, COLS));
    printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, ROWS, COLS));

    // 동적배열
    printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, ROWS, COLS));
    printf("sumAry2D_f5() %d\n", sumAry2D_f5(&ary, ROWS, COLS));

    // 동적배열 -> f1, f2, f3에 전달할 수 있을까 ?
    //printf("sumAry2D_f1 %d\n", sumAry2D_f1(ary, ROWS, COLS));
    
    // 정적배열 -> f4, f5에 전달할 수 있을까 ?
    //printf("sumAry2D_f4 %d\n", sumAry2D_f4(ary2D, ROWS, COLS));

    freeAry2D(ary, ROWS);

    return 0;
}
// Functions
// 정적배열 전달, 첫 번째 파라미터 타입은 모두 int [3]*
int sumAry2D_f1( int ary[][3], int rows, int cols )
{
    int i, j, sum = 0;

    for( i = 0; i < rows; i ++) {
        for( j = 0 ; j < cols; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f2( int (*ary)[3], int rows, int cols )
{
    int i, j, sum = 0;

    for( i = 0; i < rows; i ++) {
        for( j = 0 ; j < cols; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f3( int ary[2][3], int rows, int cols )
{
    int i, j, sum = 0;

    for( i = 0; i < rows; i ++) {
        for( j = 0 ; j < cols; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}

//동적배열 전달
int sumAry2D_f4( int **ary, int rows, int cols )
{
    int i, j, sum = 0;

    for( i = 0; i < rows; i ++) {
        for( j = 0 ; j < cols; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}
int sumAry2D_f5( int ***ary, int rows, int cols )
{
    int i, j, sum = 0;

    for( i = 0; i < rows; i ++) {
        for( j = 0 ; j < cols; j++) {
            sum += (*ary)[i][j];
        }
    }
    return sum;
}
void freeAry2D(int **ary, int rows)
{
    int i;

    for(i = 0; i < rows; i++)
        free(ary[i]);

    free(ary);
}
/* result
sumAry2D_f1(): 21
sumAry2D_f2(): 21
sumAry2D_f3(): 21
sumAry2D_f4(): 9
sumAry2D_f5(): 9
*/