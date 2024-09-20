#include <stdio.h>

int strlength(char *str)
{
	int i;
	while(str[i] != '\0')
	{
		i++;
	}
	
	return i;
}

int isAlphabet(char a)
{
	if((a>=65 && a<=90) || (a>=97 && a<=122))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char S[101]="", vokal[101]="", konsonan[101]="", selainHuruf[101]="";
	int cek=0;
	int jumlahVokal=0, jumlahKonsonan=0, jumlahSpasi=0, jumlahSelainHuruf=0;
	printf("Selamat datang di program pengeckekan huruf\n");
	printf("Silahkan mengetikkan kata/kalimat yang ingin dihitung hurufnya : ");
	scanf("%[^\n]", S);
	while(cek<strlength(S)){
		if(S[cek] == 'a' || S[cek] == 'A' 
		|| S[cek] == 'i' || S[cek] == 'I' 
		|| S[cek] == 'u' || S[cek] == 'U' 
		|| S[cek] == 'e' || S[cek] == 'E'
		|| S[cek] == 'o' || S[cek] == 'O'){
			vokal[jumlahVokal] = S[cek];
			jumlahVokal++;
		}
		else if(S[cek] == ' '){
			jumlahSpasi++;
		}
		else if(isAlphabet(S[cek])){
			konsonan[jumlahKonsonan] = S[cek];
			jumlahKonsonan++;
		}
		else{
			selainHuruf[jumlahSelainHuruf] = S[cek];
			jumlahSelainHuruf++;
		}
		cek++;
	};
	printf("huruf vokal : %s\n", vokal);
	printf("jumlah vokal : %d\n", jumlahVokal);
	printf("huruf konsonan : %s\n", konsonan);
	printf("jumlah konsonan : %d\n", jumlahKonsonan);
	printf("karakter selain huruf : %s\n", selainHuruf);
	printf("jumlah karakter selain huruf : %d\n", jumlahSelainHuruf);
	printf("jumlah spasi : %d\n\n", jumlahSpasi);
	return 0;
}
