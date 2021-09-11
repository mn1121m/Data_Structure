// remind

#include <stdio.h>

int sumAry1D_f1( int ary[], int size ); // 배열파라미터, 배열크기
int sumAry1D_f2( int *ary, int size ); // 배열포인터, 배열크기
int sumAry1D_f3( int ary[6], int size );

int  main(void)
{
    int ary1D[] = {1, 2, 3, 4, 5, 6};
    int ary_size = sizeof(ary1D) / sizeof(ary1D[0]);

    printf("sumAry1D_f1() %d\n", sumAry1D_f1(ary1D, ary_size));
    printf("sumAry1D_f2() %d\n", sumAry1D_f1(ary1D, ary_size));
    printf("sumAry1D_f3() %d\n", sumAry1D_f1(ary1D, ary_size));

    return 0;
}
int sumAry1D_f1( int ary[], int size )
{
    int i, sum = 0;

    for(i = 0; i < size; i++) {
        sum += ary[i];
    }
    return sum;
}
int sumAry1D_f2( int *ary, int size )
{
        int i, sum = 0;

    for(i = 0; i < size; i++) {
        sum += ary[i];
    }
    return sum;
}
int sumAry1D_f3( int ary[6], int size )
{
        int i, sum = 0;

    for(i = 0; i < size; i++) {
        sum += ary[i];
    }
    return sum;
}

