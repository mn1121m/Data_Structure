/* 질문
3. 다음 입력파일의 데이터를 사용하여 최대히프(Max Heap)에 대한 실습을 수행한다. input.txt : 10 40 30 5 12 6 15 9 60

- 출력 : (4) 실행 예 <--> input.txt 데이터 값이 일단 다릅니다.
- 출력에 관해서 어떻게 구현하는지 설명부탁드리겠습니다.

*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_ELEMENTS 256    /*  maximum heap size   */
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
    while(!feof(fp)) {
        fscanf(fp, "%d", &(temp.key));
        push(temp, &n);
        heap_print();
    }
    fclose(fp);
    
    //  delete
    printf("********* deletion from max heap *********\n");
    while(TRUE) {
        //if heap[] == NULL, break;
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
    /* delete element with the hightest key from the key */
    int parent, child;
    element item, temp;

    if(HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty. \n");
        exit(EXIT_FAILURE);
    }
    /* save value of the element with the highest key */
    item = heap[1];
    /* use last element in heap to adjust heap */
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
    for(i = 0; i < n; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");
}