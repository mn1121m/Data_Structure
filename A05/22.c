/*
05. 다항식더하기, 전치행렬구하기 - 1번 응용

2. 다음 희소행렬(sparse matrix)에 대한 전치행렬(transpose matrix)을 구하는 함수로 
Program 2.9 fastTranspose를 구현하여 실행결과를 보여라.
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
void createAry(int n);
void ary2SparseMat();
void printSparseMat();
void printMat();

// Global variable
int ary[ROW][COL];
int flag[ROW][COL];     // 중복된값을 판단하기 위해 사용, 기본적으로 false으로 저장됨.
term mat[MAX_TERM_SIZE];

int main(void)
{
    int n;

    printf("Press the numver of a elements : ");
    scanf("%d", &n);

    createAry(n);
    ary2SparseMat();

    printf("sparse matrix\n");
    printSparseMat();
    printMat();
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
void printMat()
{
    int i, j, count = 1;

    for(i = 0; i < mat[0].row; i++) {
        for(j = 0; j < mat[0].col; j++)
            if(i == mat[count].row && j == mat[count].col)
                printf("%3d ", mat[count++].value);
            else
                printf("%3d ", 0);
        putchar('\n');
    }
}
/*
void fast_transpose(term a[],  term b[])
{
    int rowTerms[MAX_TERMS],  startingPos[MAX_TERMS];
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
*/