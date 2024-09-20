#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input;
	char inputChar[10];
	
	//	only 1 to 8 is acceptable
	do{
		printf("Height: ");
		fflush(stdin);
		scanf("%s", inputChar);
	}while((inputChar[0] < 49 || inputChar[0] > 56) || inputChar[1] != '\0' );
	
	input = atoi(inputChar);
	
	int i,j;
	for(i=1;i<=input;i++)
	{
		for(j=1;j<=input-i;j++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("#");
		}
		printf("  ");
		for(j=1;j<=i;j++)
		{
			printf("#");
		}
		printf("\n");
	}
	
	return 0;
}
