#include <stdio.h>

int main()
{
	int matriks1[3][4] = { {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	int matriks2[4][3] = { {13,14,15}, {12,11,10}, {8,7,6}, {4,3,2} };
	int hasil[3][3];
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			hasil[i][j] = 0;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<4;k++)
			{
				hasil[i][j] = hasil[i][j] + matriks1[i][k] * matriks2[k][j];
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ", hasil[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
