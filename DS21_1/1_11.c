/* 문제 11  다시()
수를 입력 받고 이를 반드시 selection sort를 수행 후 출력하고 그 뒤 입력되는 수(searchNum)의 인덱스를 출력(반드시 binarySearch를 사용)하시오.
(기본적으로 모든 수의 출력은 %2d를 사용하시오.)
*/

#include <stdio.h>

//Function
void print_ary(int *ary, int size);
void selection_sort(int *ary, int size);
int binSearch(int *ary, int size, int value);

//Main
int main(void)
{
    int size, i;   // 입력되는 수의 갯수 : size
    int num;    // 입력되는 수 : num
    int search_num;

    scanf("%d", &size);
    int ary[size];

    for(i = 0; i < size; i++) {
        scanf("%d", &num);
        ary[i] = num;
    }
    putchar('\n');
    
    selection_sort(ary, size);
    print_ary(ary, size);
    putchar('\n');

    scanf("%d", &search_num); // searchNum 입력
    printf("%d\n", binSearch(ary, size, search_num));

    return 0;
}

//Function
void selection_sort(int *ary, int size)
{
    int i, j, min, temp;

    for(i = 0; i < size; i ++) {
        min = i;
        for(j = i+1 ; j < size; j ++) {
            if(ary[j] < ary[min])
                min = j;
        }
        temp = ary[i];
        ary[i] = ary[min];
        ary[min] = temp;
    }
}
void print_ary(int *ary, int size)
{
    int i;
    for(i = 0; i < size; i ++) {
        printf("%2d", ary[i]);
    }
}

int binSearch(int *ary, int size, int value)
{
    int middle, left = 0, right = size - 1;
    
    while(left <= right) {
        middle = (left + right) / 2;
        if(ary[middle] > value) right = middle - 1;
        else if(ary[middle] == value) return middle;
        else left = middle + 1;
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