#include <stdio.h>

int pangkat(bil,pang)
{
    int hasil = 1, i = 0;
    while(i<pang)
    {
        hasil = hasil * bil;
        i++;
    }
    return hasil;
}

int main()
{
	printf("%d", pangkat(10,2));
	return 0;
}
