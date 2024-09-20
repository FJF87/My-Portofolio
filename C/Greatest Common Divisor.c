#include <stdio.h>

long int gcd(long int num, long int div)
{
	if(div == 0)
		return num;
	else
		return gcd(div, num%div);
}

int main()
{
	printf("%ld\n", gcd(13,20));
	return 0;
}
