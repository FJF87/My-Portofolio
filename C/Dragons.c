#include <stdio.h>

typedef struct dragon{
	int level;
	int bonus;
}drg;

void swap(drg *unit1, drg *unit2)
{
	drg temp = *unit1;
	*unit1 = *unit2;
	*unit2 = temp;
}

int main()
{
	int s, n;
	scanf("%d %d", &s, &n);
	drg dragon[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &dragon[i].level, &dragon[i].bonus);
	}
	
	int j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(dragon[i].level>dragon[j].level)
				swap(&dragon[i], &dragon[j]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(dragon[i].level < s)
		{
			s += dragon[i].bonus;
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
	return 0;
}
