/*
data structure
19. Graph: Dijkstra, AOV(Topological sort)
2. 아래의 AOV network에서 task의 작업 순서를 나열하시오.
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) {\
fprintf(stderr, "Insufficient memory!\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_VERTEX_SIZE 32

// DS
struct _node {
    int vertex;
    struct _node *link;
};
typedef struct _node *nodePointer;
typedef struct {
    int count;
    nodePointer link;
} header;

// Functions
nodePointer createNode(int vertex, nodePointer link);
void topologySort();

// Global variables
header graph[MAX_VERTEX_SIZE];
int numOfVertex;

int main(void)
{
    FILE *fp;
    int i, u, v;
    nodePointer temp;

    // INIT
    for (i = 0 ;i < MAX_VERTEX_SIZE;i ++) {
        graph[i].count = 0;
        graph[i].link = NULL;
    }

    // Get graph
    if (!(fp = fopen("input2.txt", "r"))) {
        fprintf(stderr, "Wrong file name!\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%d %d", &u, &v) != EOF) {
        temp = createNode(v, graph[u].link);
        graph[u].link = temp;
        graph[v].count ++;
        if (numOfVertex < u) numOfVertex = u;
        if (numOfVertex < v) numOfVertex = v;
    }
    numOfVertex ++;
    fclose(fp);

    topologySort();

}
nodePointer createNode(int vertex, nodePointer link)
{
    nodePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->vertex = vertex;
    temp->link = link;

    return temp;
}
void topologySort()
{
    int i, poped, top = -1;
    nodePointer ptr;

    for (i = 0 ;i < numOfVertex;i ++)
        if (!graph[i].count) {
            graph[i].count = top;
            top = i;
        }

    for (i = 0 ;i < numOfVertex;i ++) {
        poped = top;
        if (poped == -1) {
            fprintf(stderr, "Cycle!\n");
            exit(EXIT_FAILURE);
        }
        top = graph[top].count;

        if (i < numOfVertex - 1)
            printf("%d -> ", poped);
        else 
            printf("%d", poped);

        for (ptr = graph[poped].link; ptr; ptr = ptr->link) {
            graph[ptr->vertex].count--;
            if (!graph[ptr->vertex].count) {
                graph[ptr->vertex].count = top;
                top = ptr->vertex;
            }
        }
    }
}
