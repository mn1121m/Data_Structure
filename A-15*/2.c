/* pass
자료구조응용
15. Binary Search Tree, Winner Tree

2. [승자트리를 이용한 정렬] k 개의 레코드(node)를 가지는 승자트리(winner tree)의 초기생 성 함수를 작성하여 정렬을 수행하라. 
 이때 k는 2의 누승 ( power of 2 )임을 가정하라. 단 승자는 키 값이 작은 노드이다.

- 질문 -
- 문제 자체에 대해서 이해를 못했습니다. Winner tree
 [2번 ~ 6번]

*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}
#define MAX_EXPR_SIZE 128

// Data structure
typedef struct _node* treePointer;
typedef struct _node {
    char data;
    treePointer leftChild, rightChild;
} node;

// Global variable
treePointer root = NULL;
int expr[MAX_EXPR_SIZE];

// Functions

int main(void)
{
    int num_key, seed;
    int i;

    printf("<<<<<<<<<<<<<<sortind with winnder tree >>>>>>>>>>>>>>>\n\n");
    printf("the number of keys( 4, 8, 16, or 32 as a power of 2) >> ");
    scanf("%d", &num_key);
    printf("value of seed >> ");
    scanf("%u", &seed);
    for(i = 0; i < num_key; i++) {

    }

}
