#include<stdio.h>

main()
{
	int accnum,taccnum;
	char name[10],tname[10];
	double balance,tbalance;

	FILE *a;
	
	if((a=fopen("bank.txt","w"))==NULL)
		printf("File couldnt open\n");

	else
	{
		printf("please enter account number, name and balance\n>>");
		
		scanf("%d%s%lf",&accnum,name,&balance);

		while(!feof(stdin))
		{
			fprintf(a,"%-12d%-10s%lf\n",accnum,name,balance);
			
			printf(">>");
			scanf("%d%s%lf",&accnum,name,&balance);
		}
		
		fclose(a);
	}
	
	
	if((a=fopen("bank.txt","r"))==NULL)
		printf("File couldnt find");

	else
	{
		fscanf(a,"%d%s%lf",&taccnum,tname,&tbalance);
		while(!feof(a))
		{
			printf("%d %s %lf\n",taccnum,tname,tbalance);
			
			fscanf(a,"%d%s%lf",&taccnum,tname,&tbalance);
		}
		
		fclose(a);
	}
}
