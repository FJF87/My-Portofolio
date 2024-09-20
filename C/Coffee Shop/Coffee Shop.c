#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

struct date{
	int year; int month; int day; int hour; int minutes; int second;
};

struct dataBarang{
	char jenis[50];
	char namaBenda[50];
	int jumlahBarangDibeli;
	int hargaPerItem;
};

struct dataTransaksi{
	int ID;
	struct date tanggalTransaksi;
	int jumlahItem;
	struct dataBarang barangDibeli[10];
	int totalPembayaran;
	char namaKasir[50];
};

struct dataStock{
	char nama[50];
	char jenis[50];
	int stok;
	int hargaPerItem;
};


// User Interface 
void Sleep(int time);
void writeline(char text[], int time); // time is set for each character output
void write(char text[], int time); // Doesn`t include \n
void intro();
void mainPage();
void stockPage();
void salesPage();
void backMain(); // Getting user input before back to main page

// Search Algorithm
void searchTransaksi();
void searchSalesRangeAmountPaid(struct dataTransaksi *data, int jumlahData);
void searchSalesAmountPaid(struct dataTransaksi *data, int jumlahData);
void searchSalesRangeAmountBought(struct dataTransaksi *data, int jumlahData);
void searchSalesAmountBought(struct dataTransaksi *data, int jumlahData);
void searchSalesRangePrice(struct dataTransaksi *data, int jumlahData);
void searchSalesPrice(struct dataTransaksi *data, int jumlahData);
void searchSalesName(struct dataTransaksi *data, int jumlahData);

void searchStock();
void searchStockCheapest(struct dataStock *data, int jumlahData);
void searchStockMostExpensive(struct dataStock *data, int jumlahData);
void searchStockRangePrice(struct dataStock *data, int jumlahData);
void searchStockPrice(struct dataStock *data, int jumlahData);
void searchStockRangeAmountStock(struct dataStock *data, int jumlahData);
void searchStockAmountStock(struct dataStock *data, int jumlahData);
void searchStockType(struct dataStock *data, int jumlahData);
void searchStockName(struct dataStock *data, int jumlahData);

// Sorting Algorithm 
void sortingDate(struct dataTransaksi data[], int jumData);
int compare(struct date a, struct date b);


void sortingNamaAsc(struct dataStock data[], int jumData);
void sortingNamaDesc(struct dataStock data[], int jumData);
void sortingStokAsc(struct dataStock data[], int jumData);
void sortingStokDesc(struct dataStock data[], int jumData);
void sortingHargaAsc(struct dataStock data[], int jumData);
void sortingHargaDesc(struct dataStock data[], int jumData);


// display para
void displayStockPara(struct dataStock *data, int jumlahData);
void displaySalesPara(struct dataTransaksi *data, int jumlahData);

// display
void displayStock();
void displaySales();

void sortStock();
void sortSales();

void addStock();
void addSales();

// time function
int monthToNumber(char *month); // ini buat ubh bulan ke integer 1-12

// Remove
void removeStock();
void removeData(char *nameToBeRemoved);

int main() {
	
	intro(); 
	mainPage();
	
	return 0;
}


void writeline(char text[], int time) {
	for(int i = 0; i < strlen(text); i++) {
		printf("%c", text[i]);
		Sleep(time);
	}
	printf("\n");
}

void write(char text[], int time) {
	for(int i = 0; i < strlen(text); i++) {
		printf("%c", text[i]);
		Sleep(time);
	}
}

void intro() {
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\tProgram Created by", 10);
 	writeline("\t\tAlexander Ricky B. - 2702224950", 10);
 	writeline("\t\tJeffrey Ferdinand H. - 2702221936", 10);
 	writeline("\t\tNathanael Christian - 2702223292", 10);
	
	printf("\n\n");
	writeline("\t\tPress any key to start", 20);
	getch();
}

void mainPage(){
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\t1.Check Stock",10);
	writeline("\t\t2.Check Sales",10);
	writeline("\t\t3.Exit Program",10);	
 	
	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 3){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	
	
	// based on user option > navigate menu
	switch (user_input) {
		case 1:
			stockPage();
			break;
		case 2:
			salesPage();
			break;
	}
}

void stockPage() {
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Stock\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\t1.Display Data",10);
 	writeline("\t\t2.Add Data",10);
	writeline("\t\t3.Search Data",10);
	writeline("\t\t4.Sort Data",10);
	writeline("\t\t5.Remove Data",10);	
	writeline("\t\t6.Back",10);
		
	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 6){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	
	// based on user option > navigate menu
	switch (user_input) {
		case 1:
			displayStock();
			break;
		case 2:
			addStock();
			break;
		case 3:
			searchStock();
			break;
		case 4:
			sortStock();
			break;
		case 5:
			removeStock();
			break;
		case 6:
			mainPage();
			break;
	}
}

void salesPage() {
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Sales\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\t1.Display Data",10);
 	writeline("\t\t2.Add Data",10);
	writeline("\t\t3.Search Data",10);
	writeline("\t\t4.Sort Data",10);
	writeline("\t\t5.Back",10);	
		
	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 5){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	
	
	// based on user option > navigate menu
	switch (user_input) {
		case 1:
			displaySales();
			break;
		case 2:
			addSales();
			break;
		case 3:
			searchTransaksi();
			break;
		case 4:
			sortSales();
			break;
		case 5:
			mainPage();
			break;
	}
}

void backMain(){
	writeline("\n\t\tPress any key to back", 10);
	getch();
	mainPage();
}


//////////////////////////////////// Add on Jeffrey //////////////////////////////////////
void searchStockName(struct dataStock *data, int jumlahData)
{
	char nameToBeSearched[50];
	printf("\t\tInput the data name to be searched: ");
	fflush(stdin);
	scanf("%[^\n]", nameToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if(strcmp(data[i].nama, nameToBeSearched)==0)
		{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
		}
	}
	backMain();
}

void searchStockType(struct dataStock *data, int jumlahData)
{
	char typeToBeSearched[50];
	printf("\t\tInput the data type to be searched: ");
	fflush(stdin);
	scanf("%[^\n]", typeToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if(strcmp(data[i].jenis, typeToBeSearched)==0)
		{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
		}
	}
	backMain();
}

void searchStockAmountStock(struct dataStock *data, int jumlahData)
{
	int stockToBeSearched;
	printf("\t\tInput the data stock to be searched: ");
	scanf("%d", &stockToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if( data[i].stok == stockToBeSearched )
		{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
		}
	}
	backMain();
}

void searchStockRangeAmountStock(struct dataStock *data, int jumlahData)
{
	int stockToBeSearchedMin, stockToBeSearchedMax;
	printf("\t\tInput the data minimum stock to be searched: ");
	scanf("%d", &stockToBeSearchedMin);
	printf("\t\tInput the data maxmum stock to be searched: ");
	scanf("%d", &stockToBeSearchedMax);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if( data[i].stok >= stockToBeSearchedMin && data[i].stok <= stockToBeSearchedMax )
		{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
		}
	}
	backMain();
}

void searchStockPrice(struct dataStock *data, int jumlahData)
{
	int priceToBeSearched;
	printf("\t\tInput the data price to be searched: ");
	scanf("%d", &priceToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if( data[i].hargaPerItem == priceToBeSearched )
		{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
		}
	}
	backMain();
}

void searchStockRangePrice(struct dataStock *data, int jumlahData)
{
	int priceToBeSearchedMin, priceToBeSearchedMax;
	printf("\t\tInput the data minimum price to be searched: ");
	scanf("%d", &priceToBeSearchedMin);
	printf("\t\tInput the data maximum price to be searched: ");
	scanf("%d", &priceToBeSearchedMax);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if( data[i].hargaPerItem >= priceToBeSearchedMin && data[i].hargaPerItem <= priceToBeSearchedMax )
		{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
		}
	}
	backMain();
}

void searchStockMostExpensive(struct dataStock *data, int jumlahData)
{
	int i,indexMaxPrice=0;
	
	for(i=1;i<jumlahData;i++)
	{
		if(data[indexMaxPrice].hargaPerItem < data[i].hargaPerItem)
		{
			indexMaxPrice = i;
		}
	}
	
	printf("\t\tBarang termahal yang dijual:\n");
	printf("\t\tNama barang: %s\n", data[indexMaxPrice].nama);
	printf("\t\tJenis barang: %s\n", data[indexMaxPrice].jenis);
	printf("\t\tStok barang: %d\n", data[indexMaxPrice].stok);
	printf("\t\tHarga per item barang: %d\n\n", data[indexMaxPrice].hargaPerItem);
	
	backMain();
}

void searchStockCheapest(struct dataStock *data, int jumlahData)
{
	int i,indexMinPrice=0;
	
	for(i=1;i<jumlahData;i++)
	{
		if(data[indexMinPrice].hargaPerItem > data[i].hargaPerItem)
		{
			indexMinPrice = i;
		}
	}
	
	printf("\t\tBarang termurah yang dijual:\n");
	printf("\t\tNama barang: %s\n", data[indexMinPrice].nama);
	printf("\t\tJenis barang: %s\n", data[indexMinPrice].jenis);
	printf("\t\tStok barang: %d\n", data[indexMinPrice].stok);
	printf("\t\tHarga per item barang: %d\n\n", data[indexMinPrice].hargaPerItem);
	
	backMain();
}

void searchStock()
{
	FILE *file = fopen("stok.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open the stok file\n");
		exit(1);
	}
	
	struct dataStock data[500];
	
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	
	int dataKe=0;
	do{
		fscanf(file, "%[^,],%[^,],%d,%d\n", data[dataKe].nama, data[dataKe].jenis, &data[dataKe].stok, &data[dataKe].hargaPerItem);
		dataKe++;
	}while(!feof(file));
	
	fclose(file);
	
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Stock > Search \n");
 	printf("\t\t==================================================================\n");
	writeline("\t\tData to be searched", 10);
	writeline("\t\t1. Name", 10);
	writeline("\t\t2. Type", 10);
	writeline("\t\t3. Stock", 10);
	writeline("\t\t4. Range stock", 10);
	writeline("\t\t5. Price", 10);
	writeline("\t\t6. Range price", 10);
	writeline("\t\t7. The most expensive", 10);
	writeline("\t\t8. The cheapest", 10);
	writeline("\t\t9. Back", 10);
	
	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 9){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	
	switch(user_input)
	{
		case 1:
			searchStockName(data, dataKe);
			break;
		case 2:
			searchStockType(data, dataKe);
			break;
		case 3:
			searchStockAmountStock(data, dataKe);
			break;
		case 4:
			searchStockRangeAmountStock(data, dataKe);
			break;
		case 5:
			searchStockPrice(data, dataKe);
			break;
		case 6:
			searchStockRangePrice(data, dataKe);
			break;
		case 7:
			searchStockMostExpensive(data, dataKe);
			break;
		case 8:
			searchStockCheapest(data, dataKe);
			break;
		case 9:
			stockPage();
			break;
		default:
			printf("Invalid input\n");
	}
	
	
}

void searchSalesName(struct dataTransaksi *data, int jumlahData)
{
	char nameToBeSearched[50];
	printf("\t\tInput the data name to be searched: ");
	fflush(stdin);
	scanf("%[^\n]", nameToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{
			if(strcmp(data[i].barangDibeli[j].namaBenda, nameToBeSearched)==0)
			{
				//untuk total pembayaran perlu diikutkan? soalnya kalau belinya cuma satu barang aja kan oke. tapi kalau belinya lebih dari 1 macam, jadinya totalnya gk cocok
				printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
				printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
				printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
			}
		}
	}
	
	backMain();
}

void searchSalesPrice(struct dataTransaksi *data, int jumlahData)
{
	int priceToBeSearched;
	printf("\t\tInput the price to be searched: ");
	scanf("%d", &priceToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{
			if( data[i].barangDibeli[j].hargaPerItem == priceToBeSearched )
			{
				//untuk total pembayaran perlu diikutkan? soalnya kalau belinya cuma satu barang aja kan oke. tapi kalau belinya lebih dari 1 macam, jadinya totalnya gk cocok
				printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
				printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
				printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
			}
		}
	}
	
	backMain();
}

void searchSalesRangePrice(struct dataTransaksi *data, int jumlahData)
{
	int priceToBeSearchedMin, priceToBeSearchedMax;
	printf("\t\tInput the minimum price to be searched: ");
	scanf("%d", &priceToBeSearchedMin);
	printf("\t\tInput the maximum price to be searched: ");
	scanf("%d", &priceToBeSearchedMax);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{
			if( data[i].barangDibeli[j].hargaPerItem >= priceToBeSearchedMin && data[i].barangDibeli[j].hargaPerItem <= priceToBeSearchedMax )
			{
				//untuk total pembayaran perlu diikutkan? soalnya kalau belinya cuma satu barang aja kan oke. tapi kalau belinya lebih dari 1 macam, jadinya totalnya gk cocok
				printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
				printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
				printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
			}
		}
	}
	
	backMain();
}

void searchSalesAmountBought(struct dataTransaksi *data, int jumlahData)
{
	int amountBoughtToBeSearched;
	printf("\t\tInput the amount bought to be searched: ");
	scanf("%d", &amountBoughtToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{
			if( data[i].barangDibeli[j].jumlahBarangDibeli == amountBoughtToBeSearched )
			{
				//untuk total pembayaran perlu diikutkan? soalnya kalau belinya cuma satu barang aja kan oke. tapi kalau belinya lebih dari 1 macam, jadinya totalnya gk cocok
				printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
				printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
				printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
			}
		}
	}
	
	backMain();
}

void searchSalesRangeAmountBought(struct dataTransaksi *data, int jumlahData)
{
	int amountBoughtToBeSearchedMin, amountBoughtToBeSearchedMax;
	printf("\t\tInput the minimum amount bought to be searched: ");
	scanf("%d", &amountBoughtToBeSearchedMin);
	printf("\t\tInput the maximum amount bought to be searched: ");
	scanf("%d", &amountBoughtToBeSearchedMax);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{
			if( data[i].barangDibeli[j].jumlahBarangDibeli >= amountBoughtToBeSearchedMin && data[i].barangDibeli[j].jumlahBarangDibeli <= amountBoughtToBeSearchedMax )
			{
				//untuk total pembayaran perlu diikutkan? soalnya kalau belinya cuma satu barang aja kan oke. tapi kalau belinya lebih dari 1 macam, jadinya totalnya gk cocok
				printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
				printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
				printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
			}
		}
	}
	
	backMain();
}

void searchSalesAmountPaid(struct dataTransaksi *data, int jumlahData)
{
	int amountPaidToBeSearched;
	printf("\t\tInput the amount paid to be searched: ");
	scanf("%d", &amountPaidToBeSearched);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if( data[i].totalPembayaran == amountPaidToBeSearched )
		{
			printf("Tanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
			printf("Waktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
			int j;
			for(j=0;j<data[i].jumlahItem;j++)
			{
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
			}
			printf("\t\tTotal pembayaran: %d\n", data[i].totalPembayaran);
			printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
		}
	}
	
	backMain();
}

void searchSalesRangeAmountPaid(struct dataTransaksi *data, int jumlahData)
{
	int amountPaidToBeSearchedMin, amountPaidToBeSearchedMax;
	printf("\t\tInput the minimum amount paid to be searched: ");
	scanf("%d", &amountPaidToBeSearchedMin);
	printf("\t\tInput the maximum amount paid to be searched: ");
	scanf("%d", &amountPaidToBeSearchedMax);
	
	int i;
	for(i=0;i<jumlahData;i++)
	{
		if( data[i].totalPembayaran >= amountPaidToBeSearchedMin && data[i].totalPembayaran <= amountPaidToBeSearchedMax )
		{
			printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
			printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
			int j;
			for(j=0;j<data[i].jumlahItem;j++)
			{
				printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
				printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
				printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
				printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
			}
			printf("\t\tTotal pembayaran: %d\n", data[i].totalPembayaran);
			printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
		}
	}
	
	backMain();
}


void searchTransaksi()
{
	FILE *file = fopen("sales.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open the sales file\n");
		exit(1);
	}
	
	struct dataTransaksi data[20];
	
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	int dataKe=0;
	do{
		int i;
		fscanf(file, "%d, {%d, %d, %d, %d, %d, %d}, %d, {", &data[dataKe].ID, &data[dataKe].tanggalTransaksi.year, &data[dataKe].tanggalTransaksi.month, &data[dataKe].tanggalTransaksi.day, &data[dataKe].tanggalTransaksi.hour, &data[dataKe].tanggalTransaksi.minutes, &data[dataKe].tanggalTransaksi.second, &data[dataKe].jumlahItem);
		for(i=0;i<data[dataKe].jumlahItem;i++)
		{
			fscanf(file, "{%[^,], %[^,], %d, %d}", data[dataKe].barangDibeli[i].jenis, data[dataKe].barangDibeli[i].namaBenda, &data[dataKe].barangDibeli[i].jumlahBarangDibeli, &data[dataKe].barangDibeli[i].hargaPerItem);
			if(i==data[dataKe].jumlahItem-1)
				fscanf(file, "}, ");
			else
				fscanf(file, ", ");
		}
		fscanf(file, "%d, %[^\n]\n", &data[dataKe].totalPembayaran, data[dataKe].namaKasir);
		dataKe++;
	}while(!feof(file));
	
	fclose(file);
	
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Sales > Search \n");
 	printf("\t\t==================================================================\n");
	writeline("\t\tData to be searched", 10);
	writeline("\t\t1. Name", 10);
	writeline("\t\t2. Price", 10);
	writeline("\t\t3. Range price", 10);
	writeline("\t\t4. Amount bought", 10);
	writeline("\t\t5. Range amount bought", 10);
	writeline("\t\t6. Amount paid", 10);
	writeline("\t\t7 Range amount paid", 10);
	
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 5){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}

	switch(user_input)
	{
		case 1:
			searchSalesName(data, dataKe);
			break;
		case 2:
			searchSalesPrice(data, dataKe);
			break;
		case 3:
			searchSalesRangePrice(data, dataKe);
			break;
		case 4:
			searchSalesAmountBought(data, dataKe);
			break;
		case 5:
			searchSalesRangeAmountBought(data, dataKe);
			break;
		case 6:
			searchSalesAmountPaid(data, dataKe);
			break;
		case 7:
			searchSalesRangeAmountPaid(data, dataKe);
			break;
		default:
			printf("Invalid input\n");
	}
	
	
}




/////////////////////////////////////// Input Chris ///////////////////////////////////////////

int compare(struct date a, struct date b){ 
	
	if(a.year != b.year)
		return a.year - b.year;
		
	if(a.month != b.month)
		return a.month - b.month;
		
	if(a.day != b.day)
		return a.day - b.day;
		
	if(a.hour != b.hour)
		return a.hour - b.hour;
		
	if(a.minutes != b.minutes)
		return a.minutes - b.minutes;
		
	return a.second - b.second;			
		
}

void sortingDate(struct dataTransaksi data[], int jumData){ 

	for(int i = 0; i < jumData; i++){
		for(int j = i + 1; j < jumData; j++){
			if(compare(data[i].tanggalTransaksi, data[j].tanggalTransaksi) > 0){
				struct dataTransaksi temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displaySalesPara(data, jumData);
	backMain();
} 

void sortingNamaAsc(struct dataStock data[], int jumData){
	
	for(int i = 0; i < jumData; i++){
		for(int j = i+1; j < jumData; j++){
			if(strcmp(data[i].nama, data[j].nama) > 0){
				struct dataStock temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displayStockPara(data, jumData);
	backMain();
}

void sortingNamaDesc(struct dataStock data[], int jumData){
	
	for(int i = 0; i < jumData; i++){
		for(int j = i+1; j < jumData; j++){
			if(strcmp(data[i].nama, data[j].nama) < 0){
				struct dataStock temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displayStockPara(data, jumData);
	backMain();
}

void sortingStokAsc(struct dataStock data[], int jumData){
	
	for(int i = 0; i < jumData; i++){
		for(int j = i+1; j < jumData; j++){
			if(data[i].stok > data[j].stok){
				struct dataStock temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displayStockPara(data, jumData);
	backMain();
}

void sortingStokDesc(struct dataStock data[], int jumData){
	
	for(int i = 0; i < jumData; i++){
		for(int j = i+1; j < jumData; j++){
			if(data[i].stok < data[j].stok){
				struct dataStock temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displayStockPara(data, jumData);
	backMain();
}

void sortingHargaAsc(struct dataStock data[], int jumData){
	
	for(int i = 0; i < jumData; i++){
		for(int j = i+1; j < jumData; j++){
			if(data[i].hargaPerItem > data[j].hargaPerItem){
				struct dataStock temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displayStockPara(data, jumData);
	backMain();
}

void sortingHargaDesc(struct dataStock data[], int jumData){
	
	for(int i = 0; i < jumData; i++){
		for(int j = i+1; j < jumData; j++){
			if(data[i].hargaPerItem < data[j].hargaPerItem){
				struct dataStock temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	displayStockPara(data, jumData);
	backMain();
}


/////////////////////////////////////////////// Void display //////////////////////////////////////////////
void displayStock() {
	FILE *file = fopen("stok.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open the stock file\n");
		exit(1);
	}
	
	struct dataStock datadisplay[500];
	
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	
	int dataKe=0;
	do{
		fscanf(file, "%[^,],%[^,],%d,%d\n", datadisplay[dataKe].nama, datadisplay[dataKe].jenis, &datadisplay[dataKe].stok, &datadisplay[dataKe].hargaPerItem);
		dataKe++;
	}while(!feof(file));
	fclose(file);
	
	for(int i = 0; i < dataKe;i++)
	{
			printf("\t\tNama barang: %s\n", datadisplay[i].nama);
			printf("\t\tJenis barang: %s\n", datadisplay[i].jenis);
			printf("\t\tStok barang: %d\n", datadisplay[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", datadisplay[i].hargaPerItem);
	}
	
	backMain();
}

void displaySales() {
	FILE *file = fopen("sales.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open the sales file\n");
		exit(1);
	}
	
	struct dataTransaksi data[100];
	
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	int dataKe=0;
	do{
		int i;
		fscanf(file, "%d, {%d, %d, %d, %d, %d, %d}, %d, {", &data[dataKe].ID, &data[dataKe].tanggalTransaksi.year, &data[dataKe].tanggalTransaksi.month, &data[dataKe].tanggalTransaksi.day, &data[dataKe].tanggalTransaksi.hour, &data[dataKe].tanggalTransaksi.minutes, &data[dataKe].tanggalTransaksi.second, &data[dataKe].jumlahItem);
		for(i=0;i<data[dataKe].jumlahItem;i++)
		{
			fscanf(file, "{%[^,], %[^,], %d, %d}", data[dataKe].barangDibeli[i].jenis, data[dataKe].barangDibeli[i].namaBenda, &data[dataKe].barangDibeli[i].jumlahBarangDibeli, &data[dataKe].barangDibeli[i].hargaPerItem);
			if(i==data[dataKe].jumlahItem-1)
				fscanf(file, "}, ");
			else
				fscanf(file, ", ");
		}
		fscanf(file, "%d, %[^\n]\n", &data[dataKe].totalPembayaran, data[dataKe].namaKasir);
		dataKe++;
	}while(!feof(file));
	fclose(file);
	
	for(int i=0;i<dataKe;i++)
	{
		printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
		printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{		
			printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
			printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
			printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
			printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
		}
		printf("\t\tTotal pembayaran: %d\n", data[i].totalPembayaran);
		printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
	}
	
		backMain();
}

void sortStock() {
	FILE *file = fopen("stok.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open the stock file\n");
		exit(1);
	}
	
	struct dataStock datadisplay[500];
	
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	
	int dataKe=0;
	do{
		fscanf(file, "%[^,],%[^,],%d,%d\n", datadisplay[dataKe].nama, datadisplay[dataKe].jenis, &datadisplay[dataKe].stok, &datadisplay[dataKe].hargaPerItem);
		dataKe++;
	}while(!feof(file));
	fclose(file);
	
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Stock > Sort\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\t1.Sort name ascending",10);
 	writeline("\t\t2.Sort name descending",10);
	writeline("\t\t3.Sort stock ascending",10);
	writeline("\t\t4.Sort stock descending",10);
	writeline("\t\t5.Sory price ascending",10);	
	writeline("\t\t6.Sory price descending",10);
	writeline("\t\t7.Back",10);		
		
	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 7){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	
	
	// based on user option > navigate menu
	switch (user_input) {
		case 1:
			sortingNamaAsc(datadisplay, dataKe);
			break;
		case 2:
			sortingNamaDesc(datadisplay, dataKe);
			break;
		case 3:
			sortingStokAsc(datadisplay, dataKe);
			break;
		case 4:
			sortingStokDesc(datadisplay, dataKe);
			break;
		case 5:
			sortingHargaAsc(datadisplay, dataKe);
			break;
		case 6:
			sortingHargaDesc(datadisplay, dataKe);
			break;
		case 7:
			stockPage();
			break;
	}
}
void sortSales() {
	
	FILE *file = fopen("sales.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open the sales file\n");
		exit(1);
	}
	
	struct dataTransaksi data[100];
	
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	int dataKe=0;
	do{
		int i;
		fscanf(file, "%d, {%d, %d, %d, %d, %d, %d}, %d, {", &data[dataKe].ID, &data[dataKe].tanggalTransaksi.year, &data[dataKe].tanggalTransaksi.month, &data[dataKe].tanggalTransaksi.day, &data[dataKe].tanggalTransaksi.hour, &data[dataKe].tanggalTransaksi.minutes, &data[dataKe].tanggalTransaksi.second, &data[dataKe].jumlahItem);
		for(i=0;i<data[dataKe].jumlahItem;i++)
		{
			fscanf(file, "{%[^,], %[^,], %d, %d}", data[dataKe].barangDibeli[i].jenis, data[dataKe].barangDibeli[i].namaBenda, &data[dataKe].barangDibeli[i].jumlahBarangDibeli, &data[dataKe].barangDibeli[i].hargaPerItem);
			if(i==data[dataKe].jumlahItem-1)
				fscanf(file, "}, ");
			else
				fscanf(file, ", ");
		}
		fscanf(file, "%d, %[^\n]\n", &data[dataKe].totalPembayaran, data[dataKe].namaKasir);
		dataKe++;
	}while(!feof(file));
	
	fclose(file);
	
	
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Sales > Sort\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\t1.Sort by date",10);
 	writeline("\t\t2.Back",10);

	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 2){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	

	// based on user option > navigate menu
	switch (user_input) {
		case 1:
			sortingDate(data, dataKe);
			break;
		case 2:
			salesPage();
			break;
	}
}

//////////////////////////// Display Parameter ////////////////////////////
void displayStockPara(struct dataStock *data, int jumlahData) {
	for(int i = 0; i < jumlahData;i++)
	{
			printf("\t\tNama barang: %s\n", data[i].nama);
			printf("\t\tJenis barang: %s\n", data[i].jenis);
			printf("\t\tStok barang: %d\n", data[i].stok);
			printf("\t\tHarga per item barang: %d\n\n", data[i].hargaPerItem);
	}
}

void displaySalesPara(struct dataTransaksi *data, int jumlahData){
	for(int i=0;i<jumlahData;i++)
	{
		printf("\t\tTanggal transaksi: %d/%d/%d\n", data[i].tanggalTransaksi.day, data[i].tanggalTransaksi.month, data[i].tanggalTransaksi.year);
		printf("\t\tWaktu transaksi: %d:%d:%d\n", data[i].tanggalTransaksi.hour, data[i].tanggalTransaksi.minutes, data[i].tanggalTransaksi.second);
		int j;
		for(j=0;j<data[i].jumlahItem;j++)
		{		
			printf("\t\tNama barang: %s\n", data[i].barangDibeli[j].namaBenda);
			printf("\t\tJenis barang: %s\n", data[i].barangDibeli[j].jenis);
			printf("\t\tJumlah pembelian: %d\n", data[i].barangDibeli[j].jumlahBarangDibeli);
			printf("\t\tHarga per item: %d\n", data[i].barangDibeli[j].hargaPerItem);
		}
		printf("\t\tTotal pembayaran: %d\n", data[i].totalPembayaran);
		printf("\t\tNama kasir: %s\n\n", data[i].namaKasir);
	}
	
}

void addStock() {
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Stock > Add\n");
 	printf("\t\t==================================================================\n");
 	writeline("\t\t1.Add food",10);
 	writeline("\t\t2.Add drink",10);
 	writeline("\t\t3.Back",10);

	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 3){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}
	
	char jenis[100];
	switch (user_input) {
		case 1:
			strcpy(jenis,"makanan");
			break;
		case 2:
			strcpy(jenis,"minuman");
			break;
		case 3:
			stockPage();
	}
	
	getchar();
	printf("\t\tMasukan nama %s >> ", jenis);
	char namaMakanan[100];
	fgets(namaMakanan, sizeof(namaMakanan), stdin);
	// fgets ada \n nya
    namaMakanan[strcspn(namaMakanan, "\n")] = '\0';
    
    
    
	write("\t\tMasukan jumlah stok >> ", 10);
	int jumlahStok;
	scanf("%d", &jumlahStok);
	
	write("\t\tMasukan harga per item >> ", 10);
	int harga;
	scanf("%d", &harga);
	
	printf("\n\n\t\t%s,%s,%d,%d\n", namaMakanan, jenis, jumlahStok, harga);
	writeline("\t\twas succesfully added to the data",10);
	
	// nambah ke file
	FILE *file = fopen("stok.txt", "a");
	
	if(file == NULL)
	{
		printf("failed to open the sales file\n");
		exit(1);
	}
	
	fprintf(file,"%s,%s,%d,%d\n", namaMakanan, jenis, jumlahStok, harga);
	
	fclose(file);
	
	backMain();
}

void addSales() {
	system("cls");
	printf("\t\t==================================================================\n");
 	printf("\t\tCoffee Shop Management >  Sales > Add\n");
 	printf("\t\t==================================================================\n");
 	
 	int totalData = 1;
    /////////// buat update total data ///////////////
    FILE *file2 = fopen("sales.txt", "r");
	
	if(file2 == NULL)
	{
		printf("failed to open the sales file\n");
		exit(1);
	}
	char ch;
	while ((ch = fgetc(file2)) != EOF) {
        if (ch == '\n') {
            totalData++;
        }
    }
	fclose(file2);
 	
   write("\t\tTotal data currently : ", 10);
   printf("%d\n", totalData - 1);
    
 	writeline("\t\t1.Add transaction",10);
 	writeline("\t\t2.Back",10);
 	
 	// user input
	int user_input = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &user_input);
	// Validation
	while(user_input < 1 || user_input > 2){
		writeline("\n\t\tInvalid input, please try again!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &user_input);
	}

	switch (user_input) {
		case 1:
			break;
		case 2:
			salesPage();
			break;
	}
	
	writeline("\t\tHow many item in this transaction?",10);

	// user input
	int totalItem = 0;
	write("\t\tuser input >> ", 10);
	scanf("%d", &totalItem);
	// Validation
	while(totalItem < 1 || totalItem > 10){
		writeline("\n\t\tInvalid input, please enter a reasonable number!", 10);
		write("\t\tuser input >> ", 10);
		scanf("%d", &totalItem);
	}
	
	char namaMakanan[20][100], jenis[20][100];
	int numItem[20], price[20];
	int totalPrice;
	for(int i = 0; i < totalItem; i++){
		write("\t\tPlease enter #",10);
		printf("%d", i + 1);
		writeline(" data",10);
		
		getchar();
		write("\t\tEnter item name \t\t: ",10);
		fgets(namaMakanan[i], sizeof(namaMakanan[0]), stdin);
		// fgets ada \n nya
    	namaMakanan[i][strcspn(namaMakanan[i], "\n")] = '\0';
    	
    	write("\t\tEnter food type 1.Food 2.Drink\t: ", 10);
    	int temptype;
		scanf("%d", &temptype);
		// Validation
		while(temptype < 1 || temptype > 2){
			writeline("\n\t\tInvalid input, please try again!", 10);
			write("\t\tuser input >> ", 10);
			scanf("%d", &temptype);
		}
		switch (temptype) {
		case 1:
			strcpy(jenis[i],"makanan");
			break;
		case 2:
			strcpy(jenis[i],"minuman");
			break;
		}
		
		write("\t\tEnter total item \t\t: ",10);
		scanf("%d", &numItem[i]);
		
		write("\t\tEnter item price \t\t: ",10);
		scanf("%d", &price[i]);
		totalPrice += price[i];
		printf("\n");
	}
	char namaKasir[100];
	getchar();
	write("\t\tEnter your name : ",10);
	fgets(namaKasir, sizeof(namaKasir), stdin);
	// fgets ada \n nya
    namaKasir[strcspn(namaKasir, "\n")] = '\0';
    	
    	
    	
	/////////////////// time func
    	
    time_t mytime = time(NULL);
	char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    // printf("%s\n", time_str);
    char realTime[100];
    strcpy(realTime, time_str);
    
    char day[20];
    char month[20];
    char date[20];
    char time[20];
    char year[20];
    
    
    char *token;
    const char S[2] = " ";
    
    // first and only for day
    token = strtok(time_str,S);
    strcpy(day,token);
    //printf("Day: %s\n", day);
    
    // for month
    token = strtok(NULL,S);
    strcpy(month,token);
    //printf("Month: %s\n", month);
    
    // for date
    token = strtok(NULL,S);
    strcpy(date,token);
    //printf("Date: %s\n", date);
    
    // for time
    token = strtok(NULL,S);
    strcpy(time,token);
    //printf("Time: %s\n", time);
    
    // for year
    token = strtok(NULL,S);
    strcpy(year,token);
    // printf("Year: %s\n", year);
   
    char hour[20];
    char minute[20];
    char second[20];
   
    char *token2;
    const char S2[2] = ":";
    token2 = strtok(time,S2);
    strcpy(hour,token2);
   
   token2 = strtok(NULL,S2);
   strcpy(minute,token2);
   
    token2 = strtok(NULL,S2);
    strcpy(second,token2);
    

    FILE *file = fopen("sales.txt", "a");
	
	if(file == NULL)
	{
		printf("failed to open the sales file\n");
		exit(1);
	}
	
	fprintf(file, "\n%d, ", totalData);
    fprintf(file, "{%s, %d, %d, %d, %d, %d}, ", year, monthToNumber(month), atoi(date), atoi(hour), atoi(minute), atoi(second));
    fprintf(file, "%d, ", totalItem);
    fprintf(file, "{");
    for (int i = 0; i < totalItem; i++) {
        fprintf(file, "{%s, %s, %d, %d}", namaMakanan[i], jenis[i], numItem[i], price[i]);
        if (totalItem > 1 && i < totalItem - 1) fprintf(file, ",");
    }
    fprintf(file, "}");
    fprintf(file, ", %d, %s", totalPrice, namaKasir);
	fclose(file);
    	
    	
    	////////////////
	printf("\t\tData succesfulled added!, Current Time : %s\n", realTime);
/// debug only
////    printf("%d, ",totalData);
////    printf("{%s, %d, %d, %d, %d %d}, ", year, monthToNumber(month) , atoi(date), atoi(hour), atoi(minute), atoi(second));	
////	printf("%d, ", totalItem);
////	if(totalItem > 1) printf("{");
////	for(int i = 0 ; i < totalItem; i++) {
////		printf("%{%s, %s, %d, %d}", namaMakanan[i], jenis[i], numItem[i], price[i]);
////		if(totalItem > 1 && i < totalItem - 1) printf(",");
////	}
////	if(totalItem > 1) printf("}");
////	printf(", %d, %s", totalPrice, namaKasir);
	
	
	backMain();
}


//// 
int monthToNumber(char *month) {
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int i;

    for (i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1; 
        }
    }

    return -1;
}


/////////////////////// Tambahan remove ///////////////////////////
void removeData(char *nameToBeRemoved)
{
	FILE *file = fopen("stok.txt", "r");
	
	if(file == NULL)
	{
		printf("failed to open stok.txt\n");
		exit(1);
	}
	
	int dataKe=0;
	struct dataStock data[100];
	char c;
	for(c=getc(file);c!='\n';c=getc(file)) {}
	do{
		fscanf(file, "%[^,],%[^,],%d,%d\n", data[dataKe].nama, data[dataKe].jenis, &data[dataKe].stok, &data[dataKe].hargaPerItem);
		dataKe++;
	}while(!feof(file));
	
	fclose(file);
	FILE *file2 = fopen("stok.txt", "w");
	
	fprintf(file2, "Nama,jenis,stok,harga per item\n");
	
	int i=0, keRemove=0;
	do{
		if(strcmp(data[i].nama, nameToBeRemoved) != 0)
		{
			fprintf(file2, "%s,%s,%d,%d\n", data[i].nama, data[i].jenis, data[i].stok, data[i].hargaPerItem);
		}
		if(strcmp(data[i].nama, nameToBeRemoved) == 0)
		{
			keRemove=1;
		}
		i++;
	}while(i<dataKe);
	
	if(keRemove == 1)
	{
		write("\t\tdata successfully removed\n",10);
	}
	else
	{
		write("\t\tdata cannot be found\n",10);
	}
	
	fclose(file2);
}

void removeStock()
{
	char nameToBeRemoved[50];
	write("\t\tName of stock data to be removed: ",10);
	fflush(stdin);
	scanf("%[^\n]", nameToBeRemoved);
	
	removeData(nameToBeRemoved);
	
	backMain();
}
