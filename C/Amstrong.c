#include <stdio.h>

int pangkat3(int x)
{
	int i,hasil=1;
	for(i=0;i<3;i++)
	{
		hasil = hasil *x;
	}
	return hasil;
}

int semua(int x)
{
	int total=0;
	int ratusan = x / 100;
	int puluhan = (x - (ratusan * 100))/10;
	int satuan = x - (ratusan*100) - (puluhan*10);
	total = pangkat3(ratusan) + pangkat3(puluhan) + pangkat3(satuan);
	return total;
}

void amstrong()
{
	int i;
	for(i=100;i<1000;i++)
	{
		if(semua(i)==i)
		{
			printf("%d\n", i);
		}
	}
}

int main()
{
	amstrong();
	return 0;
}
