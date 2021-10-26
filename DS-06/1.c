/* 중요!!
자료구조응용 06. 스택과 큐 
1. [정적할당배열의 스택] 다음과 같은 스택을 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라.
    이를 위해, push, pop, stackEmpty, stackFull, sprint(스택의 내용을 출력) 함수 를 구현하여야 한다.

- 참고 - 
+   print -> put : MAX_STACK_SIZE 정해져 있을 경우 
+   sscanf(const char *buf, const char *fomat, ...)     : 버퍼에서 포맷을 지정하여 읽어오는 함수. buf: 소스 문자열, format: 포맷 문자열

+   warning: this program uses gets(), which is unsafe.     : 어쩔 수 없이 뜬다.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 8
#define MAX_NAME_SIZE 256
#define MAX_BUF_SIZE 256

#define TRUE 1
#define FALSE 0

// Data structure
typedef struct {
    int id;                     //unique id
    char name[MAX_NAME_SIZE];  //last name
} element;

//Global variable
element stack[MAX_STACK_SIZE];
int top = -1;

// Function
void push(element item);
void stackFULL();
element pop();
element stackEmpty();
void sprint();

int main(void)
{
    //gets_s, strtok_s, strcpm, sscanf_s, strlen
    //int i = 0;    => [DEBUG]
    char buf[MAX_BUF_SIZE];
    char *ptr, *delimeter = " ";
    element temp;

    printf("<< stack operations where MAX_STACK_SIZE is 5 >>\n");
    printf("push 1 Jung\n");
    printf("pop\n\n");

    printf("**************************************************\n");
    while(TRUE) {
        // Get input
        gets(buf);
        // fgets(buf, sizeof(buf), stdin); //enter포함하고 있음. '\n'
        // buf[strlen(buf) - 1] = '\0';    //enter포함하고 있는 '\n' 자리에 '\0'을 넣어버리면 됩니다.

        ptr = strtok(buf, delimeter); //buf에 delimeter기준으로 자른다.
        if(strcmp(ptr, "push") == 0) {    // !strcmp(ptr, "push")
            // 1 kim
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%d", &(temp.id));  // 1 -> id
            // kim
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%s", temp.name);   //name자체가 char buf이기 때문이다.
            push(temp);
        } else if(strcmp(ptr, "pop") == 0) {
            pop();
        } else if(strcmp(ptr, "sprint") == 0) {
            sprint(); 
        } else {
            puts("Wrong command! try again!");
        }
        //printf("[DEBUG] : top == %d\n", top);
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
void stackFULL()
{
    int i;
    element temp;

    //printf("[DEBUG] : top == %d\n", top);
    puts("stack is full, cannot add element\ncurrent stack elements : ");
    for(i = 0; i < MAX_STACK_SIZE; i++) {     //*중요*
        //printf("[DEBUG] : %d\n", i);
        temp = pop();
        printf("%d %s\n", temp.id, temp.name);
    }
    exit(EXIT_FAILURE);
}
element pop()
{
    if(top == -1)
        return stackEmpty();
    return stack[top--];
}
element stackEmpty()
{
    element temp = {-1, "[ERROR] : STACK EMPTY!"};
    puts("Stack is empty, cannot delete element");
    exit(EXIT_FAILURE);
    return temp;
}
void sprint()
{
    int i;

    for(i = top; i > -1; i--) {
        printf("%d %s\n", stack[i].id, stack[i].name);
    }
}
/*
<< stack operations where MAX_STACK_SIZE is 5 >>
push 1 Jung
pop

**************************************************
warning: this program uses gets(), which is unsafe.
push 1 Jung 
push 2 hong
pop
push 3 Kim
push 4 song
pop
push 5 Lee
push 6 Min
push 7 Oh
push 8 Seo
stack is full, cannot add element
current stack elements : 
7 Oh
6 Min
5 Lee
3 Kim
1 Jung

================================================================================================================

<< stack operations where MAX_STACK_SIZE is 5 >>
push 1 Jung
pop

**************************************************
warning: this program uses gets(), which is unsafe.
push 1 kim
push 2 park
push 3 moon
sprint
3 moon
2 park
1 kim
opo
Wrong command! try again!
pop
pop
pop
pop
Stack is empty, cannot delete element
*/