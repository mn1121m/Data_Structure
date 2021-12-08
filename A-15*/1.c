/* 질문
자료구조응용
15. Binary Search Tree, Winner Tree

1. 다음과 같이 임의의 노드 n개로 구성된 이진탐색트리(binary search tree)를 생성하여 아래와 같이 실행하도록 프로그램을 작성하라.

- 질문 - 
    1번 문제에서는 -> srand(seed); 라고 적혀져있는데 srand(time(NULL)) 로 수정해서 푸는건가요 ?
    [2번 ~ 6번 과정]
    2번 - 난수를 생성하는 과정속에 중복이 허용하지 않는다 => 코딩
        + 중복이 허용하지 않을때와 중복이 허용될때의 구현과정 어떻게 구현하는지 설명좀 부탁드리겠습니다.
    4번 - 2~3 과정을 n번 수행하여 이진탐색트리를 구성 -> for문으로 n번 반복하는 의미인가요 ?
    5번 - 탐색할 key 값을 입력받는다고 하는데 제가 main()내에 변수를 만들어서 입력받아서 이진탐색하는 건가요 ?
    6번 - 중위 순회로 오름차순으로 정렬한다고 하는데 binary search tree 구조상 중위순회 자체가 오름차순이죠 ?
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BST_SIZE 500

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Data structure
typedef int iType;
typedef struct _element {
    int key;
    iType item;
} element;

typedef struct _node* treePointer;
typedef struct _node {
    element data;
    treePointer leftChild, rightChild;
} node;

// Global variable
treePointer root = NULL;

// Funtions
void insert(treePointer *node, int k, iType theItem);
treePointer modifiedSearch(treePointer node, int k);
element* search(treePointer root, int k);
void inorder(treePointer ptr);

// Main
int main(void)
{
    element temp;
    element* search_num;
    int n, seed;
    int i;

    printf("random number generation (1 ~ %d)\n", MAX_BST_SIZE);
    printf("%s", "the number of nodes in BST (less than and equal to 50) : ");
    scanf("%d", &n);
    printf("%s", "seed : ");
    scanf("%u", &seed);
    printf("\ncreating a BST from random numbers\n");
    srand(time(NULL)); // -> srand(seed)

    printf("generating number : ");
    for(i = 0; i < n; i++) {
        temp.key = rand() % 500;
        insert(&root, temp.key, temp.item);
        printf("%d ", temp.key);
    }
    putchar('\n');

    /* search 구현 : ??? */
    printf("the key to search : ");
    scanf("%d", &(search_num->key));
    printf("the element's item is ");
    search(root, search_num->key);
    putchar('\n');
    
    printf("inorder traversal of the BST shows the sorted sequence\n");
    inorder(root);
}
// Funtions

void insert(treePointer *node, int k, iType theItem)
{
    /* temp = parent, ptr = child */
    treePointer ptr, temp = modifiedSearch(*node, k);

    if(temp || !(*node)) {
        /* k is not in the tree */
        MALLOC(ptr, sizeof(*ptr));
        ptr->data.key = k;
        ptr->data.item = theItem;
        ptr->leftChild = ptr->rightChild = NULL;
        
        if(*node) /* insert as child of temp */
            if( k < temp->data.key) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        else *node = ptr;   /* insert into empty BST */
    }
}
treePointer modifiedSearch(treePointer node, int k)
{
    treePointer temp = root;
    while(root) {
        if( k < root->data.key)
            root = root->leftChild;
        else if( k > root->data.key)
            root = root->rightChild;
        else
            return NULL;
    }
    return temp;
}
element* search(treePointer root, int k)
{
    /* return a pointer to the element whose key is k,
    if there is no such element, return NULL. */
    if(!root) return NULL;
    if(k == root->data.key) return &(root->data);
    if(k < root->data.key)
        return search(root->leftChild, k);
    return search(root->rightChild, k);
}
void inorder(treePointer ptr)
{
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data.key);
        inorder(ptr->rightChild);
    }
}