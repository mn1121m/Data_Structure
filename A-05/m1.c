/* remind 
file: 1.c - transpose

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

#define TRUE 1
#define FALSE 0

#define MAX_TERMS_SIZE 401

// Data structrure
typedef struct {
    int row;
    int col;
    int value;
} term;
term mat[MAX_TERMS_SIZE];

// Functions
void createAry(int n);
void printAry(int ary[20][20]);

void SparseMat();
void printSparseMat();

// Global varible
int ary[ROW][COL];
int flag[ROW][COL];

int main(void)
{
    int n;

    printf("원소의 개수를 쓰시오 : ");
    scanf("%d", &n);

    createAry(n);
    printf("Random generated Matrix(20,20)\n");
    printAry(ary);
    
    /* sparse matrix */
    SparseMat(ary);
    printf("Sparse Matrix\n");
    printSparseMat(ary);

    return 0;
}
// Functions
void createAry(int n)
{
    int i;
    int row, col;

    srand(time(NULL));

    for(i = 0; i < n; i++) {
        row = rand() % 20;
        col = rand() % 20;
        while(flag[row][col]) {
            row = rand() % 20;
            col = rand() % 20;
        }
        flag[row][col] = TRUE;              // flag 초기화
        ary[row][col] = rand() % 100 + 1;   /* value of ary: 1 ~ 100 */ 
    }
}
void printAry(int ary[20][20])
{
    int i, j;

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%3d", ary[i][j]);
        }
        putchar('\n');
    }

}
void SparseMat()
{
    int row, col;
    int i, j, currentb = 1;
    row = ROW;
    col = COL;

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(ary[i][j]) {
                mat[currentb].row = i;
                mat[currentb].col = j;
                mat[currentb++].value = ary[i][j];
            }
        }
    }
    mat[0].row = row;
    mat[0].col = col;
    mat[0].value = currentb -1;
}
void printSparseMat()
{
    int i, j;
    for(i = 0; i < mat[0].value; i++) {
        printf("%3d,\t%3d,\t%3d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}