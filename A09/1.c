/* 진행중
자료구조응용
09. 연결 리스트 : 기초, 스택, 큐
1. 다음과 같이 정렬되지 않는 점수(정수 데이터)를 입력하면서 정렬된 Linked List를 만들고 실행예와 같이 수행되는 프로그램을 작성하라.

 - 질문 -
+ delete함수 : 홀수 제거하는 구현과정에서 그림을 그리면서 했는데, 
    => main(41300,0x117663dc0) malloc: *** error for object 0x7fdc934059f0: pointer being freed was not allocated
    main(41300,0x117663dc0) malloc: *** set a breakpoint in malloc_error_break to debug
    zsh: abort      ./main 
    위와 같은 오류가 발생하여서 어떤게 원인인지 잘 모르겠습니다.
+ 출력 -> 노드주소, 링크값  변환명세를 모르겠습니다. (%p인지 %x인지, 아니면 다른 것인지..)
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
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
void insertWithOrder(listPointer *first, listPointer node);
    //Delete
void deleteItem(listPointer *first);
    //Display
void printList(listPointer first);
    //Free
void freeList(listPointer first);

//Main
int main(void)
{
    //first = createNode(10, NULL);
    FILE *fp = NULL;
    int num;

    //Get input.txt
    if(!(fp = fopen("input.txt", "r"))) {
        fprintf(stderr, "don't search the file name.\n");
        exit(EXIT_FAILURE);
    }
    
    while(!feof(fp)) {  /* feof : end of file */
        fscanf(fp, "%d", &num);
        insertWithOrder(&first, createNode(num, NULL));
    }
    printf("The ordered list contaons:\n");
    printList(first);
    putchar('\n');putchar('\n');

    //delete the odd value
    deleteItem(&first);

    printf("After deleting nodes with odd value\n\n");
    printf("The ordered list contaons:\n");
    printList(first);
    freeList(first);
    return 0;
}
//Function
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
            p->link = node;
            return;
        }
    }
}
    //Delete
void deleteItem(listPointer *first)
{
    listPointer p, q;
    p = q = *first;

    for(; (*first); (*first)->link) {
        //Left
        if((p->data) % 2 == 1) {
            *first = (*first)->link;
            free(p);
        }
        //Middle, Right
        if((q->data) % 2 == 1) {
            p->link = q->link;
            free(q);
        }
        p = q;
        q = q->link;
    }
}
    //Display
void printList(listPointer first)
{
    for(; first; first = first->link) {
        printf("(%p, %d, %p)", first, first->data, first->link);
    }
}
    //Free
void freeList(listPointer first)
{
    if(first) {
        freeList(first->link);
        free(first);
    }
}