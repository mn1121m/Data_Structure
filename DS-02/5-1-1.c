//remind 5-1 swap, compare X

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARY_SIZE 1024

void selectSort(int *ary, int size);
void print_ary(int *ary, int size);
int binarySearch(int *ary, int size, int value);

int main(void)
{
    int n, i;
    int ary[MAX_ARY_SIZE];
    int searchNum;

    printf("Enter the number of number to generate: ");
    scanf("%d", &n);

    for(i = 0; i < n; i ++) {
        ary[i] = rand() % 1000; // range : 0 ~ 999
    }
    
    //selection_sort
    printf("\nSorted array: ");
    selectSort(ary, n);
    print_ary(ary, n);

    //binary_search
    printf("\nEnter the numver to search : ");
    scanf("%d", &searchNum);
    printf("The search number is present in list[%d]", binarySearch(ary, n, searchNum));

    return 0;
}
void selectSort(int *ary, int size)
{
    int i, j, temp, minIdx;

    for(i = 0; i < size; i ++) {
        minIdx = i;
        for(j = i+1 ; j < size; j++ ) 
            if(ary[j] < ary[minIdx]) {
                minIdx = j;
            }
        temp = ary[minIdx];
        ary[minIdx] = ary[i];
        ary[i] = temp;
    }
}
void print_ary(int *ary, int size)
{
    int i;

    for(i = 0 ; i < size; i ++) {
        printf("%d ", ary[i]);
    }
    putchar('\n');
}
int binarySearch(int *ary, int size, int value)
{
    int left = 0, right = size -1, middle;

    while(left <= right) {
        middle = (left + right) / 2;
        if(ary[middle] < value) left = middle +1;
        else if(ary[middle] == value) return middle;
        else right = middle-1;
    }
    return -1;
}