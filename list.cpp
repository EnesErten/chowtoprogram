#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 
typedef struct listnode{
    int num;
    struct listnode *next;
}listnode;
//struct defintion
//firs elemnt is keeping an element
//second one is pointing new listnode
//chanhge name by typedef

typedef listnode *listnodeptr;
//change name by typedef

void insertlist(listnodeptr *a, int n);
void printlist(listnodeptr a);
int sumofl(listnodeptr a);
double avrgofl(int n,int n1);
//function prototype

//this functions inserts the elements to the list
void insertlist(listnodeptr *a,int n)
{
    listnodeptr nptr,pptr,cptr;
	//dynamic memory allocation
	nptr=(listnode *)malloc(sizeof(listnode));
	if(nptr!=NULL)
	{
		nptr->num=n;
		nptr->next=NULL;
		pptr=NULL;
		cptr=*a;

		while(cptr!=NULL && n>cptr->num)
		{
			pptr=cptr;
			cptr=cptr->next;
		}
		
//finding the number locataions to insert
		if(pptr==NULL)
		{
			nptr->next=*a;
			*a=nptr;
		}

//assign number if the number is the smallest elemnt int list

		else
		{
//else assign nu,mber to the list
			pptr->next=nptr;
			nptr->next=cptr;
		}
	}

	else
		printf("No memory available!\n");
}
//this functions prints the list

void printlist(listnodeptr a)
{
	if(a==NULL)
		printf("List is empty.\n");

	else
	{
		while (a!=NULL)
		{
			printf(" %d ",a->num);
			a=a->next;
		}
//printing elemnts one by one
	}
}

//this functions returns the total of elements
//on the lists
int sumofl(listnodeptr a)
{
	listnodeptr a1;
	int sum=0;
	a1=a;
	
	while(a1!=NULL)
	{
		sum+=a1->num;
		a1=a1->next;
	} //sums elements of list

	return sum;
}

double avrgofl(int n,int n1)
{
    return (float)n/n1;
}

int main()
{
	listnodeptr list=NULL;
	int i;

	srand(time(NULL));
//to generate random number

	for (i=0;i<20;i++)
		insertlist(&list,rand()%101);
		//send to the function insert elemnts of list

	printf("The list with 20 random integers:\n");
	printlist(list);
	//send to the function to print list

	printf("\n\nsum of the integers: %d\n\n",sumofl(list));
	printf("average of the integers: %.2f\n\n",avrgofl(sumofl(list),20));
	//print the avrg of list and sum of list
}
