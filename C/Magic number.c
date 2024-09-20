#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	scanf("%d", &number);
	char strNumber[10];
	itoa(number, strNumber, 10);
	int i=0,ok = 1;
	while(ok == 1 && strNumber[i] != '\0')
	{
		if(strNumber[i] == '1')
		{
			i++;
			if(strNumber[i] == '4')
			{
				i++;
				if(strNumber[i] == '4')
				{
					i++;
				}
			}
		}
		else
		{
			ok = 0;
		}
	}
	
	if(ok == 1) printf("YES");
	else printf("NO");
	
	return 0;
}
