#include <stdio.h>

int main()
{
	int T,i,awesome=0;
	scanf("%d", &T);
	int arr[T];
	for(i=0;i<T;i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int lowest = arr[0];
	int highest = arr[0];
	
	for(i=1;i<T;i++)
	{
		if(arr[i] > highest)
		{
			highest = arr[i];
			awesome++;
		}
		else if(arr[i] < lowest)
		{
			lowest = arr[i];
			awesome++;
		}
	}
	printf("%d", awesome);
	
	return 0;
}
