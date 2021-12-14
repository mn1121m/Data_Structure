/* unsorted -> sorted
data structure
*/ 
#include <stdio.h>

void printAry(int *ary, int size);
void selectionSort(int *ary, int size);
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
    return 0;   
}

void printAry(int * ary, int size)
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