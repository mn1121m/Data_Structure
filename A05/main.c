//SparseMat -> 파일처리로 받아오기
#include <stdio.h>

#define MAX_BUF_SIZE 256
// Data structure

typedef struct {
    int row;
    int col;
    int value;
} term;

// Function
void readSparseMat(FILE *fp, term *mat);
void printSparseMat(term *mat);

int main(void)
{
    FILE *fp;
    char buf[MAX_BUF_SIZE];
    term a[MAX_BUF_SIZE], b[MAX_BUF_SIZE];

    //Get a.txt
    printf("Press the name of the file >> ");
    scanf("%s", buf);
    fp = fopen(buf, "r");
    readSparseMat(fp, a);
    fclose(fp);

    //Get b.txt
    printf("Press the name of the file >> ");
    scanf("%s", buf);
    fp = fopen(buf, "r");
    readSparseMat(fp, b);
    fclose(fp);

    printf("a.txt : \n");
    printSparseMat(a);
    printf("\nb.txt : \n");
    printSparseMat(b);

}
// Function
void readSparseMat(FILE *fp, term *mat)
{
    int i;

    fscanf(fp, "%d %d %d", &mat[0].row, &mat[0].col, &mat[0].value);
    for(i = 1; i <= mat[0].value; i++) {
        fscanf(fp, "%d %d %d", &(mat[i].row), &(mat[i].col), &(mat[i].value));
    }
}
void printSparseMat(term *mat)
{
    int i;

    for(i = 0; i <= mat[0].value; i++) {
        printf("%d %d %d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}