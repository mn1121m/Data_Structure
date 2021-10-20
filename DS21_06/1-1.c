#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0};

typedef enum {
    lparen, rparen, plus, minus,
    times, divide, mod, eos, operand
} precedence;

// Stack
precedence stack_precedence[MAX_STACK_SIZE];    //연산자 
int top = -1;

// Expression
char expr[MAX_EXPR_SIZE];                       //숫자, 연산자

// Functions
void postfix(void);
precedence get_token (char *symbol, int *n);
void push(precedence item);
precedence pop(void);
void print_token(precedence p);

int main()  //int argc, char *argv[]
{
    // input
    scanf("%s", expr);
    postfix();
    return 0;
}
// Functions
void postfix(void)
{
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack_precedence[0] = eos;

    for (token = get_token(&symbol,&n); token != eos;
     token = get_token(&symbol,&n)) {
        if (token == operand) 
            printf("%c", symbol);
        else if (token == rparen) {
            while (stack_precedence[top] != lparen)
                print_token(pop());
            pop(); /* discard the left parenthesis */
        } else { 
            while (isp[stack_precedence[top]] >= icp[token]) {
                print_token(pop());
                if (top == -1) break;
            }
            push(token);
        }
    }
    while ((token = pop()) != eos) 
        print_token(token);
    printf("\n");
}

precedence get_token (char *symbol, int * n)
{
    *symbol = expr[(*n)++];

    switch (*symbol) {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case '\0': return eos;
        default : return operand;
    }
}
void push(precedence item) {
    if (top == MAX_STACK_SIZE-1) {
        fprintf(stderr, "[ERROR] : Precedence push error.\n");
        exit(EXIT_FAILURE);
    }
    stack_precedence[++top] = item;
}
precedence pop() {
    if (top == -1) {
        fprintf(stderr, "[ERROR] : Precedence pop error.\n");
        exit(EXIT_FAILURE);
    }
    return stack_precedence[top--];
}
void print_token(precedence p)
{
    switch(p) {
    case plus: 
        printf("+");
        break;
    case minus: 
        printf("-");
        break;
    case times: 
        printf("*");
        break;
    case divide: 
        printf("/");
        break;
    case mod: 
        printf("%%");
        break; 
    default:
        break;
    }

}
