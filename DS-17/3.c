/*
자료구조응용 17. Graph: DFS, BFS

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_QUEUE_SIZE 32

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// DS
struct _node {
    int data;
    struct _node *link;
};
typedef struct _node *graphPointer;

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
    int i, j, u, v, count = 0;

    if (!(fp = fopen("input3-2.txt", "r"))) {
        fprintf(stderr, "Wrong file name!\n");
        exit(EXIT_FAILURE);
    }

    // Get meta data
    fscanf(fp, "%d %d", &numOfVer, &numOfEdges);
    // Get array
    MALLOC(adjLists, sizeof(*adjLists)*numOfVer);
    MALLOC(visited, sizeof(*visited)*numOfVer);

    for (i = 0; i < numOfVer; i ++) {
        adjLists[i] = NULL;
        visited[i] = FALSE;
    }

    for (i = 0; i < numOfEdges; i ++) {
        fscanf(fp, "%d %d", &u, &v);
        insertEdge(u, v);
        insertEdge(v, u);
    }
    fclose(fp);
    
    // Printing
    printf("<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>\n");
    printGraph(adjLists, numOfVer);
    putchar('\n');

    printf("<<<<<<<<< Connected component >>>>>>>>>>>\n");
    for (i = 0; i < numOfVer; i ++) {
        if (!visited[i]) {
            printf("connected component %d : ", ++count);
            dfs(i);
            putchar('\n');
        }
    }

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

    for (i = 0 ;i < numOfVer; i ++) {
        printf("adjList[%d] : \t", i);
        for (p = adjLists[i]; p ; p = p->link)
            printf("%d  ", p->data);
        putchar('\n');
    }

}
void dfs(int v)
{
    graphPointer p;

    printf("%d ", v);
    visited[v] = TRUE;

    for (p = adjLists[v] ;p ; p = p->link)
        if (!visited[p->data])
            dfs(p->data);
}
/* result
<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>
adjList[0] :    2  1  
adjList[1] :    3  0  
adjList[2] :    3  0  
adjList[3] :    2  1  
adjList[4] :    5  
adjList[5] :    6  4  
adjList[6] :    7  5  
adjList[7] :    6  

<<<<<<<<< Connected component >>>>>>>>>>>
connected component 1 : 0 2 3 1 
connected component 2 : 4 5 6 7
*/