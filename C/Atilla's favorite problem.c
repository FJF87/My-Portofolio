#include <stdio.h>

int main()
{
	int T,i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		int numAlp;
		scanf("%d", &numAlp);
		char str[numAlp];
		scanf("%s", str);
		int j;
		char biggest = str[0];
		for(j=1;j<numAlp;j++)
		{
			if(str[j]>biggest)
				biggest = str[j];
		}
		printf("%d\n", biggest-96);
	}
	return 0;
}
