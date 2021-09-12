/*
자료구조응용 02. 배열과 포인터

5. 다음과 같은 프로그램을 두 가지 버전으로 작성하시오. [실행순서]
1 사용자로부터 난수생성 개수(n)를 입력받는다.
2 정수 난수를 n개 발생시켜 1차원 배열에 저장한다.
3 1차원 배열에 대해 선택정렬(selection sort)을 수행한다.
4 사용자로부터 임의의 정수를 입력받는다.
5 입력받은 정수가 배열에 있는지 이진탐색(binary search)을 수행하여 그 결과를 출력한다.

다시(ok)
*cf) COMPARE 쓰는 이유: strcmp같은 함수도 이용할때 쓸 수있기 때문.

*/
#include <stdio.h>

#define MAX_ARY_SIZE 128
#define COMPARE(x, y) ( (x) > (y) ? 1: (x < y ? -1 : 0 ) )

void swap(int *a, int *b, int *temp);
void selection_sort(int *ary, int size);
int binary_sort(int *ary, int size, int value);
void print_ary(int *ary, int size);

int main(void)
{
    int n, ary[MAX_ARY_SIZE], i, search_num, num;

    printf("Enter the number of numbers to generate : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    printf("\nSorted array:\n");
    selection_sort(ary, n);
    print_ary(ary, n);

    printf("\nEnter the number to search : ");
    scanf("%d", &num);

    search_num = binary_sort(ary, n, num);
    printf("The search number is present in  list[%d]", search_num);

    return 0;
}
void swap(int *a, int *b, int *temp)
{
    *temp = *a;
    *a = *b;
    *b = *temp;
}
void selection_sort(int *ary, int size)
{
    int i, j, temp, minIdx;

    for(i = 0; i < size; i ++) {
        minIdx = i;
        for(j = i+1; j < size; j++) 
            if(ary[minIdx] > ary[j])
                minIdx = j;
        swap(&ary[i], &ary[minIdx], &temp); //중요 주소값을 전달해서 포인터를 이용하여 값을 변경한다. 
    }
}
int binary_sort(int *ary, int size, int value)
{
    int  left = 0, right = size - 1, middle;

    while(left <= right) {
        middle = (left + right) / 2;
        switch(COMPARE(ary[middle], value)) {
            case 1: right = middle - 1;    break;
            case 0: return middle; break;
            case -1: left = middle + 1;    break;
        }
        // if(ary[middle] > value) right = middle - 1;
        // else if(ary[middle] == value) return middle;
        // else left = middle + 1;
    }
    return -1;
}
void print_ary(int *ary, int size)
{
    int i;
    
    for(i = 0; i < size; i ++) {
        printf("%d ", ary[i]);
    }
    printf("\n");
}
/*
Enter the number of numbers to generate : 10
41 169 334 358 464 467 478 500 724 962

Sorted array:
41 169 334 358 464 467 478 500 724 962 

Enter the number to search : 962
The search number is present in  list[9]% 
*/