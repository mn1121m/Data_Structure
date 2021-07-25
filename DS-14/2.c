/* 질문
    2. postfix expression의 명제식을 파일로부터 입력받는다. 
    이 명제식을 참으로 만들기 위해 입력 되는 변수에 대한 모든 경우의 값을 구하시오. 
    단 프로그램의 편의를 위해 입력되는 변수는 3개로 한다.

- 전반적인 구조는 이해하였는데, 그중에서
    createPostBinTree(), postOderEval() 에 대한 이해를 제대로 못했습니다.
    풀이과정 설명부탁드리겠습니다.
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory/\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_EXPR_SIZE 128
#define TRUE 1
#define FALSE 0

//  Data structrue 
typedef enum {not, and, or, true, false, eos, operand
} logical;

typedef struct _node *treePointer;
typedef struct _node {
    treePointer leftChild;
    logical data;
    int value;
    treePointer rightChild;
}   node;

//  Global variable
treePointer root;
logical token;
treePointer stack[MAX_EXPR_SIZE];
int top = -1;
char expr[MAX_EXPR_SIZE];

//  Functions
treePointer createNode(logical data, int value, treePointer leftChild, treePointer rightChild);
void createPostBinTree();
logical get_token(char *data, int *n);
void postOrderEval(treePointer node, int a, int b, int c);
int int_true_false(int data);

//  Stack
void push(treePointer item);
treePointer pop();

int main(void)
{  
    FILE *fp;
    int a, b, c;

    if((fp = fopen("postfix.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    printf("input string(postfix)\t : %s\n", expr);
    fclose(fp);

    //  createPostBinTree
    createPostBinTree();

    printf("find true condition\n");
    for(a = 0; a <= 1; a++) 
        for(b = 0; b <= 1; b++) 
            for(c = 0; c <= 1; c++) {
                postOrderEval(root, a, b, c);
                if(root->value)
                    printf("a = %d, b = %d, c = %d\n",
                    a ? TRUE : FALSE,
                    b ? TRUE : FALSE,
                    c ? TRUE : FALSE);
            }
            printf("\n");
    return 0;
}
treePointer createNode(treePointer leftChild, logical data, int value, treePointer rightChild)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->leftChild = leftChild;
    temp->data =data;
    temp->value = value;
    temp->rightChild = rightChild;

    return temp;
}
void createPostBinTree()
{
    treePointer temp;
    int n = 0;      //counter for expression string
    char data;      // input data
    logical token;
    token = get_token(&data, &n);
    temp->data = data; temp->value = false;

    while(token != eos) {
        switch(token) {
            case and: case or:
                temp->rightChild = pop();
                temp->leftChild = pop();
                push(temp); break;
            case not:
                temp->rightChild = pop();
                push(temp); break;
            default:
                push(temp); break;
        }
        temp->data = data; temp->value = false;
    }
    root = pop();   //*중요*
}
logical get_token(char *data, int *n)   //  n : index_expr
{
    *data = expr[(*n)++];
    switch(*data) {
        case '&': return and;
        case '|': return or;
        case '~': return not;
        case '\0': return eos;
        default : return operand;
    }
}
void postOrderEval(treePointer node, int a, int b, int c)
{
    if(node) {
        postOrderEval(node->leftChild, a, b, c);
        postOrderEval(node->rightChild, a, b, c);
    }
    switch(node->data) {
        case 'a': node->value = int_true_false(a); break;
        case 'b': node->value = int_true_false(b); break;
        case 'c': node->value = int_true_false(c); break;
        case not:
            node->value =
            !node->rightChild->value;
            break;
        case and:
            node->value =
            node->rightChild->value &&
            node->leftChild->value; break;
        case or:
            node->value =
            node->rightChild->value ||
            node->leftChild->value; break;
        case true:
            node->value = TRUE; break;
        case false:
            node->value = FALSE; break;
    }
}
int int_true_false(int data)
{
    return data ? true: false;
}
//  Stack
void push(treePointer item)
{
    if(top == MAX_EXPR_SIZE -1) {
        fprintf(stderr, "stack is full/\n");
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

