/* 2018117610 moonjunyong 
2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10
#define MAX_NAME_SIZE 10

#define TRUE 1
#define FALSE 0

// Global variable
int foodList[3][20];
int front[3]={-1,-1,-1};
int rear[3]={-1, -1, -1};
int inputOutData[20];

// Functions
void inputData();
void addq(int v1, int v2);
int foodNumber(char temp[]);
void inputOut();
void deleteq();

// Main
int main(){
	inputData();
	inputOut();
	// print
	deleteq();
	return 0;
}

// Functions
void inputData(){
	int i, j, tableNumber;
	char inputName[MAX_NAME_SIZE];
	
	printf("--------------inputData--------------\n");
	for(i=0; i<4; i++){
		scanf("%d", &tableNumber);
		while(TRUE){
			scanf("%s", inputName);
			if(!strcmp(inputName,"0")){
				break;
			}
			else if(!strcmp(inputName,"end")){
				return;
			}
			addq(foodNumber(inputName), tableNumber);//
		}
	}	
}

void addq(int v1, int v2){
	if(rear[v1-1] == MAX_QUEUE_SIZE-1){
		printf("QueueFull");
		return;	
	}
	foodList[v1-1][++rear[v1-1]] = v2;

}

int foodNumber(char temp[]){
	if(!strcmp(temp,"foodA"))
		return 1;
	else if (!strcmp(temp,"foodB"))
		return 2;
	return 3;
	
}

void inputOut(){
	char fName[MAX_NAME_SIZE];
	int index = 0;
	printf("--------------inputOut--------------\n");
	scanf("%s", fName);
	while(strcmp(fName, "end")){
		inputOutData[index++] = foodNumber(fName);
		scanf("%s", fName);
	}
}

void deleteq(){
	int i=0;
	for(i=0;inputOutData[i];i++){
		if(front[inputOutData[i]-1]==rear[inputOutData[i]-1])
			printf("AHH\n");
		else 
			printf("%d\n", foodList[inputOutData[i]-1][++front[inputOutData[i]-1]]);	
		
	}
}

/* result
--------------inputData--------------
1
foodA
foodB
0
4
foodA
foodB
foodC
0
3
foodB
foodC
0
2
foodA
foodB
end
--------------inputOut--------------
foodA
foodA
foodB
foodA
foodB
foodC
foodA
foodB
foodB
foodC
end
1
4
1
2
4
4
AHH
3
2
3
*/