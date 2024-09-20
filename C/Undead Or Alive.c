#include <stdio.h>
#include <string.h>

int main()
{
	char strInput[162];
	int amountSmile = 0;
	int amountFrown = 0;
	
	scanf("%[^\n]", strInput);
	
	int i = 0;
	int lenghtOfStr = strlen(strInput);
	
	for(i=0 ; i<lenghtOfStr ; i++)
	{
		if(strInput[i] == ':')
		{
			if(strInput[i+1] == ')')
			{
				amountSmile++;
			}
			else if(strInput[i+1] == '(')
			{
				amountFrown++;
			}
		}
	}
	
	if(amountSmile > 0 && amountFrown == 0)
	{
		printf("alive");
	}
	else if(amountSmile == 0 && amountFrown > 0)
	{
		printf("undead");
	}
	else if(amountSmile > 0 && amountFrown > 0)
	{
		printf("double agent");
	}
	else
	{
		printf("machine");
	}
	
	return 0;
}
