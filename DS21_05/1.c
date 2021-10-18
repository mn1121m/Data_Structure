/* 2018117610_moonjunyong
자료구조 응용
스택응용 - 미로 탐색

1. Program 3.12 Maze search function을 사용하는 미로탐색 프로그램을 작성하여라.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

#define MAX_ROW_SIZE 10
#define MAX_COL_SIZE 10

// Data structure - move
typedef struct {
    int vert;
    int horiz;
} offsets;
offsets move[8];

// Data structre - stack
typedef struct {
    int row;
    int col;
    int dir;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

// Global variable
int maze[MAX_ROW_SIZE][MAX_COL_SIZE];
int mark[MAX_ROW_SIZE][MAX_COL_SIZE];
int EXIT_ROW, EXIT_COL;

// Functions
void push(element item);
void stackFull();
element pop();
element stackEmpty();
void path(void);

// Main
int main(void)
{
    int left, right;
    int i, j;

    // input row, col
    //printf("input row col (ex 4 5): ");
    scanf("%d %d", &left, &right);

    // for i = 0:row , j = 0:col
    for(i = 0; i < left; i ++) {
        for(j = 0; j < right; j++) {
            
        }
    }
    return 0;
}

// Functions
void push(element item)
{
    if(top >= MAX_STACK_SIZE -1) {
        stackFull();
    }
    stack[++top] = item;
}
void stackFull()
{
    int i;
    element tmp;

    puts("stack is full, cannot add element\ncurrent stack elements: ");
    exit(EXIT_FAILURE);
}
element pop()
{
    if(top == -1)
        return stackEmpty();
    return stack[top--];
}
element stackEmpty()
{
    element temp = {-1, -1, -1};
    puts("stack is empty, cannot delete element");
    exit(EXIT_FAILURE);
    return temp;
}


void path(void)
{
    /* output a path through the maze if such a path exists */
    int i, row, col, nextRow, nextCol, dir, found = FALSE;
    element position;

    mark[1][1] = 1; top = 0;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;

    while(top > -1 && !found) {
        position = pop();
        row = position.row; col = position.col;
        dir = position.dir;
        while( dir < 8 && !found) {
            /* move in direction dir */
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if( nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = TRUE;
            else if ( !maze[nextRow][nextCol] && 
            !mark[nextRow][nextCol]) {
                mark[nextRow][nextCol] = 1;
                position.row = row; position.col = col;
                position.dir = ++dir;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            }
            else ++dir;
        }
    }
    if (found) {
        printf("The path is : \n");
        printf("row\tcol\n");
        for( i = 0; i <= top; i++)
            printf("%2d%5d", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else printf("The maze does not have a path\n");
}