/* Team_1조 2번문제 - 발표자 : 문준용(moonjunyong)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nodePointer;
typedef struct node {
   int expo;
   int coef;
   nodePointer link;
}node;

typedef struct linkedList
{
   node* head;
}linkedList;

linkedList* create();
void addPoly(linkedList* A, linkedList* B, linkedList* C);
void printPoly(linkedList* l);
void addNode(linkedList* l, int e, int c);

int main()
{
   linkedList* a = create();
   linkedList* b = create();
   linkedList* r = create();
   int e, c;
   e = -1;

   printf("다항식 A의 차수와 계수를 입력하세요. 상수항의 차수는 0입니다.\n");
   while (e != 0)
   {
      printf("차수: ");
      scanf("%d", &e);
      printf("계수: ");
      scanf("%d", &c);
      printf("\n");

      addNode(a,c, e);
   }

   printf("=> 다항식 A는 ");
   printPoly(a);
   printf("입니다.\n");

   printf("\n---------------------\n");

   e = -1;
   printf("다항식 B의 차수와 계수를 입력하세요. 상수항의 차수는 0입니다.\n");
   while (e != 0)
   {
      printf("차수: ");
      scanf("%d", &e);
      printf("계수: ");
      scanf("%d", &c);
      printf("\n");

      addNode(b, c, e);
   }

   printf("=> 다항식 B는 ");
   printPoly(b);
   printf("입니다.\n");
   printf("\n---------------------\n");

   printf("다항식 A와 B를 더하면 ");
   addPoly(a, b, r);
   printPoly(r);
   printf("입니다.\n");

   return 0;
}

linkedList* create() {
   linkedList* N = (linkedList*)malloc(sizeof(linkedList));
   N->head = NULL;
   return N;
}

void printPoly(linkedList* l)
{
   node* print = l->head;
   for (; print; print = print->link)
   {
      printf("%dx^%d ", print->coef, print->expo);
   }
}

void addNode(linkedList* l, int c, int e)
{
   node* newNode = (node*)malloc(sizeof(node));
   node* p;
   newNode->expo = e;
   newNode->coef = c;
   newNode->link = NULL;
   
   if (l->head == NULL)
   {
      l->head = newNode;
      return;
   }
   else
   {
      p = l->head; 
      while (p->link != NULL)
         p = p->link;
      p->link = newNode;
   }
}

void addPoly(linkedList* a,linkedList * b,linkedList* c){
   node* pA = a->head;
   node* pB = b->head;
   int psum;

   while(pA && pB){
      if(pA->expo == pB->expo){
         psum= pA->coef + pB->coef;
         addNode(c, psum, pA->expo);
         pA = pA->link;
         pB = pB->link;
      }
      else if(pA->expo > pB->expo){
         addNode(c, pA->coef, pA->expo);
         pA = pA->link;
      }
      else{
         addNode(c, pB->coef, pB->expo);
         pB = pB->link;      
      }
   }
   for(; pA != NULL; pA = pA->link){
      addNode(c, pA->coef, pA->expo);
   }
   for(;pB != NULL; pB = pB->link){
      addNode(c, pB->coef, pB->expo);
   }
}
/*result
다항식 A의 차수와 계수를 입력하세요. 상수항의 차수는 0입니다.
차수: 5
계수: 2

차수: 3
계수: 4

차수: 2
계수: 6

차수: 1
계수: 8

차수: 0
계수: 0

=> 다항식 A는 2x^5 4x^3 6x^2 8x^1 0x^0 입니다.

---------------------
다항식 B의 차수와 계수를 입력하세요. 상수항의 차수는 0입니다.
차수: 4
계수: 3

차수: 2
계수: 5

차수: 0
계수: 7

=> 다항식 B는 3x^4 5x^2 7x^0 입니다.

---------------------
다항식 A와 B를 더하면 2x^5 3x^4 4x^3 11x^2 8x^1 7x^0 입니다.
*/