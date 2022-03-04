#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 37

typedef struct{
	char name[15];
	char surname[15];
	char pl[9];
}person;

int binarysearch(person ar[], int start, int end, char searchingplate[], int *posandcomp) 
{ 
	int middle;
	int comp = 0;
	
	while(start <= end) 
	{
		middle = (start + end) / 2;
		
		if(strcmp((ar+middle)->pl, searchingplate) == 0)
		{
			comp++;
			posandcomp[0] = middle;
			posandcomp[1] = comp;
		return (*posandcomp);
		}
		else
		{
			if (strcmp((ar+middle)->pl, searchingplate) == 1)
			{
				comp++;
				end = middle - 1;
			}
			else
			{
				start = middle + 1;
				comp++;
			}
		}
	}
	posandcomp[0] = -1;
	posandcomp[1] = comp;
	return -1;
}

int main()
{
	FILE *plate;
	int i = 0, j, ar[2];
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
			
			binarysearch(people, 0, SIZE, searchingplate, ar);
			j = ar[0];
			
			if(j==-1)
			{
			printf("NOT FOUND\n");
			printf("%d comparisons.\n\n", ar[1]);
			}
			else
			{
			printf("%s %s %s\n", (people+j)->name, (people+j)->surname, (people+j)->pl); //(people+j)->surname, 
			printf("%d comparisons.\n\n", ar[1]);
			}
			
		}while(searchingplate != "END");
		
		
	}
	fclose(plate);
	free(people);
	
	return 0;
}
