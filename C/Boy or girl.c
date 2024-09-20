#include <stdio.h>
#include <string.h>

int main()
{
	char s[101]="";
	scanf("%s",s);
	char distinct[101]="";
	int i,index=1;
	int lstr = strlen(s);
	distinct[0] = s[0];
	for(i=1;i<lstr;i++)
	{
		int j=0;
		while(distinct[j]!='\0')
		{
			if(s[i]==distinct[j]) break;
			else if(distinct[j+1]=='\0')
			{
				distinct[index] = s[i];
				index++;
			}
			j++;
		}
	}
	lstr = strlen(distinct);
	//printf("index:%d\n", index);
	//printf("lstr now:%d distinct:%s\n", lstr,distinct);
	if(index%2==0)
		printf("CHAT WITH HER!");
	else
		printf("IGNORE HIM!");
	
	return 0;
}
