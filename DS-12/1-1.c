/*
Data structure
12. Trees : 이진트리 생성

1.[이진트리] 다음과 같은 트리를 생성하고 이진트리 순회방법 중 
중위순회(inorder traversal), 전위순회(preorder traversal), 후위순회(postorder traversal)를 통해 출력하는 프로그램을 작성하라.

*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}
#define TRUE 1
#define FALSE 0

//Data structure
typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild, rightChild;
} tNode;

//Global variable
treePointer root = NULL;

//Function
treePointer createNode (char data, treePointer leftChild, treePointer rightChild);
treePointer createBinTree();
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

//Main
int main(void)
{
    printf("creating a binary tree\n\n");
    root = createBinTree();
    
    printf("three binary tree traversal\n");

    printf("inorder traversal\t: ");
    inorder(root);
    printf("\n");
    printf("preorder traversal\t: ");
    preorder(root);
    printf("\n");
    printf("postorder traversal\t: ");
    postorder(root);
    printf("\n\n");
    
}   
//Function
treePointer createNode (char data, treePointer leftChild, treePointer rightChild)
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
    , createNode('B', createNode('D', NULL, NULL), createNode('E', NULL, NULL))
    , createNode('C', NULL, NULL)
    );

    return temp;
}
//LVR
void inorder(treePointer ptr)
{
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
//VLR
void preorder(treePointer ptr)
{
    if (ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
//LRV
void postorder(treePointer ptr)
{
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}
/* result 
creating a binary tree

three binary tree traversal
inorder traversal       : DBEAC
preorder traversal      : ABDEC
postorder traversal     : DEBCA

*/