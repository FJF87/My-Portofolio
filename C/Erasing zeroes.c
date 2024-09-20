#include <stdio.h>
#include <string.h>

int main()
{
	int T,i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		char str[101];
		scanf("%s", str);
		int j,start=0,end=0,erase=0;
		for(j=0;j<strlen(str);j++)
		{
			if(str[j] == '1')
			{
				start = j;
				break;
			}
		}
		for(j=strlen(str);j>0;j--)
		{
			if(str[j] == '1')
			{
				end = j;
				break;
			}
		}
		for(j=start;j<end;j++)
		{
			if(str[j] == '0')
			{
				erase++;
			}
		}
		printf("%d\n", erase);
	}
	
	return 0;
}
