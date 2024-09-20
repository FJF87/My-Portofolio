#include <stdio.h>

float max(float *arr, int n)
{
	int i;
	float terbesar = arr[0];
	for(i=1;i<n;i++)
	{
		if(terbesar<arr[i])
			terbesar = arr[i];
	}
	return terbesar;
}

int main()
{
	int i,n;
	scanf("%d", &n);
	float arr[n];
	for(i=0;i<n;i++)
		scanf("%f", &arr[i]);
	float terbesar = max(arr,n);
	float jumlah = 0.00;
	for(i=0;i<n;i++)
	{
		printf("%f\n", jumlah);
		jumlah += arr[i] / terbesar;
	}
	printf("jumlah:%f\n", jumlah);
	printf("hasil %f", (jumlah/n)*100);
	
	return 0;
}
