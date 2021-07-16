/*
자료구조응용
12. Trees : 이진트리 생성

1.
[이진트리] 다음과 같은 트리를 생성하고 이진트리 순회방법 중 중위순회(inorder traversal), 전위순회(preorder traversal), 후위순회(postorder traversal)를 통해 출력하 는 프로그램을 작성하라.

- 질문 -
+ (2) 구현사항 -2 함수정의에서 "직접정의 : createNode" 가 있는데, 이건 createBinTree 하나로 구현하면 상관없나요 ?
만약 구현한다면 .. 밑에처럼 구현하는게 맞는건가요 ?
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}
//Data structure
typedef struct _treeNode* treePointer;
typedef struct _treeNode {
    char data;
    treePointer leftChild, rightChild;
} treeNode;

//Global variable
treePointer root = NULL;

//Function
treePointer createNode(char data);
treePointer createBinTree(char data, treePointer leftChild, treePointer rightChild);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int main(void)
{
    root = createBinTree('A'
    , createBinTree('B', createBinTree('D', NULL, NULL), createBinTree('E', NULL, NULL))
    , createBinTree('C', NULL, NULL)
    );

    printf("creating a binary tree\n\n");
    printf("three binary tree traversals\n");
    
    printf("inorder traversal\t : ");
    inorder(root);
    printf("\n");

    printf("preorder traversal\t : ");
    preorder(root);
    printf("\n");

    printf("postorder traversal\t : ");
    postorder(root);
    printf("\n");
    return 0;
}
treePointer createNode(char data)
{
    treePointer temp;
    
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;

    return temp;
}
treePointer createBinTree(char data, treePointer leftChild, treePointer rightChild)
{
    treePointer new = createNode(data);
    
    new->leftChild = leftChild;
    new->rightChild = rightChild;

    return new;
}
void inorder(treePointer ptr)   //LVR
{
    if(ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
void preorder(treePointer ptr)  //VLR
{
    if(ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
void postorder(treePointer ptr) //LRV
{
    if(ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}