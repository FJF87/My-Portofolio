#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		long long int n,two,three;
		scanf("%llu", &n);
		if(n%3==0)
			three = n/3;
		else if(n%3==1)
			three = (n/3)+2;
		else if(n%3==2)
			three = (n/3)+1;
		if(n%2==0)
			two = n/2;
		else if(n%2==1)
			two = -1;
		if(two<three && two!=-1)
			printf("%llu\n", two);
		else
			printf("%llu\n", three);
	}
	return 0;
}

//579476985
//output
//56367553
//expected
//56367552
