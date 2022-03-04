// This program reads a binary file, inserts them into three queues - it selects queue which has the least element
// if code character is P, program removes the front of queue which is indicated as amount after code
// also it calculates number of visa, cash and total amount with using removed values
// Lastly it prints, remain queues, number of visa, cash and total amount

#include <stdio.h>
#include <stdlib.h>
#include "queue_custom.h"

//This function finds the queue which has the least element
int minq(queue_t q[], int numberofqueue)
{
	int i, min = 0; 
// initializing to 0 also provides that if all queues have same number of element, insert it the first one
	
	for(i=1; i<numberofqueue; i++)
	{
		if((q[i].rear - q[i].front) < (q[min].rear - q[min].front))
		min = i;
	}
	
	return min;
}


int main()
{
	FILE *file, *binaryfile;
	queue_t customers[3];
	customer_info holder[20], reader[20], temp; //this data type belongs to my header "queue_custom.h"
	int i, j, k, min_desk, number_cash = 0, number_visa = 0, num_item;
	double totalamount = 0;
	
	//firstly, I used a text file because binary files cannot be created manually
	file = fopen("customers.txt", "r");
	if(file == NULL)
	printf("NOT EXIST OR CANNOT FOUND!");
	else
	{
		i = 0;
		while(fscanf(file, " %c %lf", &holder[i].code, &holder[i].amount) != EOF)
		i++;
		
		num_item = i; // in order to prevent to name confusion
		
		// I insterted values to a binary file because question asks that
		binaryfile = fopen("customers.bin", "wb");
	
		for(k=0; k<num_item; k++){
			fwrite(&holder[k], sizeof(customer_info), 1, binaryfile);
		}
		
		fclose(binaryfile);
		binaryfile = fopen("customers.bin", "rb");
		
		if(binaryfile == NULL)
		printf("BINARY FILE CANNOT FOUND");
		else
		{
			initialize_q((customers+0));
			initialize_q((customers+1));
			initialize_q((customers+2));
						
			i = 0;
			while(i<num_item)
			{
				fread(&reader[i], sizeof(customer_info), 1, binaryfile);
		
				// if code is C or V, insert the data to appropriate queue
				if(reader[i].code=='C' || reader[i].code=='V')
				{
					min_desk = minq(customers, 3);
					insert(&customers[min_desk], reader[i]);
				}
				else if(reader[i].code=='P')// if code is P, remove given queue and calculate asked values
				{
					int sub = reader[i].amount;
					temp = remove_q(&customers[sub-1]);
					
					if(temp.code=='C')
					number_cash++;
					else if(temp.code=='V')
					number_visa++;
					
					totalamount = totalamount + temp.amount;
				}
				i++;
			}
			
			// Prints remain queues
			// could not be printed directly from remove because of QTYPE is a special data type
			printf("Cash Desk 1:\n");
			while(is_empty_q((customers+0))!=1)
			{
				temp = remove_q((customers+0));
				printf("%c %.2f\n", temp.code, temp.amount);
			}
			
			printf("Cash Desk 2:\n");
			while(is_empty_q((customers+1))!=1)
			{
				temp = remove_q((customers+1));
				printf("%c %.2f\n", temp.code, temp.amount);
			}
			
			printf("Cash Desk 3:\n");
			while(is_empty_q((customers+2))!=1)
			{
				temp = remove_q((customers+2));
				printf("%c %.2f\n", temp.code, temp.amount);
			}
			
			printf("Number of cash payments: %d\n", number_cash);
			printf("Number of visa payments: %d\n", number_visa);
			printf("Total payment: %.2f\n", totalamount);
			
		}
		
	}
	
	fclose(file);
	fclose(binaryfile);
	
	return 0;

}
