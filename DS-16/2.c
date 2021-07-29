/*
2. 다음과 같이 사용자로부터 정보를 입력받아서 무방향그래프(undirected graph)를
 Adjacency multilist로 구성하여
 각 정점에 부속되는 간선을 출력하는 프로그램을 작성하라.

*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Data structure
typedef struct edge* tEdgePointer;
typedef struct edge {
    int vertex1;
    int vertex2;
    tEdgePointer link1;
    tEdgePointer link2;
} tEdge;

// Funtions
// create the edge node
tEdgePointer createEdge(int ver1, int ver2, tEdgePointer link1, tEdgePointer link2);
void addEdge(int ver1, int ver2);
void printMultilist(int numVertex, int choice);
// if choice is TRUE : input data order
// else : leading vertex of header node

// Global variable
tEdgePointer* adjMulList;       // MALLOC() 구현
int numOfVer, numOfEdges;
char graphType;

int main(void)
{
    FILE *fp;
    int i, u, v;

    if((fp = fopen("input2.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    // Input data of numOfVer, numOfEdges
    fscanf(fp, "%d %d", &numOfVer, &numOfEdges);
    printf("%d %d\n", numOfVer, numOfEdges);

    // MALLOC
    MALLOC(adjMulList, sizeof(*adjMulList) * numOfVer);
    for(i = 0; i < numOfVer; i++)
        adjMulList[i] = NULL;
    for(i = 0; i < numOfEdges; i++) {
        fscanf(fp, "%d %d", &u, &v);
        addEdge(u, v);
    }
    fclose(fp);
    printf("<<<<<<<<<<<<<< egdes incident to each vertex >>>>>>>>>>>>>>>>\n");
    // Printing
    printf("Input data ordered : \n");
    printMultilist(numOfVer, 1);
    putchar('\n');
    printf("Leading vertex of header node : \n");
    printMultilist(numOfVer, 0);

    return 0;
}
// Funtions
// create the edge node
tEdgePointer createEdge(int ver1, int ver2, tEdgePointer link1, tEdgePointer link2)
{
    tEdgePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->vertex1 = ver1;
    temp->vertex2 = ver2;
    temp->link1 = link1;
    temp->link2 = link2;

    return temp;
}
void addEdge(int ver1, int ver2)
{
    tEdgePointer edge = createEdge(ver1, ver2, NULL, NULL);
    tEdgePointer p;

    // Vertex 1
    if (!adjMulList[ver1]) 
        adjMulList[ver1] = edge;
    else {
        p = adjMulList[ver1];
        while(1) {
            // left side
            if (ver1 == p->vertex1) {
                if(p->link1) {
                    p = p->link1;
                    continue;
                } else {
                    p->link1 = edge;
                    break;
                }
            }
            // right side
            else {
                if(p->link2) {
                    p = p->link2;
                    continue;
                } else {
                    p->link2 = edge;
                    break;
                }
            }
        }
    }

    // Vertex 2
    if (!adjMulList[ver2]) 
        adjMulList[ver2] = edge;
    else {
        p = adjMulList[ver2];
        while(1) {
            // left side
            if (ver2 == p->vertex1) {
                if(p->link1) {
                    p = p->link1;
                    continue;
                } else {
                    p->link1 = edge;
                    break;
                }
            }
            // right side
            else {
                if(p->link2) {
                    p = p->link2;
                    continue;
                } else {
                    p->link2 = edge;
                    break;
                }
            }
        }
    }
}
void printMultilist(int numVertex, int choice)
{
    int i;
    tEdgePointer p;

    for(i = 0; i < numOfVer; i++) {
        printf("edges incident to vertex %d : ", i);
        p = adjMulList[i];
        while(p) {
            if(choice == 1)
                printf("(%d, %d) ", p->vertex1, p->vertex2);
            else {
                if(i == p->vertex1)
                    printf("(%d, %d) ", p->vertex1, p->vertex2);
                else
                    printf("(%d, %d) ", p->vertex2, p->vertex1);
            }
            if (i == p->vertex1)
                p = p->link1;
            else p = p->link2;
        }
        putchar('\n');
    }
}

/* result
case 1
<<<<<<<<<<<<<< egdes incident to each vertex >>>>>>>>>>>>>>>>
Input data ordered : 
edges incident to vertex 0 : (0, 1) (0, 2) (0, 3) 
edges incident to vertex 1 : (0, 1) (1, 2) (1, 3) 
edges incident to vertex 2 : (0, 2) (1, 2) (2, 3) 
edges incident to vertex 3 : (0, 3) (1, 3) (2, 3) 

Leading vertex of header node : 
edges incident to vertex 0 : (0, 1) (0, 2) (0, 3) 
edges incident to vertex 1 : (1, 0) (1, 2) (1, 3) 
edges incident to vertex 2 : (2, 0) (2, 1) (2, 3) 
edges incident to vertex 3 : (3, 0) (3, 1) (3, 2)

case 2
<<<<<<<<<<<<<< egdes incident to each vertex >>>>>>>>>>>>>>>>
Input data ordered : 
edges incident to vertex 0 : (0, 1) (0, 3) (0, 2) 
edges incident to vertex 1 : (0, 1) (1, 2) (1, 3) 
edges incident to vertex 2 : (2, 3) (1, 2) (0, 2) 
edges incident to vertex 3 : (2, 3) (0, 3) (1, 3) 

Leading vertex of header node : 
edges incident to vertex 0 : (0, 1) (0, 3) (0, 2) 
edges incident to vertex 1 : (1, 0) (1, 2) (1, 3) 
edges incident to vertex 2 : (2, 3) (2, 1) (2, 0) 
edges incident to vertex 3 : (3, 2) (3, 0) (3, 1)
*/