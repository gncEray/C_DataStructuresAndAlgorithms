//This program takes strings to a stack until stop values entered 
// then inserts these strings from stack to queues 
// after, takes a string and looks for if there is same string in asked queues
// if there is it displays them


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_char.h"
#include "stack_char.h"

//This function searches if there is asked value, then displays them
void printIfSubstr(queue_str_t q[] ,char str[], int num)
{
	stack_t last;
	int len = strlen(str), k;
	char temp[20], holder[20], item[20];
	
	while(!is_empty_str_q(&q[num]))
	{
		remove_str_q(&q[num], holder); // I took string from queue because of comparing
		int wordlen = strlen(holder);
	
		for(k=0; k<=wordlen-len; k++)
		{
			temp[0] = '\0';
			memmove(temp, holder + k, len);
			
			if(strcmp(temp, str) == 0)
			{
				push(&last, holder); // I inserted a stack in order to print values asked order
				break; // I used break because when asked string found more than one, it causes printing same values more than one times
			}
		}
	}

	printf("Strings that contain the substring \"%s\" are:\n", str);
	while(!is_empty_s(&last))
	printf("%s\n", pop(&last, item));
	
}


int main()
{
	stack_t stack;
	queue_str_t queue[10];
	char strings[20], item[20], srch[20];
	int i, j, k=0;
	
	char ctrl1[] = "return", ctrl2[] = "end"; // control values to stop taking string
	
	for(i=0; i<10; i++){
		initialize_str_q(&queue[i]);
	}
	
	printf("Enter strings (end to stop):\n");
	do
	{
		initialize_s(&stack);
		
		scanf("%s", strings);
		while(strcmp(strings, ctrl1)!=0 && strcmp(strings, ctrl2)!=0) // until "return" or "end" is entered
		{
			push(&stack, strings);
			scanf("%s", strings);
		}
		
		// inserting queue from stack
		while(is_empty_s(&stack)!=1)
		insert_str_q(&queue[k], pop(&stack, item));
		
		printf("Stack %d has been pushed.\n\n", k+1);
		
		k++;
	
	}while(strcmp(strings, ctrl2)!=0); // take until "end" is entered
	
	printf("Enter the string to be searched: ");
	scanf("%s", srch);
	printf("Enter the number of the stack: ");
	scanf("%d", &j);
	
	printIfSubstr(queue, srch, j-1);
	
	
	return 0;
}
