#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
    int key;
    treePointer leftChild, rightChild;
}tNode;
treePointer root=NULL;
treePointer temp=NULL;
int level;

treePointer search(treePointer main, int ptr);
treePointer createNode(int key);
void insertNode(treePointer temp, treePointer new);
void inorder(treePointer ptr);

int main(void)
{
    int keyN;
    treePointer newNode;

    while (1) {
        scanf("%d", &keyN);

        if (keyN == -1) {
            break;
        }

        temp = search(root, keyN);

        if (root == NULL) {
            root = createNode(keyN);
        }
        else if (temp) {
            insertNode(temp, createNode(keyN));
        }
    }

    inorder(root);
    printf("\n");

    while (1) {
        scanf("%d", &keyN);

        if (keyN == -1) {
            break;
        }

        level = 0;
        temp = search(root, keyN);

        if (root == NULL) {
            root = createNode(keyN);
        }
        else if (temp) {
            insertNode(temp, createNode(keyN));
        }

        if (temp == NULL) {
            printf("중복된 값입니다.\n");
        }
        else {
            printf("새로 삽입된 key값이 %d인 node의 level은 %d입니다.\n", keyN, level);
        }
    }

    inorder(root);
}

void inorder(treePointer ptr) 
{
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%d ", ptr->key);
        inorder(ptr->rightChild);
    }
}

void insertNode(treePointer temp, treePointer new) 
{
    if (new->key < temp->key)
        temp->leftChild = new;
    else
        temp->rightChild = new;
}

treePointer search(treePointer main, int keyN) 
{
    if (!main) return temp;
    if (keyN == main->key) return NULL;
    if (keyN < main->key) {
        level=level+1;
        temp = main;
        return search(main->leftChild, keyN);
    }
    else if (keyN > main->key) {
        level=level+1;
        temp = main;
        return search(main->rightChild, keyN);
    }
}

treePointer createNode(int keyN) 
{
    treePointer newNode = malloc(sizeof(*newNode));
    newNode->key = keyN;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
/* result
30 15 80 70 90 13 17 -1
13 15 17 30 70 80 90 
13
중복된 값입니다.
70
중복된 값입니다.
80
중복된 값입니다.
14
새로 삽입된 key값이 14인 node의 level은 3입니다.
31
새로 삽입된 key값이 31인 node의 level은 3입니다.
45
새로 삽입된 key값이 45인 node의 level은 4입니다.
75
새로 삽입된 key값이 75인 node의 level은 3입니다.
50
새로 삽입된 key값이 50인 node의 level은 5입니다.
-1
13 14 15 17 30 31 45 50 70 75 80 90 %  
*/