/*
3. [ 환형큐(circular queue) ] 1번 문제의 프로그램을 환형큐 프로그램으로 수정하라.
    add, delete, qprint 명령어를 구현하시오.

- Q -
+ "zsh: segmentation fault  ./main" 에러가 뜨는데 
addq() 에서 오류가 나는 것 같습니다.
element *queue; <-- 전역변수를 * (포인터)를 이용하여 문제를 푸는건데, 어떻게 해결할지 모르겠습니다.
addq, deleteq함수를 수정없이 사용하라 해서 더더욱 모르겠습니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 256
#define MAX_BUF_SIZE 256

#define TRUE 1
#define FALSE 0

//Data structure
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
} element;

//Global variable
element *queue;
int capacity = 2;
int rear = 0;
int front = 0;

//Function
void addq(element *item);
element deleteq();
void qprint();
void queueFULL();
element queueEmpty();

int main(void)
{
    element temp;
    char buf[MAX_BUF_SIZE];
    char *ptr, *delimeter = " ";

    puts("<< Circular queue operations where MAX_QUEUE_SIZE is 3\nadd 1 Jung\ndelete\n");
    puts("******************************************************************");

    while(TRUE) {
        fgets(buf, sizeof(buf), stdin);
        buf[strlen(buf) - 1] = '\0';
        ptr = strtok(buf, delimeter);
        
        if(!strcmp(ptr, "add")) {
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%d", &(temp.id));
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%s", temp.name);
            addq(temp);
        } else if(!strcmp(ptr, "delete")) {
            deleteq();

        } else if(!strcmp(ptr, "qprint")) {
            qprint();
        } else {
            puts("Wrong command! try again!");
        }
    }
    return 0;
}
void addq(element item)
{
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if(front == rear) 
        queueFULL();
    queue[rear] = item;
}
element deleteq()
{
    if(front == rear)
       return queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}
void qprint()
{
    int i;
    for(i = front + 1; i <= rear; i++) {
        printf("%d,\t%s\n", queue[i].id, queue[i].name);
        printf("[DEBUG] : i = %d", i);
    }
}
void queueFULL()
{
    if(front == 0 && rear == 0) {
        puts("queue is full, not added");
    }
}
element queueEmpty()
{
    element temp = {-1, "[ERROR] : QUEUE EMPTY!"};

    fprintf(stderr, "queue is empty\n");
    exit(EXIT_FAILURE);

    return temp;
}