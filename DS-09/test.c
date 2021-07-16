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
//Delete
int deleteFirst(listPointer *first);
int deleteItem(listPointer *first, int data);
//Display
void printList(listPointer first);
// Free
void freeList(listPointer first);

//main
int main(void)
{
    // printf("[DEBUG] : %d\n", 1);
    //first = createNode(10, createNode(20, createNode(30, createNode(100, NULL))));
    insertWithOrder(&first, createNode(5, NULL));
    insertWithOrder(&first, createNode(1, NULL));
    insertWithOrder(&first, createNode(3, NULL));
    insertWithOrder(&first, createNode(55, NULL));
    insertWithOrder(&first, createNode(100, NULL));

    //deleteFirst(&first);
    //1
    if(deleteItem(&first, 101)) {
        printf("Error!\n");
    } else {
        printf("Removed!\n");
    }
    printf("1. result : ");printList(first);
    putchar('\n');
    //2
    if(deleteItem(&first, 3)) {
        printf("Error!\n");
    } else {
        printf("Removed!\n");
    }
    printf("2. result : ");printList(first);
    putchar('\n');
    //3
    if(deleteItem(&first, 100)) {
        printf("Error!\n");
    } else {
        printf("Removed!\n");
    }
    printf("3. result : ");printList(first);
    putchar('\n');
    //4
    if(deleteItem(&first, 50)) {
        printf("Error!\n");
    } else {
        printf("Removed!\n");
    }
    printf("4. result : ");printList(first);
    putchar('\n');

    freeList(first);
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
        // Middle
        if(p->data <= node->data && node->data < q->data) {
            node->link = q;
            p->link = node;         //*중요* Middle - 순서 상관없음.
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
    listPointer temp;
    temp = *first;

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
    //Left
    if(p->data == data) {
        *first = (*first)->link;
        free(p);
        return 0;
    }
    while(TRUE) {
        //Middle, Right
        if(q->data == data) {
            p->link = q->link;
            free(q);
            return 0;
        }
        p = q;
        q = q->link;
        //No data
        if(!q)
            return -1;
    }
}
//Display
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