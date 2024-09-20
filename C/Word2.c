#include <stdio.h>
#include <string.h>

int main()
{
	char str[101];
	scanf("%s", str);
	int i,len=strlen(str),up=0,low=0;
	for(i=0;i<len;i++)
	{
		if(str[i]>=65 && str[i]<=90)
			up++;
		else
			low++;
	}
	if(low>=up)
	{
		for(i=0;i<len;i++)
		{
			if(str[i]>=65 && str[i]<=90)
				str[i]+=32;
		}
	}
	else
	{
		for(i=0;i<len;i++)
		{
			if(str[i]>=97 && str[i]<=122)
				str[i]-=32;
		}
	}
	printf("%s", str);
	
	return 0;
}
