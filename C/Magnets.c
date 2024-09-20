#include <stdio.h>

int main()
{
	int T,i;
	scanf("%d", &T);
	char m[T][2];
	for(i=0;i<T;i++)
	{
		scanf("%s", m[i]);
	}
	int sum=1;
	for(i=0;i<T;i++)
	{
		if(m[i][1] == m[i+1][0])
			sum++;
	}	
	printf("%d", sum);
	
	return 0;
}
