#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}tNode;

treePointer createNode(void);
void makeLeftsubtree(treePointer main, treePointer sub);
void makeRightsubtree(treePointer main, treePointer sub);
void saveTree(treePointer temp, int num);
int compareTree(treePointer a, treePointer b);
void printWinner(treePointer temp);

int main(void)
{
	int num;
	treePointer node[16];
	for (int i = 1; i < 16; i++) {
		node[i]= createNode();
	}

	for (int i = 15; i > 1; i--) {
		if (i % 2 == 1)
			makeRightsubtree(node[i / 2], node[i]);
		else
			makeLeftsubtree(node[i / 2], node[i]);
	}

	for (int i = 8; i < 16; i++) {
		scanf("%d", &num);
		saveTree(node[i], num);
	}

	for (int i = 15; i > 2; i -= 2) {
		saveTree(node[i / 2], compareTree(node[i], node[i - 1]));
	}

	printWinner(node[1]);
	return 0;
}

treePointer createNode(void) {
	treePointer newNode = malloc(sizeof(*newNode));
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

void makeLeftsubtree(treePointer main, treePointer sub) {
	if (main->leftChild != NULL)
		free(main->leftChild);
	main->leftChild = sub;
}

void makeRightsubtree(treePointer main, treePointer sub) {
	if (main->rightChild != NULL)
		free(main->rightChild);
	main->rightChild = sub;
}

void saveTree(treePointer temp, int num) {
	temp->data = num;
}

int compareTree(treePointer a, treePointer b) {
	if ((a->data) > (b->data))
		return a->data;
	else
		return b->data;
}

void printWinner(treePointer temp) {
	printf("%d", temp->data);
}
