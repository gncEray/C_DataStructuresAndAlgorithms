#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	double gpa;
}student;

typedef struct node_s{ 
	student data;
	struct node_s *next;
}node_t;

node_t *Getnode(void){
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t)); node->next = NULL;
	return (node);
}

void add_after(node_t *p, student item)
{
	node_t *newp;
	newp = Getnode();
	
	newp->data = item;
	newp->next = p->next;
	p->next = newp;
	
}

node_t *add_beginning(node_t *headp, student item)
{
	node_t *newp;
	newp = Getnode();
	
	newp->data = item;
	newp->next = headp;

	return newp;
}

node_t *creating_list(FILE *file)
{
	node_t *headp, *p;
	student temp[20];
	int i, j, k, size;
	
	headp = NULL;
	
	file = fopen("students.txt", "r");
	if(file==NULL)
	printf("CANNOT FOUND FILE");
	else
	{
		i=0;
		while(fscanf(file, "%d %lf", &temp[i].id, &temp[i].gpa)!=EOF)
		i++;
		
		size = i;
		
		headp = add_beginning(headp, temp[0]);
		
		p = headp;
		
		for(k=1; k<size; k++)
		{
			add_after(p, temp[k]);
			p = p->next;
		}
	}
	fclose(file);
	return headp;
}

void display_list(node_t *headp)
{
	node_t *p;
	
	if(headp == NULL)
	printf("List is empty!");
	else
	{
		p = headp;
		
		while(p!=NULL)
		{
			printf("%d %.2f\n", p->data.id, p->data.gpa);
			p = p->next;
		}
	}
}

int search_less_2(node_t *headp)
{
	node_t *p;
	p = headp;
	int cnt=0;
	double grade = 2.00;
	
	while(p!=NULL && (p->data.gpa)>grade)
	{
		p = p->next;
		cnt++;	
	}
	
	return cnt;
}

void delete_after(node_t *p)
{
	node_t *del;
	
	del = p->next;
	
//	*item = del->data;
	                        
	p->next = del->next;
	
	free(del);
}

node_t *delete_first(node_t *headp)
{
	node_t *del;
	
	del = headp;
	
	headp = del->next;
	
	free(del);
	
	return headp;
}

node_t *delete_nth(node_t *headp, int n)
{
	node_t *p;
	int k;
	
	if(headp == NULL)
		printf("LIST DOES NOT EXIST");
	else
	{	
	
		if(n == 1)
		{
			headp = delete_first(headp);
		}
			
		else
		{
			p = headp;
			k = 1;
			
			while(p->next!=NULL && k<n-1)
			{
				p = p->next;
				k++;
			}
			
			if(p->next!=NULL)
			delete_after(p);	
		}
	}
	//else
	//*item = -987654321;
	
	return headp;
}

int main()
{
	node_t *headp, *p;
	FILE *file;
	int n;
	student* item;
	
	headp = creating_list(file);
	
	printf("Content of the LIST\n");
	display_list(headp);
	
	n = search_less_2(headp);
//	printf("%d", n);
	p = delete_nth(headp, n+1);
	
	printf("After the elimination of the first student with cgpa < 2.00 :\n");
	display_list(p);
	
	return 0;
}





