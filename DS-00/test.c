#include <stdio.h>

//return을 여러개 할 경우 *을 이용한다. 
//그리고 return할 함수인자들을 가져온다. 포인터를 사용하여 주소값을 변경해주면 된다. 
void operation(int x, int y, int *returnSum, int *returnSub, int *returnTimes)
{
    // sum, sub, times

    *returnSum = x + y;
    *returnSub = x - y;
    *returnTimes = x*y;
}

int main(void)
{
    int sum, sub, times;

    operation(3, 4, &sum, &sub, &times);
    printf("%d, %d, %d\n", sum, sub, times);
}