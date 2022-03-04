#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i, j, k, n, numbers[500], num;
	FILE *file;
	
	file = fopen("numbers.bin", "wb");
	
	for(i=5; i<=500; i+=5)
	fwrite(&i, sizeof(int), 1, file);
	
	fclose(file);
	
	file = fopen("numbers.bin", "rb");
	if(file==NULL)
	printf("NOT EXIST");
	else
	{
		printf("How many numbers do you want to read: ");
		scanf("%d", &n);
	
		while(n>500 || n<1)
		{
			printf("Enter a number between 1 and 500!\n");
			printf("How many numbers do you want to read: ");
			scanf("%d", &n);
		}
			
			// read with using for loop
			for(i=0; i<n; i++)
			{
				fread(&num, sizeof(int), 1, file);	
				printf("%d ", num);
			}
			// with loop
			
			// read without using loop
			fread(&numbers, sizeof(int), n, file);
			
			for(i=0; i<n; i++)
			printf("%d ", *(numbers+i));
			// without loop
				
	}	
			
	fclose(file);
		
	return 0;
}
