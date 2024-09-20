#include <stdio.h>

int main()
{
	int input;
	scanf("%d", &input);
	if(input-2>0)
	{
		int j;
		for(j=2;j<input;j+=2)
		{
			if((input-j)%2==0)
			{
				printf("YES");
				break;
			}
			else if(j==input-2)
				printf("NO");
		}
	}
	else printf("NO");
	return 0;
}
