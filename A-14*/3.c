/*
data structure
14. Trees : 명제식 이진트리, heap

3. 다음 입력파일의 데이터를 사용하여 최대히프(Max Heap)에 대한 실습을 수행한다. 
    input.txt : 10 40 30 5 12 6 15 9 60

[구현 복습]
- void heap_print() 구현 -> ()
- pop() -> if (heap[] == NULL), break;
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_ELEMENTS 200    /*  maximum heap size  + 1 */
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

#define TRUE 1
#define FALSE 0

//  Data structure
typedef struct {
    int key;
    /* other fields */
} element;

//  Global variable
element heap[MAX_ELEMENTS];
int n = 0;  // 데이터 갯수

//  Functions
void push(element item, int *n);
element pop(int *n);
void heap_print();

//  Main
int main(void)
{
    FILE *fp;
    element temp;
    int i;
    printf("********* insertion into a max heap *********\n");

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name/\n");
        exit(EXIT_FAILURE);
    }
    //  insert
    while((fscanf(fp, "%d", &(temp.key))) != EOF) {
        push(temp, &n);
        heap_print();
    }
    fclose(fp);
    
    //  delete
    printf("********* deletion from max heap *********\n");
    while(TRUE) {
        //if (heap[] == NULL), break;
        pop(&n);
        heap_print();
    }
    printf("\n");
}
//  Functions
void push(element item, int *n)
{
    /*  insert item into a max heap of current size *n */
    int i;
    if(HEAP_FULL(*n)) {
        fprintf(stderr, "The heap is full. \n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while((i != 1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];    // insert item into a leftChild;
        i /= 2;
    }
    heap[i] = item;
}
element pop(int *n)
{
    /*  delete element with the hightest key from the heap   */
    int parent, child;
    element item, temp;

    if(HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty. \n");
        exit(EXIT_FAILURE);
    }
    /*  save value of the element with the highest key  */
    item = heap[1];
    /*  use last element in heap to adjust heap */
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while(child <= *n) {
        /* find the larger child of the current parent */
        if( (child < *n) && (heap[child].key < heap[child + 1].key) ){
            child++;
        }
        if(temp.key >= heap[child].key) break;
        /* move to the next lower level */
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
void heap_print()
{
    int i;
    for(i = 1; i <= n; i++) {   //  i = ++(*n); 먼저 ++ 했으므로 1부터 해줘야 한다.
        printf("%d ", heap[i].key);
    }
    printf("\n");
}