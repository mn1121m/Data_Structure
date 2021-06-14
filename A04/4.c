/*
4. [구조체] 다음 코드를 이용하여, 실행 예와 같은 결과를 나타내는 프로그램을 작성하라. 단 humansEqual 함수를 다음과 같이 수정하여 사용해야 한다. (1점)
수정된 함수원형 : int humansEqual(humanBing *person1, humanBeing *person2);

*/
#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct _humanbeing {
    char name[MAX_NAME_SIZE];
    int age;
    float salary;
} humanBeing;

int main(void)
{
    humanBeing person1, person2;

    printf("Input person1's name, age, salary : \n");
    

    return 0;
}