/*
Data structure 
09. 연결 리스트 : 기초, 스택, 큐

3. [Linked Stacks] 다음과 같은 스택을 생성하고 실행하는 프로그램을 작성하라. 
 이를 위해, push, pop, stackEmpty 함수를 구현하여야 한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
    fprintf(stderr, "Insufficient memory.\n"); \
    exit(EXIT_FAILURE); \
}
#define MAX_STACKS 3

// Data structure
typedef struct {
    int id;     //학번
    int grage;  //성적
} element;
typedef struct stack* stackPointer;
typedef struct stack{
    element data;
    stackPointer link;
} Node;
stackPointer top[MAX_STACKS];

// Functions
void push(int i, element item);
element pop(int i);
element stackEmpty();

// Main
int main()
{

    return 0;
}
// Functions
void push(int i, element item)
{
    /* add item to the ith stack */
    stackPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
    top[i] = temp;
}
element pop(int i)
{
    /* remove top element from the ith stack */
    stackPointer temp = top[i];
    element item;
    if( !temp )
        return stackEmpty();
    item = temp->data;
    top[i] = temp->link;
    free(temp);
    return item;
}
element stackEmpty()
{
    element temp = {-1, "[ERROR] : STACK EMPTY!"};
    puts("Stack is empty, cannot delete element");
    exit(EXIT_FAILURE);
    return temp;
}