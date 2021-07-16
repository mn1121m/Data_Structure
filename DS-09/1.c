/* Code review 0712 1:03~ Debugging 참고
자료구조응용  
09. 연결 리스트 : 기초, 스택, 큐
1. 다음과 같이 정렬되지 않는 점수(정수 데이터)를 입력하면서 정렬된 Linked List를 만들고 실행예와 같이 수행되는 프로그램을 작성하라.

* 중요 *
+ zsh: abort      ./main      => 치명적인 오류 (건드리면 안되는 곳을 건드릴때 발생한다.)
+ 출력 -> 노드주소, 링크값  변환명세 => 주소 : %p, 값: %d

- 참고 -
[DEBUG]
    printf("p == %d\nq == %d\n",p->data, q->data);
    printf("1\n");
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
    printf("The ordered list contains:\n");
    printList(first);
    putchar('\n');putchar('\n');

    //delete the odd value *중요*
    deleteItem(&first);

    printf("After deleting nodes with odd value\n\n");
    printf("The ordered list contains:\n");
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

    //Empty list
    if(!p) return;

    //Start of list
    while(p->data % 2) {
        if(q) q = q->link;
        free(p);
        p = q;
        *first = p;
        if(!p) return;
    }
    while(q) {  //*q == NULL인지 아닌지
        //Middle
        while(q->data % 2) {
            p->link = q->link;
            free(q);
            q = p->link;
        }
        // End of list
        if(!q) return;
        p = q;
        q = q->link;
    }
}
    //Display
void printList(listPointer first)
{
    for(; first; first = first->link) {
        printf("(%p, %2d, %p)\n", first, first->data, first->link);
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