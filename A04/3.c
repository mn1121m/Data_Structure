/* 다시()
3, 이차원 배열의 합을 구하는 프로그램이다. [2차원 배열을 함수로 전달] 정적배열, 동적배 열을 함수로 전달하는 방법을 비교하는 프로그램이다. 
함수의 파라미터 타입에 주의하면서 프 로그램을 작성하라. 
디버깅 창을 출력하고, 동적배열을 sumAry2D_f1의 인자로 전달할 수 없는 이유를 쓰시오.

- 질문 - 
+ int sumAry2D_f5 -> main함수에서 & 참조를 해서 역참조 *를 한게 더 쓰면 똑같아져서 
    int sumAry2D_f5내에서 sum += ary[i][j] 로 똑같이 하는게 아닌가요 ?

+ 동적배열을 sumAry2D_f1의 인자로 전달할 수 없는 이유를 쓰시오 -> 명확한 이유를 알고싶습니다.
    + 정적배열 -> 동적배열로 전달할 수 없는이유 
    + 동적배열 -> 정적배열로 전달할 수 없는이유 : 동적배열은 배열의 크기를 조절할 수 있는데 정적배열을 배열의 크기가 고정되어있기 때문이다 ?

*/
#include <stdio.h>
#include <stdlib.h>

// 정적배열 전달, 첫 번째 파라미터 타입은 모두 int [3]* --> 디버거로 확인하여 출력(디버깅 Autos 창에서 확인)
int sumAry2D_f1( int ary[][3], int rows, int cols ); // 배열 파라미터
int sumAry2D_f2( int (*ary)[3], int rows, int cols ); // 배열 포인터
int sumAry2D_f3( int ary[2][3], int rows, int cols );

// // 동적배열 전달
int sumAry2D_f4( int **ary, int rows, int cols ); //int ** 
int sumAry2D_f5( int ***ary, int rows, int cols ); // int ***
void freeAry2D(int **ary, int rows);

int main(void)
{
    //정적배열(2행 3열)
    int ary2D[][3] = { {1, 2, 3}, {4, 5, 6} };

    //동적배열(2행 3열)
    int r, c;
    int **ary = (int **)malloc(sizeof(int*) * 2);
    
    for(r = 0; r < 2; r++) {
        ary[r] = (int *)malloc(sizeof(int) * 3);
    }

    for(r = 0; r < 2; r++) {
        for(c = 0; c < 3; c++) {
            ary[r][c] = r + c;
            //printf("ary[%d][%d] = %d\n", r, c, ary[r][c]);
        }
    }
    
    //정적 배열
    printf("sumAry2D_f1(): %d\n", sumAry2D_f1(ary2D, 2, 3));
    printf("sumAry2D_f2(): %d\n", sumAry2D_f2(ary2D, 2, 3));
    printf("sumAry2D_f3(): %d\n", sumAry2D_f3(ary2D, 2, 3));

    //동적배열
    printf("sumAry2D_f4(): %d\n", sumAry2D_f4(ary, 2, 3));
    printf("sumAry2D_f5(): %d\n", sumAry2D_f5(&ary, 2, 3));

    //동적배열을 f1, f2, f3로 전달할 수 있을까? 테스트해 보라! -> 전달 x
    printf("sumAry2D_f1~f3() %d\n", sumAry2D_f1(ary, 2, 3));
    
    //정적배열을 f4, f5로 전달할 수 있을까? 테스트해 보라! -> 전달 x
    printf("sumAry2D_f4~f5() %d\n", sumAry2D_f4(ary2D, 2, 3));

    freeAry2D(ary, 2);
    return 0;
}
int sumAry2D_f1( int ary[][3], int rows, int cols )
{
    int i, j, sum = 0;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) 
            sum += ary[i][j];
    }
    return sum;
}
int sumAry2D_f2( int (*ary)[3], int rows, int cols )
{
    int i, j, sum = 0;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) 
            sum += ary[i][j];
    }
    return sum;
}
int sumAry2D_f3( int ary[2][3], int rows, int cols )
{
    int i, j, sum = 0;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) 
            sum += ary[i][j];
    }
    return sum;
}
int sumAry2D_f4( int **ary, int rows, int cols )
{
    int i, j, sum = 0;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) 
            sum += ary[i][j];
    }
    return sum;
}
int sumAry2D_f5( int ***ary, int rows, int cols )
{
    int i, j, sum = 0;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) 
            sum += (*(*ary[i]+ j));
    }
    return sum;
}
void freeAry2D(int **ary, int rows)
{
    int i;

    for(i = 0; i < rows; i++)
        free(ary[i]);
    free(ary);
}