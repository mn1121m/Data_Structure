/* 진행중
자료구조응용
12. Trees : 이진트리 생성

2. [큐를 이용한 완전이진트리 생성] 파일입력을 받아 다음과 같은 완전이진트리(complete binary tree)를 구성하여, 이진트리 순회방법 중 중위순회, 전위순회, 후위순회를 통해 출 력하는 프로그램을 작성하라.
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insuficient memory\n"); \
exit(EXIT_FAILURE); \
}
#define MAX_QUEUE_SIZE 100

//Data structure
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

//Global variable 
treePointer root = NULL;
treePointer queue[MAX_QUEUE_SIZE];

//Function - queue
addq()
deeleteq()
queueFULL()
deleteEmpty()
//Function - tree
treePointer createNode(char data);
treePointer createCompBinTree(FILE *fp);
void insert(treePointer *pRoot, treePointer pNode);
int hasBothChild(treePointer pNode);

int main(void)
{

    return 0;
}