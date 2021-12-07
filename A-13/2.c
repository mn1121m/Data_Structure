/* 0718 (일) 풀이
자료구조응용
13. Trees : 이진트리 생성 및 순회

2. 후위표현식(postfix expression)을 입력받아 Figure 5.16과 같은 이진트리를 구성한 후, 반복문을 사용한 중위순회 및 level-order 순회를 하는 프로그램을 작성하라.
[참고]
+ levelOrder() -> node: 현재노드
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory\n"); \
exit(EXIT_FAILURE); \
}

#define FALSE 0
#define TRUE 1

// Stack, Queue
#define MAX_STACK_SIZE 128
#define MAX_QUEUE_SIZE 128

// Expression
#define MAX_EXPR_SIZE 128

//
// Data Structure
// Precedence
typedef enum {eos = FALSE, plus, minus, times, divide, mod, operand} precedence;
// Binary tree
typedef struct node *treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

//
// Functions
// Stack
void push(treePointer item);
treePointer pop();

// Queue
void enqueue(treePointer item);
treePointer dequeue();

// Binary tree
void levelOrder(treePointer root);

void createPostBinTree();
treePointer createNode(char data, treePointer leftChild, treePointer rightChild);

// Precedence
precedence getToken(int *n, char *data);

//
// Global variable
treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[MAX_EXPR_SIZE];

treePointer queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;


int main(void)
{
    FILE *fp;

    printf("the length of input string should be less than %d\n", MAX_EXPR_SIZE);

    // Get String stream
    if (!(fp = fopen("input.txt", "r"))) {
        fprintf(stderr, "Wrong file name!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    fclose(fp);

    printf("input string (postfix expression) : %s\n", expr);

    printf("creating its binary tree\n\n");
    createPostBinTree();

    printf("level order traversal\t : ");
    levelOrder(root);


}
//
// Function
// Stack
void push(treePointer item)
{
    if (top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Stack full!\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
treePointer pop()
{
    if (top == -1) {
        fprintf(stderr, "Stack empty!\n");
        return NULL;
    }
    return stack[top--];
}

// Binary tree
void levelOrder(treePointer root)
{
    front = rear = 0;
    treePointer node;

    // empty tree
    if (!root) return;

    enqueue(root);
    while (TRUE) {
        node = dequeue();
        if (!node) return;
        printf("%c", node->data);
        if (node->leftChild) enqueue(node->leftChild);
        if (node->rightChild) enqueue(node->rightChild);
    }
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
treePointer createNode(char data, treePointer leftChild, treePointer rightChild)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;
    return temp;
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

// Queue (Circular)
void enqueue(treePointer item)
{
    if ((rear + 1) % MAX_QUEUE_SIZE == front) {
        fprintf(stderr, "Queue full!\n");
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}
treePointer dequeue()
{
    if (front == rear)
        return NULL;
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}
/* result
the length of input string should be less than 128
input string (postfix expression) : AB/C*D*E+
creating its binary tree

level order traversal    : +*E*D/CAB%   
*/