/* 진행중
자료구조응용
13. Trees : 이진트리 생성 및 순회
1. 후위표현식(postfix expression)을 입력받아 Figure 5.16과 같은 이진트리를 구성한 후, 이진트리 순회를 통해 중위표현식(infix expression), 전위표현식(prefix expression), 후 위표현식(postfix expression)을 출력하는 프로그램을 작성하라.

- 질문 - 
Undefined symbols for architecture x86_64:
  "_createBinTree", referenced from:
      _main in 1-82dce2.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
eval(), createBinTree() <-- 구현생각과 그 과정에 대해서 설명부탁드리겠습니다.
할 수록 뭔가 꼬이는것같고 잘모르겠습니다.
*/

#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 81
#define TRUE 1
#define FASLE 0

//Data structure
typedef struct _tNode* treePointer;
typedef struct _tNode {
    char data;  //문자열 출력을 위해 char 형으로 지정
    treePointer leftChild, rightChild;
} tNode;
typedef enum {lparen, rparen, plus, minus, times, divide,
 mod, eos, operand } precedence;

//Global variable
treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[MAX_EXPR_SIZE];  //postfix expression

//Funtion 
treePointer createNode(char data, treePointer left, treePointer right);
treePointer createBinTree(char expr[]);
treePointer eval(void);
precedence getToken(char *symbol, int *n);
void push(treePointer item);
treePointer pop();

//Function - traversals
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

//Main
int main(void)
{
    FILE *fp;

    if((fp = fopen("input.txt","r")) == NULL) {
        fprintf(stderr, "no file name.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    
    puts("the length of input string should be less than 80");
    printf("input string (postfix expression) : %s\n", expr);
    printf("creating its binary tree\n\n");
    
    root = createBinTree(expr);

    fclose(fp);
    return 0;
}
//Funtion
treePointer createNode(char data, treePointer left, treePointer right)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = left;
    temp->rightChild = right;

    return temp;
} 
treePointer createBinTree(char expr[]);
treePointer eval(void)
{
    precedence token;
    char symbol;
    treePointer op1, op2;
    int n = 0;      /* counter for the expression string */
    
    token = getToken(&symbol, &n);
    
    while(token != eos) {
        if(token == operand) {
            push(createNode(symbol, NULL, NULL));
        }
        else {
            op2 = pop();
            op1 = pop();
            switch(token) { 
                case plus: case minus: case times: case divide: case mod:
                push(createNode(symbol, op1, op2)); break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop(); // return result 
}
precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];

    switch(*symbol) {
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default : return operand;
    }
}
void push(treePointer item)
{
    if(top == MAX_STACK_SIZE -1) {
        fprintf(stderr, "stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
treePointer pop()
{
    if(top == -1) {
        fprintf(stderr, "stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}
//Function - traversals
void inorder(treePointer ptr)
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