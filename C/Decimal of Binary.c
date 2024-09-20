#include <stdio.h>

int pangkat(int x, int i)
{
	int j,hasil=1;
	for(j=0;j<i;j++)
	{
		hasil = hasil * x;
	}
	return hasil;
}

void bin(char *x)
{
	int i,total=0;
	for(i=0;i<=5;i++)
	{
		if(x[i]=='1') total += pangkat(2,4-i);
	}
	printf("%d\n", total);
}

int main()
{
	char x[5] = "00011";
	bin(x);
	return 0;
}
