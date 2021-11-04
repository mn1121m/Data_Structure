/*
자료구조 응용
2018117610_moonjunyong
2021-11-01
실습 7 - 문제 1 => ok
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s)   \
if(!(p = malloc(s))) { \
    fprintf(stderr, "Insufficient memory\n"); \
    exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

#define ROW 3
#define COL 10

// Data structure
typedef struct listNode* listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} listNode;
listPointer first = NULL;

// Function
listPointer createNode(int data, listPointer link);
void insertNode(listPointer *first, listPointer node);
void deleteNode(listPointer *first, int data);
void printList(listPointer first);
void freeList(listPointer first);

int main(void)
{
    int i, j, num, numDel;

    // Input
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            scanf("%d", &num);
            insertNode(&first, createNode(num, NULL));
        }
    }
    // Input -> Print
    printList(first);

    // Delete -> Print
    scanf("%d", &numDel);
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            deleteNode(&first, numDel);
        }
    }
    printList(first);

    // Free
    freeList(first);
    return 0;
}
// Function
// Create
listPointer createNode(int data, listPointer link)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->link = link;

    return temp;
}
// Insert
void insertNode(listPointer *first, listPointer node)
{   
    listPointer p, q;

    p = q = *first;
    // Empty (비어있는 경우)
    if(!p) {
        *first = node;
        return;
    }
    while(TRUE) {
        p = q;
        q = q->link;
        // Right (맨 끝)
        if(q == NULL) {
            p->link = node;
            return;
        }
    }
}
// *Delete*
void deleteNode(listPointer *first, int data)
{
    listPointer p, q;
    p = q = *first;
    // Empty (비어있는 경우)
    if(p == NULL) return;
    // Left (맨앞)
    if(p->data <= data) {
        *first = (*first)->link;
        free(p);
        return;
    }
    while(TRUE) {
        // Middle, Right
        if(q->data <= data) {
            p->link = q->link;
            free(q);
            return;
        }
        p = q;
        q = q->link;
        // No data (찾는 값이 없는 경우)
        if(q == NULL) return;
    }
}
// Print
void printList(listPointer first)
{
    int i = 0;

    while(TRUE) {
        printf("%2d", first->data);
        i++;
        if(!(i%10)) {
            putchar('\n');
        }else{    
            if(first->link == NULL) return;
            putchar(' ');
        }
        first = first->link;
        if(!first) return;
    }
}

// Free
void freeList(listPointer first)
{
    if(first) {
        freeList(first->link);
        free(first);
    }
}
/* result
50 80 30 20 19 90 30 55 77 30
99 45 55 89 91 10 20 66 38 59
22 55 88 22 66 29 50 95 78 83
50 80 30 20 19 90 30 55 77 30 
99 45 55 89 91 10 20 66 38 59 
22 55 88 22 66 29 50 95 78 83 
50
80 90 55 77 99 55 89 91 66 59 
55 88 66 95 78 83 %   
*/