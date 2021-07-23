/* 진행중 
자료구조응용
14. Trees : 명제식 이진트리, heap
1. postfix expression의 명제식을 파일로부터 입력받아 이진트리를 구성하여 중위순회 (inorder traversal)한 결과를 화면에 출력하라.
createPostBinTree();
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}
#define MAX_EXPR_SIZE 128
#define TRUE 1
#define FALSE 0

//Data structure
typedef enum {not, and, or, true, false
} logical;
typedef struct _node* treePointer;
typedef struct _node {
    treePointer leftChild;
    logical data;   //the value of a variable or an operator
    int value;  //TRUE, FALSE
    treePointer rightChild;
} node;

//Global variable
char expr[MAX_EXPR_SIZE];
treePointer root;
void inorder(treePointer ptr);

//Funtions
//Binary tree
treePointer createNode(logical data, int value, treePointer leftChild, treePointer rightChild);
void createPostBinTree();
void inOrderEval(treePointer node);    //LRV

int main(void)
{
    FILE *fp;

    if((fp = fopen("postfix.txt", "r")) == NULL) {
        fprintf(stderr, "Wrong file name.\n");
        exit(EXIT_FAILURE);
    }
    
    fscanf(fp, "%s", expr);
    printf("input string(postfix)\t : %s\n", expr);

    fclose(fp);
    printf("creating its binary tree\n");
    root = createBinTree();

    printf("inorder traversal\t : ");
    inorder(root);
    printf("\n");

    return 0;
}
//Funtions
treePointer createNode(logical data, int value, treePointer leftChild, treePointer rightChild)
{
    treePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->value = value;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;

    return temp;
}
void createPostBinTree();

void inOrderEval(treePointer node)    //LVR
{
    /* modefied postorder traversal to evaluate a propositional calculus tree */
    if(node) {
        postOrderEval(node->leftChild);
        switch(node->data) {
            case not: node->value = !node->rightChild->value; break;
            case and: node->value = node->rightChild->value && node->leftChild->value; break;
            case or: node->value = node->rightChild->value || node->leftChild->value; break;
            case true: node->value = TRUE; break;
            case false: node->value = FALSE; break;
        }
        postOrderEval(node->rightChild);
    }
}
