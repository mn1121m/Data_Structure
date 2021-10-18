/* 2018117610 문준용

2. [ 정적할당배열을 이용한 선형큐(linear queue) ] 
다음과 같은 선형 큐를 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라. 
이를 위해, addq, deleteq, queueFull, queueEmpty 함수를 구현하여야 한다. (10점)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 256
#define MAX_BUF_SIZE 256

#define TRUE 1
#define FALSE 0

// Data structure
typedef struct {
    int id;                     //unique id
    char name[MAX_NAME_SIZE];   //last name
} element;

// Global variable
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

// Function
void addq(element item);
void queueFULL();
element deleteq();
element queueEmpty();
void qprint();

int main(void)
{
    char buf[MAX_BUF_SIZE];
    char *ptr, *delimeter = " ";
    element temp;

    puts("<< linear queue operations where MAX_QUEUE_SIZE is 3 >>\nadd 1 Jung\ndelete\nprintq");
    puts("**************************************************");
    while(TRUE) {
        //push  *gets_s, strtok_s, strcmp, sscanf_s, strlen*
        gets(buf);
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
    if(rear == MAX_QUEUE_SIZE -1)
        queueFULL();
    queue[++rear] = item;
}
void queueFULL()
{
    int i;
    element temp;

    if(front == -1 && rear == MAX_QUEUE_SIZE - 1) {
        fprintf(stderr, "Queue is full, cannot add element\n");
        puts("current queue element : ");

        for(i = 0; i < MAX_QUEUE_SIZE; i++) {
            temp = deleteq();
            printf("%d %s\n", temp.id, temp.name);
        }
        exit(EXIT_FAILURE);
    } else { 
        puts("array shifting...");
        //전체적으로 앞으로 한칸씩 이동
        for(i = front +1; i <= rear; i++) { 
            queue[i - front - 1] = queue[i];
        }
        rear = -1 + (rear - front); // number of element = (rear - front)
        front = -1;
    }
    
}
element deleteq()
{
    if(front == rear)
        return queueEmpty();
    return queue[++front];
}
element queueEmpty()
{
    element temp = {-1, "[ERROR] : QUEUE EMPTY!"};

    fprintf(stderr, "queue is empty, cannot delete element.\n");
    exit(EXIT_FAILURE);

    return temp;
}
void qprint()
{
    int i;

    for(i = front + 1; i <= rear; i++) {
        printf("%d %s\n", queue[i].id, queue[i].name);
    }
    putchar('\n');
}