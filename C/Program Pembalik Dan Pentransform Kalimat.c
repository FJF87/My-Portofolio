#include <stdio.h>

int isLower(char a)
{
	if(a>=97 && a<=122)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int strlength(char *str)
{
	int i;
	while(str[i] != '\0')
	{
		i++;
	}
	
	return i;
}

char charToUpper(char a)
{
	if(a>=97 && a<=122)
	{
		a-=32;
	}
	
	return a;
}

char charToLower(char a)
{
	if(a>=65 && a<=90)
	{
		a+=32;
	}
	
	return a;
}

int main()
{
	int i=0;
	char S[101]="", S2[101]="", S3[101]="";
	printf("Selamat datang di program pembalik dan pentransform kata/kalimat\n");
	printf("Silahkan mengetikkan kata/kalimat yang ingin diedit : ");
	scanf("%[^\n]", S);
	int panjang = strlength(S) - 1;
	int j = panjang;
	while(i<=panjang){
		S2[j] = S[i];
		i++;
		j--;
	};
	printf("Hasil setelah dibalik : ");
	printf("%s\n", S2);
	i=0;
	while(i<=panjang){
		if(isLower(S2[i]) == 1)
		{
			S3[i] = charToUpper(S2[i]);
		}
		else
		{
			S3[i] = charToLower(S2[i]);
		}
		i++;
	};
	printf("Hasil setelah dibalik dan ditransform : ");
	printf("%s", S3);
	return 0;
}
