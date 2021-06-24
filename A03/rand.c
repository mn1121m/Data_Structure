//난수생성

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("%d\n", rand() % 6 + 1);
    return 0;
}