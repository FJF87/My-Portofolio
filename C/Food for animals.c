#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		long int a,b,c,x,y;
		scanf("%ld %ld %ld %ld %ld", &a,&b,&c,&x,&y);
		if(a<x && b<y)
		{
			long int need = x-a + y-b;
			if(c<need)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
		else if(a<x && b>=y)
		{
			long int need = x-a;
			if(c<need)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
		else if(a>=x && b<y)
		{
			long int need = y-b;
			if(c<need)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
		else
		{
			printf("YES\n");
		}
	}
	
	return 0;
}
