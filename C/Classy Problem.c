#include <stdio.h>
#include <string.h>

void swapStr(char *str1, char *str2)
{
	char temp[50] = "";
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

int main()
{
	int i, T;
	scanf("%d", &T);
	
	for(i=0; i<T; i++)
	{
		int j, n;
		scanf("%d", &n);
		
		char name[n][32];
		char classStr[100];
		
		// for each people, give 3 int, 0 for "lower", 1 for "middle", 2 for "upper"
		char wordClassCount[n][12];

		int a,b;
		for(a=0;a<n;a++)
		{
			for(b=0;b<11;b++)
			{
				wordClassCount[a][b] = '1';
			}
			wordClassCount[a][11] = '\0';
		}
		
		for(j=0; j<n; j++)
		{
			scanf("\n%[^:]: %s class", name[j], classStr);
			
			int k=0, l=0, changeOrder=0;
			char currClass[7] = "";
			
			while(k <= strlen(classStr))
			{
				if(classStr[k] == '-')
				{
					currClass[l] = '\0';
					if( strcmp(currClass, "lower")==0 )
					{
						wordClassCount[j][changeOrder] = '0';
					}
					else if( strcmp(currClass, "middle")==0 )
					{
						wordClassCount[j][changeOrder] = '1';
					}
					else if( strcmp(currClass, "upper")==0 )
					{
						wordClassCount[j][changeOrder] = '2';
					}
					
					changeOrder++;
					memset(currClass, 0, strlen(currClass));
					l = -1;
				}
				else
				{
					currClass[l] = classStr[k];
				}
				
				k++;
				l++;
			}
			
			currClass[l] = '\0';
			if( strcmp(currClass, "lower")==0 )
			{
				wordClassCount[j][changeOrder] = '0';
			}
			else if( strcmp(currClass, "middle")==0 )
			{
				wordClassCount[j][changeOrder] = '1';
			}
			else if( strcmp(currClass, "upper")==0 )
			{
				wordClassCount[j][changeOrder] = '2';
			}
		}
		
		int k,l,biggest;

		for(a=0;a<n;a++)
		{
			for(k=0; k<9; k++)
			{
				biggest = k;
				for(l=k+1; l<10; l++)
				{
					if( wordClassCount[a][biggest] < wordClassCount[a][l] )
					{
						biggest = l;
					}
				}
				
				char temp = wordClassCount[a][biggest];
				wordClassCount[a][biggest] = wordClassCount[a][k];
				wordClassCount[a][k] = temp;
			}
		}
		
		for(k=0; k<n-1; k++)
		{
			biggest = k;
			for(l=k+1; l<n; l++)
			{
				if( strcmp(wordClassCount[biggest], wordClassCount[l])<0 )
				{
					biggest = l;
				}
				else if( strcmp(wordClassCount[biggest], wordClassCount[l])==0 )
				{
					if( strcmp(name[biggest], name[l])>0 )
					{
						biggest = l;
					}
				}
			}
			swapStr(wordClassCount[biggest], wordClassCount[k]);
			swapStr(name[biggest], name[k]);
		}
		
		for(k=0;k<n;k++)
		{
			printf("%s\n", name[k]);
		}
		
		printf("==============================\n");
	}
	
	return 0;
}
