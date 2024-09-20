#include <stdio.h>

int prima(int angka)
{
	if(angka==2) return 2;
	else if(angka<2) return 0;
	else if(angka>2)
	{
		int i;
		for(i=2;i<angka;i++)
		{
			if(angka%i==0)
			{
				return 0;
			}
			else if(i==angka-1)
			{
				return angka;
			}
		}
	}
}

int main()
{
	int i,input;
	printf("masukkan n angka prima yang anda inginkan: ");
	scanf("%d", &input);
	int angka=2,arr[input];
	for(i=0;i<input;i++)
		arr[i] = 0;
	for(i=0;i<input;i++)
	{
		while(arr[i]==0)
		{
			if(prima(angka)!=0)
				arr[i] = prima(angka);
			angka++;
		}
	}
	for(i=0;i<input;i++)
		printf("%d ", arr[i]);
	
	return 0;
}
