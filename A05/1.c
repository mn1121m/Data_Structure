/*
05. 다항식더하기, 전치행렬구하기

1. 크기가 20*20인 이차원 배열로 희소 행렬을 다음과 같이 만들어라. 
0이 아닌 배열 원소의 수를 입력 받아, 
rand()함수를 이용하여 위치와 값을 설정하도록 하시오. 
(매번 수행시마다 서 로 다른 희소행렬이 만들어져야함), 
이 행렬을 이용하여, 배열의 공간을 절약하기 위한 희소행 렬을 만들고 출력하시오.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20
#define MAX_TERMS 101   /* maximum numer of terms + 1 */

// Data structure

// Functions
void createAry();
void printAry(int ary[20][20]);
void ary2SparseMat();
void printSparseMat();

// Global variable
int ary[ROW][COL];

int main(void)
{
    int n;

    printf("Press the numver of a elements : ");
    scanf("%d", &n);

    createAry();
    printf("Random generated Matrix(20,20)\n");
    printAry();

    ary2SparseMat();
    printSparseMat();
    return 0;
}
void createAry()
{

}
void printAry(int ary[20][20]);
void ary2SparseMat();
/* 
cf) rand() 함수 
    //srand(time(NULL));
    
    // for(i = 1; i <= 10; i++) 
    //     printf("%d ", (rand() % 100) + 1);
    // printf("\n");


힌트)
for i = 0 to row :
    for j = 0 to col :
        if cur.row == i and cur.col == j
            print(cur.value)
            cur <- cur_next
        else
            print(0)
    print('\n');

*/