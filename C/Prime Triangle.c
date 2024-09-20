#include <stdio.h>

int butuhAngka(int baris)
{
	int i,jumlah=0;
	if(baris<1)
	{
		jumlah=0;
	}
	else if(baris>=1)
	{
		for(i=1;i<=2*baris-1;i+=2)
		{
			jumlah+=i;
		}
	}
	return jumlah;
}

int primakah(int x)
{
	if(x<2) return 0;
	else if(x==2) return 2;
	else if(x>2)
	{
		int i;
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				return 0;
			}
			else if(i==x-1)
			{
				return x;
			}
		}
	}
}

void segitiga(int baris,int *arr, int butuh)
{
	int i,spasi,elemenke=0;
	for(i=0,spasi=baris-1;i<baris;i++,spasi--)
	{
		int j;
		for(j=0;j<spasi;j++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			printf("%d ", arr[elemenke]);
			elemenke++;
		}
		printf("\n");
	}
}

int main()
{
	int baris;
	printf("masukkan jumlah baris yang ingin diprint: ");
	scanf("%d", &baris);
	int butuh=butuhAngka(baris);
	int angka=2,i,arr[butuh];
	for(i=0;i<butuh;i++)
	{
		arr[i]=0;
	}
	for(i=0;i<butuh;i++)
	{
		while(arr[i]==0)
		{
			if(primakah(angka)!=0)
			{
				arr[i] = primakah(angka);
			}
			angka++;
		}
	}
	segitiga(baris,arr,butuh);
	
	return 0;
}
