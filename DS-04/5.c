/* remind()()

5. 다항식을 아래와 같이 표현 하는 방식을 이용하여, 두 다항식을 입력받아 더한 후 그 결과
를 출력하는 프로그램을 작성하라.

[프로그램설명]
1 각 다항식을 사용자로부터 키보드 입력을 받음 
2 다항식을 출력하는 함수를 정의하여 사용하기

- 참고 -
문제에서 "void poly_print(char [], polynomial p)" 에서
    poly_print("A(x) = ", A); <- 처럼 
    char[] = "A(x) = " 를 뜻한다.

void poly_print(const char *x , polynomial p) 으로 코딩을 하라고 했습니다.
     char [] -> const char *x  / char x[] (변수 : x)
     const 쓴 이유 : 읽기모드로 들어오는 값들은 const를 쓴다. (상수다)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 101 /* MAX degree of polynomial + 1 */
#define COMPARE(a, b) ( (a) > (b) ? (a) : (b) )

typedef struct _polynomial {
    int degree;             //차수
    float coef[MAX_DEGREE]; //계수
} polynomial;

polynomial poly_add(polynomial A, polynomial B);
void poly_print(const char *x, polynomial p);

int main(void)
{
    polynomial A, B, C;
    int i;

    printf("<< C(x) = A(x) + B(x) >>\n");

    //  input
    printf("Input the degree of items of A(x) : ");
    scanf("%d", &A.degree); getchar();
    printf("Input the coefficients A(x) : ");
    for(i = 0; i <= A.degree; i++) {
        scanf("%f", &A.coef[i]);
    }

    printf("Input the degree of items of B(x) : ");
    scanf("%d", &B.degree); getchar();
    printf("Input the coefficients B(x) : ");
    for(i = 0; i <= B.degree; i++) {
        scanf("%f", &B.coef[i]);
    }
    //  C = A + B
    C = poly_add(A, B);

    //  print
    poly_print("A(x) = ", A);
    poly_print("B(x) = ", B);
    poly_print("C(x) = ", C);
    return 0;
}
polynomial poly_add(polynomial A, polynomial B)
{
    polynomial C;
    
    int Apos = 0, Bpos = 0, Cpos = 0;   // 첫번째 주소부터 나타내주기 위해서 0으로 초기화
    int degree_a = A.degree;
    int degree_b = B.degree;

    C.degree = COMPARE(A.degree, B.degree);

    while(Apos <= A.degree && Bpos <= B.degree) {
        if(degree_a > degree_b) {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--; // 높은 -> 낮은 차수 순으로 가기때문에 차수에 -1 감소한다.
        }
        else if (degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--, degree_b--;
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
    //출력 : 높은 차수 -> 낮은 차수 
    for(i = p.degree; i > 0; i--) {
        printf("%dx^%d + ", (int)p.coef[p.degree-i], i);
    }
    printf("%d\n", (int)p.coef[p.degree]);   //마지막 계수만 있는 값 출력
}
/*
<< C(x) = A(x) + B(x) >>
Input the degree of items of A(x) : 3
Input the coefficients A(x) : 1 2 3 4
Input the degree of items of B(x) : 4
Input the coefficients B(x) : 1 2 3 4 5
A(x) = 1x^3 + 2x^2 + 3x^1 + 4
B(x) = 1x^4 + 2x^3 + 3x^2 + 4x^1 + 5
C(x) = 1x^4 + 3x^3 + 5x^2 + 7x^1 + 9
*/