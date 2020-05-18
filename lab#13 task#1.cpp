#include<stdio.h>
#include<stdlib.h>

#define MINIMUM2(n,n1) ((n)<(n1) ? (n):(n1))

main()
{
	int num1,num2,i;
	float num3,num4;
	
	printf("For integers values\n");
	for(i=0;i<4;i++)
	{
		printf("Enter two integers\n>>");
		scanf("%d%d",&num1,&num2);
		
		printf("The minumum of %d and %d is %d\n",num1,num2,MINIMUM2(num1,num2));
	}
	
	printf("\nFor float values\n");
	for(i=0;i<4;i++)
	{
		printf("Enter two floats\n>>");
		scanf("%f%f",&num3,&num4);
		
		printf("The minumum of %f and %f is %f\n",num3,num4,MINIMUM2(num3,num4));
	}
}
