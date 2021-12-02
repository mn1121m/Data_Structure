/* 8_Team 문제 - tree응용- inorder*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if (!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

/* Typedef BOOL */
#define TRUE 1
#define FALSE 0

/* Stack */
#define MAX_STACK_SIZE 1024

typedef int BOOL;

typedef struct node *treePointer;
struct node {
    char data;
    float value;
    treePointer leftChild, rightChild;
};

void inorder(treePointer ptr);
void createBinTree(FILE *fp);
void npush(treePointer node);
treePointer npop();
treePointer createNode(char data, float value, treePointer left, treePointer right);
void freeTree(treePointer ptr);

treePointer bintree = NULL;
treePointer nstack[MAX_STACK_SIZE];
int ntop = -1;

int main(int argc, char **argv) 
{
    FILE *fp = NULL;
    BOOL found = FALSE;
    
    // if (argc != 2) {
    //     fprintf(stderr, "Usage : %s [FILE_NAME]\n", argv[0]);
    //     exit(EXIT_FAILURE);
    // }
   
    fp = fopen("input2-1.txt", "r");
    createBinTree(fp);
    fclose(fp);

    inorder(bintree);
    freeTree(bintree);

    return 0;
}

treePointer createNode(char data, float value, treePointer left, treePointer right)
{
    treePointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    // TODO in 3rd prob.
    // temp->value = value; 
    temp->leftChild = left;
    temp->rightChild = right;

    return temp;
}

void inorder(treePointer ptr)
{   
    if (ptr) {
        switch (ptr->data) {
            case '+': case '-': case '/': case '*': 
                printf("(");
                break;
        }
        inorder(ptr->leftChild);
        printf("%c",ptr->data);
        inorder(ptr->rightChild);
        switch (ptr->data) {
            case '+': case '-': case '/': case '*': 
                printf(")");
                break;
        }
    }
}
void freeTree(treePointer ptr)
{
   if (ptr->leftChild) freeTree(ptr->leftChild);
   if (ptr->rightChild) freeTree(ptr->rightChild);
   free(ptr);
}
void npush(treePointer node)
{
    if (ntop == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "[ERROR] : Stack full.\n");
        exit(EXIT_FAILURE);
    }
    nstack[++ntop] = node;
}
treePointer npop()
{
    if (ntop == -1) {
        fprintf(stderr, "[ERROR] : Stack empty.\n");
        exit(EXIT_FAILURE);
    }
    return nstack[ntop--];
}
void createBinTree(FILE *fp)
{
    char temp;
    treePointer op1, op2;

    while (fscanf(fp, "%c", &temp) != EOF) {
        switch (temp) {
            case '+': case '-': case '/': case '*':
                op2 = npop();
                op1 = npop();
                npush(createNode(temp, 0.0, op1, op2));
                break;
            default:
                npush(createNode(temp, 0.0, NULL, NULL));
        }
    }
    bintree = npop();
}
/* result - input2-1.txt 
(((a+b)*c)-d)%      
*/