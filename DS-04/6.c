/* 다시()
6. 다항식을 다음 같이 표현 하는 방식을 이용하여, 두 다항식을 입력받아 더한 후 
그 결과를 출력하는 프로그램을 작성하라.

[프로그램설명]
1 각 다항식을 사용자로부터 키보드 입력을 받음
2 교재의 padd, attatch 함수는 수정 없이 그대로 사용하기 
3 다항식을 출력하는 함수를 정의하여 사용하기

- 질문 - => ok
+ 실행 예시에서 다음과 같이 -> ex) 11 9, 9 5, 3 3, 7 2, 9 0
    ',' 를 이용해서 구분하였는데, 그럴 때는 어떻게 구분해서 입력할 수 있는건가요 ?
-> scanf("%f %d,", ~~~) 처럼 %d 뒤에 ,를 붙여주면 된다.

<복습> - check 
+ print_add() 구현하는 과정
+ padd, attach 보기 없이 구현할 것.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100 /* size of terms array */
#define COMPARE(x, y) ( (x) > (y) ? 1: (x < y ? -1 : 0 ) )

typedef struct _term {
    float coef;
    int expon;
} term;
term terms[MAX_TERMS];
int avail = 0;

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD);
void attach(float coefficient, int exponent);
void print_add(int startX, int finishX);

int main(void)
{
    int startA, finishA, startB, finishB, startD, finishD;
    int A_number, B_number, i;

    //  input
    printf("<<D(x) = A(x) + B(x) >> \n");

    printf("Input the number of items of A(x) : ");
    scanf("%d", &A_number); getchar();
    printf("Input the number of items of B(x) : ");
    scanf("%d", &B_number); getchar(); putchar('\n');

    printf("Input in descending order\n\n");
    printf("coefficient and exponent of A(x) = 10x^3+8x^2+3 (10 3, 8 2, 3 0): ");
    startA = 0;
    finishA = A_number -1;
    for(i = startA; i <= finishA; i++) {
        scanf("%f %d,", &terms[i].coef, &terms[i].expon);   //%d뒤에 , 써주면 ',' 구분된다.
    }
    printf("coefficient and exponent of B(x) = 10x^3+8x^2+3 (10 3, 8 2, 3 0): ");
    startB = A_number;
    finishB = A_number + B_number - 1;
    for(i = startB; i <= finishB; i++) {
        scanf("%f %d,", &terms[i].coef, &terms[i].expon);    //%d뒤에 , 써주면 ',' 구분된다.
    }
    avail = finishB + 1;
    //  padd
    padd(startA, finishA, startB, finishB, &startD, &finishD);

    //  print
    printf("A(x) = "); print_add(startA, finishA);
    printf("B(x) = "); print_add(startB, finishB);
    printf("C(x) = "); print_add(startD, finishD);

    return 0;  
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    /*  add A(x) and B(x) to obtan D(x) */
    float coefficient;
    *startD = avail;
    while(startA <= finishA && startB <= finishB) {
        switch(COMPARE(terms[startA].expon, terms[startB].expon)) {
            case -1: /* a expon < b expon */
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
                break;
            case 0: /* equal exponents */
                coefficient = terms[startA].coef + terms[startB].coef;
                if(coefficient)
                    attach(coefficient, terms[startA].expon);
                startA++;
                startB++;
                break;
            case 1: /* a expon > b expon */
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
                break;
        }
    }
    /* add in remainning terms of A(x) */
    for(; startA <= finishA; startA++)
        attach(terms[startA].coef, terms[startA].expon);
     /* add in remainning terms of B(x) */
    for(; startB <= finishB; startB++)
        attach(terms[startB].coef, terms[startB].expon);
    *finishD = avail - 1;
}

void attach(float coefficient, int exponent)
{
    /*add a new term to the polynomial */
    if(avail >= MAX_TERMS) {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void print_add(int startX, int finishX)
{
    int i;
    
    for(i = startX; i <= finishX; i++) {
        //  처음일때
        if(i == startX) {
            if(terms[i].expon == 0)
                printf("%d", (int)terms[i].coef);
            else
                printf("%dx^%d", (int)terms[i].coef, terms[i].expon);
        }
        //  처음이 아닐때는 '+' 해줘야한다.
        else {
            if(terms[i].expon == 0)
                printf("%+d ", (int)terms[i].coef);
            else 
                printf("%+dx^%d ", (int)terms[i].coef, terms[i].expon);
        }
    }
    printf("\n");
}
/*
<<D(x) = A(x) + B(x) >> 
Input the number of items of A(x) : 5
Input the number of items of B(x) : 3

Input in descending order

coefficient and exponent of A(x) = 10x^3+8x^2+3 (10 3, 8 2, 3 0): 11 9, 9 5, 3 3, 7 2, 9 0
coefficient and exponent of B(x) = 10x^3+8x^2+3 (10 3, 8 2, 3 0): 10 9, 5 3, 5 2
A(x) = 11x^9+9x^5 +3x^3 +7x^2 +9 
B(x) = 10x^9+5x^3 +5x^2 
C(x) = 21x^9+9x^5 +8x^3 +12x^2 +9
*/