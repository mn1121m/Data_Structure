/*
자료구조응용
11. Equivalence Class, Doubly Linked Circular List
*Task*
2. 다음과 같이 정수 데이터를 입력하면서 
 “헤더노드를 가진 이중연결환형리스트 (doubly linked circular list)”를 만들고
 실행 예와 같이 수행되는 프로그램을 작성하라.(디버깅 화면 캡쳐 포함)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
   nodePointer llink;
   int data;
   nodePointer rlink;
}node;
nodePointer header = NULL;
nodePointer temp;

void dinsert(nodePointer node, nodePointer newnode);
void ddelete(nodePointer node, nodePointer deleted);
void printforward(nodePointer head);
void printreverse(nodePointer head);
void removenode(nodePointer head, int num);


int main(void)
{
   header = malloc(sizeof(*header));
   temp = header;
   int num;
   for (int i = 0; i < 30; i++) {
      nodePointer new;
      new = malloc(sizeof(*new));
      scanf("%d", &num);
      new->data = num;
      dinsert(temp, new);
      temp = new;
   }
   printforward(header);
   printreverse(header);

   int numR;
   scanf("%d", &numR);
   removenode(header, numR);
   printforward(header);
   printreverse(header);
}

void dinsert(nodePointer node, nodePointer newnode)
{
   if (node == header) {
      newnode->llink = node;
      newnode->rlink = node;
      node->llink = newnode;
      node->rlink = newnode;
   }
   else {
      newnode->llink = node;
      newnode->rlink = node->rlink;
      node->rlink->llink = newnode;
      node->rlink = newnode;
   }
}

void ddelete(nodePointer node, nodePointer deleted)
{
   if (node == deleted)
      printf("Deletion of header node not permitted.\n");
   else {
      deleted->llink->rlink = deleted->rlink;
      deleted->rlink->llink = deleted->llink;
   }
}

void printforward(nodePointer head)
{
   nodePointer temp;
   temp = head->rlink;
   int count = 0;
   while (temp != head) {
      printf("%3d", temp->data);
      temp=temp->rlink;
      count++;
      if ((count % 10 == 0) && (temp != head)) {
         printf("\n");
      }
   }
   printf("\n");
}

void printreverse(nodePointer head)
{
   nodePointer temp;
   temp = head->llink;
   int count = 0;
   while (temp != head) {
      printf("%3d", temp->data);
      temp = temp->llink;
      count++;
      if ((count % 10 == 0) && (temp != head)) {
         printf("\n");
      }
   }
   printf("\n");
}

void removenode(nodePointer head, int num)
{
   nodePointer temp;
   temp = head->rlink;
   while (temp != head) {
      if ((temp->data) <= num) {
         ddelete(header, temp);
      }
      temp = temp->rlink;
   }
}
/* result
50 80 30 20 19 90 30 55 77 30
99 45 55 89 91 10 20 66 38 59                              
22 55 88 22 66 29 50 95 78 83    // 입력
 50 80 30 20 19 90 30 55 77 30
 99 45 55 89 91 10 20 66 38 59
 22 55 88 22 66 29 50 95 78 83   //순방향 출력
 83 78 95 50 29 66 22 88 55 22
 59 38 66 20 10 91 89 55 45 99
 30 77 55 30 90 19 20 30 80 50   //역방향 출력
50                               //비교값 입력
 80 90 55 77 99 55 89 91 66 59
 55 88 66 95 78 83               //순방향 출력
 83 78 95 66 88 55 59 66 91 89
 55 99 77 55 90 80               //역방향 출력
 */