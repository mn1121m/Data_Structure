/* tree concept review */

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p ,s) \
if(!(p = malloc(s))) {  \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// DS
typedef struct _treeNode* treePointer;
typedef struct _treeNode {
    char data;
    treePointer leftChild, rightChild;
} treeNode;

// GV
treePointer root = NULL;

// Functions
treePointer createBinTree(char data, treePointer leftChild , treePointer rightChild);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int main(void) 
{
    root = createBinTree('A'
        , createBinTree('B', createBinTree('D', NULL, NULL), NULL)
        , createBinTree('C', createBinTree('E', NULL, NULL), NULL)
    );

    printf("Binary Tree\n");
    printf("Inorder : ");
    inorder(root);
    printf("\n");

    printf("Preorder : ");
    preorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");
}


// Functions
treePointer createBinTree(char data, treePointer leftChild , treePointer rightChild)
{
    treePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;

    return temp;
}
void inorder(treePointer ptr) // LVR
{
    if(ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
void preorder(treePointer ptr) //VLR
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