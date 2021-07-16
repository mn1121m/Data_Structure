#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define STACK_EMPTY -687356

typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item)
{
    if(top >= MAX_STACK_SIZE - 1) { //isFull
        fprintf(stderr, "Stack Full\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
element pop()
{
    if(top <= -1)  //isEmpty
        return STACK_EMPTY;
    return stack[top--];
}
void printStack()
{
    int i;
    
    printf("---------------------\n");
    for(i = 0; i < top + 1; i ++) {
        printf("[%d] == %d\n", i, stack[i]);
    }
}
int main(void) 
{
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();
    push(4);
    printStack();

    pop();
    printStack();
    pop();
    printStack();

    push(5);
    printStack();
    push(6);
    printStack();

}