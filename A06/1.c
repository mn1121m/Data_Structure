/*
자료구조응용 06. 스택과 큐
1. [정적할당배열의 스택] 다음과 같은 스택을 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라.
    이를 위해, push, pop, stackEmpty, stackFull, sprint(스택의 내용을 출력) 함수 를 구현하여야 한다.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct {
    int id;
    char name[MAX_STACK_SIZE];
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item)
{
    if(top >= MAX_STACK_SIZE -1) {
        stackFULL();
    }
    stack[++top] = item;
}
element pop()
{
    if(top == -1)
        return stackEmpty();
    return stack[top--];
}
void stackFULL()
{
    fprintf(stderr, "Stack is full\n");
    exit(EXIT_FAILURE);
}
element stackEmpty()
{
    fprintf(stderr, "Stack is Empty\n");
    exit(EXIT_FAILURE);
}
int main(void)
{
    

    return 0;
}