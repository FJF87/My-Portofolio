#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		int a,b,c,time=0;
		scanf("%d %d %d", &a,&b,&c);
		while(a<=c && b<=c)
		{
			if(a>b)
				b+=a;
			else
				a+=b;
			time++;
		}
		printf("%d\n", time);
	}
	return 0;
}
