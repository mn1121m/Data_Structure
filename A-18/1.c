/*
자료구조응용
18. Graph: Kruskal Algorithm, prim Algorithm
1. 다음과 같이 무방향그래프(undirected graph)에 대하여 Kruskal's Algorithm으로 최소비 용 신장트리(MST)를 구축해 나가는 과정을 출력 하시오. 
탐색되는 edge를 순서대로 출력하 고, 최소 비용을 구하시오.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 128

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

typedef struct _heap {
    int u, v;
    int weight;
} heap_t;

// Functions
void push(heap_t item, int *n);
heap_t pop(int *n);

int kruskal(int n);
int find(int *ary, int u);

// Global variable
heap_t heap[MAX_HEAP_SIZE];
int n = 0;
int numOfEdge, numOfVertex = 0;

int main(void)
{
    FILE *fp;
    int i, cost;
    heap_t temp;

    if (!(fp = fopen("input.txt", "r"))) {
        fprintf(stderr, "Wrong file name!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", &numOfEdge);
    for (i = 0 ;i < numOfEdge ;i ++) {
        fscanf(fp, "%d %d %d", &temp.u, &temp.v, &temp.weight);
        if (numOfVertex < temp.u) numOfVertex = temp.u;
        if (numOfVertex < temp.v) numOfVertex = temp.v;
        push(temp, &n);
    }
    numOfVertex ++;
    cost = kruskal(numOfVertex);
    printf("\nMinimum cost : %d\n", cost);

    fclose(fp);
}
// Functions
void push(heap_t item, int *n)
{
    int i;

    if (*n >= MAX_HEAP_SIZE - 1) {
        fprintf(stderr, "Heap full!\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((item.weight < heap[i/2].weight) && (i != 1)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}
heap_t pop(int *n)
{
    heap_t item, temp;
    int parent, child;

    if (*n == 0) {
        fprintf(stderr, "Heap empty!\n");
        exit(EXIT_FAILURE);
    }
    item = heap[1];
    temp = heap[(*n)--];

    parent = 1;
    child = 2;
    while (child <= *n) {
        if ((child < *n) && (heap[child].weight > heap[child + 1].weight))
            child ++;
        if (temp.weight < heap[child].weight) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
int kruskal(int vertex)
{
    int edgeCnt = 0, cost = 0, i, uset, vset;
    heap_t temp;
    int *parent;

    MALLOC(parent, sizeof(*parent)*numOfVertex);
    for (i = 0 ;i < numOfVertex;i ++) parent[i] = -1;

    while (edgeCnt < vertex - 1) {
        temp = pop(&n);
        uset = find(parent, temp.u);
        vset = find(parent, temp.v);
        if (uset != vset) {
            edgeCnt++;
            printf("(%d, %d) %d\n", temp.u, temp.v, temp.weight);
            cost += temp.weight;
            parent[uset] = vset;
        }
    }

    free(parent);
    if (edgeCnt != vertex - 1)
        return -1;
    return cost;
}
int find(int *ary, int u)
{
    for (; ary[u] != -1; u = ary[u]);
    return u;
}
