#include <stdio.h>

int main()
{
	unsigned long long int number,temp;
	int i=10, digit=1;
	scanf("%llu", &number);
	while(number/i!=0)
	{
		digit++;
		i*=10;
	}
	if(digit == 4 || digit == 7)
	{
		while(1)
		{
			temp = number % i;
			i/=10;
			if(i==0)
			{
				printf("YES");
				break;
			}
			else if(temp/i != 4 && temp/i != 7)
			{
				printf("NO");
				break;
			}
		}
	}
	else
	{
		printf("NO");
	}
}

//40047
//7747774
//1000000000000000000
