/*
자료구조응용 17. Graph: DFS, BFS
1. 다음과 같이 무방향그래프(undirected graph) 데이터를 입력받아 인접리스트를 만들고 dfs 결과를 출력하는 프로그램을 작성하라.

13분이후 
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

// Data structure
typedef struct _node {
    int data;                   // vertex
    struct _node* link;         // link
} node;
typedef struct _node* graphPointer;


// Functions
void insertEdge(int u, int v);
void printGraph(graphPointer *adjLists, int numOfVer);
void bfs(int v);


// Global variable
graphPointer *adjLists;
int *visited;

int numOfVer, numOfEdges;

int main(void)
{
    FILE *fp;
    int i, j, u, v;

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }

    // Get meta data
    fscanf(fp,"%d %d", &numOfVer, &numOfEdges);

    // Get array, u->v 경로
    MALLOC(adjLists, sizeof(*adjLists)*numOfVer);
    MALLOC(visited, sizeof(*visited)*numOfVer);
    for(i = 0; i < numOfVer; i++)
        adjLists[i] = NULL;
        visited[i] = FALSE;
    for(i = 0; i < numOfEdges; i++) {
        fscanf(fp, "%d %d", &u, &v);
        insertEdge(u, v);
        insertEdge(v, u);
    }
    fclose(fp);

    // Printing
    printf("<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>\n");
    printGraph(adjLists, numOfVer);
    putchar('\n');

    printf("<<<<<<<<<<< Breath First Search >>>>>>>>>>\n");
    for(i = 0; i < numOfVer; i++) {
        printf("bfs(%d) : ", i);
        bfs(i);
        for(j = 0; j < numOfVer; j++)   //다 돌고 난후에 다시 FALSE 해줘야한다.
            visited[j] = FALSE;
        putchar('\n');
    }
    return 0;
}

// Functions
void insertEdge(int u, int v)
{
    graphPointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = v;
    temp->link = NULL;

    temp->link = adjLists[u];
    adjLists[u] = temp;
}
void printGraph(graphPointer *adjLists, int numOfVer)
{
    int i;
    graphPointer p;

    for(i = 0; i < numOfVer; i++) {
        printf("adjLists[%d] : \t", i);
        for(p = adjLists[i]; p; p = p->link)
            printf("%d  ", p->data);
        putchar('\n');
    }
}
void bfs(int v)
{
    graphPointer p;

    printf("%5d", v);
    visited[v] = TRUE;
    enqueue(v);
    while(!queue empty) {

    }
}
/* result

*/