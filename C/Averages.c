#include <stdio.h>

int main()
{
	int i,T;
	scanf("%d\n", &T);
	
	for(i=0;i<T;i++)
	{
		int nCS, nE;
		scanf("%d %d", &nCS, &nE);
		long long iqCSTotal = 0, iqETotal = 0;
		int iqCS[nCS], iqE[nE];
		double avgCSIq = 0.0, avgEIq = 0.0;
		
		int j;
		for(j=0;j<nCS;j++)
		{
			scanf("%d", &iqCS[j]);
			iqCSTotal += iqCS[j];
		}
		
		for(j=0;j<nE;j++)
		{
			scanf("%d", &iqE[j]);
			iqETotal += iqE[j];
		}
		
		avgCSIq = (double)iqCSTotal / (double)nCS;
		avgEIq = (double)iqETotal / (double)nE;
		
		int funnyEvent = 0;
		
		for(j=0;j<nCS;j++)
		{
			if(iqCS[j] < avgCSIq && iqCS[j] > avgEIq)
			{
				funnyEvent++;
			}
		}
		
		printf("%d\n", funnyEvent);
	}
	
	return 0;
}
