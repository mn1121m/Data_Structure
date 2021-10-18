/* 2018117610 문준용

9. [구조체] 다음 코드를 이용하여, 실행 예와 같은 결과를 나타내는 프로그램을 작성하라.
 단 humansEqual 함수를 다음과 같이 수정하여 사용해야 한다.
 수정된 함수원형 : int humansEqual(humanBing *person1, humanBeing *person2);
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1

#define MAX_NAME_SIZE 1024

//  Data structrue
typedef struct _humanBing {
    char name[MAX_NAME_SIZE];
    int age;
    int salary;
} humanBing;

//  Functions
int humansEqual(humanBing *person1, humanBing *person2);

//  Main
int main(void)
{
    humanBing p1, p2;   //  p1: person1, p2: person2
    bool flag;

    //  input of person1
    printf("input person1's name, age, salay : \n");
    fgets(p1.name, sizeof(p1.name), stdin);
    scanf("%d", &p1.age);
    scanf("%d", &p1.salary);
    getchar();

    //  input of person2
    printf("input person2's name, age, salay : \n");
    fgets(p2.name, sizeof(p2.name), stdin);
    scanf("%d", &p2.age);
    scanf("%d", &p2.salary);
    getchar();

    //  print
    flag = humansEqual(&p1, &p2);
    if(flag)
        printf("The two human beings are the same\n");
    else
        printf("The two human beings are not the same\n");

    return 0;
}
//  Functions
int humansEqual(humanBing *person1, humanBing *person2)
{
    /*
        return TRUE if person1 and person2 are the same human
        being otherwise return FALSE
    */
    if(strcmp(person1->name, person2->name))
        return FALSE;
    if(person1->age != person2->age)
        return FALSE;
    if(person1->salary != person2->salary)
        return FALSE;
    return TRUE;
}
/* result
input person1's name, age, salay : 
Hong Gil Dong
40
350
input person1's name, age, salay : 
Kim Su Mi
60
400
The two human beings are not the same

-------------------------------------
input person1's name, age, salay : 
Hong Gil Dong 
40
400
input person2's name, age, salay : 
Hong Gil Dong
40
400
The two human beings are the same
*/