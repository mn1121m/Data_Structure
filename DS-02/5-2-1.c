//remind 5-1 MACRO - swap, compare O

#include <stdio.h>

#define MAX_ARY_SIZE 1024
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x,y) ( ((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)

// Functions
void selectSort(int *ary, int size);
void print_ary(int *ary, int size);
int binarySearch(int *ary, int left, int right, int value);

// Main
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
    printf("The search number is present in list[%d]", binarySearch(ary, 0, n, searchNum));

    return 0;
}

//Functions
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

int binarySearch(int *ary, int left, int right, int value)
{
    int middle = (left + right) / 2;

    if(left <= right) {
        switch(COMPARE(ary[middle], value)) {
            case 1:
                return binarySearch(ary, 0, middle -1, value);
                break;
            case 0:
                return middle;
                break;
            case -1:
                return binarySearch(ary, middle +1, right, value);
                break;
        }
    }
    return -1;
}