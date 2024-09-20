#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		char str[4];
		scanf("%s", str);
		if(str[0] == 89 || str[0] == 121)
		{
			if(str[1] == 69 || str[1] == 101)
			{
				if(str[2] == 83 || str[2] == 115)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}
