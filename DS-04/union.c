/* union - the biggest in the union's bytess

*/
#include <stdio.h>

int main()
{
    union test {
        int k1;
        double k2;

    }u;

    u.k1 = 4;

    printf("%d\n", sizeof(u));
    printf("%d\n", u.k1);
    
    return 0;   
}