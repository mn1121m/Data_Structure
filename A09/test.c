//main.c 복습 (Linked list concept)

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if( !(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

//Data structure
typedef struct listNode *listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} listNode;

//Global variable
listPointer first = NULL;

//Function
//Creation
listPointer createNode(int data, listPointer link);
//Insertion
void insert2First(listPointer *first, listPointer node);
void insertWithOrder(listPointer *first, listPointer node);
//Print
void printList(listPointer first);
// Free
void freeList(listPointer first);

//main
int main(void)
{
    printf("[DEBUG] : %d\n", 1);
    //first = createNode(10, createNode(20, createNode(30, createNode(100, NULL))));
    insertWithOrder(&first, createNode(5, NULL));
    insertWithOrder(&first, createNode(1, NULL));
    insertWithOrder(&first, createNode(3, NULL));
    insertWithOrder(&first, createNode(100, NULL));
    printf("[DEBUG] : %d\n", 2);
    printList(first);
    printf("[DEBUG] : %d\n", 3);
    freeList(first);
    printf("[DEBUG] : %d\n", 4);
    return 0;
}
//Creation
listPointer createNode(int data, listPointer link)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->data = data;
    temp->link = link;
    return temp;
}
//Insertion
void insert2First(listPointer *first, listPointer node)
{
    node->link = *first;
    *first = node;
}
void insertWithOrder(listPointer *first, listPointer node)
{
    listPointer p, q;

    p = q = *first;
    //Empty
    if(!p) {
        *first = node;
        return;
    }
    //Left
    if(node->data < p->data) {
        node->link = p;
        *first = node;
        return;
    }
    while(TRUE) {
        //Middle
        if(p->data <= node->data && node->data < q->data) {
            p->link = node;
            node->link = q;
            return;
        }
        p = q;
        q = q->link;
        //Right
        if(!q) {
            q->link = node;
            return;
        }
    }
}
//Print
void printList(listPointer first)
{
    int i;

    for(; first; first = first->link) {
        printf("%d ", first->data);
    }
}
// Free
void freeList(listPointer first)
{
    if (first) {
        freeList(first->link);
        free(first);
    }
}