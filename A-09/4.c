/* ()
Data structure

4. [Linked Queues] 다음과 같은 큐를 생성하고 실행하는 프로그램을 작성하라. 
이를 위해, addq, deleteq, qEmpty 함수를 구현하여야 한다.(3점)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUES 3
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

typedef struct queue* queuePointer;
typedef struct queue {
   element data;
   queuePointer link;
}Node;
queuePointer front[MAX_QUEUES];
queuePointer rear[MAX_QUEUES];

void addQueue(int i, element item)
{
   queuePointer temp;
   MALLOC(temp, sizeof(*temp));
   temp->data = item;
   temp->link = NULL;
   if (front[i])
      rear[i]->link = temp;
   else
      front[i] = temp;
   rear[i] = temp;
}

void queueEmpty() 
{
   fprintf(stderr, "queue is empty");
   exit(1);
}


element deleteQueue(int i) {
   queuePointer temp = front[i];
   element item;
   if (!temp) {
      queueEmpty();
   }
   item = temp->data;
   front[i] = temp->link;
   free(temp);
   return item;
}

void queuePrint() {
   element item;
   for (int i = 0; i < MAX_QUEUES; ++i) {
      while (front[i]) {
         item = deleteQueue(i);
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
      addQueue(n, item);
   }

   queuePrint();
   return 0;
}