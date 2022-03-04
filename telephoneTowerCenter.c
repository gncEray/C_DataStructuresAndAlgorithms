// This program has two stacks and one queue as data structure
// Also, it consists operations for stacks and queue
// Also, there are some functions to do below operations:
// 1-)a function that creates a stack with phone numbers from a file
// 2-)a function that takes person's information and inserts into a queue
// 3-)a function that takes person's information from queue and phone number from stack. Then it asks until user accepts given phone number. Lastly, inserts them into stack 
// 4->a function that removes a phone number according to user's input from installed stack

#include <stdio.h>
#define STACK_SIZE 20
#define QUEUE_SIZE 20


/*--------------------------------------
		Part a) Necessary structures	
--------------------------------------*/

// structure for application date
typedef struct{
	int day, month, year;
}date;

//struct for person's information -for queue's data type
typedef struct{
	char name[20];
	char address[50];
	date application_date;
}person;

// a queue for person who will wait for process
typedef struct{
	int front, rear;
	person data[20];
}queue_waiting_for_process;

// struct to store infos and numbers asked type for stack 
typedef struct{ 
	int phone_number;
	person info_of_person;
}number_and_person;

// stack that consists processed number and information
typedef struct{
	int top;
	number_and_person data[20];
}stack_installed_phones;

// stack for store possible telephone numbers
typedef struct{
	int top;
	int data[20];
}stack_possible_phone_numbers;

/*-------------------------------------------------------------------------*/
//---	Part b) Necessary functions for the stack and queue operations	---*/
/*-------------------------------------------------------------------------*/


/*------------FIRST STACK WHICH CONSISTS INSTALLED PHONE NUMBERS WITH PERSON INFORMATION----------*/

void initialize_s_installed(stack_installed_phones *s)
{
	s->top = -1;
}

int is_empty_s_installed(stack_installed_phones *s)
{
	if (s->top == -1)
		return 1;
		
	return 0;
}

int is_full_s_installed(stack_installed_phones *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
		
	return 0;
}

void push_installed(stack_installed_phones *s, number_and_person item)
{
	if (is_full_s_installed(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

number_and_person pop_installed(stack_installed_phones *s)
{
	number_and_person item;
	if (is_empty_s_installed(s))
	{	printf("Error: Stack is empty!\n");
	//	item = STACK_EMPTY;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}


/*------------SECOND STACK WHICH CONSISTS POSSIBLE PHONE NUMBERS------------*/

void initialize_s_numbers(stack_possible_phone_numbers *s)
{
	s->top = -1;
}

int is_empty_s_numbers(stack_possible_phone_numbers *s)
{
	if (s->top == -1)
		return 1;
		
	return 0;
}

int is_full_s_numbers(stack_possible_phone_numbers *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
		
	return 0;
}

void push_numbers(stack_possible_phone_numbers *s, int item)
{
	if (is_full_s_numbers(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

int pop_numbers(stack_possible_phone_numbers *s)
{
	int item;
	
	if (is_empty_s_numbers(s))
	{	printf("Error: Stack is empty!\n");
	//	item = STACK_EMPTY;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}


/*------------QUEUE WHICH CONSISTS PEOPLE TO PROCESS------------*/

void initialize_q(queue_waiting_for_process *q) 
{
	q->front = 0;
	q->rear = -1;
}

int is_empty_q(queue_waiting_for_process *q) 
{
	if (q->front > q->rear)
		return 1;

return 0;
}

int is_full_q(queue_waiting_for_process *q) 
{
	if (q->rear == QUEUE_SIZE - 1)
		return 1;
	
	return 0;
}

void insert(queue_waiting_for_process *q, person item) 
{
	if (is_full_q(q))
		printf("Error : Queue is full!\n"); 
	else 
	{
		q->rear = q->rear + 1;
		q->data[q->rear] = item;
	}
}

person remove_q(queue_waiting_for_process *q) 
{
	
	person item;
	
	if (is_empty_q(q)) 
	{
		printf("Error : Queue is empty!\n");
	}
	else 
	{
		item = q->data[q->front];
		q->front = q->front + 1;
	}
	
	return (item);
}


/*-----------------------------------------------------------------------------------------------*/
// this is an extra function that is not asked but I created in order to create a stack with possible phone numbers
void inserting_phone_numbers_to_stack(stack_possible_phone_numbers *phonenumbers)
{
	FILE *file;
	char filename[20];
	int ph_num;
	
	// I prefferred to get phone numbers from a file but it also can be gotten from the user   
	printf("Enter the file name: ");
	scanf("%s", filename);
	
	file = fopen(filename, "r");
	while(file == NULL) // take file name until find a file that is not NULL
	{
		printf("File not found Enter again: ");
		scanf("%s", filename);
		file = fopen(filename, "r");
	}
	
	// insert all phone numbers into a stack
	while((fscanf(file, "%d", &ph_num)) != EOF)
	push_numbers(&*phonenumbers, ph_num);
	
}



/*-----------------------------------------------------------------------------*/
/*---	Part c) function which gets an application and puts it into queue	---*/
/*-----------------------------------------------------------------------------*/

// this function takes information of person as input and inserts it into queue
void gets_and_puts_to_queue(queue_waiting_for_process *q)
{
	person application; // structure consists name address and date of person
	
	printf("\nEnter your name: ");
	scanf("%s", application.name);
	printf("Enter your address: ");
	scanf("%s", application.address);
	printf("Enter application date in format of dd-mm-yy: ");
	scanf("%d-%d-%d", &application.application_date.day, &application.application_date.month, &application.application_date.year);
	
	insert(&*q, application); // insert into queue after taking information
}



/*-------------------------------------------------------------------------------*/
/*	Part d) Function which processes an application in the queue, 
	thus gives a telephone number to thefirst application in the queue.	*/
/*-----------------------------------------------------------------------*/

// this function takes person's info from queue and phone number from stack. Then it asks until person accepts the number it offers.
void process_application_queue_to_stack(queue_waiting_for_process *q_waiting, stack_possible_phone_numbers *phonenumbers, stack_installed_phones *installed_stack)
{
	stack_possible_phone_numbers temp; //this stack stores all possible phone numbers
	person inprocess; // this struct consists person's info
	number_and_person personwithnumber; // this struct consists person's info and phone number that person accepts
	char choice;
	int ph_num;
	
	
	initialize_s_numbers(&temp);
	
	inprocess = remove_q(&*q_waiting); // taking information of person who will be processed and choose and number
	
	ph_num = pop_numbers(&*phonenumbers); // taking phone number from stack
	
	printf("\nNUMBER IS: %d\n", ph_num);
	printf("DOES HE WANT THIS NUMBER? (Y:YES, N:NO): ");
	scanf(" %c", &choice); 
	
	while(choice == 'N' && is_empty_s_numbers(phonenumbers)!=1)// if he doesn't want number, program takes another number from stack until he wants
	{
		push_numbers(&temp, ph_num);
		
		ph_num = pop_numbers(&*phonenumbers);
		printf("NUMBER IS: %d\n", ph_num);
		printf("DOES HE WANT THIS NUMBER? (Y:YES, N:NO): ");
		scanf(" %c", &choice);
	}
	
	// merging number and information of person in order to push them into installed stack
	personwithnumber.phone_number = ph_num; 
	personwithnumber.info_of_person = inprocess;
	
	push_installed(&*installed_stack, personwithnumber); // insert both number and info into stack
	
	// insert denied numbers to possible phone numbers stack again
	while(is_empty_s_numbers(&temp)!=1)
	push_numbers(&*phonenumbers, pop_numbers(&temp));
	
}

/*----------------------------------------------------------------------------------------------
	Part e) Function which will be used if a person does not want to use his telephone anymore
-----------------------------------------------------------------------------------------------*/

// this function removes a phone from stack if a person does not want to use his telephone anymore
void remove_phone(stack_possible_phone_numbers *phonenumbers, stack_installed_phones *installed_stack)
{
	number_and_person temp; // this data type is same as stack's data. So, I used it to hold given data temporary 
	stack_installed_phones tempstack; // stack that consists number and person's data
	int number;
	
	initialize_s_installed(&tempstack);
	
	// Asked number in order to remove from stack. It is also possible to use name for removing.
	printf("\nWHO WANTS TO OUT? ENTER HIS PHONE NUMBER: ");
	scanf("%d", &number);
	
	temp = pop_installed(&*installed_stack); // pop and hold data with temporary variable
	
	while(temp.phone_number!=number) // pop from stack until find the looking value
	{
		push_installed(&tempstack, temp); // store popped data in order to push them after search operation
		temp = pop_installed(&*installed_stack);
	}
	
	push_numbers(&*phonenumbers, temp.phone_number);// number is available anymore. So insert it into possible phone numbers stack
	
	// insert again popped values to stack
	while(is_empty_s_installed(&tempstack)!=1)
	{
		push_installed(&*installed_stack, pop_installed(&tempstack));
	}
}


// I added main part, if you want to check the program works or not
/*
int main()
{
	int i;
	
	stack_possible_phone_numbers phonenumbers;
	queue_waiting_for_process personforprocess;
	stack_installed_phones installedphones;
	
	number_and_person numandper;
	
	initialize_s_numbers(&phonenumbers);
	initialize_q(&personforprocess);
	initialize_s_installed(&installedphones);
	
	inserting_phone_numbers_to_stack(&phonenumbers);
	
	for(i=0; i<5; i++)
	{
		gets_and_puts_to_queue(&personforprocess);
		process_application_queue_to_stack(&personforprocess, &phonenumbers, &installedphones);
	}
	
	remove_phone(&phonenumbers, &installedphones);

	printf("\nPHONE NUMBERS AND PEOPLE'S INFORMATION:");
	while(is_empty_s_installed(&installedphones)!=1)
	{
		numandper= pop_installed(&installedphones);
	
		printf("\n%d %s %s ", numandper.phone_number, numandper.info_of_person.name, numandper.info_of_person.address);
		printf("%d-%d-%d", numandper.info_of_person.application_date.day, numandper.info_of_person.application_date.month, numandper.info_of_person.application_date.year);
	}
	
	printf("\n\nREMAIN NUMBERS:\n");
	while(is_empty_s_numbers(&phonenumbers)!=1)
	{
		printf("%d\n", pop_numbers(&phonenumbers));
	}
	
	
	return 0;
}*/


