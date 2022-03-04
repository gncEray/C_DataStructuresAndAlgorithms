// Eray Genç 19050111005
// This program takes a string from user and does specified operations according to special character

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_char.h"

//This function displays queue when special operator recognized
void display_queue(queue_t q) // I didn't initialize queue as pointer because it protects its original form after function calls
{
	printf("\nThe content of the queue is: ");
	
	while(!is_empty_q(&q))
	{
		printf("%c ", remove_q(&q));
	}
	printf("\n");
	
} // in another alternative solution: if I initialized queue as pointer, it would be changed after function call
// so there would need a temporary queue for inserting the same datas again.


//This function makes queue empty and displays appropriate message
void emptyqueue(queue_t *q)
{
	while(!is_empty_q(&*q))
	remove_q(&*q);
	
	printf("All the characters are removed from the queue\n");
}


//This function removes only front element of queue and displays appropriate message
void erasefirst(queue_t *q)
{
	printf("The character <%c> is removed from the queue\n", remove_q(&*q));
}

// In main part I just called the functions, according to special characters
int main()
{
	queue_t queue;
	char str[200];
	int i, j, k;
	
	initialize_q(&queue);
	
	printf("*\tErase the first character (remove it from the queue)\n");
	printf("+\tKill the entire line (Empty the queue)\n");
	printf(": or !\tDisplay the queue content\n");
	printf("Enter\tTerminate the string entry and display the queue content\n");
	printf("Enter characters to be inserted to the queue (press enter to stop)..:\n");
	scanf("%s", str);
	int len = strlen(str);
	
	i = 0;
	while(i<len)
	{

		if(str[i] == '*')
		erasefirst(&queue);
		else if(str[i] == '+')
		emptyqueue(&queue);
		else if(str[i] == ':' || str[i] == '!')
		display_queue(queue);
		else
		insert_q(&queue, str[i]);
		
		i++;
	}
	
	return 0;
	
}
