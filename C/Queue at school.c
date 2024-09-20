#include <stdio.h>

int main()
{
	int n,time;
	scanf("%d %d", &n, &time);
	char str[n];
	scanf("%s", str);
	int i;
	for(i=n-2;i>=0;i--)
	{
		if(str[i] == 'B')
		{
			int j;
			for(j=i+time;j>i;j--)
			{
				if(i+time>n)
				{
					j = n;
				}
				if(str[j] == 'G')
				{
					char temp = str[i];
					str[i] = str[j];
					str[j] = temp;
				}
			}
		}
	}
	printf("%s", str);
	return 0;
}

//5 1
//BGGBG
//5 2
//BGGBG
//4 1
//GGGB
