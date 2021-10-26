/* remind 
file: 1.c   => ok
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 128
#define MAX_EXPR_SIZE 80

// Data structure
typedef enum { lparen, rparen, plus, minus, times, divide,
                mod, eos, operand } precedence;

// Global variable
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

// Functions
int eval(void);
precedence getToken(char *symbol, int *n);

void push(int item);
int pop();

// Main
int main(void)
{
    FILE *fp;

    if((fp = fopen("input.txt","r")) == NULL) {
        fprintf(stderr, "no file name\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s", expr);
    fclose(fp);

    // postfix
    printf("postfix expression : %s\n", expr);

    // eval
    printf("the evaluation value : %d\n", eval());

    return 0;
}
// Functions
int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    top = -1;
    token = getToken(&symbol, &n);

    while(token != eos) {
        if( token == operand)
            push(symbol -'0');
        else {
            op2 = pop();
            op1 = pop();
            switch(token) {
                case plus: push(op1 + op2); break;
                case minus: push(op1 - op2); break;
                case times: push(op1 * op2); break;
                case divide: push(op1 / op2); break;
                case mod: push(op1 % op2); break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop();
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
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
void push(int item)
{
    if (top == MAX_STACK_SIZE -1) {
        fprintf(stderr, "stack is full\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
int pop()
{
    if(top == -1) {
        fprintf(stderr, "stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}