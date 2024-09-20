#include <stdio.h>

int main()
{
	int x,y,terkecil;
	scanf("%d %d", &x,&y);
	if(x<y)
	{
		terkecil = x;
	}
	else
	{
		terkecil = y;
	}
	
	if(terkecil%2 == 0)
	{
		printf("Malvika");
	}
	else
	{
		printf("Akshat");
	}
	
	return 0;
}
