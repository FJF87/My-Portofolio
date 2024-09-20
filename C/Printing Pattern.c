#include <stdio.h>

int main()
{
	int T,i,j;
	printf("Input number: ");
	scanf("%d", &T);
	int maks = 2*T-1;
	int start = 0;
	for(i=0;i<maks;i++)
	{
		for(j=0;j<maks;j++)
		{
			if(i==start+j || i==maks-1-j || j==start+i || j==maks-1-i)
				printf("%d%d ", i,j);
			else
				printf("   ");
		}
		printf("\n");
	}
	
	return 0;
}
