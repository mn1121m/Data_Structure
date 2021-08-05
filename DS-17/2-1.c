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

#define MAX_QUEUE_SIZE 32

// Data Structure
typedef struct _node {
    int data;
    struct _node* link;
} node;
typedef struct _node* graphPointer;

// Global variable
graphPointer *adjLists;
int *visited;
int numOfVertex, numOfEdges;

int queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

// Funtions
void insertEdge(int u, int v);
void printGraph(graphPointer *adjLists, int numofVertex);
void bfs(int v);

void enqueue(int item);
int dequeue();

int main(void)
{
    FILE *fp;
    int i, j, u, v;

    if(!(fp = fopen("input.txt","r"))) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    // Get meta data
    fscanf(fp, "%d %d", &numOfVertex, &numOfEdges);

    // Get arrary -> malloc of adjLists, visited 
    MALLOC(adjLists, sizeof(*adjLists) * numOfVertex);
    MALLOC(visited, sizeof(*visited) * numOfVertex);

    for(i = 0; i < numOfVertex; i ++) {
        adjLists[i] = NULL;
        visited[i] = FALSE;
    }
    // [**]  i < numOfEdges
    for(i = 0; i < numOfEdges; i ++) {
        fscanf(fp, "%d %d", &u, &v);
        insertEdge(u, v);
        insertEdge(v, u);
    }
    fclose(fp);

    // Printing
    printf("<<<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>\n");
    printGraph(adjLists, numOfVertex);
    putchar('\n');

    printf("<<<<<<<<<<<<<<< Breath First Search >>>>>>>>>>>>\n");
    for(i = 0; i < numOfVertex; i++) {
        printf("bfs<%d> : ", i);
        bfs(i);
        front = rear;   // [***] queue init
        for(j = 0; j < numOfVertex; j ++)   //[***] j로 초기화
            visited[j] = FALSE;
        putchar('\n');
    }
    return 0;
}
// Funtions
void insertEdge(int u, int v)
{
    graphPointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = v;
    temp->link = NULL;

    temp->link = adjLists[u];
    adjLists[u] = temp;

}
void printGraph(graphPointer *adjLists, int numofVertex)
{
    int i;
    graphPointer p;

    for(i = 0; i < numOfVertex; i ++) {
        printf("graph[%d] : \t", i);
        for(p = adjLists[i]; p; p = p->link) 
            printf("%d ", p->data);
        putchar('\n');
    }
}
void bfs(int v)
{
    int u;
    graphPointer p;

    printf("%5d ", v);
    visited[v] = TRUE;
    enqueue(v);
    while((u = dequeue()) != -1) {
        for(p = adjLists[u]; p; p = p->link) {
            if(!visited[p->data]) {
                printf("%5d ", p->data);
                enqueue(p->data);
                visited[p->data] = TRUE;
            }
        }
    }
}

void enqueue(int item)
{
    if( (rear + 1) % MAX_QUEUE_SIZE == front) {
        fprintf(stderr, "Queue is full.\n");
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}
int dequeue()
{
    if(front == rear) {
        return -1;  // Queue is Empty
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}
/* result
<<<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>
graph[0] :      2 1 
graph[1] :      4 3 0 
graph[2] :      6 5 0 
graph[3] :      7 1 
graph[4] :      7 1 
graph[5] :      7 2 
graph[6] :      7 2 
graph[7] :      6 5 4 3 

<<<<<<<<<<<<<<< Breath First Search >>>>>>>>>>>>
bfs<0> :     0     2     1     6     5     4     3     7 
bfs<1> :     1     4     3     0     7     2     6     5 
bfs<2> :     2     6     5     0     7     1     4     3 
bfs<3> :     3     7     1     6     5     4     0     2 
bfs<4> :     4     7     1     6     5     3     0     2 
bfs<5> :     5     7     2     6     4     3     0     1 
bfs<6> :     6     7     2     5     4     3     0     1 
bfs<7> :     7     6     5     4     3     2     1     0 
*/