#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[10];
	int age;
	double gpa;
}student;

int main()
{
	int i=0, j, k, x, n, num, numbers, choice;
	FILE* file, *binary;
	student stu[20], newstu[20], new_stu;
	
	file = fopen("info.txt", "r");
	if(file == NULL)
	printf("NOT EXIST");
	else
	{	
	
		binary = fopen("binary.bin", "wb");
		i=0;
		while(fscanf(file, "%s %d %lf", stu[i].name, &stu[i].age, &stu[i].gpa) != EOF)
		{
			fwrite(&stu[i], sizeof(student), 1, binary);
			i++;
		}
	
		fclose(binary);
		
		binary = fopen("binary.bin", "rb");
			
		printf("1) Go to record X from top\n");
		printf("2) Move X records ahead\n");
		printf("3) Go X records back from bottom\n");
		printf("4) Exit\n");
				
		do
		{	
			printf("Enter your choice: ");
			scanf("%d", &choice);
			
			while(choice>4)
			{
				printf("NOT AVAILABLE IN RANGE!\nEnter your choice: ");
				scanf("%d", &choice);
			}
			
			if(choice == 4)
			break;

			printf("Enter X: ");
			scanf("%d", &x);
			
			switch(choice)
			{
				case 1:
					fseek(binary, (x-1) * sizeof(student), SEEK_SET);
				break;
					
				case 2:
					fseek(binary, (x-1) * sizeof(student), SEEK_CUR);
				break;
				
				case 3:
					fseek(binary, (-x) * sizeof(student), SEEK_END);
				break;	
			}
			
			fread(&new_stu, sizeof(student), 1, binary);
			printf("%s %d %4.2f\n", new_stu.name, new_stu.age, new_stu.gpa);
				
			
		}while(choice!=4);
	}
	
	fclose(file);
	fclose(binary);	
	
	return 0;
	
}
