#include <stdio.h>

int main()
{
	unsigned int T,i;
	scanf("%d", &T);
	int sum=0;
	for(i=0;i<T;i++)
	{
		int a,b,c;
		scanf("%d %d %d", &a,&b,&c);
		if(a+b+c>=2) sum++;
	}
	printf("%d", sum);
	return 0;
}
