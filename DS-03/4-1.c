/* remind(ok)
4. 3번 소스에 대해 데이터 생성부분을 일부 수정하여 
다음 세 가지 경우에 대해 성능측정을 하여 비교하라. 
그리고 selection sort 알고리즘의 경우 worst-case, best-case, average-case data의 구분이 있는지 기술하라.
(1) 입력데이터가 내림차순 정렬이 이미 되어 있는 경우(3번 결과 사용)
10 9 8 7 ... 1
*/
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1001

void selectionSort(int *ary, int size);

int main(void)
{
    FILE *fp = fopen("output4-1.csv","w");
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
                a[i] = n - i;   

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