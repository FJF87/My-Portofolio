#include <stdio.h>
#include <string.h>

//hasil di sini benar, di sana salah

int main()
{
	char s[101];
	scanf("%s", s);
	int i,lower,upper;
	int lstr = strlen(s);
	for(i=0;i<lstr;i++)
	{
		if(s[i]>=65 && s[i]<=90)
			upper++;
		else //assuming user input only consist of char
			lower++;
	}
	if(lstr/2+lstr%2<lower)
	{
		for(i=0;i<lstr;i++)
		{
			if(s[i]>=65 && s[i]<=90)
				s[i]+=32;
		}
	}
	else
	{
		for(i=0;i<lstr;i++)
		{
			if(s[i]>=97 && s[i]<=122)
				s[i]-=32;
		}
	}
	printf("%s",s);
	
	return 0;
}
