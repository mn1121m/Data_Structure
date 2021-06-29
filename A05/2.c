/*
05. 다항식더하기, 전치행렬구하기

2. 다음 희소행렬(sparse matrix)에 대한 전치행렬(transpose matrix)을 구하는 함수로 
Program 2.9 fastTranspose를 구현하여 실행결과를 보여라.

- 추가질문-

문제처럼 "파일 처리" 함수를 이용하여 구현하는 방법에 대해서 잘 모르겠습니다.
"파일 처리"에 개념은 아는데 개념을 이용해서 풀이하는 방법이 어렵습니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERM_SIZE 401   /* maximum numer of terms + 1 */

#define ROW 6
#define COL 6

#define TRUE 1
#define FALSE 0

// Data structure

typedef struct {
    int row;
    int col;
    int value;
} term;

// Functions
void createAry(int n);
void ary2SparseMat();
void printSparseMat(term x[]);
void printMat(term x[]);

void fast_transpose();

// Global variable
int ary[ROW][COL];
int flag[ROW][COL];     // 중복된값을 판단하기 위해 사용, 기본적으로 false으로 저장됨.
term a[MAX_TERM_SIZE];
term b[MAX_TERM_SIZE];

int main(void)
{
    int n;

    printf("Press the numver of a elements : ");
    scanf("%d", &n);

    createAry(n);
    ary2SparseMat();

    printf("A\n");
    //printSparseMat(a);
    printMat(a);

    printf("\nB\n");
    fast_transpose();
    //printSparseMat(b);
    printMat(b);
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
        while(flag[row][col]) {    //값이 있으면(TRUE) 다시 뽑으라는 의미이다. flag = FALSE일때 반복문을 빠져나온다.
            row = rand() % ROW;
            col = rand() % COL;
        }
        flag[row][col] = TRUE;
        ary[row][col] = rand() % 100 + 1;     //value = rand() % 100 + 1
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
                a[numValue].row = i;
                a[numValue].col = j;
                a[numValue++].value = ary[i][j];
            }
        }
    }
    a[0].row = row;
    a[0].col = col;
    a[0].value = numValue - 1;
}
void printSparseMat(term x[])
{
    int i;

    for(i = 0; i <= x[0].value; i++) {
        printf("%3d,\t%3d\t%3d\n", x[i].row, x[i].col, x[i].value);
    }
}
void printMat(term x[])
{
    int i, j, count = 1;

    for(i = 0; i < x[0].row; i++) {
        for(j = 0; j < x[0].col; j++)
            if(i == x[count].row && j == x[count].col)
                printf("%3d ", x[count++].value);
            else
                printf("%3d ", 0);
        putchar('\n');
    }
}
void fast_transpose()
{
    int rowTerms[MAX_TERM_SIZE],  startingPos[MAX_TERM_SIZE];
    int i,j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols; b[0].col = a[0].row;
    b[0].value = numTerms;
    
    if(numTerms > 0){
        for(i = 0; i < numCols; i++){
            rowTerms[i] = 0;
        }
        for(i = 1; i <= numTerms; i++){
            rowTerms[a[i].col]++;
        }
        startingPos[0] = 1;
        for(i = 1; i< numCols; i++){
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        }
        for(i = 1; i <= numTerms; i++){
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col; b[j].col = a[i].row;
            b[j].value = a[i].value;
            
        }
    }
}
/*
Press the numver of a elements : 8
A
  0   0   0   0  90   0 
  0   0   0   0  48   0 
  0   0   0   0   0   0 
  0   0  11  95   0  72 
  0   0  31  42   0   0 
  0   0   0   0  72   0 

B
  0   0   0   0   0   0 
  0   0   0   0   0   0 
  0   0   0  11  31   0 
  0   0   0  95  42   0 
 90  48   0   0   0  72 
  0   0   0  72   0   0 
*/