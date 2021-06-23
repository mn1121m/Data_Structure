/*
2. [ 정적할당배열을 이용한 선형큐(linear queue) ] 다음과 같은 선형 큐를 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라. 
이를 위해, addq, deleteq, queueFull, queueEmpty qprint(queue의 내용을 출력) 함수를 구현하여야 한다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 5

typedef struct {
    int id;                     //unique id
    char name[MAX_NAME_SIZE];   //last name
} element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

void addq(element item)
{
    if(rear == MAX_QUEUE_SIZE -1)
        queueFULL();
    queue[++rear] = item;
}
element deleteq()
{
    if(front == rear)
        return queueEmpty();
    return queue[++front];
}
void queueFULL()
{
    fprintf("Queue is full, cannot add element!\n");
    exit(EXIT_FAILURE);
}
element queueEmpty()
{
    fprintf(stderr, "Queue is Empty\n");
    exit(EXIT_FAILURE);
}

int main(void)
{


    return 0;
}