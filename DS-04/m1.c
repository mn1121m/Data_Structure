#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(p, s) \
if(!((p) = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
}

#define MAX_ARY_SIZE 1028

// Functions
int* make1dArray(int number);

// Main
int main()
{
    int *ipp;
    int i, num;

    //input
    printf("일차원 배얄의 수를 입력 하세요 : ");
    scanf("%d", &num);

    //make1dArray 
    ipp = make1dArray(num);

    for( i = 0 ; i < num; i ++) {
        printf("ipp[%d] = %d ", i, ipp[i]);
    }

    return 0;
}
int* make1dArray(int number)
{
    int i, *pArr;

    srand((unsigned int)time(NULL));
    MALLOC(pArr, sizeof(*pArr));
    for(i = 0; i < number; i++) {
        pArr[i] = rand() % 100;
    }
    return pArr;
}