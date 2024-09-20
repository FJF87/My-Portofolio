#include <stdio.h>

int main()
{
	int number;
	scanf("%d", &number);
	int res = number -2;
	if(res%2 == 0 && res != 0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
