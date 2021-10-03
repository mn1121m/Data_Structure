/* 2018117610 문준용 
4. 다음 Program 1.24를 사용하여 선택정렬(Selection Sort)에 대한 성능측정을 하라. 그리
고 프로그램의 실행결과를 이용하여 그래프를 작성하라.
*/

#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1001

// Functions
void selectionSort(int *ary, int size);

// Main
int main(void)
{
    int i, n, step = 10;
    int a[MAX_SIZE];
    double duration;
    clock_t start;

    /* time for n = 0, 10, ..., 100, 200, ..., 1000 */
    printf("    n      time\n");
    for(n = 0; n <= 1000; n += step)
    {
        /* get time for size n */
        /* initialize with worst-case data */
        for(i = 0; i < n; i ++)
            a[i] = n - i;

        start = clock();
        selectionSort(a, n);
        duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        printf("%6d    %f\n", n, duration);
        if(n == 100) step = 100;
    }

    return 0;
}

// Functions
void selectionSort(int *ary, int size)
{
    // 5 4 3 2 1 => 1 4 3 2 1 => .... => 1 2 3 4 5
    int i, j, minIdx, temp;

    for(i = 0 ; i < size; i++ ){
        minIdx = i;
        for(j = i + 1; j < size; j++) 
            if(ary[j] < ary[minIdx])  
                minIdx = j;
        temp = ary[i];
        ary[i] = ary[minIdx];
        ary[minIdx] = temp; 
    }
}