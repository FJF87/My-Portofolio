#include <stdio.h>
#include <string.h>

struct barang
{
	char code[7];
	char name[20];
	char disease[20];
	int stok;
	float price;
};

int codeExist(struct barang obat[], char *inputCode)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(strcmp(inputCode, obat[i].code)==0)
		{
			return i;
		}
	}
	return -1;
}

int inputCode(struct barang obat[])
{
	char inputCode[7];
	int kodeObat = 0;
	
	printf("Enter medicine code: ");
	scanf("%s", &inputCode);
	kodeObat = codeExist(obat, inputCode);
	while(kodeObat < 0 || kodeObat > 3)
	{
		printf("\nMedicine code doesn't exist!\n\n");
		printf("Enter medicine code: ");
		scanf("%s", &inputCode);
		kodeObat = codeExist(obat, inputCode);
	}
	
	return kodeObat;
}

void show(struct barang obat[])
{
	printf("\t\t\t\t+----------------------+\n");
	printf("\t\t\t\t+    SUNIB Hospital    +\n");
	printf("\t\t\t\t+----------------------+\n");
	printf("+");
	int i;
	for(i=0;i<97;i++) printf("-");
	printf("+\n");
	printf("| %-3s | %-15s | %-21s | %-21s | %-5s | %-15s |\n", "No.", "Medicine Code", "Medicine Name", "Disease", "Stock", "Price");
	printf("+");
	for(i=0;i<97;i++) printf("-");
	printf("+\n");
	
	for(i=0;i<4;i++)
	{
		char completePrice[15] = "Rp. ";
		char strPrice[8];
		sprintf(strPrice, "%.3f", obat[i].price);
		strcat(completePrice, strPrice);
		strcat(completePrice, ",-");
		printf("| %c%d%c | %-15s | %-21s | %-21s | %-5d | %-15s |\n", '0', i+1, '.' , obat[i].code, obat[i].name, obat[i].disease, obat[i].stok, completePrice);
	}
	
	printf("+");
	for(i=0;i<97;i++) printf("-");
	printf("+\n\n");
	
	printf("Menu :\n");
	printf("[1.] Add Stock\n");
	printf("[2.] Sell\n");
	printf("[3.] Exit\n\n");
}

void add(struct barang obat[])
{
	int indexObat = inputCode(obat);
	int jumlahTambah = 0;
	do{
		printf("\nEnter medicine quantity [1-100]: ");
		scanf("%d", &jumlahTambah);
	}while(jumlahTambah < 1 || jumlahTambah > 100);
	
	obat[indexObat].stok += jumlahTambah;
	
	printf("\n\nPress Enter to continue...\n");
	getch();
}

void sell(struct barang obat[])
{
	int indexObat = inputCode(obat);
	int jumlahJual = 0;
	do{
		printf("\nEnter medicine quantity [1-%d]: ", obat[indexObat].stok);
		scanf("%d", &jumlahJual);
	}while(jumlahJual < 1 || jumlahJual > obat[indexObat].stok);
	
	float hargaJual = obat[indexObat].price * jumlahJual;
	obat[indexObat].stok -= jumlahJual;
	
	printf("\n\n");
	printf("+----Total Price----+\n");
	printf(" Rp. %.3f,-\n", obat[indexObat].price);
	printf(" Quantity: %d\n", jumlahJual);
	printf(" ------------------X\n");
	printf(" Total: Rp. %.3f,-\n", hargaJual);
	printf("+-------------------+\n\n");
	printf("\n\nPress Enter to continue...\n");
	getch();
}

void exitProgram()
{
	printf("\n-- Thank You --\n");
	printf("Press Enter to continue...\n");
	getch();
}

int main()
{
	struct barang obat[4] = {
		{"DIZ001", "Paramex", "Dizziness", 120, 14.000},
		{"FLU001", "Panadol", "Flu & Fever", 57, 8.000},
		{"DIA001", "Diatabs", "Diarrhea", 10, 6.500},
		{"DIA002", "Diapet", "Diarrhea", 18, 6.000},
	};
	
	int input = 0;
	
	do{
		system("cls");
		show(obat);
		do{
			printf("Input Choice [1-3]: ");
			scanf("%d", &input);
			printf("\n");
		}while(input < 1 || input > 3);
		
		switch(input)
		{
			case 1:
				add(obat);
				break;
			case 2:
				sell(obat);
				break;
			case 3:
				exitProgram();
		}
	}while(input != 3);
	
	return 0;
}
