//0907 remind
//1 (2) 2차원 배열과 배열포인터
#include <stdio.h>

int main(void)
{
    int ary2D[][3] = {4,2,3, 5,2,3}, i, j;
    int (*p)[3] = ary2D;
    int ary2D_row = sizeof(ary2D) / sizeof(ary2D[0]);
    int ary2D_col = sizeof(ary2D[0]) / sizeof(ary2D[0][0]);

    printf("ary를 이용한 출력\n");
    for(i = 0; i < ary2D_row; i++) {
        for(j = 0; j < ary2D_col; j++) {
            printf("%d ", ary2D[i][j]);
        }
        printf("\n");
    }
    
    printf("\np를 이용한 출력\n");
    for(i = 0; i < ary2D_row; i++) {
        for(j = 0; j < ary2D_col; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
ary를 이용한 출력
4 2 3 
5 2 3 

p를 이용한 출력
4 2 3 
5 2 3 
*/