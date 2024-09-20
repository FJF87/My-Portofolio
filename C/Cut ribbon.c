#include <stdio.h>

//blom

int main()
{
	int n,a,b,c,smallest,middle,biggest,i;
	scanf("%d %d %d %d", &n,&a,&b,&c);
	if(a>=b && a>=c)
	{
		biggest = a;
		if(b>c)
		{
			middle = b;
			smallest = c;
		}
		else
		{
			middle = c;
			smallest = b;
		}
	}
	else if(b>=a && b>=c)
	{
		biggest = b;
		if(a>c)
		{
			middle = a;
			smallest = c;
		}
		else
		{
			middle = c;
			smallest = a;
		}
	}
	else if(c>=a && c>=b)
	{
		biggest = c;
		if(a>b)
		{
			middle = a;
			smallest = b;
		}
		else
		{
			middle = b;
			smallest = a;
		}
	}
	
	if(n%smallest == 0)
	{
		printf("%d", n/smallest);
	}
	else
	{
		for(i=1;i<=n/smallest;i++)
		{
			if( (n%smallest)+(i*smallest) == middle )
			{
				printf("%d", (n/smallest)-i+1 );
				break;
			}
			else if( (n%smallest)+(i*smallest) == biggest )
			{
				printf("%d", (n/smallest)-i+1 );
				break;
			}
		}
	}
	
	return 0;
}
