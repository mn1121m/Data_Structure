/* remind */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
}listNode;

listPointer first = NULL;
// Functions
listPointer createNode(int data, listPointer link);

// Main
int main(void)
{

    return 0;
}

// Functions
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
void insertNode();