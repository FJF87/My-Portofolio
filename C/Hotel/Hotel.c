#include <stdio.h>
#include <stdlib.h>

#define HEADER() printf("%-26s%-18s%-11s%-10s%-10s%-10s%-16s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

const int TOTALDATA = 3939; // 3940 termasuk header

struct record
{
	char location[31];
	char city[21];
	long int price;
	int room;
	int bathroom;
	int carpark;
	char type[21];
	char furnish[21];
};

int strlength(char *str);
int strchek(char *str);
void strAppend(char *str, int strLength, char *str2, int str2Length);
int strComp(char *str, char *str2);
void strToUpper(char *str);
void strSalin(char *str1, char *str2);
void swapStruct(struct record *a, struct record *b);
void quicksort(struct record *arr, int criteria, int kr, int kn);
void display(); // fungsi utama program
int chooseRow(char *colName);
void selectRow(); // fungsi utama program
void sortBy(); // fungsi utama program
void expor(); // fungsi utama program
void mainMenu();
int pilihMainMenu();
void operation();

int main()
{
	operation();
	
	return 0;
}

// fungsi strlength digunakan untuk menghitung panjang string
// fungsi akan mereturn nilai integer yang merupakan panjang string
int strlength(char *str)
{
	int i;
	while(str[i] != '\0')
	{
		i++;
	}
	
	return i;
}

// fungsi strchek digunakan untuk mengecek nama file (akan dipanggil di fungsi expor())
// jika file mengandung spasi atau titik, maka akan diganti dengan underscore
// fungsi akan mereturn 2 macam nilai:
// nilai 0: jika ada masalah dalam penamaan file, yaitu nama awal tidak menggunakan huruf
// nilai 1: jika tidak ada masalah dalam penamaan file (jika ada spasi, maka sudah diubah)
int strchek(char *str)
{
	int i=1, stringLength = strlength(str);
	
	if((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122))
	{
		while(i < stringLength)
		{
			if(str[i] == ' ' || str[i] == '.')
			{
				str[i] = '_';
				i++;
			}
			else
			{
				i++;
			}
		}
	}
	else
	{
		printf("The file's first character can only contains letter\n");
		return 0;
	}
	
	return 1;
}

// fungsi strAppend digunakan untuk menambahkan str2 ke str1
void strAppend(char *str, int strLength, char *str2, int str2Length)
{
	int i,j;
	for(i=strLength, j=0 ; j<str2Length ; i++,j++)
	{
		str[i] = str2[j];
	}
	str[i] = '\0';
}

// fungsi strComp berfungsi untuk membandingkan 2 buah string
// ada 3 macam nilai yang direturn:
// nilai 0: jika str1 dan str2 sama persis
// nilai 1: jika str1 lebih besar daripada str2, atau jika str1 sama dengan str2, tapi str1 lebih pendek daripada str2 (misalnya: str1 = udang, str2 = udang-laut)
// nilai -1: jika str1 lebih kecil daripada str2, atau jika str1 sama dengan str2, tapi str2 lebih pendek daripada str2 (misalnya: str1 = udang-laut, str2 = udang)
int strComp(char *str, char *str2)
{
	int i=0;
	while(str[i] != '\0' && str2[i] != '\0')
	{
		if(str[i] > str2[i])
		{
			return 1;
		}
		else if(str[i] < str2[i])
		{
			return -1;
		}
		else if( str[i+1] == '\0' && str2[i+1] != '\0' )
		{
			return -1;
		}
		else if( str[i+1] != '\0' && str2[i+1] == '\0' )
		{
			return 1;
		}
		i++;
	}
	return 0;
}

// fungsi strToUpper digunakan untuk mengubah semua huruf kecil menjadi huruf kapital
void strToUpper(char *str)
{
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i]>=97 && str[i]<=122)
		{
			str[i]-=32;
		}
		i++;
	}
}

// fungsi spaceToStrip dibuat khusus untuk pencarian data (dipanggil di fungsi selectRow())
// jika user menginput kata-kata yang berspasi, maka spasi akan diganti dengan strip "-"
void spaceToStrip(char *str)
{
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] == ' ')
		{
			str[i] = '-';
		}
		i++;
	}
}

// fungsi strSalin digunakan untuk menyalin str2 ke str1
void strSalin(char *str1, char *str2)
{
	int i=0;
	while(str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

// fungsi swap digunakan untuk menukar nilai struct record
void swap(struct record *a, struct record *b)
{
	struct record temp = *a;
	*a = *b;
	*b = temp;
}

// fungsi quicksort digunakan untuk mengurutkan data
// seperti namanya, metode pengurutan yang digunakan adalah quicksort
// fungsi ini melakukan sort berdasarkan kriteria yang diberikan ketika memanggil fungsi
// nilai kriteria yang digunakan:
// nilai 1: mengurutkan berdasarkan location
// nilai 2: mengurutkan berdasarkan city
// nilai 3: mengurutkan berdasarkan price
// nilai 4: mengurutkan berdasarkan room
// nilai 5: mengurutkan berdasarkan bathroom
// nilai 6: mengurutkan berdasarkan carpark
// nilai 7: mengurutkan berdasarkan type
// nilai 8: mengurutkan berdasarkan furnish
void quicksort(struct record *arr, int criteria, int kr, int kn)
{
	int i,j;
	if(kr < kn)
	{
		i = kr;
		j = kn+1;
		if(criteria == 1)
		{
			do{
				do{ i++; }while( strComp(arr[i].location,arr[kr].location) < 0 );
				do{ j--; }while( strComp(arr[j].location,arr[kr].location) > 0 );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 2)
		{
			do{
				do{ i++; }while( strComp(arr[i].city,arr[kr].city) < 0);
				do{ j--; }while( strComp(arr[j].city,arr[kr].city) > 0 );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 3)
		{
			do{
				do{ i++; }while( arr[i].price < arr[kr].price );
				do{ j--; }while( arr[j].price > arr[kr].price );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 4)
		{
			do{
				do{ i++; }while( arr[i].room < arr[kr].room );
				do{ j--; }while( arr[j].room > arr[kr].room );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 5)
		{
			do{
				do{ i++; }while( arr[i].bathroom < arr[kr].bathroom );
				do{ j--; }while( arr[j].bathroom > arr[kr].bathroom );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 6)
		{
			do{
				do{ i++; }while( arr[i].carpark < arr[kr].carpark );
				do{ j--; }while( arr[j].carpark > arr[kr].carpark );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 7)
		{
			do{
				do{ i++; }while( strComp(arr[i].type,arr[kr].type) < 0);
				do{ j--; }while( strComp(arr[j].type,arr[kr].type) > 0 );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
		else if(criteria == 8)
		{
			do{
				do{ i++; }while( strComp(arr[i].furnish,arr[kr].furnish) < 0);
				do{ j--; }while( strComp(arr[j].furnish,arr[kr].furnish) > 0 );
				if(i<=j) swap(&arr[i], &arr[j]);
			}while(i <= j);
			swap(&arr[j], &arr[kr]);
			quicksort(arr, criteria, kr, j-1);
			quicksort(arr, criteria, j+1, kn);
		}
	}
}

// fungsi display digunakan untuk mendisplay data sebanyak yang diinginkan user
// user akan diminta menginput jumlah data yang ingin ditampilkan
// salah satu fungsi utama program
void display()
{
	FILE *file = fopen("file.csv", "r");
	
	if(file == NULL)
	{
		printf("Failed to open the file to read the record\n");
	}
	else
	{
		unsigned int dataRow=0;
		do{
			printf("Number of rows: ");
			scanf("%d", &dataRow);
		}while(dataRow<=0);
		if(dataRow>TOTALDATA)
		{
			dataRow = TOTALDATA-1;
		}
		int jumlahData = 0, record=0;
		struct record data;
		HEADER();
		char c;
		for(c=getc(file); c!='\n'; c=getc(file)) {}
		do{
			jumlahData = fscanf(file, "%[^,],%[^,],%ld,%d,%d,%d,%[^,],%s\n",
			data.location, data.city, &data.price, &data.room, &data.bathroom, &data.carpark, data.type, data.furnish);
			if(jumlahData != 8 && !feof(file))
			{
				printf("something wrong(probably format) in record number %d\n", record);
				break;
			}
			else
			{
				if(record == 0)
				{
					record++;
				}
				else
				{
					printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
					data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					record++;
				}
			}
		}while(record<=dataRow);
		
		fclose(file);
	}
	
	printf("\n\n(Press any key to continue)");
	getch();
	system("cls");
}

// fungsi chooseRow digunakan untuk mengembalikan nilai(yang berfungsi seperti kode) kolom
// nilai yang digunakan:
// nilai 1: kode untuk location
// nilai 2: kode untuk city
// nilai 3: kode untuk price
// nilai 4: kode untuk room
// nilai 5: kode untuk bathroom
// nilai 6: kode untuk carpark
// nilai 7: kode untuk type
// nilai 8: kode untuk furnish
int chooseRow(char *colName)
{
	int rowNum=0;
	strToUpper(colName);
	if( strComp(colName, "LOCATION")==0 )
	{
		rowNum = 1;
	}
	else if( strComp(colName, "CITY")==0 )
	{
		rowNum = 2;
	}
	else if( strComp(colName, "PRICE")==0 )
	{
		rowNum = 3;
	}
	else if( strComp(colName, "ROOMS")==0 )
	{
		rowNum = 4;
	}
	else if( strComp(colName, "BATHROOM")==0 )
	{
		rowNum = 5;
	}
	else if( strComp(colName, "CARPARK")==0 )
	{
		rowNum = 6;
	}
	else if( strComp(colName, "TYPE")==0 )
	{
		rowNum = 7;
	}
	else if( strComp(colName, "FURNISH")==0 )
	{
		rowNum = 8;
	}
	
	return rowNum;
}

// fungsi sortBy digunakan untuk menampilkan data secara terurut
// user akan diminta untuk menginput nama kolom dan metode yang digunakan (ascending atau descending)
// salah satu fungsi utama program
void sortBy()
{
	FILE *file = fopen("file.csv", "r");
	
	if(file == NULL)
	{
		printf("failed to open the file to choose the row\n");
	}
	else
	{
		int colNumber, jumlahData = 0, dataFound = 0, record = 0;
		char colName[21];
		do{
			printf("Choose column: ");
			fflush(stdin);
			scanf("%s", colName);
			colNumber = chooseRow(colName);
		}while( colNumber == 0 );
		
		char method[5];
		do{
			printf("Sort ascending(asc) or descending(desc)? ");
			fflush(stdin);
			scanf("%s", method);
		}while( !(strComp(method, "asc")==0) && !(strComp(method, "desc")==0) );
		
		struct record data, dataSaved[TOTALDATA];
		char c;
		for(c=getc(file);c!='\n';c=getc(file)) {}
		HEADER();
		do{
			jumlahData = fscanf(file, "%[^,],%[^,],%ld,%d,%d,%d,%[^,],%s\n",
			data.location, data.city, &data.price, &data.room, &data.bathroom, &data.carpark, data.type, data.furnish);
			if(jumlahData != 8 && !feof(file))
			{
				printf("something wrong(probably format) in record number %d\n", record);
				break;
			}
			else
			{
				strSalin(dataSaved[record].location, data.location);
				strSalin(dataSaved[record].city, data.city);
				dataSaved[record].price = data.price;
				dataSaved[record].room = data.room;
				dataSaved[record].bathroom = data.bathroom;
				dataSaved[record].carpark = data.carpark;
				strSalin(dataSaved[record].type, data.type);
				strSalin(dataSaved[record].furnish, data.furnish);
				record++;
			}
		}while( !feof(file) );
		
		quicksort(dataSaved, colNumber, 0, record-1);
		
		int i;
		if( strComp(method, "asc") )
		{
			for(i=record-1;i>=0;i--)
			{
				printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", dataSaved[i].location, dataSaved[i].city, 
				dataSaved[i].price, dataSaved[i].room, dataSaved[i].bathroom, dataSaved[i].carpark, dataSaved[i].type, dataSaved[i].furnish);
			}
		}
		else if( strComp(method, "desc") )
		{
			for(i=0;i<record;i++)
			{
				printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", dataSaved[i].location, dataSaved[i].city, 
				dataSaved[i].price, dataSaved[i].room, dataSaved[i].bathroom, dataSaved[i].carpark, dataSaved[i].type, dataSaved[i].furnish);
			}
		}
	}
	
	fclose(file);
	
	printf("\n\n(Press any key to continue)");
	getch();
	system("cls");
}

// fungsi selectRow digunakan untuk memilih data yang ingin dicari user secara spesifik
// user akan diminta untuk menginputkan nama kolom beserta nama data yang ingin dicari
// fungsi ini akan mencari data berdasarkan kode nama kolom
// nilai kode yang digunakan:
// nilai 1: kode untuk location
// nilai 2: kode untuk city
// nilai 3: kode untuk price
// nilai 4: kode untuk room
// nilai 5: kode untuk bathroom
// nilai 6: kode untuk carpark
// nilai 7: kode untuk type
// nilai 8: kode untuk furnish
// salah satu fungsi utama program
void selectRow()
{
	FILE *file = fopen("file.csv", "r");
	
	if(file == NULL)
	{
		printf("failed to open the file to select by row\n");
	}
	else
	{
		int colNumber;
		char colName[21];
		do{
			printf("Choose column: ");
			fflush(stdin);
			scanf("%[^\n]", &colName);
			colNumber = chooseRow(colName);
		}while( colNumber == 0 );
		
		char dataName[21];
		do{
			printf("What data do you want to find? ");
			fflush(stdin);
			scanf("%[^\n]", &dataName);
		}while( dataName[0] == '\0' || dataName[0] == ' ' );
		
		strToUpper(dataName);
		spaceToStrip(dataName);
		
		int jumlahData = 0, record=0, dataFound=0;
		struct record data;
		char c;
		for(c=getc(file);c!='\n';c=getc(file)) {}
		do{ 
			jumlahData = fscanf(file, "%[^,],%[^,],%ld,%d,%d,%d,%[^,],%s\n",
			data.location, data.city, &data.price, &data.room, &data.bathroom, &data.carpark, data.type, data.furnish);
			if(jumlahData != 8 && !feof(file))
			{
				printf("something wrong(probably format) in record number %d\n", record);
				break;
			}
			else
			{
				if(colNumber == 1)
				{
					char temp[51];
					strSalin(temp, data.location);
					strToUpper(temp);
					if( strComp(temp, dataName)==0 && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( strComp(temp, dataName)==0 )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if(colNumber == 2)
				{
					char temp[51];
					strSalin(temp, data.city);
					strToUpper(temp);
					if( strComp(temp, dataName)==0 && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( strComp(temp, dataName)==0 )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if (colNumber == 3)
				{
					long int dataNameLong = atol(dataName);
					if( data.price == dataNameLong && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( data.price == dataNameLong )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if(colNumber == 4)
				{
					int dataNameInt = atoi(dataName);
					if( data.room == dataNameInt && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( data.room == dataNameInt )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if(colNumber == 5)
				{
					int dataNameInt = atoi(dataName);
					if( data.bathroom == dataNameInt && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( data.bathroom == dataNameInt )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if(colNumber == 6)
				{
					int dataNameInt = atoi(dataName);
					if( data.carpark == dataNameInt && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( data.carpark == dataNameInt )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if(colNumber == 7)
				{
					char temp[51];
					strSalin(temp, data.type);
					strToUpper(temp);
					if( strComp(temp, dataName)==0 && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( strComp(temp, dataName)==0 )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
				else if(colNumber == 8)
				{
					char temp[51];
					strSalin(temp, data.furnish);
					strToUpper(temp);
					if( strComp(temp, dataName)==0 && dataFound == 0 )
					{
						printf("Data found. Detail of data:\n");
						HEADER();
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
						dataFound = 1;
					}
					else if( strComp(temp, dataName)==0 )
					{
						printf("%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
						data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					}
				}
			}
		}while( !feof(file) );
		if(dataFound == 0)
		{
			printf("Data not found!\n");
		}
	}
	
	fclose(file);
	
	printf("\n\n(Press any key to continue)");
	getch();
	system("cls");
}

// fungsi expor digunakan untuk mengekspor data ke file csv baru
// user akan diminta menginput nama file yang diinginkan
// salah satu fungsi utama program
void expor()
{
	FILE *file = fopen("file.csv", "r");
	
	if(file == NULL)
	{
		printf("failed to open the file to export the record\n");
	}
	else
	{
		char fileName[51];
		do{
			printf("File name: ");
			fflush(stdin);
			gets(fileName);
		}while(strchek(fileName) != 1);
		int strLength = strlength(fileName);
		strAppend(fileName, strLength, ".csv", 4);
		
		FILE *fileNew = fopen(fileName, "w");
		
		if(fileNew == NULL)
		{
			printf("failed to create the new file\n");
		}
		else
		{
			int jumlahData = 0, record=0;
			struct record data;
			char c;
			for(c=getc(file);c!='\n';c=getc(file)) {}
			fprintf(fileNew, "%-26s%-18s%-11s%-10s%-10s%-10s%-16s%-15s\n", 
			"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
			do{
				jumlahData = fscanf(file, "%[^,],%[^,],%ld,%d,%d,%d,%[^,],%s\n",
				data.location, data.city, &data.price, &data.room, &data.bathroom, &data.carpark, data.type, data.furnish);
				if(jumlahData != 8 && !feof(file))
				{
					printf("something wrong(probably format) in record number %d\n", record);
					break;
				}
				else
				{
					fprintf(fileNew, "%-26s%-18s%-11ld%-10d%-10d%-10d%-16s%-15s\n", 
					data.location, data.city, data.price, data.room, data.bathroom, data.carpark, data.type, data.furnish);
					record++;
				}
			}while(!feof(file));
			
			printf("Data successfully written to file %s\n", fileName);
		}
		
		fclose(fileNew);
	}
	
	fclose(file);
	
	printf("\n\n(Press any key to continue)");
	getch();
	system("cls");
}

// fungsi mainMenu digunakan untuk menampilkan menu utama
void mainMenu()
{
	printf("What do you want to do?\n");
	printf("1. Display data\n");
	printf("2. Search data\n");
	printf("3. Sort data\n");
	printf("4. Export data\n");
	printf("5. Exit\n");
	printf("Your choice: ");
}

// fungsi pilihMainMenu digunakan untuk menerima input berupa nilai operasi yang ingin dilakukakan oleh user
int pilihMainMenu()
{
	int pilih;
	do{
		mainMenu();
		scanf("%d", &pilih);
	}while(pilih<1 || pilih>5);
	
	return pilih;
}

// fungsi operation berisi pilihan operasi program yang ingin dilakukan
void operation()
{
	int pilihan;
	do{
		pilihan = pilihMainMenu();
		switch(pilihan)
		{
			case 1:
				display();
				break;
			case 2:
				selectRow();
				break;
			case 3:
				sortBy();
				break;
			case 4:
				expor();
				break;
		}
	}while(pilihan!=5);
}
