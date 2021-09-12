//remind 4-1

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, *pi;
    float f, *pf;

    pi = (int *) malloc(sizeof(int));
    pf = (float *)malloc(sizeof(float));

    if( !(pi = (int *) malloc(sizeof(int))) 
    || !(pf = (float *) malloc(sizeof(float))) )
    {
        fprintf(stderr, "Insufficient memory.\n");
        exit(EXIT_FAILURE);
    }
    *pi = 1024;
    *pf = 3.14;
    
    printf("an integer = %d, a float = %f\n", *pi, *pf);

    free(pi);
    free(pf);
    return 0;
}