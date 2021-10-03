/* 2018117610 문준용

5. 다항식더하기, 전치행렬구하기
10. 두 다항식을 입력받아 더한 후 그 결과를 출력하는 프로그램을 작성하라. [프로그램설명]
1 각 다항식을 사용자로부터 키보드 입력을 받음
2 교재의 padd, attatch 함수는 수정 없이 그대로 사용하기
3 다항식을 출력하는 함수를 정의하여 사용하기

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 // size of terms array 
#define COMPARE(x, y) ( (x) < (y) ? -1: (x > y  ? 1: 0) )

// Data structure
typedef struct {
    float coef; //계수
    int expon;  //지수
} term;

term terms[MAX_TERMS];
int avail = 0;

// Functions
void print_padd(int startX, int finishX);
void padd(int, int, int, int, int*, int*);
void attach(float coefficient, int exponent);

// Main
int main(void)
{
    int numberA, numberB, startA, startB, finishA, finishB, startD, finishD;
    int i;
    printf("<< D(x) = A(x) + B(x) >> \n");
    
    // input
    printf("Input the number of items of A(x) : ");
    scanf("%d", &numberA); getchar();
    printf("Input the number of items of B(x) : ");
    scanf("%d", &numberB); getchar();
    printf("\n\n");

    printf("input in descending order\n");
    // A(x)
    startA = 0;
    finishA = numberA -1;
    for(i = startA; i <= finishA; i++) {
        printf("the %dst coefficient and exponent of A(x), <ex>10 3: ", i+1);
        scanf("%f %d", &terms[i].coef, &terms[i].expon);
    }
    putchar('\n');

    // B(x);
    startB = numberA;
    finishB = numberA + numberB -1;
    for(i = startB; i <= finishB; i++) {
        printf("the %dst coefficient and exponent of A(x), <ex>10 3: ", i+1);
        scanf("%f %d", &terms[i].coef, &terms[i].expon);
    }
    putchar('\n');
    avail = finishB + 1;
    // padd
    padd(startA, finishA, startB, finishB, &startD, &finishD);

    // print A(x), B(x), D(x)
    printf("A(x) = ");print_padd(startA, finishA);
    printf("B(x) = ");print_padd(startB, finishB);
    printf("D(x) = ");print_padd(startD, finishD);
    return 0;
}
// Functions
void print_padd(int startX, int finishX)
{
    int i;

    for(i = startX; i <= finishX; i++) {
        // i in first
        if(i == startX) {
            // exponent is empty
            if(!(terms[i].expon)) {
                printf("%f ", terms[i].coef);
            } else {
                printf("%fx^%d ", terms[i].coef, terms[i].expon);
            }
        }
        // i not in first
        else {
            // exponent is empty
            if(!(terms[i].expon)) {
                printf("%+f ", terms[i].coef);
            } else {
                printf("%+fx^%d ", terms[i].coef, terms[i].expon);
            }
        }
    }
    putchar('\n');
}
void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    float coefficient;
    *startD = avail;

    while(startA <= finishA && startB <= finishB) {
        switch(COMPARE(terms[startA].expon, terms[startB].expon)) {
            case -1:    // a_expon < b_expon
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
                break;
            case 0:      // equal exponents
                coefficient = terms[startA].coef + terms[startB].coef;
                if(coefficient) {
                    attach(coefficient, terms[startA].expon);
                }
                startA++;
                startB++;
                break;
            case 1:      // a_expon > b_expon
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
                break;
        }
    }
    // add in remaining terms of A(x)
    for(; startA <= finishA; startA++) {
        attach(terms[startA].coef, terms[startA].expon);
    }
    // add in remaining terms of B(x)
    for(; startB <= finishB; startB++) {
        attach(terms[startB].coef, terms[startB].expon);
    }
    *finishD = avail -1;
}
void attach(float coefficient, int exponent)
{
    /* add a new term to the polynomial */
    if( avail >= MAX_TERMS) {
        fprintf(stderr, " Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}
/*
-------------result-------------
<< D(x) = A(x) + B(x) >> 
Input the number of items of A(x) : 2
Input the number of items of B(x) : 4


input in descending order
the 1st coefficient and exponent of A(x), <ex>10 3: 2 1000
the 2st coefficient and exponent of A(x), <ex>10 3: 1 0

the 3st coefficient and exponent of A(x), <ex>10 3: 1 4
the 4st coefficient and exponent of A(x), <ex>10 3: 10 3
the 5st coefficient and exponent of A(x), <ex>10 3: 3 2
the 6st coefficient and exponent of A(x), <ex>10 3: 1 0

A(x) = 2.000000x^1000 +1.000000 
B(x) = 1.000000x^4 +10.000000x^3 +3.000000x^2 +1.000000 
D(x) = 2.000000x^1000 +1.000000x^4 +10.000000x^3 +3.000000x^2 +2.000000 

*/