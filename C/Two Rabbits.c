#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		int x,y,a,b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		int dist = y - x;
		int total = a + b;
		if(dist % total == 0)
		{
			printf("%d\n", dist/total);
		}
		else
		{
			printf("-1\n");
		}
	}
	
	return 0;
}
