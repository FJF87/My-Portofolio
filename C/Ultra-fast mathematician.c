#include <stdio.h>
#include <string.h>

int main()
{
	char a[101], b[101];
	scanf("%s", a);
	scanf("%s", b);
	int i,len = strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]!=b[i])
			a[i] = '1';
		else
			a[i] = '0';
	}
	printf("%s", a);
}
