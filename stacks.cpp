#include <stdio.h>
#include "stack_int.h"

int main()
{
	int i;
	int item, temp1, temp2;
	stack_t stack, stack_2;
	
	initialize_s(&stack);	//stack->top = -1;
	initialize_s(&stack_2);
	
	for(i=0; i<6; i++)
	{
		printf("Enter an integer: ");
		scanf("%d", &item);
		push(&stack, item);
		push(&stack_2, item); // Second stack in order to print before swap part
	}
	
	//This part swaps most top two elements
	temp1 = pop(&stack);
    temp2 = pop(&stack);
    
	push(&stack, temp1);
    push(&stack, temp2);
	//Takes numbers, removes them and inserts again reversely.
	
	
	//This part prints before swap part
	printf("\nStack Content\n--------------\n");
	i = stack.top;
	while(i != -1)
	{
		printf("%d\n", pop(&stack_2));
		i--;
	} 
	
	//This part prints after swap part
	printf("\nAfter swap\n--------------\n");
	i = stack.top;
	while(i != -1)
	{
		printf("%d\n", pop(&stack));
		i--;
	} 
	
	return 0;
}

