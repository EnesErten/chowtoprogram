#include<stdio.h>
#include<stdlib.h>

#define PRINTARRAY(arr,len,i) for(i=0;i<len;i++)\
    printf("%d ",arr[i])
                               
main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10},i;
	
	printf("The array is:\n");
	PRINTARRAY(arr,10,i);
}

