/* 2018117610 문준용

7. [3차원 배열을 함수로 전달] 1번과 유사한 형태의 3차원 배열 프로그램을 작성하라. [프로그램설명]
- 배열 : 2×3×4 크기의 정적배열과 동적배열을 사용
- 함수 : sumAry3D_f1, sumAry3D_f2, sumAry3D_f3, sumAry3D_f4, sumAry3D_f5,
freeAry3D
*/
#include <stdio.h>
#include <stdlib.h>

// Functions
// 정적배열 전달
int sumAry3D_f1( int ary[][3][4], int h, int rows, int cols); // 배열 파라미터
int sumAry3D_f2( int (*ary)[3][4], int h, int rows, int cols ); // 배열 포인터
int sumAry3D_f3( int ary[][3][4], int h, int rows, int cols );

// 동적배열 전달
int sumAry3D_f4( int ***ary, int h, int rows, int cols ); //int ** 
int sumAry3D_f5( int ****ary, int h, int rows, int cols ); // int ***
void freeAry3D(int ***ary, int h, int rows);

// Main

int main(void)
{
    //정적배열(높이2 2행 3열)
    int ary3D[2][3][4] = {
         {  
            {1, 2, 3, 4},
            {2, 3, 4, 5},
            {3, 4, 5, 6}
         },
         {
            {1, 2, 3, 4},
            {2, 3, 4, 5},
            {3, 4, 5, 6}
         }
    };  // 크기 : 2 * 3 * 4 * 4 = 96
    //printf("sizeof(ary3D[][3][4] = %d\n", sizeof(ary3D));
    //동적배열(높이 2 * 3행 * 4열), int ***를 가리키는 포인터
    int h, r, c;
    int ***ary;
    ary = (int ***)malloc(sizeof(int**) * 2);   
    
    for(h = 0; h < 2; h++) {
        ary[h] = (int**)malloc(sizeof(int*) * 3);
    }

    for(h = 0; h < 2; h++) {
        for(r = 0; r < 3; r++) {
            ary[h][r] = (int *)malloc(sizeof(int) * 4);
        }
    }
    for(h = 0; h < 2; h++) {
        for(r = 0; r < 3; r++) {
            for(c = 0; c < 4; c++) {
                ary[h][r][c] = h + r + c;
                printf("ary[%d][%d][%d] = %d\n", h, r, c, ary[h][r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    //정적 배열
    printf("sumAry3D_f1(): %d\n", sumAry3D_f1(ary3D, 2, 3, 4));
    printf("sumAry3D_f2(): %d\n", sumAry3D_f2(ary3D, 2, 3, 4));
    printf("sumAry3D_f3(): %d\n", sumAry3D_f3(ary3D, 2, 3, 4));

    //동적배열
    printf("sumAry3D_f4(): %d\n", sumAry3D_f4(ary, 2, 3, 4));
    printf("sumAry3D_f5(): %d\n", sumAry3D_f5(&ary, 2, 3, 4));

    //동적배열을 f1, f2, f3(정적배열)로 전달할 수 있을까? 테스트해 보라! -> 전달 x
    
    //정적배열을 f4, f5(동적배열)로 전달할 수 있을까? 테스트해 보라! -> 전달 x

    freeAry3D(ary, 2, 3);
    return 0;
}
int sumAry3D_f1( int ary[][3][4], int h, int rows, int cols )
{
    int k, i, j, sum = 0;

    for(k = 0; k < h; k++) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) 
                sum += ary[k][i][j];
        }
    }
    return sum;
}
int sumAry3D_f2( int (*ary)[3][4], int h, int rows, int cols )
{
    int k, i, j, sum = 0;

    for(k = 0; k < h; k++) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) 
                sum += ary[k][i][j];
        }
    }
    return sum;
}
int sumAry3D_f3( int ary[2][3][4], int h, int rows, int cols )
{
    int k, i, j, sum = 0;

    for(k = 0; k < h; k++) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) 
                sum += ary[k][i][j];
        }
    }
    return sum;
}
int sumAry3D_f4( int ***ary, int h, int rows, int cols )
{
    int k, i, j, sum = 0;

    for(k = 0; k < h; k++) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) 
                sum += ary[k][i][j];
        }
    }
    return sum;
}
int sumAry3D_f5( int ****ary, int h, int rows, int cols )
{
    int k, i, j, sum = 0;

    for(k = 0; k < h; k++) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) 
                sum += (*ary)[k][i][j];
        }
    }
    return sum;
}
void freeAry3D(int ***ary, int h, int rows)
{
    int i, j;

    for(i = 0; i < h; i++) {
        for(j = 0; j < rows; j++) {
            free(ary[i][j]);
        }
    }
    for(i = 0; i < h; i++)
        free(ary[i]);

    
    free(ary);
    printf("3d array - free!\n");
}

/* 
-------------error(밑에 출력)-------------

main(18173,0x10cfdde00) malloc: *** error for object 0x100000000: pointer being freed was not allocated
main(18173,0x10cfdde00) malloc: *** set a breakpoint in malloc_error_break to debug
zsh: abort      ./main

*/