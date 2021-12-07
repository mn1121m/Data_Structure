/* 과제 : A01 ~ A03 */
#include <stdio.h>

int main(void)
{

    int i;
    FILE *fp = fopen("output.csv","w");

    fprintf(fp, "n,time\n");
    for(i = 0; i < 100; i ++) {
        fprintf(fp, "%d,%d\n", i, i*i);
    }

    fclose(fp);
    return 0;
}