#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 8

void readFromFile(FILE *file, char phnums[][15])
{
	int i=0;

	while(fscanf(file, "%s", &phnums[i]) != EOF)
	{
		i++;
	}
}

void updateDirectory(char phnumbers[][15], int size)
{
	int i, j = 0, k;

	char temp[15], arr[15];
	char areacode[] = "(312) ";
	
	for(k=0; k<size; k++)
	{
		if(strlen(phnumbers[k])==10)
		{
			j=0;
			temp[0] = '\0';
			for(i=3; i<10; i++)
			temp[j++] = phnumbers[k][i];
			
			strcpy(phnumbers[k], areacode);
			strcat(phnumbers[k], temp);
			
			phnumbers[k][14] = '\0';
		}
		else
		{
			j = 0;
			temp[0] = '\0';
			for(i=0; i<7; i++)
			temp[j++] = phnumbers[k][i];
			
			strcpy(phnumbers[k], areacode);
			strcat(phnumbers[k], temp);
		
			phnumbers[k][14] = '\0';
		}
	}
}


void printDirectory(char phnumbers[][15], int size)
{
	int j;
	printf("There are %d phone numbers in the directory\n", SIZE);
	
	for(j=0; j<size; j++)
	printf("%s\n", phnumbers[j]);
}

int main()
{
	FILE *numbersfile;
	char phonenumbers[SIZE][15];
	int a, i;
	
	numbersfile = fopen("phones.txt", "r");
	if(numbersfile==NULL)
	printf("FILE CANNOT FOUND");
	else
	{
		readFromFile(numbersfile, phonenumbers); 
		updateDirectory(phonenumbers, SIZE);
		printDirectory(phonenumbers, SIZE);
	}
	fclose(numbersfile);
	
	return 0;
}
