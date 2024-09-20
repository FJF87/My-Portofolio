#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int i,N;
	scanf("%d", &N);
	int arr[N];
	for(i=0;i<N;i++)
		scanf("%d", &arr[i]);
	
	int j;
	for(i=0;i<N;i++)
		for(j=0;j<N-i;j++)
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
	
	if(N%2 == 0)
	{
		int acc = N / 2 - 1;
		printf("%d", arr[acc]);
	}
	else
	{
		int acc = N / 2;
		printf("%d", arr[acc]);
	}
	
	return 0;
}
