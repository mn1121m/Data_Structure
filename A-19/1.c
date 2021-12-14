/*
data structure
19. Graph: Dijkstra, AOV(Topological sort)
1. Dijkstra's algorithm을 사용하여 아래 그래프에서 시작 정점(0)에서 
다른 모든 정점으로 가는 최단 경로와 가중치 값(weight value)을 시오.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 32
#define INF 1000

#define TRUE 1
#define FALSE 0

void dijkstra();
int choose();
void printPath(int src, int dest);

int weights[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
int distance[MAX_VERTEX_SIZE];
int found[MAX_VERTEX_SIZE];
int path[MAX_VERTEX_SIZE];
int numOfVertex = 0, numOfEdge;

int main(void)
{
    FILE *fp;
    int i, j, u, v, cost;

    // Get weights
    if (!(fp = fopen("input.txt", "r"))) {
        fprintf(stderr, "Wrong file name!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d", &numOfEdge);
    for (i = 0 ;i < numOfEdge;i ++) {
        fscanf(fp, "%d %d %d", &u, &v, &cost);
        weights[u][v] = weights[v][u] = cost;
        if (u > numOfVertex) numOfVertex = u;
        if (v > numOfVertex) numOfVertex = v;
    }
    numOfVertex ++;
    for (i = 0 ;i < numOfVertex;i ++)
        for (j = 0 ;j < numOfVertex ;j ++)
            if (!weights[i][j] && i != j)
                weights[i][j] = INF;
    fclose(fp);

    // Find shortest path
    dijkstra();

    // print Path
    for (i = 1; i < numOfVertex ;i ++) {
        printf("distance[%d-%d]=%2d \t: ", 0, i, distance[i]);
        printPath(0, i);
        putchar('\n');
    }
}
void dijkstra()
{
    int i, u, v;

    for (i = 0 ;i < numOfVertex;i ++) {
        found[i] = FALSE;
        distance[i] = weights[0][i];
        path[i] = 0;
    }

    found[0] = TRUE;
    path[0] = -1;

    for (i = 0 ;i < numOfVertex - 1; i ++) {
        if ((u = choose()) == -1) {
            printf("No choosed node!\n");
            exit(1);
        }
        found[u] = TRUE;
        for (v = 0 ; v < numOfVertex; v ++) {
            if (!found[v]
                && distance[u] + weights[u][v] < distance[v]) {
                    distance[v] = distance[u] + weights[u][v];
                    path[v] = u;
                }
        }
    }

}
int choose()
{
    int i, minValue = INF, minIdx = -1;

    for (i = 0 ;i < numOfVertex;i ++)
        if (!found[i] && distance[i] < minValue) {
            minIdx = i;
            minValue = distance[i];
        }

    return minIdx;
}
void printPath(int src, int dest)
{
    // Terminal condition
    if (src == dest)
        return;
    printPath(src, path[dest]);
    printf("<%d->%d> ", path[dest], dest);
}
