#include <stdio.h>

int main()
{
	unsigned int i,T;
	scanf("%u", &T);
	for(i=0;i<T;i++)
	{
		int allODD = 1, allEVEN=1;
		unsigned int n,j;
		scanf("%u", &n);
		long int arr[n];
		for(j=0;j<n;j++)
		{
			scanf("%ld", &arr[j]);
		}
		for(j=0;j<n;j++)
		{
			if(arr[j]%2 == 0)
			{
				allODD = 0;
				break;
			}
		}
		for(j=0;j<n;j++)
		{
			if(arr[j]%2 == 0)
			{
				allEVEN = 0;
				break;
			}
		}
		if(allODD == 1 || allEVEN == 1)
		{
			printf("0\n");
		}
		else
		{
			unsigned int erase = 0;
			for(j=0;j<n;j++)
			{
				if(arr[j]%2 == 1)
				{
					erase++;
				}
			}
			printf("%u\n", erase);
		}
	}
	
	return 0;
}
