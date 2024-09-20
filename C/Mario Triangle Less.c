#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int validateNumber(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(str[i] < 48 && str[i] > 57)
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int main()
{
	char strInput[10];
	int intInput = 0;
	
	do{
		int valid = 0;
		do{
			printf("Height: ");
			fflush(stdin);
			scanf("%s", strInput);
			valid = validateNumber(strInput);
		}while(valid == 0);
		
		intInput = atoi(strInput);
		
	}while(intInput < 0);
	
	int i,j;
	for(i=1;i<=intInput;i++)
	{
		for(j=1;j<=intInput-i;j++)
			printf(" ");
		for(j=1;j<=i;j++)
			printf("#");
		printf("\n");
	}
	
	return 0;
}
