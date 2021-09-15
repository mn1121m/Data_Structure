/* remind(ok)(ok)(ok)

자료구조응용
04. 배열, 구조체, 다항식더하기

2. 입력 받은 이차원 배열의 행의 수와 열의 수를 함수 make2dArray()에 전달하면, 
함수 make2dArray()는 전달 받은 원소 갯수 만큼 동적으로 메모리를 할당 받아 
램덤으로 100보다 적은 값으로 메모리를 초기화 시킨 후, 주소값을 반환한다. 
(즉 함수 호출로 2차원 배열 만들 기) 프로그램을 작성하고 반환 직전에 변수값을 디버깅하세요. 
(Autos, Watch 창 사용)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
    fprintf(stderr, "Insufficient memory\n"); \
    exit(EXIT_FAILURE); \
}

int **make2dArray(int row, int col);

int main(void)
{
    int **ipp;
    int i, j, rows, cols;

    printf("이차원 배열의 행과 열의 수를 입력 하세요 : "); 
    scanf("%d %d",&rows, &cols);

    ipp = make2dArray(rows, cols);

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            printf("ipp[%d] =%d ", i, ipp[i][j]);
    printf("\n");
    return 0; // break point 설정
}
// 반환값이 int **이기 때문에 함수원형도 " int ** " 으로 반환해줘야한다.
int **make2dArray(int row, int col)
{
    int **temp, i, j;
    srand((unsigned int)time(NULL));

    MALLOC(temp, sizeof(*temp) * row);
    for(i = 0; i < row; i ++) {
        MALLOC(temp[i], sizeof(*temp[i]) * col);
    }

    for(i = 0; i < row; i ++) {
        for( j = 0; j < col; j ++) 
            temp[i][j] = rand() % 100;
    }
    return temp;
}
/*
1)
이차원 배열의 행과 열의 수를 입력 하세요 : 2 3
ipp[0] =91 ipp[0] =37 ipp[0] =29 ipp[1] =17 ipp[1] =98 ipp[1] =5 

2)
이차원 배열의 행과 열의 수를 입력 하세요 : 2 3
ipp[0] =45 ipp[0] =74 ipp[0] =83 ipp[1] =23 ipp[1] =94 ipp[1] =1 
*/