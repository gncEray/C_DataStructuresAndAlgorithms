/*
	structure
	recursive bubble sort function
	recursive binarysearch function
 	
 	main
 	read employee data from a text 
 	sort them with bubble func
 	take ID and find with binarySearch function
 	display ID NAME SALARY
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char name[15];
	char surname[15];
	int salary;	
}employee;

void swap(employee *a, employee *b)
{
	employee temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

void bubblesort(employee str[], int n)
{
	int pass, k;
	
	if(n==1)
	return;
	else
	{
		for(k=0; k<n-1; k++)
		{
			if(str[k].id > str[k+1].id)
			{
				swap(&str[k], &str[k+1]);
			}
		}
	}
	
	bubblesort(str, n-1);
}
/*
void bubblesort(employee list[], int n)
{
	int pass, k;
	for (pass = 1; pass <= n - 1; pass++)
		for (k = 0; k < n - pass; k++)
		if (list[k].id > list[k+1].id)
		{
			swap(&list[k], &list[k+1]);
		}
		
}
*/

int binarySearch(employee str[], int top, int bottom, int num)
{
	int middle, ctrl = -1;
	middle = (top + bottom) / 2;
	
	if(str[middle].id == num)
	ctrl = (middle);
	else if(str[middle].id > num)
	ctrl = (binarySearch(str, top, middle-1, num));
	else if((str[middle].id < num))
	ctrl = (binarySearch(str, middle+1, bottom, num));
	
	return ctrl;
}

int main()
{
	FILE *file;
	int i, j, k, num, ctrl;
	employee str[25];
	char filename[25];
	
	printf("Enter the file name: ");
	scanf("%s", filename);
	
	file = fopen(filename, "r");
	while(file == NULL)
	{
		printf("File not found Enter again: ");
		scanf("%s", filename);
		file = fopen(filename, "r");
	}
	
	
	i = 0;
	while(fscanf(file, "%d %s %s %d", &str[i].id, str[i].name, str[i].surname, &str[i].salary) != EOF)
	i++;
	
	bubblesort(str, i);
	
	do
	{
		printf("Enter an employee id (-1 to stop): ");
		scanf("%d", &num);
	
		if(num==-1)
		break;
		
		ctrl = binarySearch(str, 0, i, num);
		
		if(ctrl == -1)
		printf("ID not found!!!\n");
		else
		{
			printf("\nSearch Result\n*************\n");
			printf("%d %s %s %d\n\n", str[ctrl].id, str[ctrl].name, str[ctrl].surname, str[ctrl].salary);
		}
		
	}while(num!=-1);
	
	
	fclose(file);
	
	return 0;
}



