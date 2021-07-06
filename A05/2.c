/* 2번 복습
05. 다항식더하기, 전치행렬구하기 - 1번 응용

2. 다음 희소행렬(sparse matrix)에 대한 전치행렬(transpose matrix)을 구하는 함수로 
Program 2.9 fastTranspose를 구현하여 실행결과를 보여라.

- 질문 - 
+ fast_transpose() 안에서 
맨마지막 조건문에서  j = startingPos[a[i].col]++; << 이게 a와 b를 바꾸고 난뒤 j에 +1를 하는거죠 ?
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERM_SIZE 401 
#define MAX_COL 6
//Data strutrue
typedef struct {
    int row;
    int col;
    int value;
} term;

//Global variable
term a[MAX_TERM_SIZE];
term b[MAX_TERM_SIZE];

//Function
void readSparseMat(FILE *fp, term *mat);
void printMat(term x[]);
void fast_transpose();

int main(void)
{
    FILE *fp = NULL;

    //Get filename
    if((fp = fopen("a.txt", "r")) == NULL) {
        fprintf(stderr, "no file name.\n");
        exit(EXIT_FAILURE);
    }
    readSparseMat(fp, a);
    fclose(fp);
    
    printf("A\n");
    printMat(a);

    printf("\nB\n");
    fast_transpose();
    printMat(b);
    return 0;
}
void readSparseMat(FILE *fp, term *mat)
{
    int i;

    fscanf(fp, "%d %d %d", &(mat[0].row), &(mat[0].col), &(mat[0].value));
    for(i = 1; i <= mat[0].value; i++) {
        fscanf(fp, "%d %d %d", &(mat[i].row), &(mat[i].col), &(mat[i].value));
    }
}
void printMat(term x[])
{
    int i, j, count = 1;

    for(i = 0; i < x[0].row; i++) {
        for(j = 0; j < x[0].col; j ++) {
            if(i == x[count].row && j == x[count].col) {
                printf("%3d ", x[count++].value);
            }else 
                printf("%3d ", 0);
        }
        putchar('\n');
    }
}
void fast_transpose()
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols, b[0].col = a[0].row;
    b[0].value = numTerms;

    if(numTerms > 0) {
        for(i = 0; i < numCols; i++) {
            rowTerms[i] = 0;
        }
        for(i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }
        startingPos[0] = 1;
        for(i = 1; i < numCols; i++) {
            startingPos[i] = rowTerms[i-1] + startingPos[i-1];
        }
        /*중요*/
        for(i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col, b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}
/* 결과
A
 15   0   0  22   0 -15 
  0  11   3   0   0   0 
  0   0   0  -6   0   0 
  0   0   0   0   0   0 
 91   0   0   0   0   0 
  0   0  28   0   0   0 

B
 15   0   0   0  91   0 
  0  11   0   0   0   0 
  0   3   0   0   0  28 
 22   0  -6   0   0   0 
  0   0   0   0   0   0 
-15   0   0   0   0   0 
*/