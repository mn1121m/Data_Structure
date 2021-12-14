/*  
data structure
16. Adjacency List, Adjacency Multilists
1. 다음과 같이 파일 입력을 통해 무방향 그래프(undirected graph)나 
 방향 그래프(directed graph)를 인접리스트(adjacency-list)로 구성하는 프로그램을 작성하시오.


- 질문 -
+   graphPointer *adjLists;      -> * 쓰는이유 : MutiLinkedlist (다중연결리스트이기 때문이다)
+   int numOfVer, numOfEdges;
    char graphType;             ->  main()함수내에서가 아닌 전역변수로 바로 구현하는건 경험에서 나오는 건가요 ? 아니면 무슨 이유가 있나요 ?

*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Data structure
typedef struct _node {
    int data;                   // vertex
    struct _node* link;         // link
} node;
typedef struct _node* graphPointer;


// Functions
void insertEdge(int u, int v);
void printGraph(graphPointer *adjLists, int numOfVer);

// Global variable
graphPointer *adjLists;
int numOfVer, numOfEdges;
char graphType;

// Main
int main(void)
{
    FILE *fp;
    int i, u, v;
    int debug = 0;

    printf("<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>\n");
    if((fp = fopen("input1.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }

    // Get meta data
    fscanf(fp, "%c %d %d", &graphType, &numOfVer, &numOfEdges);
    //printf("%c %d %d\n", graphType, numOfVer, numOfEdges);

    // Get array, u->v 경로
    MALLOC(adjLists, sizeof(*adjLists)*numOfVer);
    for(i = 0; i < numOfVer; i++)
        adjLists[i] = NULL;
    for(i = 0; i < numOfEdges; i++) {
        fscanf(fp, "%d %d", &u, &v);
        switch (graphType) {
            case 'u' :  //undirected graph
                insertEdge(u, v);
                insertEdge(v, u);
                break;
            case 'd' :  ///directed graph
                insertEdge(u, v);
        }
    }
    fclose(fp);

    // Printing
    printGraph(adjLists, numOfVer);
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
/* result
[input1.txt]
<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>
adjLists[0] :   3  2  1  
adjLists[1] :   3  2  0  
adjLists[2] :   3  1  0  
adjLists[3] :   2  1  0  


[input2.txt]
<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>
adjLists[0] :   1  
adjLists[1] :   0  2  
adjLists[2] :


[input3.txt]
<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>
adjLists[0] :   2  1  
adjLists[1] :   3  0  
adjLists[2] :   3  0  
adjLists[3] :   2  1  
adjLists[4] :   5  
adjLists[5] :   6  4  
adjLists[6] :   7  5  
adjLists[7] :   6 
*/