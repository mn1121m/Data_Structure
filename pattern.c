#include <stdio.h>
#include <string.h>

int substing(char *str, char *pat);

int main(void)
{
    char *str = "ababbaabaa";
    char *pat = "aab";

    printf("%d\n", substing(str, pat));

    return 0;
}
int substing(char *str, char *pat)
{
    //ababbaabaa
    //aab
    int i, j, lenStr = strlen(str), lenPat = strlen(pat);

    for(i = 0; i < lenStr - lenPat; i++) {
        for(j = 0; j < lenPat; j++) {
            if(str[i + j] != pat[j]) break;
            if(j == lenPat - 1) return i;
        }
    }
    return -1;
}