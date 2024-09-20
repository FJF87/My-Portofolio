#include <stdio.h>

int main()
{
	int n, time;
	scanf("%d %d", &n, &time);
	char str[n];
	scanf("%s", str);
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(str[j] == 'B' && str[j+1]=='G')
			{
				char temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
				j++;
			}
		}
	}
	printf("%s", str);
	return 0;
}
