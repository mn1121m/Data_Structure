#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6

typedef int element;

element queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(element item)
{
    if(rear == MAX_QUEUE_SIZE - 1) {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
    queue[++rear] = item;
}

element dequeue()
{
    if(front == rear) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue[++front];
}
void printQueue()
{
    int i;
    
    printf("---------------------\n");
    for(i = front + 1; i < rear + 1; i ++) {
        printf("[%d] == %d\n", i, queue[i]);
    }
}
int main(void) 
{
    printQueue();
    enqueue(1);
    printQueue();
    enqueue(2);
    printQueue();
    enqueue(3);
    printQueue();

    dequeue();
    printQueue();
    dequeue();
    printQueue();

    // enqueue(5);
    // printQueue();
    // enqueue(6);
    // printQueue();

}