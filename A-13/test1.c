/*  review 1.c  */
// 2:13:44~
/*
[중요]
+createPostBinTree() , getToken구현
[참고]
+ 전역변수는 프로그램종료전까지 초기화가 안되기 때문에 따로 함수안의 변수에 안써도 된다. 
+ typedef A B; A를 B라 부른다.
+ / eos = FALSE 쓰는 이유 : createPostBinTree() 내의 while문 
while((tocken = getToken(&n)) != eos) 에서 값이 0일때 조건문에서 빠져나가는 것을 간단하게 구현하기 위해서 쓰였다.
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

// Stack
#define MAX_STACK_SIZE 128
// Expression
#define MAX_EXPR_SIZE 128

// Data structure
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

// Precedence
typedef enum {eos = FALSE, plus, minus, times, divide, mod, operand} precedence;

// Global variable
treePointer root = NULL;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[MAX_EXPR_SIZE];  // postfix expression

// Functions
// Stack
void push(treePointer item);
treePointer pop();

// Binary tree => *중요*
treePointer createNode(char data, treePointer leftChild, treePointer rightChild);
void createPostBinTree();
precedence getToken();

// In, Pre, Post order
void preorder(treePointer ptr);
void inorder(treePointer ptr);
void postorder(treePointer ptr);

// Main
int main(void)
{
    FILE *fp;
    if( !(fp = fopen("input.txt", "r")) ) {
        fprintf(stderr, "Wrong file name\n"); 
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    fclose(fp);

    printf("input string (postfix expression) : %s\n", expr);

    printf("creating its binary tree\n\n");
    createPostBinTree();

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
void push(treePointer item)
{
    if(top == MAX_STACK_SIZE -1) {
        fprintf(stderr, "Stack is full\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
treePointer pop()
{
    if( top == -1) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
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
/* 중요 */
void createPostBinTree()
{
    int n = 0;
    char data;
    precedence token;
    treePointer op1, op2;

    while(token = getToken(&n, &data)) {
        switch (token) {
        case operand:
            push(createNode(data, NULL, NULL));
            break;
        case plus: case minus: case times: case divide:
            op2 = pop();
            op1 = pop();
            push(createNode(data, op1, op2));
        }

    }
    root = pop();
}
/* 중요 */
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

void preorder(treePointer ptr)
{
    if(ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
void inorder(treePointer ptr)
{
    if(ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
void postorder(treePointer ptr)
{
    if(ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}