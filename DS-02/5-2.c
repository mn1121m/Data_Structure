/*
자료구조응용 02. 배열과 포인터
*/
/*
자료구조응용 02. 배열과 포인터

5. 다음과 같은 프로그램을 두 가지 버전으로 작성하시오. [실행순서]
1 사용자로부터 난수생성 개수(n)를 입력받는다.
2 정수 난수를 n개 발생시켜 1차원 배열에 저장한다.
3 1차원 배열에 대해 선택정렬(selection sort)을 수행한다.
4 사용자로부터 임의의 정수를 입력받는다.
5 입력받은 정수가 배열에 있는지 이진탐색(binary search)을 수행하여 그 결과를 출력한다.

다시()
*/
#include <stdio.h>

#define MAX_ARY_SIZE 128
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#define COMPARE(x, y) ( (x) > (y) ? 1: (x < y ? -1 : 0 )) 

void selection_sort(int *ary, int size);
int binary_sortR(int *ary, int left, int right, int value);
void print_ary(int *ary, int size);
int main(void)
{
    int n, ary[MAX_ARY_SIZE], i, search_num, num;

    printf("Enter the number of numbers to generate : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    selection_sort(ary, n);
    printf("\nSorted array:\n");
    print_ary(ary, n);

    printf("\nEnter the number to search : ");
    scanf("%d", &num);

    search_num = binary_sortR(ary, 0, n, num);
    printf("The search number is present in  list[%d]", search_num);

    return 0;
}
void selection_sort(int *ary, int size)
{
    int i, j, temp, minIdx;

    for(i = 0; i < size; i ++) {
        minIdx = i;
        for(j = i+1; j < size; j++) 
            if(ary[minIdx] > ary[j])
                minIdx = j;
        SWAP(ary[i], ary[minIdx], temp);
    }
}
int binary_sortR(int *ary, int left, int right, int value)
{
    int middle = (left + right) / 2;

    if(left <= right) {
        switch(COMPARE(ary[middle], value)) {
            case 1: 
                return binary_sortR(ary, 0, middle - 1, value); 
                break;
            case 0: 
                return middle; 
                break;
            case -1:
                return binary_sortR(ary, middle + 1, right, value); 
                break;
        }
        // if(ary[middle] > value) 
        //     return binary_sortR(ary, 0, middle - 1, value);
        // else if(ary[middle] == value)
        //     return middle;
        // else
        //     return binary_sortR(ary, middle + 1, right, value);
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

Enter the number of numbers to generate : 10
1 4 5 2 3 7 6 9 8 10

Sorted array:
1 2 3 4 5 6 7 8 9 10 

Enter the number to search : 10
*/
