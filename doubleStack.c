// This program consists stack operations for doublestack which has two stacks

#include <stdio.h>
#define STACK_SIZE 20

int STACK_EMPTY = -987654321;

// there are two different top values for each stack in doublestack
typedef struct{
	
	int top1;
	int top2;
	int data[STACK_SIZE];
	
}doublestack;

// initializing first stack, thus first stack starts from the beginning position of doublestack
void initialize_s1(doublestack *s1)
{
	s1->top1 = -1;
}

// checking if first stack is empty or not according the top1 value
int is_empty_s1(doublestack *s1)
{
	if (s1->top1 == -1)
		return 1;
		
	return 0;
}

// checking if first stack is full or not according to top values of both stack
int is_full_s1(doublestack *s1, doublestack *s2)
{
	if (s1->top1 == (s2->top2 - 1)) // if they cross -top2 value is 1 less than top1- this means first stack is full, no more place to add new item
		return 1;
		
	return 0;
}

// push function for first stack is the same as usual stack push operation, except controlling is full part
void push1(doublestack *s1, doublestack *s2, int item)
{
	if(is_full_s1(s1, s2)==1)
		printf("Error: Stack is full!\n");
	else
	{
		s1->top1 = s1->top1 + 1;
		s1->data[s1->top1] = item;
	}
}

// pop function for first stack is also same as usual stack pop operation. 
int pop1(doublestack *s1)
{
	int item;
	
	if(is_empty_s1(s1)==1)
	{
		printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;
	}
	else
	{
		item = s1->data[s1->top1];
		s1->top1 = s1->top1 - 1;
	}
	
	return item;	
}

/*---------------------------------------------------------------------------*/
/*------------------------BELOW PART FOR SECOND STACK------------------------*/
/*---------------------------------------------------------------------------*/

// initializing second stack, thus second stack starts from the ending position of doublestack
void initialize_s2(doublestack *s2)
{
	s2->top2 = STACK_SIZE;
}

// checking is empty or not according to top2 value
int is_empty_s2(doublestack *s2)
{
	if(s2->top2==STACK_SIZE) // if top value equals size of doublestack. It is empty, no more item in second stack.
		return 1;
		
	return 0;
}

// checking the second stack is full or not according to both top values of doublestack
int is_full_s2(doublestack *s2, doublestack *s1)
{
	if(s2->top2 == (s1->top1 + 1)) // if they cross -top1 value is 1 number more than top2- this means second stack is full, no more place to add new item
		return 1;
		
	return 0;
}

// unlike the first stack, second stack starts to push items from ending.
void push2(doublestack *s2, doublestack *s1, int item)
{
	if(is_full_s2(s2, s1)==1)
		printf("Error: Stack is full!\n");
	else
	{
		s2->top2 = s2->top2 - 1; //from ending to beginning until the stack is not full -don't cross with first stack-
		s2->data[s2->top2] = item;
	}
}

// this pop function also works in "last in first out" strategy but it works backwards according to array 
int pop2(doublestack *s2)
{
	int item;
	
	if(is_empty_s2(s2)==1)
		printf("Error: Stack is empty!\n");
	else
	{
		item = s2->data[s2->top2]; 
		s2->top2 = s2->top2 + 1; // unlike a usual stack, it increases top number
	}
	
	return item;
}


