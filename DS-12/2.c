/* 진행중
자료구조응용
12. Trees : 이진트리 생성

2. [큐를 이용한 완전이진트리 생성] 파일입력을 받아 다음과 같은 완전이진트리(complete binary tree)를 구성하여, 이진트리 순회방법 중 중위순회, 전위순회, 후위순회를 통해 출 력하는 프로그램을 작성하라.
    - Q -
treePointer createCompBinTree(FILE *fp);
void insert(treePointer *pRoot, treePointer pNode);
위의 함수식에 대한 풀이과정을 듣고싶습니다. 일단 구조는 짰는데, 세부적으로 구현과정에서 막막한 부분들이 있는데, 혹시 힌트만 먼저 주실수 있을까요 ?
그리고 왜 *pRoot에서 이중포인트를 쓴 이유를 왜썼는지에 대해서 궁금합니다.
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insuficient memory\n"); \
exit(EXIT_FAILURE); \
}
#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FALSE 0

//Data structure
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

//Global variable 
treePointer root;
treePointer queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

//Function - queue
void addq(treePointer item);
treePointer deleteq();
void queueFULL();
treePointer deleteEmpty();

//Function - complete binary tree
treePointer createNode(char data);
treePointer createCompBinTree(FILE *fp);
void insert(treePointer *pRoot, treePointer pNode);
int hasBothChild(treePointer pNode);

//Function - traversals
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

//Main
int main(void)
{
    FILE *fp;

    if(fp = fopen("input.txt", "r") == NULL) {
        fprintf(stderr, "no file name.\n");
        exit(EXIT_FAILURE);
    }
    printf("creating a complete binary tree\n");
    root = createBinTree(&fp);

    fclose(fp);

    printf("three binary tree traversals\n");
    printf("inorder traversals\t : ");
    inorder(root);
    printf("\n");

    printf("preorder traversals\t : ");
    preorder(root);
    printf("\n");

    printf("postorder traversals\t : ");
    postorder(root);
    printf("\n\n");
    return 0;
}
//Function - queue
void addq(treePointer item)
{
    if(rear == MAX_QUEUE_SIZE -1) {
        queueFULL();
    }
    queue[++rear] = item;
}
treePointer deleteq()
{
    if(front = rear) {
        return deleteEmpty();
    }
    return queue[++front];
}
void queueFULL()
{
    fprintf(stderr, "queue is full, can not add element.\n");
    exit(EXIT_FAILURE);
}
treePointer deleteEmpty()
{
    treePointer message = {'\n', NULL, NULL};

    fprintf(stderr, "queue is empty, can not delete element/\n");
    exit(EXIT_FAILURE);

    return message;
}
//Function - complete binary tree
treePointer createNode(char data)
{
    treePointer temp;
    MALLOC(new, sizeof(*temp));

    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}
treePointer createCompBinTree(FILE *fp)
{
    treePointer new;
    char ch;
    
    while(!feof(fp)) {
        fscanf(fp, "%c", &ch);
        insert(&new, createNode(ch));
    }
    return new;
}
void insert(treePointer *pRoot, treePointer pNode)
{
    //1)if the tree is empty, initialize the root with new node.
    if(pRoot == NULL) {
        createNode(pRoot->data);
    //2)else
    } else {
        //1)leftChild is empty
        if(pNode->leftChild == NULL) {
            
        }
        //2)rightChild is empty
        else if(pNode->rightChild == NULL) {

        }
        //3)front node has both left, right.
        if(hasBothChild(pNode)) {   // not null일 경우
            deleteq();
        }
    }
    //3)Enqueue() the new node.
    addq(pNode);
}
int hasBothChild(treePointer pNode)
{
    int flag = FALSE;

    if(pNode->leftChild != NULL && pNode->rightChild != NULL) {
        both = TRUE;
    }

    return flag;
}
//Function - traversals
void inorder(treePointer ptr)   //LVR
{
    if(ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
void preorder(treePointer ptr)
{
    if(ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
void postorder(treePointer ptr)
{
    if(ptr) {
        postorder(ptr->leftChild);
        printf("%c", ptr->data);
        postorder(ptr->rightChild);
    }
}