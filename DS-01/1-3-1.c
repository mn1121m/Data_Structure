//0907 remind
// 1 (3) 3차원 배열과 배열포인터 다시(0)
#include <stdio.h>

int main(void)
{
    int ary[2][2][3] = {
        {{1,2,3}, {4,5,6}}, {{7,8,9}, {10,11,12}}
    };
    int (*p)[2][3] = ary, i, j, k;

    int sec_size = sizeof(ary) / sizeof(ary[0]);
    int row_size = sizeof(ary[0]) / sizeof(ary[0][0]);
    int col_size = sizeof(ary[0][0]) / sizeof(ary[0][0][0]);

    printf("ary를 이용한 출력\n");
    for(i = 0; i < sec_size; i ++) {
        for(j = 0 ; j < row_size; j++) {
            for(k = 0; k < col_size; k++) {
                printf("%3d ", ary[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("p를 이용한 출력\n");
    for(i = 0; i < sec_size; i ++) {
        for(j = 0 ; j < row_size; j++) {
            for(k = 0; k < col_size; k++) {
                printf("%3d ", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
/* result
ary를 이용한 출력
  1   2   3 
  4   5   6 

  7   8   9 
 10  11  12 

p를 이용한 출력
  1   2   3 
  4   5   6 

  7   8   9 
 10  11  12 
*/