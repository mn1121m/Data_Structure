//8조 - Circular Linkedlist
//어떤 놀이공원에서 일주일동안 각 나이대별 사람이 몇명 오는지 조사하려고 한다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)
#define TRUE 1
#define FALSE 0
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a, b;

polyPointer lastA, lastB, lastC, lastD, lastE, lastF, lastG, result, avail = NULL;

polyPointer cpadd(polyPointer a, polyPointer b);
void erase(polyPointer* ptr);
polyPointer getNode(void);
void cerase(polyPointer* ptr);
void insertFront2(polyPointer* last, polyPointer node);
void insertLast(polyPointer* last, polyPointer node);
void printCList(polyPointer last);
void attach(int coef, int expon, polyPointer* ptr);

int main(void)
{
	char day1[100];
	char day2[100];
	char day3[100];
	char day4[100];
	char day5[100];
	char day6[100];
	char day7[100];

	gets(day1);
	char* ptr1 = strtok(day1, " ");
	polyPointer emptyA, emptyB, emptyC, emptyD, emptyE, emptyF, emptyG;
	emptyA = malloc(sizeof(*emptyA));
	emptyB = malloc(sizeof(*emptyB));
	emptyC = malloc(sizeof(*emptyC));
	emptyD = malloc(sizeof(*emptyD));
	emptyE = malloc(sizeof(*emptyE));
	emptyF = malloc(sizeof(*emptyF));
	emptyG = malloc(sizeof(*emptyG));
	emptyA->expon = -1;
	emptyB->expon = -1;
	emptyC->expon = -1;
	emptyD->expon = -1;
	emptyE->expon = -1;
	emptyF->expon = -1;
	emptyG->expon = -1;


	if (strcmp(ptr1, "a") == 0) {
		ptr1 = strtok(NULL, " ");
		while (ptr1 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr1);
			ptr1 = strtok(NULL, " ");
			temp->expon = atoi(ptr1);
			ptr1 = strtok(NULL, " ");
			insertFront2(&lastA, temp);
		}
	}
	else if (strcmp(ptr1, "d") == 0) {
		ptr1 = strtok(NULL, " ");
		while (ptr1 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr1);
			ptr1 = strtok(NULL, " ");
			temp->expon = atoi(ptr1);
			ptr1 = strtok(NULL, " ");
			insertLast(&lastA, temp);
		}
	}

	gets(day2);
	char* ptr2 = strtok(day2, " ");
	if (strcmp(ptr2, "a") == 0) {
		ptr2 = strtok(NULL, " ");
		while (ptr2 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr2);
			ptr2 = strtok(NULL, " ");
			temp->expon = atoi(ptr2);
			ptr2 = strtok(NULL, " ");
			insertFront2(&lastB, temp);
		}
	}
	else if (strcmp(ptr2, "d") == 0) {
		ptr2 = strtok(NULL, " ");
		while (ptr2 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr2);
			ptr2 = strtok(NULL, " ");
			temp->expon = atoi(ptr2);
			ptr2 = strtok(NULL, " ");
			insertLast(&lastB, temp);
		}
	}

	gets(day3);
	char* ptr3 = strtok(day3, " ");
	if (strcmp(ptr3, "a") == 0) {
		ptr3 = strtok(NULL, " ");
		while (ptr3 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr3);
			ptr3 = strtok(NULL, " ");
			temp->expon = atoi(ptr3);
			ptr3 = strtok(NULL, " ");
			insertFront2(&lastC, temp);
		}
	}
	else if (strcmp(ptr3, "d") == 0) {
		ptr3 = strtok(NULL, " ");
		while (ptr3 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr3);
			ptr3 = strtok(NULL, " ");
			temp->expon = atoi(ptr3);
			ptr3 = strtok(NULL, " ");
			insertLast(&lastC, temp);
		}
	}

	gets(day4);
	char* ptr4 = strtok(day4, " ");
	if (strcmp(ptr4, "a") == 0) {
		ptr4 = strtok(NULL, " ");
		while (ptr4 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr4);
			ptr4 = strtok(NULL, " ");
			temp->expon = atoi(ptr4);
			ptr4 = strtok(NULL, " ");
			insertFront2(&lastD, temp);
		}
	}
	else if (strcmp(ptr4, "d") == 0) {
		ptr4 = strtok(NULL, " ");
		while (ptr4 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr4);
			ptr4 = strtok(NULL, " ");
			temp->expon = atoi(ptr4);
			ptr4 = strtok(NULL, " ");
			insertLast(&lastD, temp);
		}
	}

	gets(day5);
	char* ptr5 = strtok(day5, " ");
	if (strcmp(ptr5, "a") == 0) {
		ptr5 = strtok(NULL, " ");
		while (ptr5 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr5);
			ptr5 = strtok(NULL, " ");
			temp->expon = atoi(ptr5);
			ptr5 = strtok(NULL, " ");
			insertFront2(&lastE, temp);
		}
	}
	else if (strcmp(ptr5, "d") == 0) {
		ptr5 = strtok(NULL, " ");
		while (ptr5 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr5);
			ptr5 = strtok(NULL, " ");
			temp->expon = atoi(ptr5);
			ptr5 = strtok(NULL, " ");
			insertLast(&lastE, temp);
		}
	}

	gets(day6);
	char* ptr6 = strtok(day6, " ");
	if (strcmp(ptr6, "a") == 0) {
		ptr6 = strtok(NULL, " ");
		while (ptr6 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr6);
			ptr6 = strtok(NULL, " ");
			temp->expon = atoi(ptr6);
			ptr6 = strtok(NULL, " ");
			insertFront2(&lastF, temp);
		}
	}
	else if (strcmp(ptr6, "d") == 0) {
		ptr6 = strtok(NULL, " ");
		while (ptr6 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr6);
			ptr6 = strtok(NULL, " ");
			temp->expon = atoi(ptr6);
			ptr6 = strtok(NULL, " ");
			insertLast(&lastF, temp);
		}
	}

	gets(day7);
	char* ptr7 = strtok(day7, " ");
	if (strcmp(ptr7, "a") == 0) {
		ptr7 = strtok(NULL, " ");
		while (ptr7 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr7);
			ptr7 = strtok(NULL, " ");
			temp->expon = atoi(ptr7);
			ptr7 = strtok(NULL, " ");
			insertFront2(&lastG, temp);
		}
	}
	else if (strcmp(ptr7, "d") == 0) {
		ptr7 = strtok(NULL, " ");
		while (ptr7 != NULL)
		{
			polyPointer temp;
			temp = malloc(sizeof(*temp));
			temp->coef = atoi(ptr7);
			ptr7 = strtok(NULL, " ");
			temp->expon = atoi(ptr7);
			ptr7 = strtok(NULL, " ");
			insertLast(&lastG, temp);
		}
	}


	insertFront2(&lastA, emptyA);
	insertFront2(&lastB, emptyB);
	insertFront2(&lastC, emptyC);
	insertFront2(&lastD, emptyD);
	insertFront2(&lastE, emptyE);
	insertFront2(&lastF, emptyF);
	insertFront2(&lastG, emptyG);

	result = cpadd(lastA->link, lastB->link);
	result = cpadd(result, lastC->link);
	result = cpadd(result, lastD->link);
	result = cpadd(result, lastE->link);
	result = cpadd(result, lastF->link);
	result = cpadd(result, lastG->link);
	printCList(result);

	cerase(&(lastA->link));
	cerase(&(lastB->link));
	cerase(&(lastC->link));
	cerase(&(lastD->link));
	cerase(&(lastE->link));
	cerase(&(lastF->link));

	cerase(&result);
	erase(&avail);
	free(emptyA);
	free(emptyB);
	free(emptyC);
	free(emptyD);
	free(emptyE);
	free(emptyF);
	free(emptyG);

	return 0;
}


polyPointer cpadd(polyPointer a, polyPointer b)
{
	polyPointer startA, startB, c, lastC;
	int sum, done = FALSE;
	startA = a;
	startB = b;
	a = a->link;
	b = b->link;
	c = getNode();
	c->expon = -1;
	lastC = c;
	do {
		switch (COMPARE(a->expon, b->expon)) {
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		case 0:
			if ((startA == a) || (startB == b)) done = TRUE;
			else {
				sum = (a->coef) + (b->coef);
				if (sum) attach(sum, a->expon, &lastC);
				a = a->link;
				b = b->link;
			}
			break;
		case 1:
			attach(a->coef, a->expon, &lastC);
			a = a->link;
		}
	} while (!done);
	lastC->link = c;
	return c;
}

void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

polyPointer getNode(void)
{
	polyPointer node;
	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else
		node = malloc(sizeof(*node));
	return node;
}

void cerase(polyPointer* ptr)
{
	polyPointer temp;
	if (*ptr) {
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

void insertFront2(polyPointer* last, polyPointer node)
{
	if (!(*last)) {
		(*last) = getNode();
		(*last) = node;
		(*last)->link = node;
	}
	else {
		node->link = (*last)->link;
		(*last)->link = node;
	}
}

void insertLast(polyPointer* last, polyPointer node)
{
	if (!(*last)) {
		(*last) = getNode();
		(*last) = node;
		(*last)->link = node;
	}
	else {
		node->link = (*last)->link;
		(*last)->link = node;
		(*last) = node;
	}
}

void printCList(polyPointer last)
{
	polyPointer temp;
	if (last) {
		temp = last;
		do {
			temp = temp->link;
			if ((temp->expon >= 0)) {
				printf("%d %d ", temp->coef, temp->expon);
			}
		} while ((temp) != last);
	}
	printf("\n");
}

void attach(int coef, int expon, polyPointer* ptr)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = coef;
	temp->expon = expon;
	(*ptr)->link = temp;
	*ptr = temp;
}

/* result

a 5 0 10 1 12 2 10 4 11 6 12 8
d 3 5 17 3 17 1 10 0
d 1 9 4 7 3 4 7 2 1 0
a 11 0 12 2 11 3 3 5 2 8
a 3 1 8 3 8 4 7 6 6 7 1 9
a 10 0 11 1 12 3 11 4 7 5
d 3 9 5 7 4 5 3 2 1 0
// 입력
5 9 14 8 15 7 18 6 17 5 32 4 48 3 34 2 41 1 38 0 
// 출력

*/
