// Remind(ok)()
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define TRUE 1
#define FALSE 0

//Data Structure
typedef struct _node {
    int data;           //vertex
    struct _node* link;
} node;
typedef struct _node *graphPointer;

//Funtions
void insertEdge(int u, int v);
void printGraph(graphPointer *adjList, int numOfVertex);
void dfs(int v);

//Global variable
graphPointer *adjLists;
int *visited;
int numOfVertex, numOfEdges;

int main(void)
{
    FILE *fp;
    int i, j, u, v;

    if(!(fp = fopen("input.txt","r")) ) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    
    //Get meta data
    fscanf(fp, "%d %d", &numOfVertex, &numOfEdges);
    
    // Get array, u->v 경로
    MALLOC(adjLists, sizeof(*adjLists)* numOfVertex);
    MALLOC(visited, sizeof(*visited)* numOfVertex);

    for(i = 0; i < numOfVertex; i ++) {
        adjLists[i] = NULL;
        visited[i] = FALSE;
    }
    for(i = 0; i < numOfEdges; i ++) {
        fscanf(fp, "%d %d", &u, &v);
        insertEdge(u, v);
        insertEdge(v, u);
    }
    fclose(fp);

    //Printing
    printf("<<<<<<<<<<< Adjacency List >>>>>>>>>>>>\n");
    printGraph(adjLists, numOfVertex);
    putchar('\n');

    printf("<<<<<<<<<< Depth First Search >>>>>>>>>\n");
    for(i = 0; i < numOfVertex; i ++) {
        printf("dfs(%d) : " , i);
        dfs(i);
        for(j = 0; j< numOfVertex; j ++) {
            visited[j] = FALSE;
        }
        putchar('\n');
    }
    return 0;
}
//Funtions
//Funtions
void insertEdge(int u, int v)
{
    graphPointer temp;
    
    MALLOC(temp, sizeof(*temp));
    temp->data = v;
    temp->link = NULL;

    temp->link = adjLists[u];
    adjLists[u] = temp;
}
void printGraph(graphPointer *adjList, int numOfVertex)
{
    int i;
    graphPointer p;

    for(i = 0; i < numOfVertex; i++) {
        printf("adjList[%d] : \t", i);
        for(p = adjLists[i]; p; p = p->link)
            printf("%d ", p->data);
        putchar('\n');
    }
}
void dfs(int v)
{
    graphPointer p;

    visited[v] = TRUE;
    printf("%5d", v);
    for(p = adjLists[v]; p; p = p->link) {
        if(!visited[p->data])
            dfs(p->data);
    }
}
/* result
<<<<<<<<<<< Adjacency List >>>>>>>>>>>>
adjList[0] :    2 1 
adjList[1] :    4 3 0 
adjList[2] :    6 5 0 
adjList[3] :    7 1 
adjList[4] :    7 1 
adjList[5] :    7 2 
adjList[6] :    7 2 
adjList[7] :    6 5 4 3 

<<<<<<<<<< Depth First Search >>>>>>>>>
dfs(0) :     0    2    6    7    5    4    1    3
dfs(1) :     1    4    7    6    2    5    0    3
dfs(2) :     2    6    7    5    4    1    3    0
dfs(3) :     3    7    6    2    5    0    1    4
dfs(4) :     4    7    6    2    5    0    1    3
dfs(5) :     5    7    6    2    0    1    4    3
dfs(6) :     6    7    5    2    0    1    4    3
dfs(7) :     7    6    2    5    0    1    4    3
*/