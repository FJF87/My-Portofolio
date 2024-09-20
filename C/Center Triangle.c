#include <stdio.h>

int triangle(int n)
{
	int i,j,spasi;
	for(i=1,spasi=0;i<=2*n-1;i+=2,spasi++)
	{
		for(j=n-1;j>spasi;j--)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
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
	triangle(input);
	
	return 0;
}
