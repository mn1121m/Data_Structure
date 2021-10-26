/* remind 
file 2.c

[*]
    - queuefull() 전체적으로 + if, else 문
    - 
*/
#include <stdio.h>
#include <stdlib.h> /* exit(EXIT_FAILURE) */
#include <string.h>  /* strcmp, strtok, strlen */

#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 100
#define MAX_BUF_SIZE 100

#define TRUE 1
#define FALSE 0

// Data structure
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
} element;

// Global variable
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

// Functions
void addq(element item);
void queueFull();
element deleteq();
element queueEmpty();
void qprint();

// Main
int main(void)
{
    element temp;
    char buf[MAX_BUF_SIZE];
    char *ptr, *delimeter = " ";

    printf("<< linear queue operations where MAX_QUEUE_SIZE is 5 >> \n");
    printf("add 1 Jung\n");
    printf("delete\n");

    printf("******************************************************\n");
    while(TRUE) {
        gets(buf);
        ptr = strtok(buf, delimeter);

        // add
        if(!strcmp("add", buf)) {
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%d", &(temp.id));  // 1
            ptr = strtok(NULL, delimeter);
            sscanf(ptr, "%s", temp.name);   // Jung
            addq(temp);
        }
        // delete
        else if(!strcmp("delete", ptr)) {
            deleteq();
        }
        else if(!strcmp("sprint", ptr))
            qprint();
        // else
        else {
            printf("Wrong command! try again!\n");
        }
    }
    return 0;
}
// Functions
void addq(element item)
{
    if(rear == MAX_QUEUE_SIZE -1) {
        queueFull();
    }
    queue[++rear] = item;
}
void queueFull()
{
    int i;
    element temp;

    if(front == -1 && rear == MAX_QUEUE_SIZE -1) {
        fprintf(stderr, "Queue is full, cannot add element!\n");
        printf("current queue element : \n");

        for(i = 0; i < MAX_QUEUE_SIZE; i++) {
            temp = deleteq();
            printf("%d %s\n", temp.id, temp.name);
        }
        exit(EXIT_FAILURE);
    } else {    /* 중요 */
        puts("array shifting...");
        for(i = front+1; i<= rear; i++) {
            queue[i - front - 1] = queue[i];
        }
        rear = -1 + (rear - front);
        front = -1;
    }
}
element deleteq()
{
    if(front == rear) {
        return queueEmpty();
    }
    return queue[++front];
}
element queueEmpty()
{
    element temp = {-1, "[ERROR] : QUEUE EMPTY!"};

    fprintf(stderr, "Queue is empty, cannot delete element!\n");
    exit(EXIT_FAILURE);

    return temp;
}
void qprint() 
{
    int i;

    for(i = front + 1; i <= rear; i++) {
        printf("[DEBUG] : i == %d\n", i);
        printf("%d %s\n", queue[i].id, queue[i].name);
    }
    putchar('\n');
}