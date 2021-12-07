#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x, y) ( (x) > (y) ? (x) : (y) )
#define MAX_DEGREE 101 /* Max degree of polynomial + 1 */

// DS
typedef struct _polynomial {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

// Function
polynomial padd(polynomial A, polynomial B);
void poly_print(const char *x, polynomial p);

// Main
int main(void)
{
    printf("<< C(x) = A(x) + B(x) >> \n");
    polynomial A, B, C;
    int i;

    // input of A(x)
    printf("Input the degree itmes of A(x) : ");
    scanf("%d", &A.degree); getchar();
    printf("Input the coefficients A(x): ");
    for(i = 0; i <= A.degree; i++) {
        scanf("%f", &A.coef[i]);
    }
    printf("\n");

    // input of B(x)
    printf("Input the degree itmes of B(x) : ");
    scanf("%d", &B.degree); getchar();
    printf("Input the coefficients B(x): ");
    for(i = 0; i <= B.degree; i++) {
        scanf("%f", &B.coef[i]);
    }
    printf("\n");
    // padd
    C = padd(A, B);

    // print
    poly_print("A(x) = ", A);
    poly_print("B(x) = ", B);
    poly_print("C(x) = ", C);

    return 0;
}
// Function
polynomial padd(polynomial A, polynomial B)
{
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;

    C.degree = COMPARE(A.degree, B.degree);

    while(Apos <= A.degree && Bpos <= B.degree) {
        if(degree_a > degree_b) {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if(degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else {
             C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}
void poly_print(const char *x, polynomial p)
{
    int i;

    printf("%s", x);
    for(i = p.degree; i > 0; i--) {
        printf("%dx^%d + ", (int)p.coef[p.degree - i], i);
    }
    printf("%d\n", (int)p.coef[p.degree]);
}