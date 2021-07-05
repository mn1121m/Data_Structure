/* 자료구조응용 08. 스택과 큐
1. 후위표기법(postfix notation)으로 표현된 하나의 수식을 파일(input.txt)로 입력받아 그 계 산결과를 화면에 출력하는 프로그램을 작성하라.

- 질문 - 
1.c:75:20: warning: enumeration values 'eos' and 'operand' not handled in switch [-Wswitch]
            switch(token) {
                   ^
1.c:75:20: note: add missing switch cases
            switch(token) {
                   ^
그리고 결과가 다음과 같이 뜹니다.
=> zsh: floating point exception  ./main
어떤 의미이고, 어떻게 고쳐야 하는건가요 ?
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 128
#define MAX_EXPR_SIZE 80
#define TRUE 1
#define FALSE 0

//Data structure
typedef enum {plus, minus, times
, divide, mod, eos, operand} precedence;

//Global variable
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

//Function
void push(int item);
int pop();
int eval(void);
precedence getToken(char *symbol, int *n);

int main(void)
{
    FILE *fp;

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "don't exist file name.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    
    printf("postfix expression : %s", expr);
    printf("the evaluation value : %d", eval());

    fclose(fp);
    return 0;
}
void push(int item)
{
    if(top == MAX_STACK_SIZE -1) {
        fprintf(stderr, "stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack[top++] = item;
}
int pop()
{
    if(top == -1) {
        fprintf(stderr, "stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}
int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;      /* counter for the expression string */
    top = -1;
    
    token = getToken(&symbol, &n);
    
    while(token != eos) {
        if(token == operand)
            push(symbol-'0');
        else {
            op2 = pop();
            op1 = pop();
            switch(token) {
                case plus: push(op1 + op2); break;
                case minus: push(op1 - op2); break;
                case times: push(op1 * op2); break;
                case divide: push(op1 / op2); break;
                case mod: push(op1 % op2);
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