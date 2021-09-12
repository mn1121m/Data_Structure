//remind 4-2

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
if(!((p) = malloc(s))) { \
fprintf(stderr, "Insufficient memory\n"); \
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
    
    printf("an integer = %d, a float = %f\n", *pi, *pf);

   free(pi);
   free(pf);
    return 0;
}