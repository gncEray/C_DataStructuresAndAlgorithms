//This program takes an employee's informations as strings then increase salary with user's choice amount
// then show all information in data types of both integers and strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a struct with string elements
typedef struct{
	char name[20];
	char surname[20];
	char id[10];
	char age[3];
	char salary[6];
	char department[40];
}employee;

int main()
{
	char increase[4];
	int number, salary, id, age;
	employee person;
	
	printf("Enter an employee: ");
	scanf("%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]", person.name, person.surname, &person.id, &person.age, &person.salary, &person.department);
	printf("Enter increase in the salary: ");
	scanf("%s", &increase);
	
	//Convert strings to integers
	number = atoi(increase);
	id = atoi(person.id);
	age = atoi(person.age);
	salary = atoi(person.salary);
	
	salary += number;
	
	printf("Employee Information\n--------------------\n");
	printf("Name : %s\nSurname : %s\nEmployee ID : %s\nAge : %s\nSalary : %d\nDepartment : %s", person.name, person.surname, person.id, person.age, salary, person.department);
	
	return 0;
}
