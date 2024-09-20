#include <stdio.h>
#include <string.h>

int main()
{
	int T,i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		char S[101]="";
		scanf("%s", &S);
		int lstr = strlen(S);
		if(lstr<=10)
		{
			printf("%s\n", &S);
		}
		else
		{
			int lmidstr = strlen(S) - 2;
			printf("%c%d%c\n", S[0], lmidstr, S[lstr-1]);
		}
	}
	return 0;
}
