#include <stdio.h>

int largest(int a,int b, int c)
{
	int terbesar;
	if(a>b && a>c) return a;
	if(b>a && b>c) return b;
	else return c;
}

int main()
{
	int T,i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		int a,b,c,n;
		scanf("%d %d %d %d", &a, &b, &c,&n);
		largest(a,b,c);
		//int equal = 
	}
	return 0;
}
