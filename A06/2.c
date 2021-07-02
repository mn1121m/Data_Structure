/*
2. [ 정적할당배열을 이용한 선형큐(linear queue) ] 다음과 같은 선형 큐를 생성하고 실행 예와 같이 수행되는 프로그램을 작성하라. 
이를 위해, addq, deleteq, queueFull, queueEmpty qprint(queue의 내용을 출력) 함수를 구현하여야 한다.


- 질문 - 

+ 2번문제 [자료형과 함수의 정의] 에서는 #define MAX_QUEUE_SIZE 5 인데, 
    밑에 출력예시에서는 맨 처음 줄에 << linear queue ~ MAX_QUEUE_SIZE is 3>> 크기가 3이라고 되어 있습니다.
    MAX_QUEUE_SIZE 3이 맞는건가요 ?
+ 구현조건 - 3번에서 "그 이외에 대해서는 큐의 항목들을 이동" 에 대한 구현을 그림을 그려봐도 잘 이해가 되질 않습니다..

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
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
    int i = 0;
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
            printf("[DEBUG] : i == %d\n", i);
            temp = deleteq();
            printf("%d %s\n", temp.id, temp.name);
        }
        exit(EXIT_FAILURE);
    } else { // *중요* 그 이외에 대해서는 큐의 항목들을 이동 
        puts("array shifting...");
        //한칸씩 앞으로 이동 
        
        //한칸씩 앞으로 이동 후 
        front--;
        rear--;
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

    fprintf(stderr, "Queue is empty, cannot delete element.\n");
    exit(EXIT_FAILURE);

    return temp;
}
void qprint()
{
    int i;

    printf("[DEBUG] : front == %d\n", front);
    printf("[DEBUG] : rear == %d\n", rear);
    for(i = front + 1; i <= rear; i++) {
        printf("%d %s\n", queue[i].id, queue[i].name);
    }
    putchar('\n');
}