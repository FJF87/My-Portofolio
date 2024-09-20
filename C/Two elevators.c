#include <stdio.h>

int main()
{
	int T,i;
	scanf("%d", &T);
	int a,b,c;
	for(i=0;i<T;i++)
	{
		scanf("%d %d %d", &a,&b,&c);
		if(c>b)
		{
			if(a < 2*c-b)
				printf("1\n");
			else if(a > 2*c-b)
				printf("2\n");
			else printf("3\n");
		}
		else
		{
			if(a < b)
				printf("1\n");
			else if(a > b)
				printf("2\n");
			else printf("3\n");
		}
	}
	return 0;
}
