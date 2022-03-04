//This program takes a plate and found who is connected with it.
//then displays comparison numbers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 37

typedef struct{ //to seperate names and plates in text file
	char name[15];
	char surname[15];
	char pl[9];
}person;

//This function search the person of plate sequentially 
int search(person ar[], int size, char searchingplate[])
{
	int k = 0;
	
	while ((k < size) && (strcmp((ar+k)->pl, searchingplate)!=0))
	k++;
		
	if (k == size)
	return -1;
	
	return k;
}


int main()
{
	FILE *plate;
	int i = 0, j;
	person *people;
	char *searchingplate;
	
	searchingplate = (char *)malloc(9 * sizeof(char));
	people = (person *)malloc(SIZE * sizeof(person));
	
	plate = fopen("plates.txt", "r");
	if(plate==NULL)
	printf("CANNOT OPEN");
	else
	{
		for(i=0; i<SIZE; i++)
		{
		fscanf(plate, "%s %s %s", &(people+i)->name, &(people+i)->surname, &(people+i)->pl); //maybe  &(people+i)->surname,
		}
		
		
		do
		{
			printf("Enter plate of a car (END for exit): ");
			scanf("%s", searchingplate);
			if(searchingplate[0]=='E' && searchingplate[1]=='N'&& searchingplate[2]=='D')
			break;
			
			j = search(people, SIZE, searchingplate);
		
			
			if(j==-1)
			{
			printf("NOT FOUND\n");
			printf("%d comparisons.\n\n", SIZE);
			}
			else
			{
			printf("%s %s %s\n", (people+j)->name, (people+j)->surname, (people+j)->pl); //(people+j)->surname, 
			printf("%d comparisons.\n\n", j+1);
			}
			
		}while(searchingplate != "END");
		
		
	}
	fclose(plate);
	free(people);
	
	return 0;
}
