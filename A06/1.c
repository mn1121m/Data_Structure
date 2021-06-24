/*
자료구조응용 06. 스택과 큐 
1. [정적할당배열의 스택] 다음과 같은 스택을 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라.
    이를 위해, push, pop, stackEmpty, stackFull, sprint(스택의 내용을 출력) 함수 를 구현하여야 한다.

- 질문 -

다시() - strtok, gets, strcmp, strlen
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5
#define MAX_BUF_SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct {
    int id;                     //unique id
    char name[MAX_STACK_SIZE];  //last name
} element;

element stack[MAX_STACK_SIZE];
int top = -1;
 
void push(element item);
element pop();
void stackFULL();
element stackEmpty();

int main(void)
{
    //gets_s, strtok_s, strcpm, sscanf_s, strlen
    int i = 0;
    char buf[MAX_BUF_SIZE];
    char *token, *delemeter = " ";

    printf("<< stack operations where MAX_STACK_SIZE is 5 >>\n");
    printf("push 1 Jung\n");
    printf("pop\n");

    printf("**************************************************\n");
    while(TRUE) {
        //push
        fgets(buf, sizeof(buf), stdin); //enter포함하고 있음. '\n'
        buf[strlen(buf) - 1] = '\0';    //enter포함하고 있는 '\n' 자리에 '\0'을 넣어버리면 됩니다.

        token = strtok(buf, delemeter);
        if(strcmp(token, "push") == 0) {
            token = strtok(NULL, delemeter);
            sscanf(token, "%d", temp);
            push(temp);
            
            token = strtok(NULL, delemeter);
            sscanf(token, "%s", temp);
            push(temp);
        }
        if(strcmp(token, "pop") == 0) {
            pop();
        }
        
        if(i > MAX_STACK_SIZE -1 ) {
            stackFULL();
            break;
        }
        i++;
        printf("[Debug] : %d\n", i);
    }
    return 0;
}

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
    int i;

    printf("stack is full, cannot add element\n");
    printf("current stack elements :\n");
    for(i = 0; i < top + 1; i++) {
        printf("%d %s\n", stack[i].id, stack[i].name);
    }
    exit(EXIT_FAILURE);
}
element stackEmpty()
{
    fprintf(stderr, "Stack is Empty\n");
    exit(EXIT_FAILURE);
}