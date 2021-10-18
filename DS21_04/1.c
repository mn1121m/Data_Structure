/* 2018117610 문준용
자료구조응용 스택과 큐(일부)
1. [정적할당배열의 스택] 다음과 같은 스택을 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라. 
이를 위해, push, pop, stackEmpty, stackFull 함수를 구현하여야 한다. (10점)

[구현조건]
1 사용자입력으로부터 데이터 추출을 위해 gets, strtok, strcmp, sscanf, strlen 등을 사용 2 push, pop 함수는 교재 코드를 수정 없이 그대로 사용할 것
3 stackFull은 코드를 수정하되, pop()을 사용하여 현재 스택요소들을 출력해 준 후 exit(EXIT_FAILURE)을 호출하도록 구현할 것
4 stackEmpty는 새로 정의하되, 반환형은 임의의 에러키를 가지는 element형이어야 함 ※ EXIT_FAILURE를 사용하기 위해 stdlib.h를 인클루드해야 함
5 잘못된 커맨드를 입력하면 에러메시지를 출력 후 다시 사용자 입력을 받도록 함
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5
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
    int i = 0;
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
        
        ptr = strtok(buf, delimeter); 
        if(strcmp(ptr, "push") == 0) {    // !strcmp(ptr, "push")
            // 1 kim
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%d", &(temp.id));  // 1 -> id
            // kim
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%s", temp.name);   
            push(temp);
        } else if(strcmp(ptr, "pop") == 0) {
            pop();
        } else if(strcmp(ptr, "sprint") == 0) {
            sprint(); 
        } else {
            puts("Wrong command! try again!");
        }
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

    puts("stack is full, cannot add element\ncurrent stack elements : ");
    for(i = 0; i < MAX_STACK_SIZE; i++) {     //*중요*
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
    puts("stack is empty, cannot delete element");
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
