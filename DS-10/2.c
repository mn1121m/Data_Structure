/*
자료구조응용
10. 연결 리스트 : 다항식

2. 다음과 같이 chain을 이용한 다항식 더하기 프로그램을 작성하라.

[*] - 전반적으로 모르겠음.
*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory\n"); \
exit(EXIT_FAILURE); \
}

#define COMPARE(a, b) ( (a) < (b) ? -1: ( a == b ? 0: 1 ) )

#define TRUE 1
#define FALSE 0

// Data structure

typedef struct polyNode* polyPointer;
typedef struct polyNode {
    int coef;
    int expon;
    polyPointer link;
} polyNode;
polyPointer avail = NULL;

// Functions
polyPointer getNode(void);
void insertTerm(polyPointer *ptr, int coef, int exp);
polyPointer cpadd(polyPointer a, polyPointer b);
void attach(int coefficient, int exponent, polyPointer *ptr);
void printPoly(polyPointer ptr);
void freePoly(polyPointer ptr);

// Main
int main(void)
{
    FILE *fp = NULL;
    polyPointer a = NULL, b = NULL, c = NULL;
    int termNum, i, tempCoef, tempExp;
    char type;

    // File read
    if((fp = fopen("a.txt","r")) == NULL) {
        fprintf(stderr, "Don't search the file name\n");
        exit(EXIT_FAILURE);
    }

    // Read a
    //fscanf(fp, "%c", &type);
    while(fscanf(fp, "%d %d", &tempCoef, &tempExp) != EOF) {
        insertTerm(&a, tempCoef, tempExp);
    }
    insertTerm(&a, 0, -1);
    printf("\ta :\t");printPoly(a);

    // Read b
    //fscanf(fp, "%c", &type);
    while(fscanf(fp, "%d %d", &tempCoef, &tempExp) != EOF) {
        insertTerm(&b, tempCoef, tempExp);
    }
    insertTerm(&b, 0, -1);
    printf("\tb :\t"); printPoly(b);

    c = cpadd(a, b);
    printf("\tc :\t"); printPoly(c);

    freePoly(a);
    freePoly(b);
    freePoly(c);

    return 0;
}

// Functions
polyPointer getNode(void)
{
    polyPointer node;
    if(avail) {
        node = avail;
        avail = avail->link;
    } else
        MALLOC(node, sizeof(*node));
    return node;
}
void insertTerm(polyPointer *ptr, int coef, int exp)
{
    polyPointer temp = getNode(), first;

    temp->coef = coef;
    temp->expon = exp;
    if(!(*ptr)) {
        temp->link = temp;
        *ptr = temp;
        return;
    }
    first = (*ptr)->link;
    (*ptr)->link = temp;
    temp->link = first;
    *ptr = temp;
}
polyPointer cpadd(polyPointer a, polyPointer b)
{
    polyPointer c, rear, temp;
    int sum;
    MALLOC(rear, sizeof(*rear));
    c = rear;
    while(a && b) {
        switch (COMPARE(a->expon, b->expon)) {
            case -1: /* a->expon < b->expon */
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0: /* a->expon = b->expon */
                sum = a->coef + b->coef;
                if(sum) attach(sum, a->expon, &rear);
                a = a->link; b = b->link; break;
            case 1: /* a->expon > b->expon */
                attach(a->coef, a->expon, &rear);
                a = a->link;
        }
    }
    /* copy rest of list a and list b */
    for(; a; a = a->link) attach(a->coef, a->expon, &rear);
    for(; b; b = b->link) attach(b->coef, b->expon, &rear);
    rear->link = NULL;
    /* delete extra initial node */
    temp = c; c = c->link; free(temp);
    return c;
    

}
void attach(int coefficient, int exponent, polyPointer *ptr)
{
    polyPointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->coef = coefficient;
    temp->expon = exponent;

    (*ptr)->link = temp;
    *ptr = temp;
}
void printPoly(polyPointer ptr)
{
    polyPointer lastNode = ptr;
    if (ptr) {
        ptr = ptr->link;
        while (ptr != lastNode) {
            printf("(%d, %d) ", ptr->coef, ptr->expon);
            ptr = ptr->link;
        }
    }
}
void freePoly(polyPointer ptr)
{
    polyPointer last = ptr, p;
    ptr = ptr->link;
    last->link = NULL;

    while (ptr) {
        p = ptr;
        ptr = ptr->link;
        free(p);
    }
}