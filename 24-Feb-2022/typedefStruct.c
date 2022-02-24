#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    char fName[30];
    char lName[30];
    int age;
    double salary;
    char position[30];
} employee;

int main()
{
    system("clear");

    employee e1;

    strcpy(e1.fName, "John");
    strcpy(e1.lName, "Smith");
    e1.age = 32;
    e1.salary = 23500;
    strcpy(e1.position, "Director");

    printf("Full name: %s %s\n", e1.fName, e1.lName);
    printf("Age: %d\n", e1.age);
    printf("Salary: %.2lf\n", e1.salary);
    printf("Position: %s\n", e1.position);
    
    return 0;
}