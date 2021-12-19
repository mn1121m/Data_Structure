/*  review 2.c  */
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


// Data structure
// Binary tree
typedef struct node *treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;


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
    FILE *fp = NULL;

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name\n");
        exit(EXIT_FAILURE);
    }
    printf("creating a complete binary tree\n\n");
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

    return 0;
}
// Functions
// Binary tree
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

    while(fscanf(fp, "%c", &temp) != EOF) {
        insert(&root, createNode(temp));
    }
    return root;
}
void insert(treePointer *pRoot, treePointer newNode)
{
    treePointer frontNode;

    if(!(*pRoot)) {
        *pRoot = newNode;
    }
    else {
        frontNode = queue[front + 1];

        if(!(frontNode->leftChild)) {
            frontNode->leftChild = newNode;
        } else if(!(frontNode->rightChild)) {
            frontNode->rightChild = newNode;
        }
        if(hasBothChild(frontNode)) {
            dequeue();
        }
    }
    enqueue(newNode);
}
treePointer insert2(treePointer root, treePointer newNode)
{
    treePointer frontNode;

    if(!(root)) {
        root = newNode;
    }
    else {
        frontNode = queue[front + 1];

        if(!(frontNode->leftChild)) {
            frontNode->leftChild = newNode;
        } else if(!(frontNode->rightChild)) {
            frontNode->rightChild = newNode;
        }
        if(hasBothChild(frontNode)) {
            dequeue();
        }
    }
    enqueue(newNode);
    return root;
}
BOOL hasBothChild(treePointer ptr) //* 의문형함수 -> boolean 많이 쓴다.
{
    int flag = FALSE;

    if(ptr->leftChild && ptr->rightChild) {
        flag = TRUE;
        return flag;
    }
    return flag;
}
//treePointer insert2(treePointer root, treePointer newNode);
// Queue
void enqueue(treePointer item)
{
    // Queue Full
    if( rear == MAX_QUEUE_SIZE -1) {
        fprintf(stderr, "Queue is Full!\nTermination...\n");
        exit(EXIT_FAILURE);
    }
    // Enqueue
    queue[++rear] = item;
}
treePointer dequeue()
{
    // Queue empty
    if( front == rear) {
        fprintf(stderr, "Queue is empty!\n");
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