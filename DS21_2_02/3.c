/* 2018117610 문준용
3. 다음 프로그램의 func1, func2, func3을 정의한 후 실행되도록 구현하라.
그리고, func1, func2, func3, main 함수의 종료직전 메모리 상태(스택 & 힙)를 각각 그려서 보고서에 추가 하라.
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
if(!((p) = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

// Functions
int* func1();
int* func2(int *pNum);
int** func3(int **pNum);

int main(void)
{
    int *pNum = func1(); // int 크기만큼 동적할당 받아 0을 지정

    printf("%d\n", *pNum);
    printf("%d\n", *func2(pNum));   // pNum이 가리키는 것을 100으로 수정
    printf("%d\n", **func3(&pNum)); // pNum이 가리키는 것을 200으로 수정
}
// Functions
int* func1()
{
    int *p;
    MALLOC(p, sizeof(*p));
    *p = 0;
    
    return p;

}
int* func2(int *pNum)
{
    *pNum = 100;
    return pNum;
}
int** func3(int **pNum)
{
    **pNum = 200;
    return pNum;
}
/* result
0
100
200
*/