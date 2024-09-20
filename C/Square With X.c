#include <stdio.h>

int main()
{
	int i,j,input;
	printf("Masukkan angka: ");
	scanf("%d", &input);
	for(i=1;i<=input;i++)
	{
		for(j=1;j<=input;j++)
		{
			if(i==1 || j==1 || i==input || j==input)
				printf("*");
			else if(i==j || i+j==input+1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
