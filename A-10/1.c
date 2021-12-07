/*
자료구조응용
10. 연결 리스트 : 다항식

1. 다음과 같이 정렬되지 않는 점수(정수 데이터)를 입력에 대하여
 Circularly Linked List를 만들고 실행 예와 같이 수행되는 프로그램을 작성하라.

[*] - DeleteNode
*/


#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory\n"); \
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

// Data structure
typedef struct listNode* listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} listNode;
listPointer last = NULL;

// Functions
listPointer createNode(int data, listPointer link);
void insertEndNode(listPointer *last, listPointer node);
void deleteNode(listPointer *last);
void printCircularList(listPointer last);

// Main
int main(void)
{
    FILE *fp = NULL;
    int num;

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Don't search the file name\n");
        exit(EXIT_FAILURE);
    }
    while(!feof(fp)) {
        fscanf(fp, "%d", &num);
        insertEndNode(&last, createNode(num, NULL));
    }

    printf("The Circularly Linked List contains:\n");
    printCircularList(last);

    //delete the odd value
    deleteNode(&last);
    
    printf("After Circularly Linked List contains:\n");
    printCircularList(last);
    return 0;
}
// Functions
// Create CircularLinkedList
listPointer createNode(int data, listPointer link)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->link = link;

    return temp;
}
// Insert node end of last
void insertEndNode(listPointer *last, listPointer node)
{   
    // Empty
    if(!(*last)) {
       *last = node;
       node->link = node;
    }
    
    else {
        node->link = (*last)->link;
        (*last)->link = node;
        (*last) = node; 
    }

}
// Deleting node with odd value
void deleteNode(listPointer *last)
{
        
}

// Display contens of the circular linked list
void printCircularList(listPointer last)
{
    listPointer p;
    p = last;

    if(last == NULL) {
        printf("The list is empty\n");
        return;
    }
    else {
        //printf("Nodes of the circular linked list: \n");
        do {
            p = p->link;
            printf("(%p, %2d, %p)\n", p, p->data, p->link);
        } while( p != last);
        printf("\n");
    }
}