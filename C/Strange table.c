#include <stdio.h>

//blom

int main()
{
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		long int n,m,x,j,k, colByCol, rowByCol;
		scanf("%ld %ld %ld", &n,&m,&x);
		for(j=1;j<=m;j++)
		{
			if(x <= n*j)
			{
				colByCol = j;
				for(k=0;k<n;k++)
				{
					if(x == n*j-k)
					{
						rowByCol = n-k;
					}
				}
			}
		}
		
		printf("row:%ld col:%ld\n", rowByCol,colByCol);
	}
	
	return 0;
}
