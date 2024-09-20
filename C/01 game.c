#include <stdio.h>
#include <string.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		char str[101];
		scanf("%s", str);
		int lenghtMin = strlen(str) - 1;
		int j;
		int totalMoves = 0;
		int numberStored = 0;
		char charStored = ' ';
		for(j=0;j<lenghtMin;j++)
		{
			if(str[j] == str[j+1] )
			{
				totalMoves++;
				j++;
			}
			else if(str[j] == charStored && numberStored > 0 )
			{
				totalMoves++;
				numberStored--;
			}
//			else if( strcmp(str[j],charStored)!=0 && numberStored > 0 )
//			{
//				numberStored++;
//				
//			}
			else if(numberStored == 0)
			{
				charStored = str[j];
				numberStored++;
			}
			else if(numberStored != 0)
			{
				numberStored++;
			}
		}
		
		if(totalMoves%2 == 0)
		{
			printf("NET\n");
		}
		else if(totalMoves%2 == 1)
		{
			printf("DA\n");
		}
	}
	
	return 0;
}
