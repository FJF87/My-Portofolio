#include <stdio.h>

int main()
{
	unsigned int T,i;
	scanf("%u", &T);
	for(i=0;i<T;i++)
	{
		int width;
		scanf("%d", &width);
		char str[width];
		scanf("%s", str);
		int j;
		for(j=0;j<width;j++)
		{
			if(str[j] == 'U')
			{
				str[j] = 'D';
			}
			else if(str[j] == 'D')
			{
				str[j] = 'U';
			}
		}
		printf("%s\n", str);
	}
	
	return 0;
}
