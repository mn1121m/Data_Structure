/* remind
data structure
04. 배열, 구조체, 다항식더하기

4. [구조체] 다음 코드를 이용하여, 실행 예와 같은 결과를 나타내는 프로그램을 작성하라. 단 humansEqual 함수를 다음과 같이 수정하여 사용해야 한다. (1점)
수정된 함수원형 : int humansEqual(humanBing *person1, humanBeing *person2);

[약점]
 - fgets() , scanf() -> getchar()
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define MAX_NAME_SIZE 32

typedef struct _humanbeing {
    char name[MAX_NAME_SIZE];
    int age;
    float salary;
} humanBeing;

int humansEqual(humanBeing *person1, humanBeing *person2);

int main(void)
{
    humanBeing person1, person2;
    int flag;

    printf("Input person1's name, age, salary :\n");
    fgets(person1.name, sizeof(person1.name), stdin);
    scanf("%d", &person1.age);
    scanf("%f", &person1.salary);
    getchar();

    printf("Input person2's name, age, salary :\n");
    fgets(person2.name, sizeof(person2.name), stdin);
    scanf("%d", &person2.age);
    scanf("%f", &person2.salary);

    flag = humansEqual(&person1, &person2);

    if(flag)
        printf("The to human beings are the same\n");
    else 
        printf("The to human beings are not the same\n");
    return 0;
}
int humansEqual(humanBeing *person1, humanBeing *person2)
{
    if(strcmp(person1->name, person2->name))
        return FALSE;
    if(person1->age != person2->age)
        return FALSE;
    if(person1->salary != person2->salary)
        return FALSE;
    return TRUE;  
}
/*
1)
Input person1's name, age, salary :
hong gil dong 
40
400
Input person2's name, age, salary :
hong gil dong
40
400
The to human beings are the same
=======================================
2)
Input person1's name, age, salary :
hong gil dong
40
350
Input person2's name, age, salary :
kim su mi 
60
400
The to human beings are not the same
*/