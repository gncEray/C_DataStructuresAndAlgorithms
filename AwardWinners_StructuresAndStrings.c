//This program reads name date and store name from a text file. Then show them as award winners.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// a struct to define date separately day, month and year
typedef struct{
	int day, month, year;
}date_t;
// a struct to define name separately name and surname 
typedef struct{
	char firstname[10];
	char secondname[15];
}customername;
// to read information from text as given
typedef struct{
	customername name;
	date_t date;
	char store[30];
}customer;

int main()
{
	int i, num;
	FILE *customersfile;
	customer *winners;
	
	winners = (customer *) malloc (10 * sizeof(customer));
	
	customersfile = fopen("customers.txt", "r");
	if(customersfile==NULL)
	printf("File does not exist");
	else
	{
		for(i=0; i<6; i++)
		fscanf(customersfile, "%s %[^-]--%d/%d/%d--%[^\n]", &(winners+i)->name.firstname ,&(winners+i)->name.secondname, 
		&(winners+i)->date.day, &(winners+i)->date.month, &(winners+i)->date.year, &(winners+i)->store);
	}

	printf("AWARD WINNING CUSTOMERS\n");
	printf("------------------------------------------------\n");

	for(i=0; i<6; i++){
		printf("%d/0%d ", (winners+i)->date.day, (winners+i)->date.month);
		
		num = strlen((winners+i)->name.firstname) + strlen((winners+i)->name.secondname); //calculate total length 
		
		if(num > 12)
		printf("%c. %s\t", (winners+i)->name.firstname[0], (winners+i)->name.secondname);
		else
		printf("%s %s\t", (winners+i)->name.firstname, (winners+i)->name.secondname);
		
		printf(" %s\n", (winners+i)->store);
	}
	fclose(customersfile);
	free(winners);
	
	return 0;
}
