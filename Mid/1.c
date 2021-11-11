/* 2018117610 moonjunyong 
1.c 

Q&A :result -> error
*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 3
#define MAX_STACKS 3
#define MAX_NAME_SIZE 10

// Data structure
typedef struct {
	char name[MAX_NAME_SIZE];
}element;
element game_stack[MAX_STACKS][MAX_STACK_SIZE];

// Global variable
int top[MAX_STACKS] = {-1, -1, -1};
int fullOutput[3]= {0,};
int inputOutData[10]={0,};

// Functions
int push(int v1, element item, int i);
void inputData();
void stackFull();
void inputOut();
void result();
void pop();

// Main
int main(){
	inputData();
	inputOut();
	result();
	
	return 0;
}

// Functinos
void inputData(){
	int i, j, v1;
	char inputName[MAX_NAME_SIZE];
	element temp;
	
	printf("--------------input data--------------\n");
	for(i = 0; i < 3; i++){
		scanf("%d", &v1);
		while(1){
			scanf("%s", inputName);
			if(!strcmp(inputName,"0")){
				break;
			}
			else if(!strcmp(inputName,"end")){
				stackFull();
				return;
			}
			strcpy(temp.name, inputName);
			if(push(v1-1, temp, i))
				continue;
		}
	}
}

int push(int v1, element item, int i){
	if(top[v1] >= MAX_STACK_SIZE-1){
		fullOutput[i]= v1+1;
		return 1;
	}
	game_stack[v1][++top[v1]] = item;
	return 0;
}

void stackFull(){
	int i;
	printf("--------------stackFull--------------\n");
	for(i=0;i<3;i++)
		if(fullOutput[i]!=0)	
			printf("%d stackFull\n", fullOutput[i]);
}

void inputOut(){
	char temp[10];
	static int index = 0;
	printf("--------------inputOut--------------\n");
	scanf("%s", temp);
	while(strcmp(temp, "end") && index <9){
		inputOutData[index++] = temp[0]-'0';
		scanf("%s", temp);
	}
}

void result(){
	int i;
	printf("--------------result--------------\n");
	for(i=0;inputOutData[i];i++){
		pop(inputOutData[i]);
	}
}

void pop(int v1){
	if(top[v1-1] <=-1)
		printf("stackEmpty\n");
	else
	 printf("%s\n", game_stack[v1-1][top[v1-1]--]);
}