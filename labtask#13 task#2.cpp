#include<stdio.h>
#include<stdlib.h>

#define MINIMUM2(n,n1) ((n)<(n1) ? (n):(n1))

#define MINIMUM3(n2,n3,n4) (MINIMUM2(n2,MINIMUM2(n3,n4)))

main()
{
	int num1,num2,num3,i;
	float num4,num5,num6;
	
	printf("For integers values\n");
	for(i=0;i<3;i++)
	{
		printf("Enter three integers\n>>");
		scanf("%d%d%d",&num1,&num2,&num3);
		
		printf("The minumum of %d, %d ,and %d is %d\n",num1,num2,num3,MINIMUM3(num1,num2,num3));
	}
	
	printf("\nFor float values\n");
	for(i=0;i<3;i++)
	{
		printf("Enter three floats\n>>");
		scanf("%f%f%f",&num4,&num5,&num6);
		
		printf("The minumum of %f, %f and %f is %f\n",num4,num5,num6,MINIMUM3(num4,num5,num6));
	}
}
