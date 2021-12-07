/* 0718(일) 풀이
자료구조응용
12. Trees : 이진트리 생성

1.
[이진트리] 다음과 같은 트리를 생성하고 이진트리 순회방법 중 중위순회(inorder traversal), 전위순회(preorder traversal), 후위순회(postorder traversal)를 통해 출력하 는 프로그램을 작성하라.

[중요]
+ createNode() 구현 -> ()
+ createBinTree() 구현 -> ()
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// 
// Data structure
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

// Functions
treePointer createNode(char data, treePointer leftChild, treePointer rightChild);
treePointer createBinTree(); //Specific binTree
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

// Global variable
treePointer root = NULL;

int main(void)
{
    printf("creating a binary tree\n\n");
    root = createBinTree();

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
    printf("\n");
    
}
// Functions
treePointer createNode(char data, treePointer leftChild, treePointer rightChild)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;
    
    return temp;
}
treePointer createBinTree()
{
    treePointer temp;

    temp = createNode('A'
    , createNode('B', createNode('D', NULL, NULL), createNode('E', NULL, NULL) )
    , createNode('C', NULL, NULL));

    return temp;
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
/* result
creating a binary tree

three binary tree traversals
inorder traversal        : DBEAC
preorder traversal       : ABDEC
postorder traversal      : DEBCA
*/