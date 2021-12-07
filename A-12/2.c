/* 
Data structure 
12. Trees : create Binary tree

2. [큐를 이용한 완전이진트리 생성] 파일입력을 받아 다음과 같은 완전이진트리(complete binary tree)를 구성하여,
이진트리 순회방법 중 중위순회, 전위순회, 후위순회를 통해 출 력하는 프로그램을 작성하라.

[구현] - 중요
+ treePointer createCompBinTree(FILE *fp); -> ()
+ void insert(treePointer *pRoot, treePointer newNode);
[참고]
+ insert() => Transformer (Chapter 01(1) 참고)
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Queue
#define MAX_QUEUE_SIZE 128

// BOOL
typedef int BOOL;
#define TRUE 1
#define FALSE 0

//
// Data structure
// Binary tree
typedef struct node *treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

// Queue
// Linear queue

//
// Functions
// Binary tree
treePointer createNode(char data);
treePointer createCompBinTree(FILE *fp);

void insert(treePointer *pRoot, treePointer newNode);
BOOL hasBothChild(treePointer ptr); //* 의문형함수 -> boolean 많이 쓴다.
treePointer insert2(treePointer root, treePointer newNode);

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

// Queue
void enqueue(treePointer item);
treePointer dequeue();

// Global variable
treePointer root = NULL;
treePointer queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

int main(void)
{
    FILE *fp;

    printf("creating a complete binary tree\n\n");
    if (!(fp = fopen("input.txt", "r"))) {
        printf("Wrong file name!\n");
        exit(EXIT_FAILURE);
    }
    root = createCompBinTree(fp);
    fclose(fp);

    printf("three binary tree traversals\n");
    printf("inorder traversals\t : ");
    inorder(root);
    putchar('\n');
    printf("preorder traversals\t : ");
    preorder(root);
    putchar('\n');
    printf("postorder traversals\t : ");
    postorder(root);
    putchar('\n');
    putchar('\n');

}
// Functions
treePointer createNode(char data)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}
treePointer createCompBinTree(FILE *fp)
{
    char temp;

    while (fscanf(fp, "%c", &temp) != EOF) {
        root = insert2(root, createNode(temp));
    }
    return root;
}
/*중요*/
void insert(treePointer *pRoot, treePointer newNode)
{
    treePointer frontNode;  //* queue에서 맨앞에 있는 노드구나.

    if (!(*pRoot)) {
        *pRoot = newNode;
    } else {
        frontNode = queue[front + 1];

        if (!(frontNode->leftChild)) {
            frontNode->leftChild = newNode;
        } else if (!(frontNode->rightChild)) {
            frontNode->rightChild = newNode;
        }
        if (hasBothChild(frontNode))
            dequeue();
    }
    enqueue(newNode);
}
//root 는 지역변수이기 때문에 return을 해줘야 하고 treePointer형으로 반환한다.
treePointer insert2(treePointer root, treePointer newNode)
{
    treePointer frontNode;

    if (!root) {
        root = newNode;
    } else {
        frontNode = queue[front + 1];

        if (!(frontNode->leftChild)) {
            frontNode->leftChild = newNode;
        } else if (!(frontNode->rightChild)) {
            frontNode->rightChild = newNode;
        }

        if (hasBothChild(frontNode))
            dequeue();
    }
    enqueue(newNode);

    return root;
}

BOOL hasBothChild(treePointer ptr)
{
    if (ptr->leftChild && ptr->rightChild)
        return TRUE;
    return FALSE;
}


// Queue
void enqueue(treePointer item)
{
    // Queue Full
    if (rear == MAX_QUEUE_SIZE - 1) {
        fprintf(stderr, "Queue Full!\nTermination...\n");
        exit(EXIT_FAILURE);
    }
    // Enqueue
    queue[++rear] = item;
}
treePointer dequeue()
{
    // Queue empty
    if (front == rear) {
        fprintf(stderr, "Queue empty!\n");
        return NULL;
    }
    // Dequeue
    return queue[++front];

}

//LVR
void inorder(treePointer ptr)
{
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
//VLR
void preorder(treePointer ptr)
{
    if (ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
//LRV
void postorder(treePointer ptr)
{
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}
/* result
creating a complete binary tree

three binary tree traversals
inorder traversals       : HDIBEAFCG
preorder traversals      : ABDHIECFG
postorder traversals     : HIDEBFGCA
*/