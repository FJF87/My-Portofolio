#include <stdio.h>
#include <math.h>

int lastIndex = 0;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int *maxHeapTree)
{
	if(lastIndex >= 31)
	{
		printf("Tree is full");
	}
	else
	{
		int newData = 0;
	
		do{
			printf("Input your data [1-100]: ");
			scanf("%d", &newData);
		}while(newData < 1 || newData > 100);
		
		maxHeapTree[lastIndex] = newData;
		
		int indexNow = lastIndex;
		while(indexNow > 0)
		{
			int indexParent = (indexNow - 1) / 2;
			
			if(maxHeapTree[indexParent] < maxHeapTree[indexNow])
			{
				swap(&maxHeapTree[indexParent], &maxHeapTree[indexNow]);
				indexNow = indexParent;
			}
			else
			{
				break;
			}
		}
		
		lastIndex += 1;
		
		printf("Insert Success");
	}
}

void view(int *maxHeapTree)
{
	int num = 0;
	int i = 0;
	
	printf("Only 5 level shown\n");
	printf("                                      ");
	for(i=0;i<1;i++)
	{
		if(maxHeapTree[num] == 0)
		{
			printf("NL\n");
			num++;
		}
		else
		{
			printf("%-2d\n", maxHeapTree[num++]);
		}
	}
	
	printf("                   ");
	for(i=0;i<2;i++)
	{
		if(maxHeapTree[num] == 0)
		{
			printf("NL                                     ");
			num++;
		}
		else
		{
			printf("%-2d                                     ", maxHeapTree[num++]);
		}
	}
	printf("\n");
	
	printf("         ");
	for(i=0;i<4;i++)
	{
		if(maxHeapTree[num] == 0)
		{
			printf("NL                  ");
			num++;
		}
		else
		{
			printf("%-2d                  ", maxHeapTree[num++]);
		}
	}
	printf("\n");
	
	printf("    ");
	for(i=0;i<8;i++)
	{
		if(maxHeapTree[num] == 0)
		{
			printf("NL        ");
			num++;
		}
		else
		{
			printf("%-2d        ", maxHeapTree[num++]);
		}
	}
	printf("\n");
	
	printf(" ");
	for(i=0;i<16;i++)
	{
		if(maxHeapTree[num] == 0)
		{
			printf("NL   ");
			num++;
		}
		else
		{
			printf("%-2d   ", maxHeapTree[num++]);
		}
	}
	printf("\n");
}

void pop(int *maxHeapTree)
{
	if(lastIndex == 0)
	{
		printf("Tree is empty\n");
	}
	else
	{
		lastIndex--;
		maxHeapTree[0] = maxHeapTree[lastIndex];
		maxHeapTree[lastIndex] = 0;
		
		int indexNow = 0;
		
		while(indexNow < lastIndex)
		{
			int leftChild = 2 * indexNow + 1;
			int rightChild = 2 * indexNow + 2;
			
			if(leftChild > lastIndex)
			{
				break;
			}
			else
			{
				int biggest = 0;
			
				if(maxHeapTree[leftChild] < maxHeapTree[rightChild])
				{
					biggest = maxHeapTree[rightChild];
				}
				else
				{
					biggest = maxHeapTree[leftChild];
				}
				
				if(maxHeapTree[indexNow] < maxHeapTree[leftChild] || maxHeapTree[indexNow] < maxHeapTree[rightChild])
				{
					if(maxHeapTree[leftChild] == biggest)
					{
						swap(&maxHeapTree[indexNow], &maxHeapTree[leftChild]);
						indexNow = leftChild;
					}
					else
					{
						swap(&maxHeapTree[indexNow], &maxHeapTree[rightChild]);
						indexNow = rightChild;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
}

void terminate(int *maxHeapTree)
{
	while(maxHeapTree[0] != 0)
	{
		pop(maxHeapTree);
	}
}

void showMenu()
{
	printf("MAX HEAP TREE\n");
	printf("=============\n");
	printf("1. Insert\n");
	printf("2. View\n");
	printf("3. Pop\n");
	printf("4. Exit\n");
	printf("Choose: ");
}

void operation(int *maxHeapTree)
{
	int inputOperation = 0;
	
	do{
		do{
			system("cls");
			showMenu();
			scanf("%d", &inputOperation);
		}while(inputOperation < 1 && inputOperation > 4);
		
		switch(inputOperation)
		{
			case 1:
				insert(maxHeapTree);
				break;
			case 2:
				view(maxHeapTree);
				break;
			case 3:
				pop(maxHeapTree);
				printf("Delete Success");
				break;
			case 4:
				terminate(maxHeapTree);
				printf("Thank you for using this program\n");
		}
		
		getch();
	}while(inputOperation != 4);
}

int main()
{
	int maxHeapTree[32];
	
	int i = 0;
	for(i=0;i<32;i++)
	{
		maxHeapTree[i] = 0;
	}
	
	operation(maxHeapTree);
	
	return 0;
}
