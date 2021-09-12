#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(p, s) \
if(!((p) = malloc(s))) { \
    fprintf(stderr, "Insufficient memory.\n"); \
    exit(EXIT_FAILURE); \
}
// Functions
int** make2dArray(int ROW, int COL);

// Main
int main(void)
{
    int **ipp;
    int i, j, rows, cols;

    printf("이차원 배열의 행과 열의 수를 입력하세요 : ");
    scanf("%d %d", &rows, &cols);

    ipp = make2dArray(rows, cols);
    
    for( i = 0; i < rows; i++)
        for( j = 0; j < cols; j++) 
            printf("ipp[%d] = %d ", i, ipp[i][j]);
    putchar('\n');
    return 0;
}
// Functions
int** make2dArray(int ROW, int COL)
{
    int i, j, **pArr;
    srand((unsigned int)time(NULL));

    MALLOC(pArr, sizeof(*pArr) * ROW);
    for(i = 0; i < ROW; i++) {
        MALLOC(pArr[i], sizeof(*pArr[i]) * COL);
    }
    for(i = 0; i < ROW; i ++) {
        for(j = 0; j < COL; j++) {
            pArr[i][j] = rand() % 100;
        }
    }
    return pArr;
}
/* result
이차원 배열의 행과 열의 수를 입력하세요 : 2 3
ipp[0] = 62 ipp[0] = 21 ipp[0] = 8 ipp[1] = 62 ipp[1] = 62 ipp[1] = 18 
*/