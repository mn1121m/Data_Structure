/*
data structure
18. Graph: Kruskal Algorithm, prim Algorithm
2. 다음과 같이 무방향그래프(undirected graph)에 대하여 prim Algorithm으로 최소비용 신장트리(MST)를 구축하는 과정에서,
정점 선택으로 인해 변화되는 가중치 값을 출력 하 고 최소 비용을 구하시오.
*/
#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX_VERTEX_SIZE 32

#define TRUE 1
#define FALSE 0

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Functions
int prim(int startVertex, int n);
int getCorrectVertex(int n);

// Global variable
int dist[MAX_VERTEX_SIZE];
int selected[MAX_VERTEX_SIZE] = {FALSE, };
int adjMat[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
int numOfVer = 0, numOfEdge; 

int main(void)
{
    FILE *fp;
    int i, j, u, v, weight, cost;

    if (!(fp = fopen("input.txt", "r"))) {
        fprintf(stderr, "Wrong file name!\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAX_VERTEX_SIZE; i ++)
        for (j = 0 ;j < MAX_VERTEX_SIZE; j ++)
            adjMat[i][j] = INF;

    fscanf(fp, "%d", &numOfEdge);
    for (i = 0 ;i < numOfEdge ;i ++) {
        fscanf(fp, "%d %d %d", &u, &v, &weight);
        if (numOfVer < u) numOfVer = u;
        if (numOfVer < v) numOfVer = v;
        adjMat[v][u] = adjMat[u][v] = weight;
    }
    numOfVer ++;

    for (i = 0 ;i < numOfVer ;i ++)
        adjMat[i][i] = 0;
    // mat complete

    
    cost = prim(0, numOfVer);

    printf("Minimum cost : %d\n", cost);
        

}
// Functions
int prim(int startVertex, int n)
{
    int i, j, v, cost = 0, edgeCnt = 0;

    for (i = 0; i < n; i ++) {
        selected[i] = FALSE;
        dist[i] = INF;
    }
    dist[startVertex] = 0;

    for (i = 0 ;i < n ;i ++) {
        v = getCorrectVertex(n);

        if (dist[v] == INF) break;
        edgeCnt ++;
        // Update dist
        selected[v] = TRUE;
        cost += dist[v];

        for (j = 0; j < n; j ++)
            if (adjMat[v][j] != INF && adjMat[v][j] < dist[j] && !selected[j])
                dist[j] = adjMat[v][j];
        
        printf("Selected vertex : %d \t distance : ", v);
        for (j = 0 ;j < n ;j ++)  {
            if (dist[j] == INF) printf("INF  ");
            else printf("%3d  ", dist[j]);
        }
        putchar('\n');

    }
    

    if (edgeCnt != n)
        return -1;
    return cost;
}
int getCorrectVertex(int n)
{
    int v, i;

    for (i = 0 ; i < n ;i ++) 
        if (!selected[i]) {
            v = i;
            break;
        }

    for (i = 0;i < n ;i ++)
        if (!selected[i] && dist[i] < dist[v]) 
                v = i;
    return v;
}
