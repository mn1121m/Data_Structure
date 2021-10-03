/* 2018117610 문준용

8. [동적할당배열을 이용한 행렬 더하기]
 Program 1.16 (3개의 정적할당 배열 전달)의 행렬 더하기 함수를 동적으로 할당된 배열을 이용하는 함수로 수정한 후 테스트하라.

*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if( !(p = malloc(s)) ) { \
    fprintf(stderr, "Insufficient memory.\n"); \
    exit(EXIT_FAILURE); \
}

// Functions
void add(int **a, int **b, int **c, int rows, int cols);

int** make2dArray(int rows, int cols);
void init2dArray(int **arr, int rows, int cols);
void print2dArray(int **arr, int rows, int cols);
void free2dArray(int **arr, int rows);

int main(void)
{
    int **ptr;  // 2차원 배열의 동적할당
    int rowSize, colSize;
    int i, j;
    int **arr2A, **arr2B, **arr2C;

    // input
    printf("Enter row size and column size (ex) 3 4 : ");
    scanf("%d %d", &rowSize, &colSize); getchar();

    // malloc
    ptr = make2dArray(rowSize, colSize);
    arr2A = make2dArray(rowSize, colSize);
    arr2B = make2dArray(rowSize, colSize);
    arr2C = make2dArray(rowSize, colSize);

    // init
    init2dArray(ptr, rowSize, colSize);
    //printf("matirx ptr\n"); print2dArray(ptr, rowSize, colSize); putchar('\n');
    
    // arr2A, arr2B
    arr2A = ptr;
    for(i = 0; i < rowSize; i++) 
        for(j = 0; j < colSize; j++)
            arr2B[i][j] = arr2A[i][j] + 1;
    
    // add
    add(arr2A, arr2B, arr2C, rowSize, colSize);

    // print
    
    printf("matrix A\n"); print2dArray(arr2A, rowSize, colSize); putchar('\n');
    printf("matrix B\n"); print2dArray(arr2B, rowSize, colSize); putchar('\n');
    printf("matrix C\n"); print2dArray(arr2C, rowSize, colSize); putchar('\n');

    // free
    free2dArray(ptr, rowSize);

    return 0;
}
// Functions
void add(int **a, int **b, int **c, int rows, int cols)
{
    int i, j;

    for(i = 0 ; i < rows; i++) {
        for(j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
}

int **make2dArray(int rows, int cols)
{
    /* create a two dimensional rows X cols array */
    int **x, i;

    /* get memory for row pointers */
    MALLOC(x, sizeof(*x) * rows);

    /* get memory for each row */
    for(i = 0; i < rows; i++) {
        MALLOC(x[i], sizeof(*x[i]) * cols);
    }
    return x;
}
void init2dArray(int **arr, int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++)
            arr[i][j] = i + j + 1;
    }
}
void print2dArray(int **arr, int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%2d ", arr[i][j]);
        }
        putchar('\n');
    }
}
void free2dArray(int **arr, int rows)
{
    int i;

    for(i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    printf("2d arry - free!!!\n");
}
/* result
Enter row size and column size (ex) 3 4 : 3 7
matrix A
 1  2  3  4  5  6  7 
 2  3  4  5  6  7  8 
 3  4  5  6  7  8  9 

matrix B
 2  3  4  5  6  7  8 
 3  4  5  6  7  8  9 
 4  5  6  7  8  9 10 

matrix C
 3  5  7  9 11 13 15 
 5  7  9 11 13 15 17 
 7  9 11 13 15 17 19 

2d arry - free!!!
*/