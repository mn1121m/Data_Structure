//review test(21_12_07)
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if( !(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory/\n");\
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

typedef struct listNode *listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} listNode;

// Function
// Creation
listPointer createNode(int data, listPointer link);
//Insertion
void inset2First(listPointer *first, listPointer node);
void insertWithOrder(listPointer *first, listPointer node);
//Delete
int deleteFirst(listPointer *first);
int deleteItem(listPointer *first, int data);
//Display
void printList(listPointer first);
//Free
void freeList(listPointer first);

//Global variable
listPointer first = NULL;

//Main
int main(void)
{
    //insert
    insertWithOrder(&first, createNode(1, NULL));
    insertWithOrder(&first, createNode(5, NULL));
    insertWithOrder(&first, createNode(2, NULL));
    insertWithOrder(&first, createNode(-3, NULL));
    insertWithOrder(&first, createNode(100, NULL));
    insertWithOrder(&first, createNode(77, NULL));
    printf("시작 : "); printList(first);
    printf("\n");
    //delete
    if(deleteItem(&first, 2)) {
        printf("Error\n");
    }else
        printf("Removed\n");
    printList(first);
    printf("\n");

    if(deleteItem(&first, -100)) {
        printf("Error\n");
    }else
        printf("Removed\n");
    printList(first);
    printf("\n");

    if(deleteItem(&first, 100)) {
        printf("Error\n");
    }else
        printf("Removed\n");
    printList(first);
    printf("\n");

    if(deleteItem(&first, 5)) {
        printf("Error\n");
    }else
        printf("Removed\n");
    printList(first);
    printf("\n");
    //free
    freeList(first);
}
// Function
// Creation
listPointer createNode(int data, listPointer link)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->link = link;

    return temp;
}
// Insert2First
void inset2First(listPointer *first, listPointer node)
{
    node->link = *first;
    *first = node;
}
// InsertWithOrder
void insertWithOrder(listPointer *first, listPointer node)
{
    listPointer p, q;

    p = q = *first;
    // Empty
    if(!p) {
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
        //Middle
        if(p->data <= node->data && node->data < q->data) {
            p->link = node;
            node->link = q;
            return;
        }
        p = q;
        q = q->link;
        //Right
        if(q == NULL) {
            p->link = node;
            return;
        }
    }
}
//Delete
int deleteFirst(listPointer *first)
{
    listPointer temp = *first;

    if(*first) {
        *first = (*first)->link;
        free(temp);
        return 0;
    }
    return -1;
}
int deleteItem(listPointer *first, int data)
{
    listPointer p, q;
    p = q = *first;
    // Empty
    if( p == NULL) return -1;
    //Left
    if(p->data  == data) {
        *first = (*first)->link;
        free(p);
        return 0;
    }
    while(TRUE) {
        //Middle
        if(q->data == data) {
            p->link = q->link;
            free(q);
            return 0;
        }
        p = q;
        q = q->link;
        // No data
        if(q == NULL)
            return -1;
    }

}
//Display
void printList(listPointer first)
{
    for(;first; first = first->link)
        printf("%d ", first->data);
}
//Free
void freeList(listPointer first)
{
    if(first) {
        freeList(first->link);
        free(first);
    }
}