#include <stdio.h>

int main()
{
	unsigned long long int number,temp=0,i=10;
	int digit=1, ln=0;
	scanf("%llu", &number);
	while(number/i!=0)
	{
		digit++;
		i*=10;
	}
	while(digit>0)
	{
		temp = number % i;
		i/=10;
		if(temp/i == 4 || temp/i == 7)
		{
			ln++;
		}
		digit--;
	}
	if(ln == 4 || ln == 7)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}

//40047
//7747774
//1000000000000000000  19 digit termasuk 1
//4744000695826
