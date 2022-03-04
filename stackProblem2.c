//This program takes a sentence from user and ordered its words reversely

#include <stdio.h>
#include <string.h>
#include "stack_char.h"

void reverse(stack_t *ar, char words[][20], int size)
{
	int i, j, k;
	char temp[20];
	
	initialize_s(&*ar);
	
	for(i=0; i<size; i++)
	{
		memmove(temp, words[i], 20);//Because of push() type's second argument is 1D array
		push(&*ar, temp);
		temp[0] = '\0';
	}
	
}


int main()
{
	int i=0, j=0, r=0, c=0;
	char ch, words[10][20], holder[200];
	stack_t sentence;
	
	printf("Enter a string: ");
	scanf("%[^\n]", holder);
	
	int size = strlen(holder);
	int newsize = size;
	
	// This loop separates words from the string
	for(i=0; i<=size; i++)
	{
		if(holder[i]==' ' || holder[i]=='\0') //if space or null character, skip next row
		{
			words[r][c] = '\0';
			r++;
			c = 0;
		}
		else //skip until a space or null character
		{
			words[r][c] = holder[i];
			c++;
		}
	}
	
	reverse(&sentence, words, r);
	
	printf("Reverse is: ");
	for(i=sentence.top; i>=0; i--)
	{
		printf("%s ", sentence.data[i]);
	}
	
	return 0;
}

