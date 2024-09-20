#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		int n,x;
		scanf("%d %d", &n,&x);
		int j=0,floor=1;
		while(n >= (j*x+3))
		{
			floor++;
			j++;
		}
		printf("%d\n", floor);
	}
	return 0;
}
