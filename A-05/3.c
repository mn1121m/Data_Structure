/*
data structure
05. 다항식더하기, 전치행렬구하기

3. 위 3번 문제에서 fastTranspose 함수의 파라미터를 구조체 포인터로 정의하여 사용할 수 있다. 
다음과 같이 수정된 함수 fastTranspose1과 fastTranspose2를 사용하여 전치행렬을 구하는 프로그램을 작성하라.

    참조 :  & 
    역참조 : *, [], ->
[질문]
 +  수정을 했는데도 결과값이 제대로 안나오는데, 무엇이 잘못되었나요 ?
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
void fastTranspose1(term *a, term *b);  /* a, b배열 원소를 구조체멤버 참조연산자 (->)를 사용한 표현으로 바꾸기 */
void fastTranspose2(term *a, term *b);  /* a, b배열 원소를 역참조연산자(*)를 사용한 표현으로 바꾸기 */
void printMat(term x[]);

int main(void)
{
    FILE *fp = NULL;

    fp = fopen("a.txt", "r");
    readSparseMat(fp, a);
    fclose(fp);

    printf("A\n");
    printMat(a);

    printf("\nB\n");
    fastTranspose1(a, b);
    fastTranspose2(a, b);
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
void fastTranspose1(term *a, term *b)
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a->col, numTerms = a->value;

    for(i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }
    for(i = 1; i <= numTerms; i++) {
        rowTerms[(a+i)->col]++;
    }
    startingPos[0] = 1;
    for(i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];
    }
    for(i = 1; i <= numTerms; i++) {
        j = startingPos[(a+i)->col]++;
        (b+j)->row = (a+i)->col, (b+j)->col = (a+i)->row;
        (b+j)->value = (a+i)->value;
    }

}
void fastTranspose2(term *a, term *b)
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = (*a).col, numTerms = (*a).value;

    for(i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }
    for(i = 1; i <= numTerms; i++) {
        rowTerms[(*(a + i)).col]++;  
    }
    startingPos[0] = 1;
    for(i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];
    }
    for(i = 1; i <= numTerms; i++) {
        j = startingPos[(*(a + i)).col]++; 
        (*(b + j)).row = (*(a + i)).col, (*(b + j)).col = (*(a + i)).row;
        (*(b + j)).value = (*(a + i)).value;
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