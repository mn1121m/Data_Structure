/* unsorted -> sorted
data structure
*/
#include <stdio.h>

void printAry(int *ary, int size);
void selectionSort(int *ary, int size);
int binSearch(int *ary, int size, int value);
int binSearchR(int *ary, int left, int right, int value);

/*
    return index of value
    if fail: return -1  (배열에 값이 들어가 있지 않은 경우)
*/
int main(void)
{
    int ary[30];
    int i;

    for( i = 0; i < 30; i++ )
        ary[i] = 30 - i;
    
    printAry(ary, 30);
    putchar('\n');
    selectionSort(ary, 30);
    printAry(ary, 30);

    if(binSearch(ary, 30, 7) != -1 ) {
        printf("there is 7 at %d\n", binSearch(ary, 30 , 7));
    } else {
        printf("there isn't 7\n");
    }
    return 0;   
}

void printAry(int *ary, int size)
{
    int i;

    for(i = 0; i < size; i++) {
        printf("%d ", ary[i]);
    }
}
void selectionSort(int *ary, int size)
{
    // 5 4 3 2 1 => 1 4 3 2 1 => .... => 1 2 3 4 5
    int i, j, minIdx, temp;

    for(i = 0 ; i < size; i++ ){
        minIdx = i;
        for(j = i + 1; j < size; j++) 
            if(ary[j] < ary[minIdx])  
                minIdx = j;
        temp = ary[i];
        ary[i] = ary[minIdx];
        ary[minIdx] = temp; 
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
int binSearchR(int *ary, int left, int right, int value)
{
    int middle = (left + right) / 2;

    if(left <= right ) {
        if(ary[middle] < value) 
            return binSearchR(ary, left, middle - 1, value);
        else if(ary[middle] == value)
            return middle;
        else
            return binSearchR(ary, middle + 1, right, value);
    }
    return -1;
}