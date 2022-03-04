
// This program wants addresses with a nickname character from user and checks if there are addresses with same location, shows them with their nicknames.

#include <stdio.h>
#include <stdlib.h>

//a struct consists four integer which are elements of location and one character that is nickname
typedef struct{
	int x;
	int y;
	int z;
	int w;
	char ch;
}address_t;

//this function checks if a character has used before or not.
int search_nick(address_t control[], int k)
{
	int j;
	
	for(j=0; j<k; j++)
		if(control[j].ch == control[k].ch || control[j].ch + 32 == control[k].ch || control[j].ch == control[k].ch + 32)
		return 1;
	
	return 0;
}

int main()
{
	int i = 0, status, samelocnum;
	int a, b, *sameloc;
	address_t *ads;
	int ctrl;
	
	ads = (address_t *) malloc (100 * sizeof(address_t));
	
	printf("Numeric addresses are specified in the form of xxx.yyy.zzz.www\n\n");
	
	do
	{
		printf("Enter the numeric address and nickname: ");
		scanf("%d.%d.%d.%d %c", &(*(ads+i)).x, &(*(ads+i)).y, &(*(ads+i)).z, &(*(ads+i)).w, &(*(ads+i)).ch);
		
		//checks if all elements are zero, program stops.
		ctrl = ((*(ads+i)).x==0 && (*(ads+i)).y==0 && (*(ads+i)).z==0 && (*(ads+i)).w==0);
		if(ctrl==1)
		break;
		
		status = search_nick(ads, i);
		
		while(status == 1)
		{
			printf("Existing nickname!\nEnter another nickname: ");
			scanf(" %c", &(*(ads+i)).ch);
			status = search_nick(ads, i);
		}
			
		i++;
		
	}while(ctrl != 1);
	
	sameloc = (int *) malloc (100 * sizeof(int));
	
	samelocnum = 0;
	int n = 0;
	
	//this nested loops checks is there same locations or not. If there is, store their subcript number into a new array which is called sameloc.
	for(a=0; a<i; a++){
		for(b=a+1; b<i; b++){
			if((*(ads+a)).x==(*(ads+b)).x && (*(ads+a)).y==(*(ads+b)).y){
				samelocnum += 2;
				*(sameloc+n) = a; n++;
				*(sameloc+n) = b; n++;
			}
		}
	}
	
	if(samelocnum > 0)
	{	
		int v;
		printf("\n\nComputers");
		for(i=0; i<samelocnum; i++){
			v = *(sameloc+i);
			printf("\n'%c' (%d.%d.%d.%d)", (*(ads+v)).ch, (*(ads+v)).x, (*(ads+v)).y, (*(ads+v)).z, (*(ads+v)).w);
		}
		printf("\nare from the same locality!");
		
	}
	else
	{
		printf("\n\nNo computers are from the same locality!");
	}
	
	return 0;
}

