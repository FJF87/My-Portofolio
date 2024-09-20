#include <stdio.h>

int maximum(int x,int y);
int minimum(int x, int y);

int main()
{
	int a,b;
	printf("Input 2 values: ");
	scanf("%d %d", &a, &b);
	printf("Largest value is : %d\n", maximum(a,b));
	printf("Smallest value is : %d", minimum(a,b));
	
	return 0;
}

int maximum(int x, int y)
{
	int max = x;
	if(y>max)
		max = y;
	return max;
}

int minimum(int x, int y)
{
	int min = x;
	if(y<min)
		min = y;
	return min;
}
