#include <stdio.h>

void segitigaAtas(int diagonal)
{
	int i;
	for(i=0;i<diagonal/2;i++)
	{
		int j;
		for(j=diagonal/2;j>i;j--)
			printf(" ");
		printf("*");
		if(i>0)
		{
			for(j=0;j<2*i-1;j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
}

void segitigaBawah(int diagonal)
{
	int i;
	for(i=0;i<diagonal/2;i++)
	{
		int j;
		for(j=0;j<=i;j++)
			printf(" ");
		printf("*");
		if(i!=diagonal/2-1)
		{
			for(j=diagonal-4;j>2*i;j--)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
}

void tengah(int diagonal)
{
	int i;
	printf("*");
	for(i=0;i<diagonal-2;i++)
		printf(" ");
	printf("*\n");
}

int main()
{
	int diagonal;
	printf("masukkan diagonal: ");
	scanf("%d", &diagonal);
	if(diagonal%2==0)
		diagonal+=1;
	segitigaAtas(diagonal);
	tengah(diagonal);
	segitigaBawah(diagonal);
	
	return 0;
}
