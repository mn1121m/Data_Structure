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

// Data structure
typedef struct _node {
    int data;                   // vertex
    struct _node* link;         // link
} node;
typedef struct _node* graphPointer;


// Functions
void insertEdge(int u, int v);
void printGraph(graphPointer *adjLists, int numOfVer);
void dfs(int v);


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

    printf("<<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
    for(i = 0; i < numOfVer; i++) {
        printf("dfs(%d) : ", i);
        dfs(i);
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
void dfs(int v)
{
    /* depth first search of a graph beginning at v */
    graphPointer p;
    visited[v] = TRUE;
    printf("%5d", v);

    for(p = adjLists[v]; p; p = p->link) {
        if(!visited[p->data])
            dfs(p->data);
    }
}
/* result
<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>
adjLists[0] :   2  1  
adjLists[1] :   4  3  0  
adjLists[2] :   6  5  0  
adjLists[3] :   7  1  
adjLists[4] :   7  1  
adjLists[5] :   7  2  
adjLists[6] :   7  2  
adjLists[7] :   6  5  4  3  

<<<<<<<<<<< Depth First Search >>>>>>>>>>
dfs(0) :     0    2    6    7    5    4    1    3
dfs(1) :     1    4    7    6    2    5    0    3
dfs(2) :     2    6    7    5    4    1    3    0
dfs(3) :     3    7    6    2    5    0    1    4
dfs(4) :     4    7    6    2    5    0    1    3
dfs(5) :     5    7    6    2    0    1    4    3
dfs(6) :     6    7    5    2    0    1    4    3
dfs(7) :     7    6    2    5    0    1    4    3
*/