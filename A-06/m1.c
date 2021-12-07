/* remind 
file : 1.c

[*]
    - strtok() function, main안의 반복문 이해 
    - stackFupp() function안의 반복문 이해
    - stackEmpty() function안의 "return temp" <- temp 이해
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define */
#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 100
#define MAX_BUF_SIZE 100    // input

#define TRUE 1
#define FALSE 0

/* Data structure */
typedef struct {
    int id;                     // unique id
    char name[MAX_NAME_SIZE];   // last name
} element;

/* Global variavle */
element stack[MAX_STACK_SIZE];
int top = -1;

/*  Functions */
void push(element item);
void stackFull();
element pop();
element stackEmpty();

int main(void)
{
    element temp;
    char buf[MAX_BUF_SIZE];         // user's input data
    char *ptr, *delimeter = " ";

    printf("<< stack operation where MAX_STACK_SIZE is 5 >>\n");
    printf("push 1 Jung\n");
    printf("pop\n\n");
    printf("************************************************\n");

    while(TRUE) {
        gets(buf);

        ptr = strtok(buf, delimeter);
        // push 
        if(!strcmp("push", buf)) {
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%d", &(temp.id));

            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%s", temp.name);
            push(temp);
        }
        // pop
        else if(!strcmp("pop", buf)) {
            pop();
        }
        // if buf != push or buf != pop
        else {
            printf("Wrong command! try again!\n");
        }
    }
    return 0;
}
/*  Functions */
void push(element item)
{
    if( top >= MAX_STACK_SIZE -1) {
        stackFull();
    }
    stack[++top] = item;
}

void stackFull()
{
    int i = 0;
    element temp;

    fprintf(stderr, "stack is full, cannot add element\n");
    printf("current stack element:\n");
    for(i = 0; i < MAX_STACK_SIZE; i++) {
        temp = pop();
        printf("%d %s\n", temp.id, temp.name);
    }
    exit(EXIT_FAILURE);
}

element pop()
{
    if( top == -1) {
        return stackEmpty();
    }
    return stack[top--];
}

element stackEmpty()
{
    element temp = { -1, "[ERROR] : STACK EMPTY!"};
    puts("stack is empty, cannot delete element\n");
    exit(EXIT_FAILURE);

    return temp;
}
