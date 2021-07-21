/* 
자료구조응용
13. Trees : 이진트리 생성 및 순회

2. 후위표현식(postfix expression)을 입력받아 Figure 5.16과 같은 이진트리를 구성한 후, 반복문을 사용한 중위순회 및 level-order 순회를 하는 프로그램을 작성하라.
[중요]
levelOrder, iterInorder -> 다시()
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_STACK_SIZE 128
#define MAX_QUEUE_SIZE 128
#define MAX_EXPR_SIZE 128

#define TRUE 1
#define FALSE 0

//  Data structure
//  Precedence
typedef enum {eos = FALSE, plus, minus, times, divide, mod, operand} precedence;

typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

/*  Global variable */
treePointer root;
char expr[MAX_EXPR_SIZE];

// stack
treePointer stack[MAX_STACK_SIZE];
int top = -1;

// circular queue
treePointer queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

/*  Functions   */
//  Binary tree
treePointer createNode(char data, treePointer leftChild, treePointer rightChild);
void createPostBinTree();
void iterInorder(treePointer node);
void levelOrder(treePointer ptr);

// Precedence
precedence getToken(int *n, char *data);

//  Stack
void push(treePointer item);
treePointer pop();

//  Circular Queue
void enqueue(treePointer item);
treePointer dequeue();

int main(void)
{
    FILE *fp;

    printf("the length of input string should be less than %d\n", MAX_EXPR_SIZE);

    if((fp = fopen("input-2.txt", "r")) == NULL) {
        fprintf(stderr, "Insufficient memory.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    fclose(fp);

    printf("input string (postfix expression) : %s\n", expr);
    printf("creating its binary tree\n\n");
    createPostBinTree();

    printf("iterative inorder traversal\t : ");
    iterInorder(root);
    printf("\n");

    printf("level order traversal\t\t : ");
    levelOrder(root);
    printf("\n\n");

}
//  Functions
//  Binary tree
treePointer createNode(char data, treePointer leftChild, treePointer rightChild)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;

    return temp;
}
void createPostBinTree()
{
    int n = 0;
    char data;
    precedence token;
    treePointer op1, op2;

    while (token = getToken(&n, &data)) {
        switch (token) {
            case operand: 
                push(createNode(data, NULL, NULL));
                break;
            case plus: case minus: case times: case divide: case mod:
                op2 = pop();
                op1 = pop();
                push(createNode(data, op1, op2));   
        }
    }
    root = pop();
}
void iterInorder(treePointer node)  // 현재노드 (root에서 시작)
{
    while(TRUE) {
        for(; node; node = node->leftChild)
            push(node);
        node = pop();
        if (!node) break;
        printf("%c", node->data);
        node = node->rightChild;
    }
}
void levelOrder(treePointer ptr)    // 현재노드 (root에서 시작)
{
    if(!ptr) return;    /* empty tree */
    enqueue(ptr);

    while(TRUE) {
        ptr = dequeue();
        if(!ptr) return;
        printf("%c", ptr->data);
        if(ptr->leftChild)
            enqueue(ptr->leftChild);
        if(ptr->rightChild)
            enqueue(ptr->rightChild);
    }
}
// Precedence
precedence getToken(int *n, char *data)
{
    *data = expr[(*n)++];
    switch (*data) {
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}
//  Stack
void push(treePointer item)
{
    if (top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
treePointer pop()
{
    if (top == -1 ) {
        return NULL;
    }
    return stack[top--];
}
//  Circular Queue
void enqueue(treePointer item)
{
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if (front == rear) {
        fprintf(stderr, "queue is full.\n");
        exit(EXIT_FAILURE);
    }
    queue[rear] = item;
}
treePointer dequeue()
{
    if( front == rear ) {
        return NULL;
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}
/* result
the length of input string should be less than 128
input string (postfix expression) : AB/C*D*E+
creating its binary tree

iterative inorder traversal      : A/B*C*D+E
level order traversal            : +*E*D/CAB

*/
