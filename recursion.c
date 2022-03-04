#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	check it is divisible or not 
//	from its half to 1 // from 1 to its half
/*
for(i=1; i<num/2; i++)
if(num%i == 0)
total + i;
*/
int recursive(int num, int i) //control statement // recursive statement
{
	int total;
	
	if((num/2) < i)
	total = 0;
	else
	{
		if((num % i) == 0)
		total = i + recursive(num, i+1);
		else
		total = recursive(num, i+1);
	}
	 
	return total;
}

int main()
{
	int number, i=1, total;
	
	do
	{
		printf("Enter a number: ");
		scanf("%d", &number);
	
		total = recursive(number, i);
	
		if(total==number)
		printf("%d is a perfect number!\n", number);
		else
		printf("%d is NOT a perfect number!\n", number);	
	}while(number>-1);
	
	
	return 0;
}


