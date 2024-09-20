// Finpro Data Structure - Tries
// 2702223310 - Ofellia Marvella Amin
// 2702350075 - Annisa Lutfiah Rahmah
// 2702221936 - Jeffrey Ferdinand Hartono

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define ALPHABET_SIZE 95 

struct data {
    char judulBuku[51];
    char pengarang[51];
    int tahunTerbit;
    char penerbit[31];
    int kategori;
    int stockTotal;
};

struct kodeBuku {
    char hurufKode;
    struct data *dataBuku;
    struct node *next;
};

struct node {
    struct kodeBuku karakterKode[ALPHABET_SIZE];
};

struct dataList {
	struct data *dataBukuDiList;
	struct dataList *next;
};

void animation(char *text, int time)
{
	int i;
	for(i = 0; i < strlen(text); i++)
	{
		printf("%c", text[i]);
		Sleep(time);
	}
}

int countBook(struct dataList *head)
{
	int numberOfBook = 0;
	
	if(head != NULL)
	{
		struct dataList *ptr = head;
	
		do{
			ptr = ptr->next;
			numberOfBook++;
		}while(ptr != NULL);
	}
	
	return numberOfBook;
}

void lowercaseStr(char *str)
{
	int lengthOfStr = strlen(str);
	
	int i;
	for(i=0;i<lengthOfStr;i++)
	{
		str[i] = tolower(str[i]);
	}
}

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++) {
        newNode->karakterKode[i].hurufKode = 0;
        newNode->karakterKode[i].dataBuku = NULL;
        newNode->karakterKode[i].next = NULL;
    }
    return newNode;
}

struct node *createTrie() {
    return createNode();
}

void insertBook(struct node *root, const char *code, struct data *bookData) {
    struct node *current = root;
    int length = strlen(code);
    int i;

    for (i = 0; i < length; i++) {
        int index = code[i] - 32; 

        if (current->karakterKode[index].next == NULL) {
            current->karakterKode[index].hurufKode = code[i];
            current->karakterKode[index].next = createNode();
        }
        current = current->karakterKode[index].next;
    }
    current->karakterKode[0].dataBuku = bookData; 
}

void viewKategori() {
    printf("Kategori\n");
    printf("====================\n");
    printf("100 - Filsafat\n");
    printf("200 - Agama\n");
    printf("300 - Ilmu Sosial\n");
    printf("400 - Bahasa\n");
    printf("500 - Sains\n");
    printf("600 - Teknologi\n");
    printf("700 - Kesenian\n");
    printf("800 - Literatur\n");
    printf("900 - Sejarah\n");
    printf("=====================\n");
}

void generateKodeBuku(char *code, const char *judul, const char *pengarang, int tahun, int kategori) {
    int lenJudul = strlen(judul);
    int lenPengarang = strlen(pengarang);
    int sumOfChar = 0;
	int midIndex = lenJudul / 2;
    while (midIndex < lenJudul && isspace(judul[midIndex])) {
        midIndex++;
    }
    char kodeJudul[4] = {toupper(judul[0]), toupper(judul[midIndex]), toupper(judul[lenJudul-1]), '\0'};
    char kodePengarang[3] = {toupper(pengarang[0]), toupper(pengarang[lenPengarang-1]), '\0'};
    char kodeTahun[3];
    snprintf(kodeTahun, 3, "%02d", tahun % 100);

    char kodeKategori[2];
    snprintf(kodeKategori, 2, "%1d", kategori / 100);
    
    snprintf(code, 10, "%s%02d%s%s%s", kodeJudul, lenJudul, kodePengarang, kodeTahun, kodeKategori);
    code[10] = '\0';
}

void insertBookData(struct node *root, struct dataList **head) {
    char judul[51];
    int tahun;
    char pengarang[51];
    char penerbit[31];
    int kategori;
    int stok;
    char code[11];

    do {
        printf("Judul buku[1-30 karakter]: ");
        fflush(stdin);
        scanf(" %[^\n]s", judul);
    } while (strlen(judul) < 1 || strlen(judul) > 30);

    do {
        printf("Tahun terbit[1000-2024]: ");
        fflush(stdin);
        scanf("%d", &tahun);
    } while (tahun < 1000 || tahun > 2024);

    do {
        printf("Nama pengarang[1-30 karakter]: ");
        fflush(stdin);
        scanf(" %[^\n]s", pengarang);
    } while (strlen(pengarang) < 1 || strlen(pengarang) > 30);

    do {
        printf("Nama penerbit[1-20 karakter]: ");
        fflush(stdin);
        scanf(" %[^\n]s", penerbit);
    } while (strlen(penerbit) < 1 || strlen(penerbit) > 20);

    printf("\n");
    viewKategori();
    do {
        printf("Kategori(tulis angkanya): ");
        fflush(stdin);
        scanf("%d", &kategori);
    }while(kategori != 100 && kategori != 200 && kategori != 300 &&
             kategori != 400 && kategori != 500 && kategori != 600 &&
             kategori != 700 && kategori != 800 && kategori != 900);

    do {
        printf("Stok[1-100]: ");
        fflush(stdin);
        scanf("%d", &stok);
    }while(stok < 1 || stok > 100);

    generateKodeBuku(code, judul, pengarang, tahun, kategori);
    printf("Kode buku: %s\n", code);

    struct data *newBook = (struct data *)malloc(sizeof(struct data));
    strcpy(newBook->judulBuku, judul);
    strcpy(newBook->pengarang, pengarang);
    newBook->tahunTerbit = tahun;
    strcpy(newBook->penerbit, penerbit);
    newBook->kategori = kategori;
    newBook->stockTotal = stok;

    insertBook(root, code, newBook);
    
    struct dataList *newBookList = (struct dataList*)malloc(sizeof(struct dataList));
    newBookList->dataBukuDiList = newBook;
    newBookList->next = NULL;
    if(*head == NULL)
    {
    	*head = newBookList;
	}
	else
	{
		struct dataList *ptr = *head;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newBookList;
	}
	
	printf("\nInsert success !\n");
}

void displayBookInfo(struct data *bookData, const char *code) {
    if (bookData) {
        printf("| %-11s| %-31s| %-13d| %-31s| %-21s| %-12d| %-6d|\n",
               code, bookData->judulBuku, bookData->tahunTerbit, bookData->pengarang,
               bookData->penerbit, bookData->kategori, bookData->stockTotal);
    }
}

void traverseTrie(struct node *root, char *code, int level, void (*displayFunc)(struct data*, const char*)) {
    if (root == NULL) return;

    if (root->karakterKode[0].dataBuku != NULL) {
        code[level] = '\0';
        displayFunc(root->karakterKode[0].dataBuku, code);
    }
    
    int i;

    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (root->karakterKode[i].next != NULL) {
            code[level] = root->karakterKode[i].hurufKode;
            traverseTrie(root->karakterKode[i].next, code, level + 1, displayFunc);
        }
    }
}

void viewAllBookData(struct node *root) {
	viewKategori();
    char code[100];
    printf("\nData buku\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-11s| %-31s| %-13s| %-31s| %-21s| %-12s| %-6s|\n", "Kode buku", "Judul buku", "Tahun terbit", "Nama Pengarang", "Nama penerbit", "Kategori", "Stok");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
    traverseTrie(root, code, 0, displayBookInfo);
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
}

struct data* searchBook(struct node *root, const char *code) {
    struct node *current = root;
    int length = strlen(code);
    int i;

    for (i = 0; i < length; i++) {
        int index = code[i] - 32;

        if (current->karakterKode[index].next == NULL) {
            return NULL;
        }
        current = current->karakterKode[index].next;
    }
    return current->karakterKode[0].dataBuku;
}

void displayBookCode(struct data *bookData, const char *code) {
    if (bookData) {
        printf("| %-11s |\n", code);
    }
}

int isTrieEmpty(struct node *root) {
	int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (root->karakterKode[i].next != NULL || root->karakterKode[i].dataBuku != NULL) {
            return 0;
        }
    }
    return 1;
}

void deleteBook(struct node *root, struct dataList **head, char *kodeBuku)
{
	struct node *ptr = root;
	int codeLength = strlen(kodeBuku);
	int i, index;
	
	for (i = 0; i < codeLength; i++) {
        index = kodeBuku[i] - 32;
        
        if(ptr->karakterKode[index].hurufKode == kodeBuku[i])
        {
        	if(i == codeLength-1)
        	{
        		break;
			}
			else
			{
				ptr = ptr->karakterKode[index].next;
			}
		}
    }
    
    struct node *ptr2 = ptr;
    
    index = kodeBuku[i] - 32;
    ptr2 = ptr->karakterKode[index].next;
    struct data *getData = ptr2->karakterKode[0].dataBuku;
    
    
    struct dataList *ptrDataList1 = *head;
    struct dataList *ptrDataList2 = (**head).next;
    
    if(ptrDataList1->dataBukuDiList == getData)
    {
    	*head = ptrDataList2;
    	free(ptrDataList1);
	}
	else
	{
		while(ptrDataList2->dataBukuDiList != getData)
	    {
	    	ptrDataList1 = ptrDataList1->next;
	    	ptrDataList2 = ptrDataList2->next;
		}
		ptrDataList1->next = ptrDataList2->next;
		free(ptrDataList2);
	}
    
	free(getData);
    free(ptr2);
    ptr->karakterKode[index].next = NULL;
}

void updateStock(struct node *root, struct dataList **head) {
	int amountOfBook = countBook(*head);
	if (amountOfBook <= 0) {
        printf("Belum ada data buku.\n");
    	return;
	}
    char code[10];
    int newStock;
    int choice;

    viewAllBookData(root);
    do{
    	printf("\nMasukkan kode buku: ");
    	fflush(stdin);
    	scanf("%s", code);
	}while(strlen(code) != 10);

    struct data *bookData = searchBook(root, code);

    if (bookData) {
    	printf("==================\n");
        printf("Stok saat ini: %d\n", bookData->stockTotal);
        printf("\n1. Tambah stok\n");
        printf("2. Kurangi stok\n");
        do {
            printf(">> ");
            fflush(stdin);
            scanf("%d", &choice);
        }while (choice != 1 && choice != 2);
        printf("==================\n");

        if (choice == 1) {
        	do{
        		printf("\nMasukkan jumlah penambahan: ");
        		fflush(stdin);
            	scanf("%d", &newStock);
			}while(newStock < 1);
            
            bookData->stockTotal += newStock;
            printf("Stok berhasil ditambahkan\n");
        } else if (choice == 2) {
        	do{
        		printf("\nMasukkan jumlah pengurangan: ");
        		fflush(stdin);
            	scanf("%d", &newStock);
			}while(newStock < 1 || newStock > bookData->stockTotal);
            
            bookData->stockTotal -= newStock;
            printf("Stok berhasil dikurangi\n");
            if(bookData->stockTotal == 0)
            {
            	deleteBook(root, head, code);
            	printf("Data buku berhasil dihapus\n");
			}
        }
    } else {
        printf("Buku tidak ditemukan!\n");
    }
}

void choiceToSortBy()
{
	printf("Urutkan berdasarkan:\n");
	printf("1. Judul buku\n");
	printf("2. Nama pengarang\n");
	printf("3. Nama penerbit\n");
	printf("4. Tahun terbit\n");
	printf("5. Kategori buku\n");
}

void swap(struct dataList **a, struct dataList **b)
{
	struct dataList *temp = *a;
	*a = *b;
	*b = temp;
}

void sortBy(struct dataList *head, int amountOfBook, int choiceToSort, int order)
{
	struct dataList *sorted[amountOfBook];
	struct dataList *ptr = head;
	int i=0, j=0;
	for(i=0;i<amountOfBook;i++)
	{
		sorted[i] = ptr;
		ptr = ptr->next;
	}
	
	if(choiceToSort == 1)
	{
		if(order == 1)
		{
			int smallest;
			for(i=0;i<amountOfBook;i++)
			{
				smallest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					char str1[51], str2[51];
					strcpy(str1, sorted[j]->dataBukuDiList->judulBuku);
					lowercaseStr(str1);
					strcpy(str2, sorted[smallest]->dataBukuDiList->judulBuku);
					lowercaseStr(str2);
					if(strcmp(str1, str2)<0)
					{
						smallest = j;
					}
				}
				swap(&sorted[smallest], &sorted[i]);
			}
		}
		else
		{
			int biggest;
			for(i=0;i<amountOfBook;i++)
			{
				biggest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					char str1[51], str2[51];
					strcpy(str1, sorted[j]->dataBukuDiList->judulBuku);
					lowercaseStr(str1);
					strcpy(str2, sorted[biggest]->dataBukuDiList->judulBuku);
					lowercaseStr(str2);
					if(strcmp(str1, str2)>0)
					{
						biggest = j;
					}
				}
				swap(&sorted[biggest], &sorted[i]);
			}
		}
	}
	else if(choiceToSort == 2)
	{
		if(order == 1)
		{
			int smallest;
			for(i=0;i<amountOfBook;i++)
			{
				smallest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					char str1[51], str2[51];
					strcpy(str1, sorted[j]->dataBukuDiList->pengarang);
					lowercaseStr(str1);
					strcpy(str2, sorted[smallest]->dataBukuDiList->pengarang);
					lowercaseStr(str2);
					if(strcmp(str1, str2)<0)
					{
						smallest = j;
					}
				}
				swap(&sorted[smallest], &sorted[i]);
			}
		}
		else
		{
			int biggest;
			for(i=0;i<amountOfBook;i++)
			{
				biggest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					char str1[51], str2[51];
					strcpy(str1, sorted[j]->dataBukuDiList->pengarang);
					lowercaseStr(str1);
					strcpy(str2, sorted[biggest]->dataBukuDiList->pengarang);
					lowercaseStr(str2);
					if(strcmp(str1, str2)>0)
					{
						biggest = j;
					}
				}
				swap(&sorted[biggest], &sorted[i]);
			}
		}
	}
	else if(choiceToSort == 3)
	{
		if(order == 1)
		{
			int smallest;
			for(i=0;i<amountOfBook;i++)
			{
				smallest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					char str1[51], str2[51];
					strcpy(str1, sorted[j]->dataBukuDiList->penerbit);
					lowercaseStr(str1);
					strcpy(str2, sorted[smallest]->dataBukuDiList->penerbit);
					lowercaseStr(str2);
					if(strcmp(str1, str2)<0)
					{
						smallest = j;
					}
				}
				swap(&sorted[smallest], &sorted[i]);
			}
		}
		else
		{
			int biggest;
			for(i=0;i<amountOfBook;i++)
			{
				biggest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					char str1[51], str2[51];
					strcpy(str1, sorted[j]->dataBukuDiList->penerbit);
					lowercaseStr(str1);
					strcpy(str2, sorted[biggest]->dataBukuDiList->penerbit);
					lowercaseStr(str2);
					if(strcmp(str1, str2)>0)
					{
						biggest = j;
					}
				}
				swap(&sorted[biggest], &sorted[i]);
			}
		}
	}
	else if(choiceToSort == 4)
	{
		if(order == 1)
		{
			int smallest;
			for(i=0;i<amountOfBook;i++)
			{
				smallest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					if(sorted[j]->dataBukuDiList->tahunTerbit < sorted[smallest]->dataBukuDiList->tahunTerbit)
					{
						smallest = j;
					}
				}
				swap(&sorted[smallest], &sorted[i]);
			}
		}
		else
		{
			int biggest;
			for(i=0;i<amountOfBook;i++)
			{
				biggest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					if(sorted[j]->dataBukuDiList->tahunTerbit > sorted[biggest]->dataBukuDiList->tahunTerbit)
					{
						biggest = j;
					}
				}
				swap(&sorted[biggest], &sorted[i]);
			}
		}
	}
	else if(choiceToSort == 5)
	{
		if(order == 1)
		{
			int smallest;
			for(i=0;i<amountOfBook;i++)
			{
				smallest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					if(sorted[j]->dataBukuDiList->kategori < sorted[smallest]->dataBukuDiList->kategori)
					{
						smallest = j;
					}
				}
				swap(&sorted[smallest], &sorted[i]);
			}
		}
		else
		{
			int biggest;
			for(i=0;i<amountOfBook;i++)
			{
				biggest = i;
				for(j=i+1;j<amountOfBook;j++)
				{
					if(sorted[j]->dataBukuDiList->kategori > sorted[biggest]->dataBukuDiList->kategori)
					{
						biggest = j;
					}
				}
				swap(&sorted[biggest], &sorted[i]);
			}
		}
	}
	
	printf("\nData buku\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %-11s| %-31s| %-13s| %-31s| %-21s| %-12s| %-6s|\n", "Kode buku", "Judul buku", "Tahun terbit", "Nama Pengarang", "Nama penerbit", "Kategori", "Stok");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<amountOfBook;i++)
	{
		char kodeBuku[11];
		generateKodeBuku(kodeBuku, sorted[i]->dataBukuDiList->judulBuku, sorted[i]->dataBukuDiList->pengarang, sorted[i]->dataBukuDiList->tahunTerbit, sorted[i]->dataBukuDiList->kategori);
		printf("| %-11s| %-31s| %-13d| %-31s| %-21s| %-12d| %-6d|\n", kodeBuku, sorted[i]->dataBukuDiList->judulBuku, sorted[i]->dataBukuDiList->tahunTerbit, sorted[i]->dataBukuDiList->pengarang, sorted[i]->dataBukuDiList->penerbit, sorted[i]->dataBukuDiList->kategori, sorted[i]->dataBukuDiList->stockTotal);
	}
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void showSortingOrder()
{
	printf("Sorting order:\n");
	printf("1. Ascending\n");
	printf("2. Descending\n");
}

void viewBookBy(struct node *root, struct dataList *head)
{
	int choiceToSort = 0;
	int order = 0;
	
	choiceToSortBy();
	do{
		printf(">> ");
		fflush(stdin);
		scanf("%d", &choiceToSort);
	}while(choiceToSort < 1 || choiceToSort > 5);
	
	showSortingOrder();
	do{
		printf(">> ");
		fflush(stdin);
		scanf("%d", &order);
	}while(order < 1 || order > 2);
	
	int numberOfBook = countBook(head);
	
	if(numberOfBook > 1)
		sortBy(head, numberOfBook, choiceToSort, order);
	else
		viewAllBookData(root);
}

void viewBookData(struct node *root, struct dataList **head)
{
	int amountOfBook = countBook(*head);
	
	if(amountOfBook > 0)
	{
		int viewType;
		printf("1. Tampilkan semua data\n");
		printf("2. Tampilkan data urut berdasarkan(sort by)\n");
		do{
			printf(">> ");
			fflush(stdin);
			scanf("%d", &viewType);
		}while(viewType < 1 || viewType > 2);
		
		switch(viewType)
		{
			case 1:
				viewAllBookData(root);
				break;
			case 2:
				viewBookBy(root, *head);
		}
	}
	else
	{
		printf("Tidak ada data buku\n");
	}
}

void choiceToSearch()
{
	printf("Data Buku yang ingin dicari:\n");
	printf("1. Judul buku\n");
	printf("2. Nama pengarang\n");
	printf("3. Nama penerbit\n");
	printf("4. Tahun terbit\n");
	printf("5. Kategori buku\n");
	printf(">> ");
}

void printHeader()
{
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %-11s| %-31s| %-13s| %-31s| %-21s| %-12s| %-6s|\n", "Kode buku", "Judul buku", "Tahun terbit", "Nama Pengarang", "Nama penerbit", "Kategori", "Stok");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printInfoBuku(struct data *infoBuku)
{
	char kodeBuku[10];
	generateKodeBuku(kodeBuku, infoBuku->judulBuku, infoBuku->pengarang, infoBuku->tahunTerbit, infoBuku->kategori);
	printf("| %-11s| %-31s| %-13d| %-31s| %-21s| %-12d| %-6d|\n", kodeBuku, infoBuku->judulBuku, infoBuku->tahunTerbit, infoBuku->pengarang, infoBuku->penerbit, infoBuku->kategori, infoBuku->stockTotal);
}

void searchJudul(struct dataList *head)
{
	char inputJudul[51];
	
	do{
		printf("Masukkan judul buku yang ingin dicari: ");
		fflush(stdin);
		scanf("%[^\n]", inputJudul);
	}while(strlen(inputJudul) < 3);
	
	int found = 0;
	struct dataList *ptr = head;
	while(ptr != NULL)
	{
		char getData[60], getInput[60];
		strcpy(getData, ptr->dataBukuDiList->judulBuku);
		lowercaseStr(getData);
		strcpy(getInput, inputJudul);
		lowercaseStr(getInput);
		if(strcmp(getInput, getData)==0)
		{
			if(found == 0)
			{
				printf("\nbuku dengan judul %s ditemukan\n\n", inputJudul);
				printHeader();
				printInfoBuku(ptr->dataBukuDiList);
				found = 1;
			}
			else if(found == 1)
			{
				printInfoBuku(ptr->dataBukuDiList);
			}
		}
		ptr = ptr->next;
	}
	
	if(found == 0)
	{
		printf("judul buku %s tidak ditemukan\n", inputJudul);
	}
	else
	{
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

void searchPengarang(struct dataList *head)
{
	char inputPengarang[51];
	
	do{
		printf("Masukkan nama pengarang yang ingin dicari: ");
		fflush(stdin);
		scanf("%[^\n]", inputPengarang);
	}while(strlen(inputPengarang) < 3);
	
	int found = 0;
	struct dataList *ptr = head;
	while(ptr != NULL)
	{
		char getData[60], getInput[60];
		strcpy(getData, ptr->dataBukuDiList->pengarang);
		lowercaseStr(getData);
		strcpy(getInput, inputPengarang);
		lowercaseStr(getInput);
		if(strcmp(getInput, getData)==0)
		{
			if(found == 0)
			{
				printf("\nbuku dengan pengarang %s ditemukan\n\n", inputPengarang);
				printHeader();
				printInfoBuku(ptr->dataBukuDiList);
				found = 1;
			}
			else if(found == 1)
			{
				printInfoBuku(ptr->dataBukuDiList);
			}
		}
		ptr = ptr->next;
	}
	
	if(found == 0)
	{
		printf("nama pengarang %s tidak ditemukan\n", inputPengarang);
	}
	else
	{
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

void searchPenerbit(struct dataList *head)
{
	char inputPenerbit[51];
	
	do{
		printf("Masukkan nama penerbit yang ingin dicari: ");
		fflush(stdin);
		scanf("%[^\n]", inputPenerbit);
	}while(strlen(inputPenerbit) < 3);
	
	int found = 0;
	struct dataList *ptr = head;
	while(ptr != NULL)
	{
		char getData[60], getInput[60];
		strcpy(getData, ptr->dataBukuDiList->penerbit);
		lowercaseStr(getData);
		strcpy(getInput, inputPenerbit);
		lowercaseStr(getInput);
		if(strcmp(getInput, getData)==0)
		{
			if(found == 0)
			{
				printf("\nbuku dengan penerbit %s ditemukan\n\n", inputPenerbit);
				printHeader();
				printInfoBuku(ptr->dataBukuDiList);
				found = 1;
			}
			else if(found == 1)
			{
				printInfoBuku(ptr->dataBukuDiList);
			}
		}
		ptr = ptr->next;
	}
	
	if(found == 0)
	{
		printf("nama penerbit %s tidak ditemukan\n", inputPenerbit);
	}
	else
	{
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

void searchTahunTerbit(struct dataList *head)
{
	int inputTahunBawah = 0;
	int inputTahunAtas = 0;
	
	do{
		printf("Masukkan rentang bawah tahun : ");
		fflush(stdin);
		scanf("%d", &inputTahunBawah);
	}while(inputTahunBawah < 1000 || inputTahunBawah > 2024);
	
	do{
		printf("Masukkan rentang atas tahun : ");
		fflush(stdin);
		scanf("%d", &inputTahunAtas);
	}while(inputTahunAtas < 1000 || inputTahunAtas > 2024);
	
	int found = 0;
	struct dataList *ptr = head;
	while(ptr != NULL)
	{
		if(ptr->dataBukuDiList->tahunTerbit >= inputTahunBawah && ptr->dataBukuDiList->tahunTerbit <= inputTahunAtas)
		{
			if(found == 0)
			{
				printf("\nbuku dengan rentang tahun %d-%d ditemukan\n\n", inputTahunBawah, inputTahunAtas);
				printHeader();
				printInfoBuku(ptr->dataBukuDiList);
				found = 1;
			}
			else if(found == 1)
			{
				printInfoBuku(ptr->dataBukuDiList);
			}
		}
		ptr = ptr->next;
	}
	
	if(found == 0)
	{
		printf("buku dengan rentang tahun %d-%d tidak ditemukan\n\n", inputTahunBawah, inputTahunAtas);
	}
	else
	{
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

void searchKategori(struct dataList *head)
{
	int inputKategori = 0;
	
	viewKategori();
	do{
		printf("Masukkan Kode Kategori yang ingin dicari: ");
		fflush(stdin);
		scanf("%d", &inputKategori);
	}while(inputKategori < 100 || inputKategori > 900);
	
	int found = 0;
	struct dataList *ptr = head;
	while(ptr != NULL)
	{
		if(ptr->dataBukuDiList->kategori == inputKategori)
		{
			if(found == 0)
			{
				printf("\nbuku dengan kode %d ditemukan\n\n", inputKategori);
				printHeader();
				printInfoBuku(ptr->dataBukuDiList);
				found = 1;
			}
			else if(found == 1)
			{
				printInfoBuku(ptr->dataBukuDiList);
			}
		}
		ptr = ptr->next;
	}
	
	if(found == 0)
	{
		printf("kode buku %d tidak ditemukan\n", inputKategori);
	}
	else
	{
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

void searchDataBuku(struct dataList **head)
{
	int inputOperation = 0;
	
	do{
		choiceToSearch();
		fflush(stdin);
		scanf("%d", &inputOperation);
	}while(inputOperation < 1 || inputOperation > 6);
	
	switch(inputOperation)
	{
		case 1:
			searchJudul(*head);
			break;
		case 2:
			searchPengarang(*head);
			break;
		case 3:
			searchPenerbit(*head);
			break;
		case 4:
			searchTahunTerbit(*head);
			break;
		case 5:
			searchKategori(*head);
	}
}

void showMenu()
{
	printf("=================\n");
    printf("Book Management\n");
    printf("=================\n");
    printf("1. Insert data buku\n");
    printf("2. View data buku\n");
    printf("3. Update stok buku\n");
    printf("4. Search data buku\n");
    printf("5. Keluar\n");
}

int main() {
    struct node *root = createTrie();
    struct dataList *head = NULL;
    int menu;

    do {
    	do{
    		system("cls");
    		showMenu();
    		printf(">> ");
    		fflush(stdin);
        	scanf("%d", &menu);
		}while(menu < 1 || menu > 5);

        switch (menu) {
            case 1: {
                insertBookData(root, &head);
                break;
            }
            case 2: {
                viewBookData(root, &head);
                break;
            }
            case 3: {
                updateStock(root, &head);
                break;
            }
            case 4: {
                searchDataBuku(&head);
                break;
            }
            case 5: {
            	animation("Thank you for using this Library Management Book program", 1);
            	animation(" . . . \n", 60);
			}
        }
        
        if(menu != 5)
        {
        	printf("Press any key to continue . . . ");
        	getch();
		}
    } while (menu != 5);

    return 0;
}
