/*
2. 다음 희소행렬(sparse matrix)에 대한 전치행렬(transpose matrix)을 구하는 함수로 
Program 2.9 fastTranspose를 구현하여 실행결과를 보여라.

[프로그램 설명]
1. 희소행렬(sparse matrix) 파일 a.txt을 사용하여 전치행렬(transpose matrix)을 구함
2. 출력 파일의 이름은 b.txt이며 입력 파일의 전치행렬(transpose matrix)이다.
3. 입력과 출력 파일인 희소행렬(sparse matrix)을 화면에 출력한다. 이때 0의 값을 갖는 항 목도 함께 출력한다.
4. fastTranspose 함수는 수정 없이 그대로 유지

소요: 2H
- 질문 - 
+ 3 입력과 출력 파일인 희소행렬(sparse matrix)을 화면에 출력한다. 이때 0의 값을 갖는 항 목도 함께 출력한다.
위에 대한 설명중에서 0의 값을 갖는 항목도 같이 출력하는 방법을 모르겠습니다.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct _term {
    int row, col, value;
} term;

void print_sparse_matrix(term *a);
void fast_transpose(term a[],  term b[]);
void zero_sparse_matrix(term *a, term *b);

int main(int argc, char **argv)
{
    int i;
    term a[MAX_TERMS], b[MAX_TERMS];

    //  open file
    FILE *fp;
    if((fp = fopen("a.txt", "r")) == NULL) {
        fprintf(stderr, "don't open file\n");
        exit(EXIT_FAILURE);
    }

    //  read input data
    fscanf(fp, "%d %d %d", &a[0].row, &a[0].col, &a[0].value);
    for (i = 1 ;i <= a[0].value; i++)
        fscanf(fp, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);


    //print_sparse_matrix(a);
    fast_transpose(a, b);
    zero_sparse_matrix(a, b);

    return 0;
}

void print_sparse_matrix(term *a)
{
    int i;

    for(i = 0; i <= a[0].value; i++) {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    }
}
//  세 쌍으로 표현된 fast_transposition 된 행렬
void fast_transpose(term a[],  term b[])
{
    FILE *fp2;
    fp2 = fopen("b.txt","w");
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
//    printf("\n(row, col, value) 의 세 쌍으로 표현된 fastTransposition 된 행렬:\n");
//    printf("\nRow\tColumn\tValue\n");
    for(int i = 0; i <= a[0].value; i++)
    {
        fprintf(fp2, "%d ", b[i].row);
        fprintf(fp2, "%d ", b[i].col);
        fprintf(fp2, "%d\n", b[i].value);
    }
}
void zero_sparse_matrix(term *a, term *b)
{
    int i, j, zero = 0;

    printf("A\n");
    for(i = 0; i < a[0].row; i++) {
        for(j = 0; j < a[0].col; j++) {
            
        }
        printf("\n");
    }
    printf("B\n");
    for(i = 0; i < b[0].row; i++) {
        for(j = 0; j < b[0].col; j++) {
            
        }
        printf("\n");
    }
}