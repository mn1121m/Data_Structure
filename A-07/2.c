/* pass
2. Program 3.12 Maze search function을 사용하는 미로탐색 프로그램을 작성하여라. [프로그램 설명]
다음 1 ~ 5의 변수는 모두 전역으로 선언되며 정적할당을 사용함.
    1 maze
    - 입구는 left top, 출구는 right bottom으로 가정
    - 미로 데이터입력 (“input.txt”, 최대 10×10 행렬로 파일입력)
    45
    2 mark 3 move
    4 stack
    entrance (1, 1), exit (4, 5)
    
    #define MAX_STACK_SIZE 100 typedef struct {
    short int row; short int col; short int dir;
    } element;
    element stack[MAX_STACK_SIZE]; int top = -1;
    5 기호상수 : 전역변수 :
    #define TRUE 1
    #define FALSE 0
    int EXIT_ROW, EXIT_COL;
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0
#define MAX_ROW 30
#define MAX_COL 30

int EXIT_ROW, EXIT_COL;

typedef struct {
   short int row;
   short int col;
   short int dir;
}element;

typedef struct {
   short int vert;
   short int horiz;
}offsets;

offsets move[8] = { {-1, 0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
element stack[MAX_STACK_SIZE];
int top = -1;

int maze[MAX_ROW][MAX_COL];
int mark[MAX_ROW][MAX_COL];

void path();

element stackEmpty()
{
   fprintf(stderr, "stack is empty, cannot delete element.");
   exit(EXIT_FAILURE);
}

element pop()
{
   if (top == -1)
      return stackEmpty();
   return stack[top--];
}

void stackFull()
{
   fprintf(stderr, "Stack is full, cannot add element.");
   exit(EXIT_FAILURE);
}

void push(element item)
{
   if (top >= MAX_STACK_SIZE - 1)
      stackFull();
   top++;
   stack[top].col = item.col;
   stack[top].row = item.row;
   stack[top].dir = item.dir;
}

int main(void)
{
   scanf("%d %d", &EXIT_ROW, &EXIT_COL);

   for (int i = 0; i <= (EXIT_ROW + 1); i++) {
      for (int j = 0; j <= (EXIT_COL + 1); j++) {
         maze[i][j] = 1;
      }
   }

   for (int i = 0; i < EXIT_ROW; i++) {
      for (int j = 0; j < EXIT_COL; j++) {
         scanf("%d", &maze[i + 1][j + 1]);
      }
   }

   for (int i = 0; i < MAX_ROW; i++)
      for (int j = 0; j < MAX_COL; j++)
         mark[i][j] = 0;
   
   path();

   return 0;
}

void path()
{
   int i, row, col, nextRow, nextCol, dir, found = FALSE;
   element position;
   mark[1][1] = 1; top = 0;
   stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
   while (top > -1 && !found) {
      position = pop();
      row = position.row; col = position.col;
      dir = position.dir;
      while (dir < 8 && !found) {
         nextRow = row + move[dir].vert;
         nextCol = col + move[dir].horiz;
         if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
            found = TRUE;
         else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
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
      for (i = 0; i <= top; i++)
         printf("%2d%2d\n", stack[i].row, stack[i].col);
      printf("%2d%2d\n", row, col);
      printf("%2d%2d\n", EXIT_ROW, EXIT_COL);
   }
   else printf("The maze does not have a path\n");
}