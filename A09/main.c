#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

typedef struct listNode *listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} listNode;

// Functions
// Creation
listPointer createNode(int data, listPointer link);
// Insertion
void insert2First(listPointer *first, listPointer node);
void insertWithOrder(listPointer *first, listPointer node);
// Delete
int deleteFirst(listPointer *first);
int deleteItem(listPointer *first, int data);
// Display
void printList(listPointer first);
// Free
void freeList(listPointer first);

// Global Variable
listPointer first = NULL;

//main
int main(void)
{
    // first = createNode(10, createNode(20, createNode(30, NULL)));

    insertWithOrder(&first, createNode(5, NULL));
    insertWithOrder(&first, createNode(1, NULL));
    insertWithOrder(&first, createNode(3, NULL));
    insertWithOrder(&first, createNode(5, NULL));
    insertWithOrder(&first, createNode(-4, NULL));
    insertWithOrder(&first, createNode(3453, NULL));
    printList(first);
    putchar('\n');

    // 실패한 경우 ( deleteItem(&first, 3) == 0(성공했을때 : return 0) ) 
    if(deleteItem(&first, 3)) { 
        printf("Error!\n");
    }
    printf("Removed!\n");
    printList(first);
    putchar('\n');

    if(deleteItem(&first, -4)) { 
        printf("Error!\n");
    }
    printf("Removed!\n");
    printList(first);
    putchar('\n');

    if(deleteItem(&first, 3453)) { 
        printf("Error!\n");
    }
    printf("Removed!\n");
    printList(first);
    putchar('\n');

    if(deleteItem(&first, 234)) { 
        printf("Error!\n");
    }
    printf("Removed!\n");
    printList(first);
    putchar('\n');

    freeList(first);
}
// Functions
// Creation
listPointer createNode(int data, listPointer link)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->link = link;
    return temp;
}
// Insertion
void insert2First(listPointer *first, listPointer node)
{
    node->link = *first;
    *first = node;
}
void insertWithOrder(listPointer *first, listPointer node)
{
    listPointer p, q;

    p = q = *first;
    // Empty (비어있는 경우)
    if(!p) {
        *first = node;
        return;
    }
    // Left (맨 앞)
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
        // Right (맨 끝)
        if(q == NULL) {
            p->link = node;
            return;
        }
    }
}
// Delete
int deleteFirst(listPointer *first)
{
    listPointer temp = *first;

    if (*first) {
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
    // Empty (비어있는 경우)
    if(p == NULL) return -1;
    // Left (맨앞)
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
        // No data (찾는 값이 없는 경우)
        if(q == NULL) return -1;
    }
}
// Display
void printList(listPointer first)
{
    for (; first; first = first->link)
        printf("%d ", first->data);
}
// Free
void freeList(listPointer first)
{
    if (first) {
        freeList(first->link);
        free(first);
    }
}