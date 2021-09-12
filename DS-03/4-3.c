/* 난수생성 - remind(ok)

4. 3번 소스에 대해 데이터 생성부분을 일부 수정하여 
다음 세 가지 경우에 대해 성능측정을 하여 비교하라. 
그리고 selection sort 알고리즘의 경우 worst-case, best-case, average-case data의 구분이 있는지 기술하라.
(3) 입력데이터를 난수생성으로 만들어 사용하는 경우 [ 프로젝트명:4-3 ]
    for( i = 0; i < n ; i++)
         a[i] = rand() % n;

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1001

int main(void)
{
    FILE *fp = fopen("output4-3.csv","w");
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

            /* inisialize with average-case data data */ 
            for( i = 0; i < n ; i++)
                a[i] = rand() % n;


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
