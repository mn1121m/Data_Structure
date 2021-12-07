/* DS 5 12 ex)inorder, preorder, postorder
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
    treePointer leftChild;
    treePointer rightChild;
} treeNode;

//Global variable
treePointer root = NULL;

//Function
treePointer createBinTree(char data, treePointer leftChild, treePointer rightChild);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int main(void)
{
    //(A(B(D), C(E)))
    root = createBinTree('A'
        , createBinTree('B', createBinTree('D', NULL, NULL), NULL)
        , createBinTree('C', createBinTree('E', NULL, NULL), NULL)
        );

    printf("inorder : ");
    inorder(root);
    printf("\n");

    printf("preorder : ");
    preorder(root);
    printf("\n");

    printf("postorder : ");
    postorder(root);
    printf("\n");
}
treePointer createBinTree(char data, treePointer leftChild, treePointer rightChild)
{
    treePointer temp;
    
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;
    return temp;
}
void inorder(treePointer ptr)
{
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}
void preorder(treePointer ptr)
{
    if (ptr) {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
void postorder(treePointer ptr)
{
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}