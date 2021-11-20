/*
자료구조응용
11. Equivalence Class, Doubly Linked Circular List
*Task*
1. 다음과 같이 집합 S에 대한 동치관계(equivalence relation, ≡)
 가 성립할 때 S의 동치류 (equivalence class)를 구하는 프로그램을 작성하라.
 연결리스트를 이용하여야 한다. 출력은 실행 예와 같아야 한다.
    S = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    0≡4, 3≡1, 6≡10, 8≡9, 7≡4, 6≡8, 3≡5, 2≡11, 11≡0

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

typedef struct node* nodePointer;
typedef struct node {
   int data;
   nodePointer link;
}node;


void bubble_sort(int arr[], int count);

int main(void)
{
   short int out[MAX_SIZE];
   nodePointer seq[MAX_SIZE];
   nodePointer x, y, top;
   int i, j, n;

   int s;
   int num;
   scanf("%d", &s);
   scanf("%d", &num);
   for (int k = 0; k < s; k++) {
      out[k] = FALSE; seq[k] = NULL;
   }

   for (int k = 0; k < num; k++) {
      scanf("%d %d", &i, &j);
      x = malloc(sizeof(*x));
      x->data = j;
      x->link = seq[i];
      seq[i] = x;
      x = malloc(sizeof(*x));
      x->data = i;
      x->link = seq[j];
      seq[j] = x;
   }
   int arr[MAX_SIZE];
   int count=0;
   int arr1[MAX_SIZE];
   int count1 = 0;
   int count2 = 0;
   for (int k = 0; k < s; k++) {
      if (out[k] == FALSE) {
         arr[count++] = k;
         out[k] = TRUE;
         x = seq[k]; top = NULL;
         while (1) {
            while (x) {
               j = x->data;
               if (out[j] == FALSE) {
                  arr[count++] = j;
                  out[j] = TRUE;
                  y = x->link; x->link = top; top = x; x = y;
               }
               else {
                  x = x->link;
               }
            }
            if (!top) {
               arr1[count1++] = count;
               count2++;
               break;
            }
            else {
               x = seq[top->data]; top = top->link;
            }
         }
      }
   }

   bubble_sort(&arr[0], arr1[0]);
   for (int i = 1; i < count2; i++) {
      bubble_sort(&arr[arr1[i - 1]], arr1[i] - arr1[i - 1]);
   }


   for (int i = 0; i < arr1[0]; i++) {
      printf("%d", arr[i]);
      if (i != arr1[0] - 1) {
         printf(" ");
      }
   }
   printf("\n");
   for (int i = 1; i < count2; i++) {
      for (int j = arr1[i-1]; j < arr1[i]; j++) {
         printf("%d", arr[j]);
         if (j != arr1[i] - 1) {
            printf(" ");
         }
      }
      printf("\n");
   }


   return 0;
}

void bubble_sort(int arr[], int count)
{
   int temp;

   for (int i = 0; i < count; i++)
   {
      for (int j = 0; j < count - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}
/* result
12
9
0 4
3 1
6 10
8 9
7 4
6 8
3 5
2 11
11 0
0 2 4 7 11
1 3 5
6 8 9 10
*/