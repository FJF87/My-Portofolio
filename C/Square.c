#include <stdio.h>
#include <stdlib.h>

void printStar(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)
				printf("*\n");
			else if(i==0 || j==0 || i==n-1)
				printf("*");
			else
				printf(" ");
		}
	}
}

int main()
{
	//int input,benar=0;
//	char input[100];
//	do{
//		printf("masukkan angka: ");
//		scanf("%[^\n]", input);
//		int i=0,hasil=0;
//		do{
//			if(!(input[i]>=48 && input[i]<=57))
//			{
//				printf("not a number");
//				break;
//			}
//			else if(input[i+1]=='\0')
//			{
//				hasil = atoi(input);
//				printf("hasil = %d", hasil);
//			}
//		}while(input[i+1]!='\0');
//	}while(benar!=0);
	int input;
	printf("masukkan angka: ");
	scanf("%d", &input);
	printStar(input);
	
	return 0;
}
