/* link.c review  DS 4 12 30M ~ */

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
    fprintf(stderr, "Insufficient memory.\n"); \
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

listPointer first = NULL;

// Function
// Creation
listPointer createNode(int data, listPointer link);
// insert
void inset2First(listPointer *first, listPointer node);
void insertWithOrder(listPointer *first, listPointer node);

// delete
int deleteFirst(listPointer *first);
int deleteItem(listPointer *first, int data);

// print
void printList(listPointer first);
// free
void freeList(listPointer first);

int main(void)
{
    insertWithOrder(&first, createNode(5, NULL));
    insertWithOrder(&first, createNode(10, NULL));
    insertWithOrder(&first, createNode(2, NULL));
    insertWithOrder(&first, createNode(2, NULL));
    insertWithOrder(&first, createNode(1, NULL));
    insertWithOrder(&first, createNode(-4, NULL));
    insertWithOrder(&first, createNode(2, NULL));
    insertWithOrder(&first, createNode(3232, NULL));

    printf("시작 : ");
    printList(first); putchar('\n');

    deleteItem(&first, -4);
    printf("수정 : ");
    printList(first); putchar('\n');

     deleteItem(&first, 2);
    printf("수정 : ");
    printList(first); putchar('\n');

     deleteItem(&first, 10);
    printf("수정 : ");
    printList(first); putchar('\n');

     deleteItem(&first, 2);
    printf("수정 : ");
    printList(first); putchar('\n');

    freeList(first);
    return 0;
}
// Creation
listPointer createNode(int data, listPointer link)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->data = data;
    temp->link = link;

    return temp;
}
// Insert
void inset2First(listPointer *first, listPointer node)
{
    node->link = *first;
    *first = node;
}
void insertWithOrder(listPointer *first, listPointer node)
{
    listPointer p, q;

    p = q = *first;
    // First
    if(!p) {    // p == NULL
        *first = node;
        return;
    }
    // Left
    if(node->data < p->data) {
        node->link = p;
        *first = node;
        return;
    }
    while(TRUE) {
        // Middle
        if(p->data <= node->data && node->data < q->data) {
            p->link = node;
            node->link = q;
            return;
        }
        p = q;
        q = q->link;
        // Right
        if(!q) { // q == NULL
            p->link = node;
            return;
        }
    }
}
// delete
int deleteFirst(listPointer *first)
{
    listPointer temp = *first;
    if(*first) {
        *first = (*first)->link;
        free(temp);
        return 0;
    }
    return  -1;
}
int deleteItem(listPointer *first, int data)
{
    listPointer p, q;
    p = q = *first;

    // Empty
    if(p == NULL) return -1;

    // Left
    if(p->data == data) {
        *first = (*first)->link;
        free(p);
        return 0;
    }
    while(TRUE) {
        // Middle, Right
        if(q->data == data) {
            p->link = q->link;
            free(q);
            return 0;
        }
        p = q;
        q = q->link;
        // no data
        if(q == NULL) return -1;
    }
}

// print
void printList(listPointer first)
{
    for(;first; first = first->link) {
        printf("%d ", first->data);
    }
}
// free
void freeList(listPointer first)
{
    if(first) {
        freeList(first->link);
        free(first);
    }
}