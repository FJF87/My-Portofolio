#include <stdio.h>

int rekursiFaktorial(int x)
{
	if(x==1) return 1;
	else return x * rekursiFaktorial(x-1);
}

int iterasiFaktorial(int x)
{
	int i,y=1,z=1;
	for(i==1;i<x;i++,y++)
		z = z * y;
	return z;
}

int main()
{
	printf("%d",rekursiFaktorial(30));
	return 0;
}
