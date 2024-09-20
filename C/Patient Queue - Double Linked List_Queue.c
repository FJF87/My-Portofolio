#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient{
	char name[30];
	char ID[10];
	int age;
	char description[200];
	char codeStr[10];
	int codeNumber;
	struct patient *next;
};

void inputData(struct patient *newPatient)
{
	do{
		printf("Input patient name[4-25]: ");
		fflush(stdin);
		scanf("%[^\n]", newPatient->name);
	}while(strlen(newPatient->name) < 4 || strlen(newPatient->name) > 25);
	
	do{
		printf("Input patient age[>= 0]: ");
		scanf("%d", &newPatient->age);
	}while(newPatient->age < 0);
	
	do{
		printf("Input patient ID[5]: ");
		scanf("%s", newPatient->ID);
	}while(strlen(newPatient->ID) != 5);
	
	do{
		printf("Input description[>= 6 characters]: ");
		fflush(stdin);
		scanf("%[^\n]", newPatient->description);
	}while(strlen(newPatient->description) < 6);
	
	do{
		printf("Input code[Red|Yellow|Green]: ");
		scanf("%s", newPatient->codeStr);
	}while(strcmp(newPatient->codeStr, "Red") != 0 && strcmp(newPatient->codeStr, "Yellow") != 0 && strcmp(newPatient->codeStr, "Green") != 0);
	
	if(strcmp(newPatient->codeStr, "Red") == 0) newPatient->codeNumber = 3;
	else if(strcmp(newPatient->codeStr, "Yellow") == 0) newPatient->codeNumber = 2;
	else newPatient->codeNumber = 1;
}

void insertPatient(struct patient **head, struct patient **tail)
{
	struct patient *newPatient = (struct patient*) calloc(1, sizeof(struct patient));
	inputData(newPatient);
	
	if(*head == NULL)
	{
		*head = newPatient;
		*tail = newPatient;
		newPatient->next = NULL;
	}
	else
	{
		if(newPatient->codeNumber == 3)
		{
			struct patient *ptr = *head;
			struct patient *ptrBefore = NULL;
			while(ptr != NULL)
			{
				if(ptr->codeNumber == 3)
				{
					ptrBefore = ptr;
					ptr = ptr->next;
				}
				else break;
			}
			
			if(ptrBefore == NULL) *head = newPatient;
			else ptrBefore->next = newPatient;
			
			newPatient->next = ptr;
			if(ptr == NULL) *tail = newPatient;
		}
		else if(newPatient->codeNumber == 2)
		{
			struct patient *ptr = *head;
			struct patient *ptrBefore = NULL;
			while(ptr != NULL)
			{
				if(ptr->codeNumber >= 2)
				{
					ptrBefore = ptr;
					ptr = ptr->next;
				}
				else break;
			}
			
			if(ptrBefore == NULL) *head = newPatient;
			else ptrBefore->next = newPatient;
			
			newPatient->next = ptr;
			if(ptr == NULL) *tail = newPatient;
		}
		else
		{
			(*tail)->next = newPatient;
			*tail = newPatient;
			newPatient->next = NULL;
		}
	}
	
	printf("data added successfully\n");
	printf("press any key to continue . . . \n");
	getch();
}

void viewList(struct patient **head, struct patient **tail)
{
	if(*head == NULL)
	{
		printf("There is no queue yet!\n");
	}
	else
	{
		struct patient *ptr = *head;
		int i;
		
		printf("Patient List:\n");
		for(i=0;i<98;i++) printf("-");
		printf("\n");
		printf("| %-3s | %-27s | %-8s | %-4s | %-30s | %-7s |\n", "No", "Name", "ID", "Age", "Description", "Code");
		for(i=0;i<98;i++) printf("-");
		printf("\n");
		i=1;
		do{
			printf("| %-3d | %-27s | %-8s | %-4d | %-30s | %-7s |\n", i, ptr->name, ptr->ID, ptr->age, ptr->description, ptr->codeStr);
			i++;
			ptr = ptr->next;
		}while(ptr != NULL);
		
		for(i=0;i<98;i++) printf("-");
		printf("\n");
	}
	printf("Press any key to continue . . . \n");
	getch();
}

void nextQueue(struct patient **head, struct patient **tail)
{
	if(*head == NULL)
	{
		printf("There is no queue yet!\n");
		printf("Press any key to continue . . . \n");
		getch();
	}
	else
	{
		printf("The next patient is:\n");
		printf("Name\t\t: %s\n", (*head)->name);
		printf("Age\t\t: %d\n", (*head)->age);
		printf("ID\t\t: %s\n", (*head)->ID);
		printf("Description\t: %s\n", (*head)->description);
		printf("Code\t\t: %s\n", (*head)->codeStr);
		printf("Press any key to continue . . . \n");
		getch();
		
		*head = (*head)->next;
	}
}

void showMenu()
{
	printf("Sunib Patient Entry\n");
	printf("====================\n");
	printf("[1] Insert Patient\n");
	printf("[2] View List\n");
	printf("[3] Next Queue\n");
	printf("[4] Exit\n");
	printf(">>> ");
}

int main()
{
	struct patient *head = NULL;
	struct patient *tail = NULL;
	
	int input;
	do{
		input = 0;
		do{
			system("cls");
			showMenu();
			scanf("%d", &input);
		}while(input < 1 || input > 4);
		
		switch(input)
		{
			case 1:
				insertPatient(&head, &tail);
				break;
			case 2:
				viewList(&head, &tail);
				break;
			case 3:
				nextQueue(&head, &tail);
				break;
			case 4:
				printf("Thank you for using this program\n");
				printf("Press any key to continue . . . \n");
				getch();
				break;
		}
	}while(input != 4);
	
	return 0;
}
