/*
data structure
05. 다항식더하기, 전치행렬구하기

1. 크기가 20*20인 이차원 배열로 희소 행렬을 다음과 같이 만들어라. 
0이 아닌 배열 원소의 수를 입력 받아, rand()함수를 이용하여 위치와 값을 설정하도록 하시오. 
(매번 수행시마다 서 로 다른 희소행렬이 만들어져야함), 
이 행렬을 이용하여, 배열의 공간을 절약하기 위한 희소행 렬을 만들고 출력하시오.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERM_SIZE 401   /* maximum numer of terms + 1 */

#define ROW 20
#define COL 20

#define TRUE 1
#define FALSE 0

// Data structure

typedef struct {
    int row;
    int col;
    int value;
} term;

// Functions
void createAry(int n);  //Random generated Matrix(20, 20)
void printAry(int ary[20][20]);
void ary2SparseMat();
void printSparseMat();

// Global variable
int ary[ROW][COL];
int flag[ROW][COL];     // 중복된값을 판단하기 위해 사용, 기본적으로 false으로 저장됨.
term mat[MAX_TERM_SIZE];

int main(void)
{
    int n;

    printf("Press the number of a elements : ");
    scanf("%d", &n);

    createAry(n);
    printf("Random generated Matrix(20,20)\n");
    printAry(ary);

    ary2SparseMat();
    printf("Sparse Matrix\n");
    printSparseMat();
    return 0;
}
void createAry(int n)
{
    int row, col;
    int i;

    srand(time(NULL));

    for(i = 0; i < n; i ++) {
        //중복처리
        row = rand() % ROW;
        col = rand() % COL;
        while(flag[row][col]) {     //값이 있으면(TRUE) 다시 뽑으라는 의미이다. flag = FALSE 일때 반복문을 빠져나온다.
            row = rand() % ROW;
            col = rand() % COL;
        }
        flag[row][col] = TRUE;                  /* flag 초기화 */
        ary[row][col] = rand() % 100 + 1;     //value = rand() % 100 + 1 : 1 ~ 100
    }
}
void printAry(int ary[20][20])
{
    int i, j;

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%3d ", ary[i][j]);
        }
        putchar('\n');
    }
}
void ary2SparseMat()
{
    int row, col, numValue = 1;
    int i, j;

    row = ROW;
    col = COL;

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            if(ary[i][j]) {
                mat[numValue].row = i;
                mat[numValue].col = j;
                mat[numValue++].value = ary[i][j];
            }
        }
    }
    mat[0].row = row;
    mat[0].col = col;
    mat[0].value = numValue - 1;
}
void printSparseMat()
{
    int i;
    
    for(i = 0; i <= mat[0].value; i++) {
        printf("%3d,\t%3d\t%3d\n",mat[i].row, mat[i].col, mat[i].value);
    }
}
/*
Press the numver of a elements : 7
Random generated Matrix(20,20)
  0   0   0   0  59   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0  92   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0  16   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   4 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0  39   0   0   0   0   0  99   0   0   0   0 
  0   0  61   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 
sparse matrix
 20,     20       7
  0,      4      59
  1,     11      92
  8,     17      16
  9,     19       4
 13,      9      39
 13,     15      99
 14,      2      61
 */