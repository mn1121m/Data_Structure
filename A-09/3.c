/* ()
data structure

3. [Linked Stacks] 다음과 같은 스택을 생성하고 실행하는 프로그램을 작성하라. 
이를 위해, push, pop, stackEmpty 함수를 구현하여야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 3
#define MALLOC(p,s){\
   if(!((p)=malloc(s))){\
      fprintf(stderr, "insufficient memory");\
      exit(EXIT_FAILURE);\
   }\
}

typedef struct {
   int id;
   int grade;
}element;

typedef struct stack* stackPointer;
typedef struct stack {
   element data;
   stackPointer link;
}Node;
stackPointer top[MAX_STACKS];

void push(int i, element item)
{
   stackPointer temp;
   MALLOC(temp, sizeof(*temp));
   temp->data = item;
   temp->link = top[i];
   top[i] = temp;
}

void stackEmpty()
{
   fprintf(stderr, "stack is empty");
   exit(1);
}

element pop(int i)
{
   stackPointer temp = top[i];
   element item;
   if (!temp)
      stackEmpty();
   item = temp->data;
   top[i] = temp->link;
   free(temp);
   return item;
}

void stackPrint() 
{
   element item;
   for (int i = 0; i < MAX_STACKS; i++)
   {
      while (top[i])
      {
         item = pop(i);
         printf("%d %d %2d\n", i, item.id, item.grade);
      }
   }
}

int main()
{
   int n, id, score;
   element item;

   for (int i = 0; i < 13; i++)
   {
      scanf("%d %d %d", &n, &id, &score);
      item.id = id;
      item.grade = score;
      push(n, item);
   }

   stackPrint();
   return 0;
}