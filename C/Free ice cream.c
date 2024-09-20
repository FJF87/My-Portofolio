#include <stdio.h>

int main()
{
	int T,i,dist=0;
	long long int x;
	scanf("%d %d", &T, &x);
	for(i=0;i<T;i++)
	{
		char op;
		long long int num;
		fflush(stdin);
		scanf("%c %lld", &op, &num);
		switch(op)
		{
			case '+':
				x+=num;
				break;
			case '-':
				if(x-num <= 0)
					dist++;
				else x-=num;
				break;
		}
	}
	printf("%lld %d", x,dist);
	return 0;
}
