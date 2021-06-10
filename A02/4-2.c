/*
자료구조응용 02. 배열과 포인터

*/

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!(p = malloc(s))) { \
fprintf(stderr, "Insufficient memory.\n"); \
exit(EXIT_FAILURE); \
} 

int main(void)
{
    int i, *pi;
    float f, *pf;
    MALLOC(pi, sizeof(*pi));
    MALLOC(pf, sizeof(*pf));

    *pi = 1024;
    *pf = 3.14;

    printf("an inteager = %d, a float = %f\n", *pi, *pf);
    free(pi);
    free(pf);

    return 0;
}
/*
an inteager = 1024, a float = 3.140000
*/