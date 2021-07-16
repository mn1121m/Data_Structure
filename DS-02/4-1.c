/*
자료구조응용 02. 배열과 포인터

4. 메모리의 동적 할당과 해제에 대해 다음 두 가지 버전으로 프로그램을 작성하라. 
모두 제 대로 main 함수를 구현하여 실행되도록 하여야 한다.
*/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, *pi;
    float f, *pf;

    pi = (int *)malloc(sizeof(int));
    pf = (float *)malloc(sizeof(float));

    if((pi = (int *)malloc(sizeof(int))) == NULL 
        || (pf = (float*)malloc(sizeof(float))) == NULL) {
        fprintf(stderr, "Insufficient memory\n");
        exit(EXIT_FAILURE);
    }
    *pi = 1024;
    *pf = 3.14;

    printf("an inteager = %d, a float = %f\n", *pi, *pf);
    free(pi);
    free(pf);

    return 0;
}
/*
an inteager = 1024, a float = 3.140000
*/