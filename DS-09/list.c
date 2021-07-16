#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

typedef struct listNode *listPointer; // 포인터
typedef struct listNode {
    int data;
    listPointer link;
} listNode;

listPointer first = NULL, second = NULL;

void create2(listPointer *header, listPointer *header2)
{
    listPointer first, second;

    MALLOC(first, sizeof(*first));
    MALLOC(second, sizeof(*second));
    second->link = NULL;
    second->data = 20;
    first->data = 10;
    first->link = second;

    *header = first;
    *header2 = second;
}

int main(void)
{
    create2(&first, &second);
    printf("%d->%d\n", first->data, second->data);

    free(second);
    free(first);
}