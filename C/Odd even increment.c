#include <stdio.h>

int main()
{
	int T,i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		int n;
		scanf("%d", &n);
		int j,arr[n],oke=0;
		for(j=0;j<n;j++)
		{
			scanf("%d", &arr[j]);
			arr[j] %= 2;
		}
		int a,b;
		for(j=0;j<n;j+=2)
		{
			if(arr[j] != arr[0])
			{
				a=0;
				break;
			}
			else if(j+2>=n)
				a=1;
		}
		for(j=1;j<n;j+=2)
		{
			if(arr[j] != arr[1])
			{
				b=0;
				break;
			}
			else if(j+2>=n)
				b=1;
		}
		if(a==1 && b==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//1
//6
//3 5 1 6 3 1
