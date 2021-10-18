/* 문제 11  다시(ok)(ok)
수를 입력 받고 이를 반드시 selection sort를 수행 후 출력하고 그 뒤 입력되는 수(searchNum)의 인덱스를 출력(반드시 binarySearch를 사용)하시오.
(기본적으로 모든 수의 출력은 %2d를 사용하시오.)

[Cf] 
- 출력할때 "%2d" 로 출력할 것.
- getchar('\n') or printf("\n") 으로 개행문자 확인
*/
#include <stdio.h>

// Function
void selection_sort();
void print_ary(int *ary, int size);
int binsearch(int *ary, int size, int value);

// Main
int main(void)
{
    int num_size;  //입력되는 수의 갯수
    int i, num, search_num;

    scanf("%d", &num_size); //5
    int ary[num_size];

    for(i = 0; i < num_size; i++) {
        scanf("%d", &ary[i]);
    }
    selection_sort(ary, num_size);
    print_ary(ary, num_size);

    //searchNum 입력
    scanf("%d", &search_num);
    printf("%2d\n", binsearch(ary, num_size, search_num));
    return 0;
}
// Function
void selection_sort(int *ary, int size)
{
    int i, temp, min, j;

    for(i = 0; i < size; i++) {
        min = i;
        for(j = i+1; j < size; j++) {
            if(ary[j] < ary[min])
                min = j;
        }
        temp = ary[min];
        ary[min] = ary[i];
        ary[i] = temp;
    }
}
void print_ary(int *ary, int size)
{
    int i;

    for(i = 0; i < size; i++) {
        printf("%2d", ary[i]);
    }
    putchar('\n');
}
int binsearch(int *ary, int size, int value)
{
    int left = 0, right = size - 1;
    int middle;

    while(left <= right) {
        middle = (left + right) / 2;
        if(ary[middle] < value)
            left = middle +1;
        else if (ary[middle] == value) return middle;
        else
            right = middle -1;
    }
    return -1;
}
/* result
Ex
5 //입력되는 수의 갯수(1~9)
1
3
5
2
9
1 2 3 5 9 //출력
3 //searchNum 입력
2 //searchNum의 인덱스 출력
*/