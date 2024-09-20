#include <stdio.h>

void lowerLeft(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void lowerRight(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>=n-1-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void upperLeft(int n)
{
	int i,j;
	for(i=n;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void upperRight(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int input;
	printf("masukkan angka: ");
	scanf("%d", &input);
	lowerLeft(input);
	printf("\n");
	lowerRight(input);
	printf("\n");
	upperLeft(input);
	printf("\n");
	upperRight(input);
	return 0;
}
