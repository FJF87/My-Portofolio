#include <stdio.h>
#include <string.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		char characters[51];
		scanf("%s", characters);
		int j, ok=0;
		int midstr = strlen(characters) / 2;
		for(j=0;j<midstr-1;j++)
		{
			if(characters[j] != characters[j+1])
			{
				ok = 1;
			}
		}
		
		if(ok == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
