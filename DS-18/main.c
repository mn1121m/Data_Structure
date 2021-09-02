/*DS 6-3-1
자료구조응용
18. Graph: Kruskal Algorithm, prim Algorithm

예시) Kruskal Algorithm ~30분  / Heap 사용

[참고] : heap은 인덱스 0을 쓰지않는다.  => n = 0 ( ex) top = -1 인것처럼 말이다) 
*/
//ㄴㅇㅁㄴㅇㅁ엉마ㅣㅗ아ㅓㄴ온ㅁ;ㅣ어ㅣㅁ너이너이마너이;ㅁㄴ
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 128

// Function 
void printHeap();
void push(int item, int *n);
int pop(int *n);

int minheap[MAX_HEAP_SIZE];
int n = 0;

int main(void)
{
    printf("*****************\n");
    push(1, &n);
    printHeap();
    printf("\n");

    push(56, &n);
    printHeap();
    printf("\n");

    push(-34, &n);
    printHeap();
    printf("\n");

    push(23, &n);
    printHeap();
    printf("\n");
    printf("*****************\n");
    printf("poped : %d\n", pop(&n));
    printHeap();
    printf("\n");

    printf("poped : %d\n", pop(&n));
    printHeap();
    printf("\n");

    printf("poped : %d\n", pop(&n));
    printHeap();
    printf("\n");

    printf("*****************\n");



    return 0;
}
void printHeap()
{
    int i;

    for(i = 1; i <= n; i++)
        printf("%2d ", minheap[i]);
}
void push(int item, int *n)
{
    int i;

    // Heap Full
    if(*n >= MAX_HEAP_SIZE -1) {
        fprintf(stderr, "Heap full!\n");
        exit(1);
    }

    i = ++(*n);
    while(item < minheap[i/2] && (i != 1)) {
        minheap[i] = minheap[i/2];
        i /= 2;
    }
    minheap[i] = item;

}
int pop(int *n)
{
    int item, temp;
    int parent = 1, child = 2;

    //Heap empty
    if (!(*n)) {
        fprintf(stderr, "Heap empty!\n");
        exit(1);
    }

    item = minheap[1];
    temp = minheap[(*n)--];

    while (*n >= child ) {
        if((*n > child) && (minheap[child] > minheap[child + 1])) {
            child ++;
        }
        if (minheap[child] < temp) {
            minheap[parent] = minheap[child];
            parent = child;
            child *= 2;
        }
    }
    minheap[parent] = temp;
    return item;
}