#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Data structrue
typedef struct _treeNode *treePointer;
typedef struct _treeNode {
    char data;
    treePointer leftChild, rightChild;
} treeNode;

// Global varibale
treePointer root = NULL;

// Functions
treePointer createNode(char data, treePointer leftChild , treePointer rightChild);
treePointer createBinTree();
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

// Main
int main(void) 
{
    printf("creating a binary tree\n");
    root = createBinTree();
    putchar('\n');

    printf("three binary tree traversals\n");
    printf("inorder traversal\t : ");
    inorder(root); putchar('\n');
    printf("preorder traversal\t : ");
    preorder(root); putchar('\n');
    printf("postorder traversal\t : ");
    postorder(root); putchar('\n');

}
 
// Functions
treePointer createNode(char data, treePointer leftChild , treePointer rightChild)
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
/* result
creating a binary tree

three binary tree traversals
inorder traversal        : DBEAC
preorder traversal       : ABDEC
postorder traversal      : DEBCA
*/