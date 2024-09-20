#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=1;i<=T;i++)
	{
		if(i%2 == 1)
			printf("I hate ");
		else if(i%2 == 0)
			printf("I love ");
		if(i == T)
			printf("it");
		else
			printf("that ");
	}
	return 0;
}
