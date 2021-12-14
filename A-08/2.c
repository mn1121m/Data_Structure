/*
data structure
08. 스택과 큐

2. 중위표기법(infix notation)으로 표현된 하나의 수식을 파일로 입력받아 후위표기법(postfix notation)으로 변환하여 화면 및 파일에 동시에 출력하는 프로그램을 작성하라.

[중요]
    - postfix() 이해와 구현 /  마지막 while() - 남은 token도 출력
    - printToken() 구현
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 128
#define MAX_EXPR_SIZE 80

// Data Structure
typedef enum { lparen, rparen, plus, minus, times, divide,
                mod, eos, operand } precedence;

// Global variable
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
precedence stack[MAX_STACK_SIZE];

char expr[MAX_EXPR_SIZE];
int top = -1;

// Function
void postfix();
precedence getToken(char *symbol, int *n);
void printToken(precedence p);
void push(precedence item);
precedence pop();

// Main
int main(void)
{
    FILE *fp = NULL;

    if((fp = fopen("input2.txt","r")) == NULL) {
        fprintf(stderr, "no file name\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    fclose(fp);

    printf("<<<<<<<<infix to postfix >>>>>>>>>\n");
    printf("infix expression\t: %s\n", expr);

    // postfix
    printf("postfix expression\t: ");
    postfix();
    putchar('\n');

    return 0;
}
// Function
void postfix()
{
    /* output the postfix expression.
    The expression string, the stack, and top are global */
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack[0] = eos;
    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if(token == operand) {
            printf("%c", symbol);
        }
        else if( token == rparen) {
            while(stack[top] != lparen)
                printToken(pop());
            pop();
        }
        else {
            /* remove and print symbols whose isp is greater than
            or equal to cuurent token's icp */
            while(isp[stack[top]] >= icp[token])
                printToken(pop());
            push(token);
        }
    }
    /* 남은 token(operator)도 출력 */
    while( (token = pop()) != eos)
        printToken(token);
    printf("\n");
}
precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch (*symbol) {
    case '('    :   return lparen;
    case ')'    :   return rparen;
    case '+'    :   return plus;
    case '-'    :   return minus;
    case '/'    :   return divide;
    case '*'    :   return times;
    case '\0'   :  return eos;
    default     :   return operand;
    }
}
/* printToken */
void printToken(precedence p)
{
    switch (p) {
    case plus: printf("+"); break;
    case minus: printf("-"); break;
    case times: printf("*"); break;
    case divide: printf("/"); break;
    case mod: printf("%%"); break;
    default : break;
    }
}
void push(precedence item)
{
    if( top == MAX_STACK_SIZE -1) {
        fprintf(stderr, "stack is full\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
precedence pop()
{
    if( top == -1) {
        fprintf(stderr, "stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

