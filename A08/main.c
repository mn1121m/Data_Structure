#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

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
    first = createNode(10, createNode(20, createNode(30, NULL)));

    insert2First(&first, createNode(5, NULL));
    printList(first);
    putchar('\n');

    deleteFirst(&first);
    printList(first);
    putchar('\n');

    deleteFirst(&first);
    printList(first);
    putchar('\n');
    
    deleteFirst(&first);
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
void insertWithOrder(listPointer *first, listPointer node);
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
int deleteItem(listPointer *first, int data);
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