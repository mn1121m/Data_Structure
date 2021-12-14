/* 21_09_08 => remind
data structure
01. 배열과 포인터

2. 다음과 같은 자료구조를 생성하는 코드를 작성하고, 배열요소의 역참조를 이용해서 a, b, c의 값을 출력하는 문장을 추가하라.
단, 변수 a, b, c는 int형이며 포인터 배열을 사용하라
*/
#include <stdio.h>
#include <stdlib.h>

// Functions

// Main
int main(void)
{
    int ary[] = {2, 3, 4};
    int *a = ary, *b = ary + 1, *c = ary + 2;
    printf("포인터 배열의 배열요소를 이용한 a, b, c 출력\n");

    printf("a : %d, b : %d, c : %d\n", *a, *b, *c);

    return 0;
}
