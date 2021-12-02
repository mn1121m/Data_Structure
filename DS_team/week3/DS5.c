#include<stdio.h>
#include<stdlib.h>

#define TRUE    1
#define FALSE   0

typedef int MyElement;
typedef struct listNode
{
    MyElement data;
    struct listNode* prev;
    struct listNode* next;

}ListNode;

typedef struct listStack
{
    ListNode* stackTop;
    int size;
}ListStack;

typedef ListStack Stack;

//초기 스택 생성 함수
void InitStack(Stack* s);
//스택에 data를 집어넣고 스택의 stackTop을 증가시키는 함수
int PushStack(Stack* s, int data);
//스택에 있는 data를 빼면서 스택의 stackTop을 감소시키는 함수
int PopStack(Stack* s);
//스택 출력
void PrintStack(Stack* s);
//스택이 비었을 때
int StackEmpty(Stack* s);

int main(void)
{
    Stack stack;
    InitStack(&stack);
    if(StackEmpty(&stack))
        printf("예외 : 현재 스택이 비어 있습니다.\n");
    
    stack.size = 0;

    for (int i = 0; i <= 9; i++)
    {
        PushStack(&stack, i);
        printf("push (%2d)\n", i);
        printf("현재 스택(size :%2d) :",++stack.size);
        PrintStack(&stack);
    }

    for (int i = 9; i >=0; i--)
    {
        PopStack(&stack);
        printf("pop (%2d)\n", i);
        if (StackEmpty(&stack))
        {
            printf("예외 : 현재 스택이 비어 있습니다.\n\n");
            exit(0);
        }
        printf("현재 스택(size :%2d) :",--(stack.size));
        PrintStack(&stack);
    }
  
}

void InitStack(Stack* s)
{
    s->stackTop = NULL;    
    printf("스택을 초기화 한 후\n");
}

int PushStack(Stack* s, int data)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));    
    newNode->data = data;           
    newNode->next = s->stackTop;   

    s->stackTop = newNode;        
}

int PopStack(Stack* s)
{
    
    int data;
    ListNode* temp;
    
    data = s->stackTop->data;
    temp = s->stackTop;

    s->stackTop = s->stackTop->next;
    free(temp);

    return data;
    

}

void PrintStack(Stack* s)
{
    ListNode* temp = s->stackTop;
   
    while (temp != StackEmpty(s))
    {
        printf("%2d,", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int StackEmpty(Stack* s)
{
    int empty = FALSE;

    if (s->stackTop == NULL)
        empty = TRUE;
    else
        empty = FALSE;

    return empty;
}