
// This program reads information of products from a file and shows them as names, prices and warranty years respectively.

#include <stdio.h>
#include <stdlib.h>

//a struct with three different data types which contain name, price and warranty year of a product.
typedef struct{
	char prod_name[20];
	double price;
	int warranty;
} product_t;

int main()
{
	int i, temp, prod_num;
	FILE *productfile;
	product_t *whitegoods;

	productfile = fopen("product.txt", "r");

	if(productfile == NULL)
		printf ("File does not exist!\n"); 
	else
	{
		//in order to avoid from errors, I used a temporary variable for number of products.
		fscanf(productfile, "%d", &temp); 
		
		prod_num = temp;
		
		whitegoods = (product_t *) malloc (prod_num * sizeof(product_t));
		
		for(i=0; i<prod_num; i++)
		fscanf(productfile, "%s %lf %d", &(*(whitegoods + i)).prod_name, &(*(whitegoods + i)).price, &(*(whitegoods + i)).warranty);
	}
	
	fclose(productfile);
	
	printf("There are %d products\n\n", prod_num);
	printf("The Product Information:\n");
	
	for(i=0; i<prod_num; i++){
	printf("************************\n");
	printf("Name: %s\nPrice: %5.2f\nYears of Warranty: %d\n", (*(whitegoods + i)).prod_name, (*(whitegoods + i)).price, (*(whitegoods + i)).warranty);
	}

	return 0;
}
