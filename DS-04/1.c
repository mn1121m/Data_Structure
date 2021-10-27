/* remind

자료구조응용
04. 배열, 구조체, 다항식더하기

1. 입력 받은 일차원 배열의 원소 개수를 함수 make1dArray()에 전달하면, 
함수 make1dArray()는 전달 받은 원소 갯수 만큼 동적으로 메모리를 할당 받아 램덤으로 100 보다 적은 값으로 메모리를 초기화 시킨 후, 
주소값을 반환한다. (즉 함수 호출로 1차원 배열 만들기)

[복습]
    - rand() 매번 다르게 나오게 하는 알고리즘   =>  srand((unsigned int)time(NULL));
    - int* make1dArray() 구현
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
    fprintf(stderr, "Insufficient memory\n"); \
    exit(EXIT_FAILURE); \
}
int *make1dArray(int num);

int main(void) 
{
    int *ipp;
    int i, num;

    printf("일차원 배열의 수를 입력하세요 : ");
    scanf("%d", &num);

    ipp = make1dArray(num);

    for(i = 0; i < num; i++ )
        printf("ipp[%d] = %d ", i, ipp[i]);
    printf("\n");
    
    return 0;
}

int *make1dArray(int num)
{
    int *temp, i;

    srand((unsigned int)time(NULL));
    MALLOC(temp, sizeof(*temp) * num);

    for( i = 0; i < num; i++) {
        temp[i] = rand() % 100;
    }
    return temp;
}
/*
1)
일차원 배열의 수를 입력하세요 : 5
ipp[0] = 42 ipp[1] = 7 ipp[2] = 91 ipp[3] = 77 ipp[4] = 69 

2)
일차원 배열의 수를 입력하세요 : 5
ipp[0] = 64 ipp[1] = 79 ipp[2] = 4 ipp[3] = 58 ipp[4] = 21 
*/