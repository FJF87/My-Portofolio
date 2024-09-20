#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		char str[11][11];
		int j,k,point=0;
		for(j=0;j<10;j++)
		{
			scanf("%s", &str[j]);
		}
		
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			{
				if(str[j][k] == 'X')
				{
					if((j==0 || j==9) || (k==0 || k==9))
					{
						point+=1;
					}
					else if((j==1 || j==8) || (k==1 || k==8))
					{
						point+=2;
					}
					else if((j==2 || j==7) || (k==2 || k==7))
					{
						point+=3;
					}
					else if((j==3 || j==6) || (k==3 || k==6))
					{
						point+=4;
					}
					else if((j==4 || j==5) || (k==4 || k==5))
					{
						point+=5;
					}
				}
			}
		}
		
		printf("%d\n", point);
	}
	
	return 0;
}
