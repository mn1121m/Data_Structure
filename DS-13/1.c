/* 진행중
자료구조응용
13. Trees : 이진트리 생성 및 순회
1. 후위표현식(postfix expression)을 입력받아 Figure 5.16과 같은 이진트리를 구성한 후, 이진트리 순회를 통해 중위표현식(infix expression), 전위표현식(prefix expression), 후 위표현식(postfix expression)을 출력하는 프로그램을 작성하라.
*/

#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}
#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FASLE 0

//Data structure
typedef struct _tNode* treePointer;
typedef struct _tNode {
    char data;  //문자열 출력을 위해 char 형으로 지정
    treePointer leftChild, rightChild;
} tNode;

//Global variable
treePointer root;
treePointer queue[MAX_QUEUE_SIZE];
int top = -1;
char expr[81];  //postfix expression

//Funtion - create
treePointer createBinTree(FILE *fp);

//Function - traversals
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

//Main
int main(void)
{
    FILE *fp;

    if((fp = fopen("input.txt","r")) == NULL)) {
        fprintf(stderr, "no file name.\n");
        exit(EXIT_FAILURE);
    }
    root = createBinTree(fp);

    fclose(fp);
    return 0;
}
//Funtion - create
treePointer createBinTree(FILE *fp);

//Function - traversals
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);