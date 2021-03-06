/* remind
data structure
03. 성능측정(Performance Measurement)

1. 다음 프로그램의 func1, func2, func3을 정의한 후 실행되도록 구현하라.

[참고]
    1.c:45:1: warning: non-void function does not return a value [-Wreturn-type]
    }
    ^
    1.c:49:1: warning: non-void function does not return a value [-Wreturn-type]
    }
=> non-void funcion : return을 해야한다.
=> void * type가 있기 때문에 error가 생기는 것이다. 
*/

#include <stdio.h>
#include <stdlib.h>

int *func1();
void func2(int *p);
void func3(int **p);

int main(void)
{
    int *pNum;

    pNum = func1(); // int 크기만큼 동적할당 받아 10을 지정후 정수형 포인터 리턴 
    printf("%d\n", *pNum);

    func2(pNum);// pNum이 가리키는 것을 100으로 수정 
    printf("%d\n", *pNum);

    func3(&pNum); // pNum이 가리키는 것을 200으로 수정 
    printf("%d\n", *pNum);

    free(pNum);

    return 0;
}
int *func1()
{
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 10;

    return p;
}
void func2(int *p)
{
    *p = 100;
}
void func3(int **p)
{
    **p = 200;
}