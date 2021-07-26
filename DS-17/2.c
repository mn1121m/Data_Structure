/*
자료구조응용 17. Graph: DFS, BFS
2. 위 1번 문제에 대해 dfs 대신 bfs의 결과를 출력하는 프로그램을 작성하라.
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
#define MAX_VERTICES_SIZE 128

// Data structure
typedef struct _graph {
    int n;
    node* adjList[MAX_VERTEX_SIZE];
} graph;

typedef struct _queue* queuePointer;
typedef struct _queue {
    int vertex;
    queuePointer link;
} queue;

// Global variable
queuePointer front, rear;
int visited[MAX_VERTICES_SIZE];

// Functions
void addq();
int deleteq();
void bfs(int v);

int main(void)
{

}
void bfs(int v)
{
    queuePointer w;
    front = rear = NULL;
    printf("%5d", v);
    visited[v] = TRUE;
    addq(v);
    while(front) {
        v = deleteq();
        for(w = graph[v]; w; w = w->link)
            if(!visited[w->vertex]) {
                printf("%5d", w->vertex);
                addq(w->vertex);
                visited[w->vertex] = TRUE;
            }
    }
}