/* remind
file: 2.c - fastTransepose()

[*]
    1. fastTransepose  범위(부등호) 조심
    2. readMat() -> 범위(부등호) 조심
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS_SIZE 400 + 1

#define ROW 6
#define COL 6

// Data structure
typedef struct {
    int row;
    int col;
    int value;
} term;
term a[MAX_TERMS_SIZE];
term b[MAX_TERMS_SIZE];

// Functions
void readMat(FILE *fp, term *mat);
void printMat(term x[]);
void fastTranspose(term a[], term b[]);

// Main
int main()
{
    FILE *fp = NULL;

    if((fp = fopen("a.txt", "r")) == NULL) {
        fprintf(stderr, "no file name\n");
        exit(EXIT_FAILURE);
    }
    // read a.txt && print A
    readMat(fp, a);
    fclose(fp);
    
    printf("A\n");
    printMat(a);

    // fastTranspose && print B
    fastTranspose(a, b);
    printf("B\n");
    printMat(b);

    return 0;
}
// Functions
void readMat(FILE *fp, term *mat)
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
        for(j = 0; j < x[0].col; j++) {
            if(i == x[count].row && j == x[count].col)
                printf("%3d ", x[count++].value);
            else
                printf("%3d ", 0);
        }
        putchar('\n');
    }
}
void fastTranspose(term a[], term b[])
{
    int rowTerms[COL], startingPos[COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols; b[0].col = a[0].row;
    b[0].value = numTerms;

    if( numTerms > 0) {
        for(i = 0; i < numCols; i++) {
            rowTerms[i] = 0;
        }
        for(i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }
        startingPos[0] = 1;
        for(i = 1; i < numCols; i++) {
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        }
        for(i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col; b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}