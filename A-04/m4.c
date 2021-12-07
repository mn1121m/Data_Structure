#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define MAX_SIZE_NAME 128

// Data structure
typedef struct {
    char name[MAX_SIZE_NAME];
    int age;
    int salary;
} humanBeing;

// Functions
int humansEqual(humanBeing *person1, humanBeing *person2);

// Main
int main(void)
{
    humanBeing person1, person2;

    printf("Input person1's name, age, salary : \n");
    fgets(person1.name, sizeof(person1.name), stdin);
    scanf("%d", &person1.age);
    scanf("%d", &person1.salary);
    getchar();

    printf("Input person2's name, age, salary : \n");
    fgets(person2.name, sizeof(person2.name), stdin);
    scanf("%d", &person2.age);
    scanf("%d", &person2.salary);
    getchar();

    if(!humansEqual(&person1, &person2)) {
        printf("The two human beings are not the same\n");
    } else 
        printf("The two human beings are the same\n");
    return 0;
}
// Functions
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