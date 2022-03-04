#include <stdio.h>
#include <string.h>
#include "stack_char.h" //local header which I modified from given
#define SIZE 30

//This function determines the string is palindrome or not from stack 
int palindrome(stack_t ar)
{
	char item[SIZE];
	int j;
	int size = strlen(pop(&ar, item, SIZE));
	
	for(j=0; j<size/2; j++)
	{
		if(item[j] != item[size-2-j])//takes same steps from beginning and end
		return 0; // if there is different characters, suddenly return 0(it is not palindrome)
	}
	return 1;
}

int main()
{
	FILE* file;
	int i, j=0, k, c, num = 30, cnt=0;
	stack_t stack, reverse;
	char temp[40], words[10][30], late[40];
	
	file = fopen("Palindrome.txt", "r");
	if(file == NULL)
	printf("FILE DOES NOT EXIST");
	else
	{
		initialize_s(&stack);
		initialize_s(&reverse);
		
		for(i=0; i<7; i++)
		{	
			fgets(temp, SIZE, file);//Reads from file and inserts into temporary array
			push(&stack, temp); //Insert from temp array to stack.
		}
		int filesize = i;	
		
		for(i=0; i<filesize; i++)
		{
			if(palindrome(stack) == 1)
			{
				late[0] = '\0';
				pop(&stack, late, num);
				push(&reverse, late);
				cnt++;
			}
			else
			pop(&stack, late, num);//Removes the top element
		}
		
		for(i=0; i<cnt; i++)
		printf("%s", pop(&reverse, late, num));
		
	}
	
	fclose(file);
	
	return 0;
}
