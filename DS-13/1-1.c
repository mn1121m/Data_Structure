/* 진행중
자료구조응용
13. Trees : 이진트리 생성 및 순회
1. 후위표현식(postfix expression)을 입력받아 Figure 5.16과 같은 이진트리를 구성한 후, 이진트리 순회를 통해 중위표현식(infix expression), 전위표현식(prefix expression), 후 위표현식(postfix expression)을 출력하는 프로그램을 작성하라.

[중요]
+createPostBinTree() , getToken구현
[참고]
+ 전역변수는 프로그램종료전까지 초기화가 안되기 때문에 따로 함수안의 변수에 안써도 된다. 
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory\n"); \
exit(EXIT_FAILURE); \
}
//  Stack
#define MAX_STACK_SIZE 128

//  Expression
#define MAX_EXPR_SIZE 128

#define TRUE 1
#define FALSE 0

//  Data structures
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

typedef enum {plus, minus, times, divide, mod, eos, operand
} precedence;

//  Global variable
treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[MAX_EXPR_SIZE];

//  Functions

//  Stack
void push(treePointer item);
treePointer pop();

//  Binary tree
void createPostBinTree();
treePointer createNode(char data, treePointer leftChild, treePointer rightChild);

// Precedence
precedence getToken(int *n, char *data);

//  inorder, preorder, postorder
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

//  Main
int main(void)
{
    printf("the length of input string should be less than %d\n", MAX_EXPR_SIZE -1);
    FILE *fp;

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    fclose(fp);

    printf("input string (postfix expression) : %s\n", expr);

    printf("creating its binary tree\n\n");
    createPostBinTree();

    printf("inorder traversal\t : ");
    inorder(root);
    printf("\n");

    printf("preorder traversals\t : ");
    preorder(root);
    printf("\n");

    printf("postorder traversals\t : ");
    postorder(root);
    printf("\n\n");


}
//  Functions

//  Stack
void push(treePointer item)
{
    if(top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
treePointer pop()
{
    if(top == -1 ) {
        fprintf(stderr, "stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}
//  Binary tree
void createPostBinTree()
{
    int n = 0;      //counter for expression string
    char data;      // input data
    precedence token;
    treePointer op1, op2;

    while(token = getToken(&n, &data)) {
        if(token == operand) {
            push(createNode(data, NULL, NULL));  //stack insert
        }
        else {
            op2 = pop();
            op1 = pop();
            switch(token) {
                case plus : case minus : case times : case divide : case mod : 
                push(createNode(data, op1, op2));
            }
        }
    }
    root = pop();   //*중요*
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

   switch(*data) {
       case '+' : return plus;
       case '-' : return minus;
       case '*' : return times;
       case '/' : return divide;
       case '%' : return mod;
       case '\0' : return eos;
       default : return operand;
   }
}

//  inorder, preorder, postorder
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
// the length of input string should be less than 128
// input string (postfix expression) : AB-C-DE/*+
// creating its binary tree

// Stack empty!
// inorder traversals       : +A-B-C*D/E
// preorder traversals      : +*--ABC/DE
// postorder traversals     : AB-C-DE/*+