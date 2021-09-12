/* remind(ok)
3. 다음 Program 1.25를 사용하여 선택정렬(Selection Sort)에 대한 성능측정을 하라. 
그리고 프로그램의 실행결과를 이용하여 그래프를 작성하라. 
또한, 문제 2의 결과와 같이 하나의 그래프로 작성해서 비교해 보라.

*중요* - ',' 로 구분해서 출력하면 .csv 에서는 열이 구분되어 값이 표시된다. => 콤마로 나눠진다.
*/
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1001

void selectionSort(int *ary, int size);

int main(void)
{
    FILE *fp = fopen("output.csv","w");
    int i, n, step = 10;
    int a[MAX_SIZE];
    double duration;

    /*times for n = 0, ..., 100, 200, ..., 1000 */
    fprintf(fp, "n,repetitions,time\n");
    for(n = 0; n <= 1000; n += step) {
        /* get time for size n */
        long repetitions = 0;
        clock_t start = clock();
        do {
            repetitions++;

            /* inisialize with worst-case data */ 
            for( i = 0; i < n ; i++)
                a[i] = n - i;   // 10 9 8 7 ...

            selectionSort(a, n);
        } while(clock() - start < 1000);
            /* repeat until enought time has elapsed */
        
        duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        duration /= repetitions;
        fprintf(fp, "%6d,%9ld,%f\n", n, repetitions, duration);
        if(n == 100) step = 100;
    }
    fclose(fp);
    return 0;
}
void selectionSort(int *ary, int size)
{
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