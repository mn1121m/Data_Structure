/* 1번 복습
05. 다항식더하기, 전치행렬구하기 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

#define TRUE 1
#define FALSE 0

#define MAX_TERM_SIZE 401

//Data structure
typedef struct {
    int row;
    int col;
    int value;
} term;

//Global varible
int ary[ROW][COL];
int flag[ROW][COL]; //flag 초기값 = FALSE(=0)
term mat[MAX_TERM_SIZE];

// Function
void createAry(int n);
void printMat(int ary[20][20]);
void ary2SparseMat();
void printSparseMat();

int main(void)
{
    int n;

    printf("원소의 개수를 쓰시오 : ");
    scanf("%d", &n);

    puts("Random generated Matrix(20, 20)");
    createAry(n);
    printMat(ary);

    ary2SparseMat();
    printf("sparse matrix\n");
    printSparseMat();

    return 0;
}
void createAry(int n)
{
    int row, col;
    int i;
    srand(time(NULL));

    for(i = 0; i < n; i++) {
        row = rand() % ROW;
        col = rand() % COL;
        // value = rand() % 100 + 1;

        while(flag[row][col]) {     /**/
            row = rand() % ROW;
            col = rand() % COL;
        }
        flag[row][col] = TRUE;
        ary[row][col] = rand() % 100 + 1;
    }
}
void printMat(int ary[20][20])
{
    int i, j;

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j ++) {
            printf("%3d", ary[i][j]);
        }
        putchar('\n');
    }
}
void ary2SparseMat()
{
    int row, col, numofValue = 1;   /**/
    int i, j;

    row = ROW;
    col = COL;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            if(ary[i][j]) {
                mat[numofValue].row = i;    /**/
                mat[numofValue].col = j;
                mat[numofValue++].value = ary[i][j];
            }
        }
    }
    mat[0].row = row;
    mat[0].col = col;
    mat[0].value = numofValue - 1;
}
void printSparseMat()
{
    int i;

    for(i = 0; i < mat[0].value; i++)  {
        printf("%3d,\t%3d\t%3d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}
/*
원소의 개수를 쓰시오 : 7
Random generated Matrix(20, 20)
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0 70  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0 72  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 59  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0 39  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 95  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 38  0
  0  0  0  0  0  0  0  0 61  0  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
sparse matrix
 20,     20       7
  4,     14      70
  6,     10      72
  7,     17      59
 13,      9      39
 15,     17      95
 17,     18      38
 */