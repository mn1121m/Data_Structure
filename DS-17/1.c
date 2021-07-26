/*
자료구조응용 17. Graph: DFS, BFS
1. 다음과 같이 무방향그래프(undirected graph) 데이터를 입력받아 인접리스트를 만들고 dfs 결과를 출력하는 프로그램을 작성하라.


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
typedef struct _node {
    int vertex;
    struct _node* link;
} node;
typedef struct _node* graphPointer;

typedef struct _graph {
    int n;
    node* adjList[MAX_VERTEX_SIZE];
} graph;

// Global variable
int visited[MAX_VERTICES_SIZE];

// Functions
void dfs(int v);

int main(void)
{
    FILE *fp = NULL;
    int numVertex, numEdge;

    if((fp = fopen("input.txt","r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return 0;
}

// Functions
void dfs(int v)
{
    /* depth first search of a graph beginning at v */
    graphPointer w;
    visited[v] = TRUE;
    printf("%5d", v);

    for(w = graph[v]; w; w = w->link) {
        if(!visited[w->vertex])
            def(w->vertex);
    }
}