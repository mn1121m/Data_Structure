/* pass
data structure
06. 스택과 큐 
3. [ 환형큐(circular queue) ] 2번 문제의 프로그램을 환형큐 프로그램으로 수정하라.
    add, delete, qprint 명령어를 구현하시오.

- 중요 -
element *queue; => MALLOC (동적할당)을 하라~

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 256
#define MAX_BUF_SIZE 256

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory!\n"); \
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

//Data structure
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
} element;

//Global variable
element *queue;

// int capacity = 2; => #define MAX_QUEUE_SIZE 3 하므로 없어도 된다.
int rear = 0;
int front = 0;

//Function
void addq(element item);
element deleteq();
void qprint();
void queueFULL();
element queueEmpty();

int main(void)
{
    element temp;
    char buf[MAX_BUF_SIZE];
    char *ptr, *delimeter = " ";

    //*
    MALLOC(queue, sizeof(*queue) * MAX_QUEUE_SIZE); 
    puts("<< Circular queue operations where MAX_QUEUE_SIZE is 3\nadd 1 Jung\ndelete\n");
    puts("******************************************************************");

    while(TRUE) {
        fgets(buf, sizeof(buf), stdin);
        buf[strlen(buf) - 1] = '\0';
        ptr = strtok(buf, delimeter);
        
        if(!strcmp(ptr, "add")) {
            //Parsing
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
void addq(element item) //* if문
{
    if(front == (rear + 1) % MAX_QUEUE_SIZE) 
        queueFULL();
    else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = item;
    }
}
element deleteq()
{
    if(front == rear)
       return queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}
void qprint()   //*
{
    int i;
    
    for(i = (front + 1) % MAX_QUEUE_SIZE; i != (rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d, %s\n", queue[i].id, queue[i].name);
        printf("[DEBUG] : i = %d\n", i);
    }
}
void queueFULL()
{
    puts("queue is full, not added");
}
element queueEmpty()
{
    element temp = {-1, "[ERROR] : QUEUE EMPTY!"};

    fprintf(stderr, "queue is empty\n");
    exit(EXIT_FAILURE);

    return temp;
}
/*
<< Circular queue operations where MAX_QUEUE_SIZE is 3
add 1 Jung
delete

******************************************************************
add 1 kim
add 2 park
qprint
1,      kim
2,      park

add 3 lww
queue is full, not added
delete
delete
qprint
add 6 korea
sprint
Wrong command! try again!
qprint
6,      korea
delete
delete
queue is empty
*/