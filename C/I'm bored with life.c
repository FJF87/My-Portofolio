#include <stdio.h>

long int recursion(long int x)
{
	if(x == 1)
	{
		return 1;
	}
	else
	{
		return x * recursion(x-1);
	}
}

int main()
{
	long int a,b,smallest;
	scanf("%ld %ld", &a,&b);
	if(a<b)
	{
		smallest = a;
	}
	else
	{
		smallest = b;
	}
	printf("%ld\n", recursion(smallest));
	
	return 0;
}
