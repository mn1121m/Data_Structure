#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS_SIZE 128
#define COMPARE(x, y) ( ((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

// Data structure
typedef struct {
    float coef;
    int expon;
} term;
term terms[MAX_TERMS_SIZE];
int avail = 0;

// Funtions
void print_padd(int startX, int finishX);
void padd(int, int, int, int, int*, int*);
void attach(float coefficient, int exponent);

// Main
int main(void)
{
    int numberA, numberB;
    int startA, finishA, startB, finishB, startD, finishD;
    int i;

    printf("<<D(x) = A(x) + B(x) >>\n");
    printf("input the number of items of A(x) : ");
    scanf("%d", &numberA); getchar();

    printf("input the number of items of B(x) : ");
    scanf("%d", &numberB); getchar();

    putchar('\n');
    printf("input in desceding order\n\n");

    // A(x)
    startA = 0;
    finishA = numberA - 1;
    printf("coefficent and exponent of A(x) = 10x^2+8x^2+3(10 3, 8 2, 3 0) : ");
    for(i = startA; i <= finishA; i++) {
        scanf("%f %d,", &terms[i].coef, &terms[i].expon);
    }
    
    // B(x)
    startB = numberA;
    finishB = numberA + numberB - 1;
    printf("coefficent and exponent of B(x) = 10x^2+8x^2+3(10 3, 8 2, 3 0) : ");
    for(i = startB; i <= finishB; i++) {
        scanf("%f %d,", &terms[i].coef, &terms[i].expon);
    }
    // putchar('\n'); putchar('\n');
    avail = finishB + 1;
    // print A(x), B(x) and D(x)
    printf("A(x) = ");  print_padd(startA, finishA);
    printf("B(x) = ");  print_padd(startB, finishB);

    // padd
    padd(startA, finishA, startB, finishB, &startD, &finishD);
    printf("D(x) = "); print_padd(startD, finishD);

    return 0;
}
// Funtions
void print_padd(int startX, int finishX)
{
    int i;

    for(i = startX; i <= finishX; i++) {
        // if print_variable is  first
        if(i == startX) {
            if(terms[i].expon == 0) {
                printf("%d ", (int)terms[i].coef);
            }else {
                printf("%dx^%d ", (int)terms[i].coef, terms[i].expon);
            }
        }
        // if print_variable is not first
        else {
            if(terms[i].expon == 0) {
                printf("%+d ", (int)terms[i].coef);
            }else {
                printf("%+dx^%d ", (int)terms[i].coef, terms[i].expon);
            }
        }
    }
    putchar('\n');
}
void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    /* add A(x) and B(x) to obtain D(x) */
    float coefficient;
    *startD = avail;
    while(startA <= finishA && startB <= finishB) {
        switch(COMPARE(terms[startA].expon, terms[startB].expon)) {
            case -1:
                /* b_expon > a_expon */
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
                break;
            case 0:
                /* b_expon == a_expon */
                coefficient = terms[startA].coef + terms[startB].coef;
                if(coefficient)
                    attach(coefficient, terms[startA].expon);
                startA++;
                startB++;
                break;
            case 1:
                /* b_expon < a_expon */
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
                break;
        }
        /* add in remainning terms of A(x) */
        for(; startA <= finishA; startA++)
            attach(terms[startA].coef, terms[startA].expon);

        /* add in remainning terms of B(x) */
        for(; startB <= finishB; startB++)
            attach(terms[startB].coef, terms[startB].expon);
        *finishD = avail - 1;
    }

}
void attach(float coefficient, int exponent)
{
    /* add a new term to the polynomial */
    if(avail >= MAX_TERMS_SIZE) {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}