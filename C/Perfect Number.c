#include <stdio.h>

int factor(int x, int *arr) //store it in an array
{
	int i,index=0;
	for(i=1;i<x;i++)
	{
		if(x%i==0)
		{
			arr[index] = i;
			index++;
		}
	}
	return index;
}

int isPerfect(int x, int *arr, int index)
{
	int i,sum=0;
	printf("%d's factors are: ", x);
	for(i=0;i<index;i++)
	{
		sum+=arr[i];
		printf("%d ", arr[i]);
	}
	if(sum==x)
		printf("\n%d: yes, %d is a perfect number\n", x, x);
	else
		printf("\n%d: no, %d is not a perfect number\n", x, x);
}

int main()
{
	int arr[1000];
	int i,max;
	printf("input the number: ");
	scanf("%d", &max);
	for(i=1;i<=max;i++)
	{
		int index = factor(i,arr);
		isPerfect(i,arr,index);
		printf("\n");
	}
	
	return 0;
}
