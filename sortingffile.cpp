#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void bblsrt(long long int [],int [],int );
void swap(int *,int *);
void swap1(long long int *,long long int *);
//prototype of the functions

void bblsrt(long long int a[],int b[],int n)
{
	//buble sort
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1]) 
			//if a[j]>a[j+1] is true
			{
				swap(&b[j],&b[j+1]);
				swap1(&a[j],&a[j+1]);
				//change the index order and sort numbers
			}
		}
	}
}

void swap(int *p,int *p1)
{
	//swap values(int)
	int temp;
	temp=*p;
	*p=*p1;
	*p1=temp;
}

void swap1(long long int *p2,long long int *p3)
{//swap values(long long int)
	long long int temp;
	temp=*p2;
	*p2=*p3;
	*p3=temp;
}

main()
{
	int i=0,ar[10]={0,1,2,3,4,5,6,7,8,9};
	char temp[150],name[10][20],sname[10][20],tname[20],tsname[20];
	long long int num[10],tnum,a;

	//declaring variables
	FILE *fptr,*f1ptr,*f2ptr;
	//declaring 3 file pointers
	
	if((fptr=fopen("Input.txt","r"))==NULL)
		printf("File couldnt open");
	//if computer couldnt read the text file

	else
	{
		//if copmuter read the text file
		printf("The content of the file before sorting is :\n");
		printf("The content of the file :\n");
		printf("%-23s%-15s%-s\n","Number","Name","Surname");
		
		fscanf(fptr,"%lli%s%s",&tnum,tname,tsname);
		
		num[i]=tnum;
		
		strcpy(name[i],tname);
		strcpy(sname[i],tsname);
		//take the datas from to end of line and copy to arrays
		
		printf("%-23lli%-15s%s\n",tnum,tname,tsname);
		//display the line which one is coppied to the arrays
		i++;
		
		while(!feof(fptr) && i<10)
		{
		//take the datas from to end of line and copy to arrays to the end of file
			fscanf(fptr,"%lli%s%s",&tnum,tname,tsname);
			
			num[i]=tnum;
			
			strcpy(name[i],tname);
			
			strcpy(sname[i],tsname);
			
			printf("%-23lli%-15s%s\n",tnum,tname,tsname);
			
			i++;
			//display the line which one is coppied to the arrays
		}
		
		//close the file
		fclose(f1ptr);
	}

	//send arrays to the functions to sort num array and their index order
	bblsrt(num,ar,10);
	
	if((f1ptr=fopen("Output.txt","w"))==NULL)
		printf("File couldnt open");
		//if couldnt open

	else
	{
	//if file open
		
		for(i=0;i<10;i++)
			fprintf(f1ptr,"%-23lli%-15s%s\n",num[i],name[ar[i]],sname[ar[i]]);
			//write the arrays to the new file(output.txt)
		
		fclose(f1ptr);
		//close the file
	}

	if((f2ptr=fopen("Output.txt","r"))==NULL)
			printf("File couldnt open");
	//if output.txt couldnt read

	else
	{
		printf("The content of the file after sorting is :\n");
		printf("The content of the file :\n");
		printf("%-23s%-15s%s\n","Number","Name","Surname");
		//if output.txt could read
		fscanf(f2ptr,"%lli%s%s",&tnum,tname,tsname);
		printf("%-23lli%-15s%s\n",tnum,tname,tsname);
		//take data's from the file and display ont the screen
		
		while(!feof(f2ptr))
		{
			fscanf(f2ptr,"%lli%s%s",&tnum,tname,tsname);
	
			if(!feof(f2ptr))
				printf("%-23lli%-15s%s\n",tnum,tname,tsname);
		}
	}
}
