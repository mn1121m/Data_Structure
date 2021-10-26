/*
자료구조응용 08. 스택과 큐
1. 후위표기법(postfix notation)으로 표현된 하나의 수식을 파일(input.txt)로 입력받아 그 계 산결과를 화면에 출력하는 프로그램을 작성하라.

*중요*
=> zsh: floating point exception  ./main -> DEBUG를 통해 찾는 연습을 많이 해둬야 한다. (지속적으로)

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
    
    printf("postfix expression : %s\n", expr);
    printf("the evaluation value : %d\n", eval());

    fclose(fp);
    return 0;
}
void push(int item)
{
    if(top == MAX_STACK_SIZE -1) {
        fprintf(stderr, "stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
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
    
    token = getToken(&symbol, &n);
    
    while(token != eos) {
        if(token == operand) {
            push(symbol-'0');
            //printf("Operand : stack[%d] == %d\n", top, stack[top]);
        }
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
            //printf("Cal : stack[%d] == %d\n", top, stack[top]);
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
/* result
postfix expression : 82/3-42*+
the evaluation value : 9
*/