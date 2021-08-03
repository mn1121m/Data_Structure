/*
자료구조응용 17. Graph: DFS, BFS
1. 다음과 같이 무방향그래프(undirected graph) 데이터를 입력받아 인접리스트를 만들고 dfs 결과를 출력하는 프로그램을 작성하라.

13분이후 
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
void bfs(int v);

void enqueue(int item);
int dequeue();

// Global variable
graphPointer *adjLists;
int *visited;
int numOfVer, numOfEdges;

int queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

int main(void)
{
    FILE *fp;
    int i, j, u, v;

    if (!(fp = fopen("input.txt", "r"))) {
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

    printf("<<<<<<<<< Breadth First Search >>>>>>>>>>>\n");
    for (i = 0; i < numOfVer ;i ++) {
        printf("dfs(%d) : ", i);
        bfs(i);
        front = rear; // Queue init
        for (j = 0 ; j < numOfVer ;j ++)
            visited[j] = FALSE;
        putchar('\n');
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
void bfs(int v)
{
    int u;
    graphPointer p;

    printf("%d ", v);
    visited[v] = TRUE;
    enqueue(v);
    while ((u = dequeue()) != -1) {
        for (p = adjLists[u]; p ; p = p->link) {
            if (!visited[p->data]) {
                printf("%d ", p->data);
                enqueue(p->data);
                visited[p->data] = TRUE;
            }
        }
    }
}
void enqueue(int item)
{
    if ((rear + 1)%MAX_QUEUE_SIZE == front) {
        fprintf(stderr, "Queue full!\n");
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1)%MAX_QUEUE_SIZE;
    queue[rear] = item;
}
int dequeue()
{
    if (front == rear) 
        return -1;
    front = (front + 1)%MAX_QUEUE_SIZE;
    return queue[front];
}

/* result
<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>
adjList[0] :    2  1  
adjList[1] :    4  3  0  
adjList[2] :    6  5  0  
adjList[3] :    7  1  
adjList[4] :    7  1  
adjList[5] :    7  2  
adjList[6] :    7  2  
adjList[7] :    6  5  4  3  

<<<<<<<<< Breadth First Search >>>>>>>>>>>
dfs(0) : 0 2 1 6 5 4 3 7 
dfs(1) : 1 4 3 0 7 2 6 5 
dfs(2) : 2 6 5 0 7 1 4 3 
dfs(3) : 3 7 1 6 5 4 0 2 
dfs(4) : 4 7 1 6 5 3 0 2 
dfs(5) : 5 7 2 6 4 3 0 1 
dfs(6) : 6 7 2 5 4 3 0 1 
dfs(7) : 7 6 5 4 3 2 1 0
*/