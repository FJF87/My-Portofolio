#include <stdio.h>
#include <stdlib.h>

void showAscii(char *str)
{
	int i=0;
	int total = 0;
	while(str[i] != '\0')
	{
		total += (int)str[i];
		printf("%c nomornya %d\n", str[i], str[i]);
		i++;
	}
	printf("totalnya: %d\n", total);
}

int main()
{
	char kode[100];
	int masih = 1;
	do{
		printf("Masukkan kode: ");
		fflush(stdin);
		scanf("%[^\n]", kode);
		showAscii(kode);
		printf("apakah masih mau lanjut(1=ya, 0=tidak) ? ");
		scanf("%d", &masih);
	}while(masih == 1);
	
	return 0;
}
