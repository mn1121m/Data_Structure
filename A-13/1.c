/* 0718 풀이
자료구조응용
13. Trees : 이진트리 생성 및 순회

1. 후위표현식(postfix expression)을 입력받아 Figure 5.16과 같은 이진트리를 구성한 후, 
이진트리 순회를 통해 중위표현식(infix expression), 전위표현식(prefix expression), 후 위표현식(postfix expression)을 출력하는 프로그램을 작성하라.
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

// Stack
#define MAX_STACK_SIZE 128

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

// Binary tree
void createPostBinTree();
treePointer createNode(char data, treePointer leftChild, treePointer rightChild);

// Precedence
precedence getToken(int *n, char *data);

// Inorder, Preorder, Postorder
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

//
// Global variable
treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[MAX_EXPR_SIZE];

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

void inorder(treePointer ptr)
{
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
void preorder(treePointer ptr)
{
    if (ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
void postorder(treePointer ptr)
{
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}

// result
// the length of input string should be less than 127
// input string (postfix expression) : AB-C-DE/*+
// creating its binary tree

// inorder traversal        : A-B-C*D/E
// preorder traversals      : *--ABC/DE
// postorder traversals     : AB-C-DE/*

