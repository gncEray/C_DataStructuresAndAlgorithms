#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char city[20];
	char country[20];
	int population;
}cities;

int readAndWrite(cities str[], FILE* file, FILE* binary)
{
	file = fopen("cities.txt", "r");
	int cntcity;
	int i = 0, k=0;
	
	while(fscanf(file, "%s %s %d", str[i].city, str[i].country, &str[i].population) != EOF)
	{
		i++;
	}
	
	binary = fopen("binarycity.bin", "wb");
	
	
	fwrite(&str[k], sizeof(cities), i, binary);
		
	
	fclose(file);
	fclose(binary);
	
	return i;
}


int binarySearch(cities str[], int top, int bottom, char town[])
{
	int middle = (top + bottom) / 2;
	
	if(strcmp(str[middle].city, town) == 0)
	return middle;
	else if(strcmp(str[middle].city, town) == 1)
	return (binarySearch(str, top, middle-1, town));
	else if(strcmp(str[middle].city, town) == -1)
	return (binarySearch(str, middle+1, bottom, town));
	
	return -1;
}



int main()
{
	int i, j, k, cntofcity, citynumber;
	FILE *file, *binary;
	cities str[50];
	char cityname[20];
	
	cntofcity = readAndWrite(str, file, binary);
	
	printf("Enter a city name: ");
	scanf("%s", cityname);
	
	citynumber = binarySearch(str, 0, cntofcity, cityname);
	
	printf("%s %s %d", str[citynumber].city, str[citynumber].country, str[citynumber].population);
	
	return 0;
		
}
