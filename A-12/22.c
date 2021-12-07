#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

//  Queue 
#define MAX_QUEUE_SIZE 128

//  BOOL
typedef int BOOL;
#define TRUE 1
#define FALSE 0

//  Data structrue 
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

//  Global variable
treePointer root = NULL;
treePointer queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

//  Functions
//  Complete Binary tree
treePointer createNode(char data);
treePointer createComBinTree(FILE *fp);
void insert(treePointer *pRoot, treePointer newNode);
int hasBothChild(treePointer ptr);

//  Queue
void enqueue(treePointer item);
treePointer dequeue();
void queueFULL();
treePointer deleteEmpty();

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);
//  Main
int main(void)
{
    FILE *fp;

    printf("creating a complete binary tree\n\n");
    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    root = createComBinTree(fp);
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
//  Functions
//  Complete Binary tree
treePointer createNode(char data)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}
treePointer createComBinTree(FILE *fp)
{
    char temp;

    while(fscanf(fp, "%c", &temp) != EOF) {
        insert(&root, createNode(temp));
    }
    return root;
}
/*중요*/
void insert(treePointer *pRoot, treePointer newNode)
{
    treePointer frontNode;

    if(!(*pRoot)) {
        *pRoot = newNode;
    } else {
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
int hasBothChild(treePointer ptr)
{
    int flag = FALSE;

    if(ptr->leftChild && ptr->rightChild) {
        flag = TRUE;
        return flag;
    }
    return flag;
}

//  Queue
void enqueue(treePointer item)
{
    if(rear == MAX_QUEUE_SIZE -1) {
        queueFULL();
    }
    queue[++rear] = item;
}
treePointer dequeue()
{
    if(front == rear) {
        return deleteEmpty();
    }
    return queue[++front];
}
void queueFULL()
{
    fprintf(stderr, "queue is full.\n");
    exit(EXIT_FAILURE);
}
treePointer deleteEmpty()
{
    fprintf(stderr, "queue is empty.\n");
    return NULL;
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