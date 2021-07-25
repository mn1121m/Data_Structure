/* 진행중
자료구조응용
16. Adjacency List, Adjacency Multilists
1. 다음과 같이 파일 입력을 통해 무방향 그래프(undirected graph)나 
 방향 그래프(directed graph)를 인접리스트(adjacency-list)로 구성하는 프로그램을 작성하시오.

*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_VERTEX_SIZE 256

// Data structure - graph_Node
typedef struct _node* graphPointer;
typedef struct _node {
    int data;           // vertex
    graphPointer link;
} graphNode;

typedef struct _graphType {
    int n;
    graphPointer adj_list[MAX_VERTEX_SIZE];
} graphType;

// Functions
create()
insertVertex();
insertEdge();

int main(void)
{
    FILE *fp;
    printf("<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>\n");

    if((fp = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }

}