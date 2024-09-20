#include <stdio.h>

int main()
{
	unsigned int T,i;
	scanf("%u", &T);
	for(i=0;i<T;i++)
	{
		int j,strlength;
		scanf("%d", &strlength);
		char str[strlength];
		scanf("%s", str);
		char lower[] = "meow";
		char upper[] = "MEOW";
		int now = 0, cat = 1;
		for(j=0;j<strlength;j++)
		{
			if(str[j] == lower[now] || str[j] == upper[now])
			{
				continue;
			}
			else if(j != 0)
			{
				if(str[j] == lower[now+1] || str[j] == upper[now+1])
				{
					now++;
				}
				else
				{
					cat = 0;
				}
			}
			else if(j == 0)
			{
				cat = 0;
			}
		}
		
		if(cat == 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	
	return 0;
}
