#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

const int textX = 5;
const int textY = 10;
const int relKiri = 0;
const int relKanan = 50;
const int maksPenghalang = 10;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(float milliSecond)
{
    clock_t startTime = clock();
    while (clock() < startTime + milliSecond);
}

struct position
{
	int x;
	int y;
};

struct car
{
	int isiBensin;
	unsigned int point;
	int bonus;
	struct position posisiMobil;
}mobil;

struct obs
{
	struct position posisiPenghalang[10];
	int adaPenghalang[10];
}penghalang;

struct fuel
{
	struct position posisiBensin[2];
	int adaBensin[2];
}bensin;

void printBoard();
int tabrak(); // cek apakah mobilnya menabrak penghalang/lintasan
void awalBonus(); // cek apakah dapat bonus
void printBonus(); // display keterangan kalau dapat bonus
int akhirBonus(); // menghilangkan bonus kalau terpakai dan menghapus keterangan bonus
void printMobil(int x, int y);
void gerakMobil();
void spawnBensin(); // spawn random position bensin
void tambahBensin(); // memanggil spawnBensin() kalau tidak ada bensin di layar
void printBensin(); //print posisi bensin
void isiBensin(); // kalau mobil dapat bensin, bensinnya akan penuh
void bensinDiLayarBawah(); // kalau bensin sudah di layar bawah akan dihapus
void hapusBensin(int i); // hapus bensin kalau sudah nabrak
void spawnPenghalang(int ke); // dipanggil di fungsi tambahPenghalang()
void tambahPenghalang(); // menambahkan penghalang
void printPenghalang();
void hapusPenghalang(); // kalau sudah di layar bawah
void predefined();
void printKesulitan(); // display level kesulitan yang tersedia
int pilihKesulitan(); // memilih level kesulitan
void countdown(); // countdown sebelum game mulai
void inGame(int kesulitan); // yang dijalankan dalam game
void textPreGame(); // main menu
int inputMenu(); // memilih main menu
void instruksi(); // display petunjuk permainan
void printKeterangan(); // display keterangan selama di dalam game
void textGameOver(); // display text setelah game over beserta poin yang didapat

int main()
{
	srand((unsigned)time(NULL));
	int pilihan;
	do{
		textPreGame();
		pilihan = inputMenu();
		switch(pilihan)
		{
			case 1:
				{
					int kesulitan = pilihKesulitan();
					inGame(kesulitan);
					break;
				}
			case 2:
				{
					instruksi();
					break;
				}
		}
	}while(pilihan!=3);

	return 0;
}

void printBoard()
{
	int i,j;
	for(i=0;i<25;i++)
	{
		printf("-");
		gotoxy(i,relKanan);
		printf("-\n");
	}
	for(i=0;i<relKanan;i++)
		printf("-");
}

int tabrak()
{
	int i;
	int mobx = mobil.posisiMobil.x;
	int moby = mobil.posisiMobil.y;
	
	if(moby <= relKiri || moby+2 >= relKanan)
	{
		Beep(750, 500);
		return 1;
	}
	
	for(i=0;i<maksPenghalang;i++)
	{
		int pengx = penghalang.posisiPenghalang[i].x;
		int pengy = penghalang.posisiPenghalang[i].y;
		if(mobx == pengx+1 || mobx == pengx)
		{
			if(moby == pengy || moby == pengy+1 || moby+1 == pengy || moby+1 == pengy+1 || moby+2 == pengy || moby+2 == pengy+1)
			{
				Beep(750, 500);
				return 1;
			}
			else
				return 0;
		}
	}
}

void awalBonus()
{
	if(mobil.point%100 == 0 && mobil.point!=0)
		mobil.bonus = 1;
}

void printBonus()
{
	if(mobil.bonus == 1)
	{
		gotoxy(textX-2, relKanan+10);
		printf("SUPER CAR");
	}
}

int akhirBonus()
{
	mobil.bonus = 0;
	gotoxy(textX-2, relKanan+10);
	printf("         ");
	return 0; // nilai "tabrakan" di main jadi 0
}

void printMobil(int x, int y)
{
	gotoxy(x,y);
	printf("010");
	gotoxy(x+1,y);
	printf("010");
}

void gerakMobil()
{
	while(kbhit())
	{
		char input = getch();
		switch(input)
		{
			case 'a':
			case 'A':
				mobil.posisiMobil.y--;
				break;
			case 'd':
			case 'D':
				mobil.posisiMobil.y++;
				break;
			case 27:
				gotoxy(textX+10, relKanan+10);
				printf("Paused");
				gotoxy(textX+11, relKanan+10);
				printf("Press any key to continue");
				getch();
				gotoxy(textX+10, relKanan+10);
				printf("      ");
				gotoxy(textX+11, relKanan+10);
				printf("                         ");
				Beep(540, 500);
		}
	}
}

void spawnBensin(int ke)
{
	bensin.posisiBensin[ke].x = 0;
	int i, sama, sementara = 2 + rand() % 48;
	do{
		sama = 0;
		for(i=0;i<maksPenghalang;i++)
		{
			if(penghalang.posisiPenghalang[i].y == sementara || penghalang.posisiPenghalang[i].y+1 == sementara)
			{
				sementara = 2 + rand() % 47;
				sama = 1;
			}
		}
	}while(sama==1);
	bensin.posisiBensin[ke].y = sementara;
	bensin.adaBensin[ke] = 1;
}

void tambahBensin()
{
	int i;
	for(i=0;i<2;i++)
		if(bensin.adaBensin[i] == 0)
			spawnBensin(i);
}

void printBensin()
{
	int i;
	for(i=0;i<2;i++)
	{
		gotoxy(bensin.posisiBensin[i].x, bensin.posisiBensin[i].y);
		printf("$$");
		gotoxy(bensin.posisiBensin[i].x+1, bensin.posisiBensin[i].y);
		printf("$$");
		bensin.posisiBensin[i].x++;
	}
}

void isiBensin()
{
	int i;
	int mobx = mobil.posisiMobil.x;
	int moby = mobil.posisiMobil.y;
	for(i=0;i<2;i++)
	{
		int benx = bensin.posisiBensin[i].x;
		int beny = bensin.posisiBensin[i].y;
		if(benx == mobx || benx+1 == mobx || benx == mobx+1 || benx+1 == mobx+1)
		{
			if(moby == beny || moby == beny+1 || moby+1 == beny || moby+1 == beny+1 || moby+2 == beny || moby+2 == beny+1)
			{
				mobil.isiBensin = 10;
				hapusBensin(i);
				Beep(1800, 100);
			}
		}
	}
}

void bensinDiLayarBawah()
{
	int i;
	for(i=0;i<2;i++)
		if(bensin.posisiBensin[i].x > 23)
			hapusBensin(i);
}

void hapusBensin(int i)
{
	bensin.adaBensin[i] = 0;
	bensin.posisiBensin[i].x = 0;
	bensin.posisiBensin[i].y = 0;
}

void spawnPenghalang(int ke)
{
	penghalang.posisiPenghalang[ke].x = 0;
	penghalang.posisiPenghalang[ke].y = 2 + rand() % 47;
	penghalang.adaPenghalang[ke] = 1;
}

void tambahPenghalang()
{
	int i,jumlah;
	for(i=0;i<maksPenghalang;i++) // menghitung jumlah penghalang yang ada
		if(penghalang.adaPenghalang[i] == 1)
			jumlah++;
	if(jumlah < 3 || penghalang.posisiPenghalang[0].x > 10)
	{
		for(i=0;i<maksPenghalang;i++)
		{
			if(penghalang.adaPenghalang[i] == 0)
			{
				spawnPenghalang(i);
				break;
			}
		}
	}
}

void printPenghalang()
{
	int i;
	for(i=0;i<maksPenghalang;i++)
	{
		if(penghalang.adaPenghalang[i] == 1)
		{
			gotoxy(penghalang.posisiPenghalang[i].x, penghalang.posisiPenghalang[i].y);
			printf("++");
			gotoxy(penghalang.posisiPenghalang[i].x+1, penghalang.posisiPenghalang[i].y);
			printf("++");
			penghalang.posisiPenghalang[i].x++;
		}
	}
}

void hapusPenghalang()
{
	int i;
	for(i=0;i<maksPenghalang;i++)
	{
		if(penghalang.posisiPenghalang[i].x > 23)
		{
			penghalang.posisiPenghalang[i].x = 0;
			penghalang.posisiPenghalang[i].y = 0;
			penghalang.adaPenghalang[i] = 0;
			mobil.point++;
		}
	}
}

void predefined()
{	
	//posisi pucuk kiri
	mobil.posisiMobil.x = 22;
	mobil.posisiMobil.y = 25;
	mobil.point = 0;
	mobil.isiBensin = 10;
	int i;
	for(i=0;i<maksPenghalang;i++)
	{
		penghalang.posisiPenghalang[i].x = 0;
		penghalang.posisiPenghalang[i].y = 0;
	}
	for(i=0;i<2;i++)
	{
		bensin.adaBensin[i] = 0;
		bensin.posisiBensin[i].x = 0;
		bensin.posisiBensin[i].y = 0;
	}
}

void printKesulitan()
{
	system("cls");
	gotoxy(textX,textY);
	printf("-----------------------------");
	gotoxy(textX+2,textY);
	printf("  PILIH TINGKAT KESULITAN");
	gotoxy(textX+4,textY);
	printf("        1. Mudah");
	gotoxy(textX+5,textY);
	printf("        2. Sedang");
	gotoxy(textX+6,textY);
	printf("        3. Sulit");
	gotoxy(textX+7,textY);
	printf("    4. Kembali ke menu");
	gotoxy(textX+9,textY);
	printf("-----------------------------");
	gotoxy(textX+10,textY);
	printf("  Pilihan anda >> ");
	
}

int pilihKesulitan()
{
	int pilih, bensinPerDetik;
	do{
		printKesulitan();
		scanf("%d", &pilih);
	}while(pilih<1 || pilih>4);
	switch(pilih)
	{
		case 1:
			bensinPerDetik = 35;
			break;
		case 2:
			bensinPerDetik = 25;
			break;
		case 3:
			bensinPerDetik = 15;
			break;
		case 4:
			bensinPerDetik = 0;
			break;
	}
	return bensinPerDetik;
}

void countdown()
{
	int a;
	for(a = 360 ; a < 540 ; a = a + 60 )
	{
		Beep(a, 800);
		delay(0.8);
	}
	Beep(540, 1200);
	delay(1.2);
}

void inGame(int bensinPerDetik)
{
	predefined();
	int tabrakan;
	int detik = 0;
	if(bensinPerDetik!=0)
	{
		do{
			system("cls");
			printBoard();
			printKeterangan();
			printMobil(mobil.posisiMobil.x, mobil.posisiMobil.y);
			if(detik == 0)
			{
				countdown();
				predefined();
			}
			tambahPenghalang();
			printPenghalang();
			hapusPenghalang();
			tambahBensin();
			printBensin();
			isiBensin();
			bensinDiLayarBawah();
			gerakMobil();
			detik++;
			if(detik%bensinPerDetik == 0)
				mobil.isiBensin--;
			awalBonus();
			printBonus();
			tabrakan = tabrak();
			if(mobil.bonus == 1 && tabrakan == 1)
				tabrakan = akhirBonus();
			delay(50);
		}while(tabrakan != 1 && mobil.isiBensin > 0);
		textGameOver();
	}
}

void textPreGame()
{
	int pilih;
	system("cls");
	gotoxy(textX,textY);
	printf("----------------------------------");
	gotoxy(textX+1,textY);
	printf("          SELAMAT DATANG  ");
	gotoxy(textX+2,textY);
	printf("   DI GAME \"MOBIL MENGHINDAR\"");
	gotoxy(textX+3,textY);
	printf("----------------------------------");
	gotoxy(textX+4,textY);
	printf("  1. Mulai permainan");
	gotoxy(textX+5,textY);
	printf("  2. Petunjuk permainan");
	gotoxy(textX+6,textY);
	printf("  3. Keluar game");
	gotoxy(textX+7,textY);
	printf("----------------------------------");
	gotoxy(textX+8,textY);
	printf("Ketikkan pilihan anda >> ");
}

int inputMenu() // hasil disimpan di variabel, makanya pakai int
{
	int pilih;
	do{
		textPreGame();
		scanf("%d", &pilih);
	}while(pilih<1 || pilih>3);
	return pilih;
}

void instruksi()
{
	system("cls");
	gotoxy(textX,textY);
	printf("------------------------------------------------------");
	gotoxy(textX+1,textY);
	printf("                 PETUNJUK PERMAINAN");
	gotoxy(textX+3,textY);
	printf("                 Control player(010):");
	gotoxy(textX+4,textY);
	printf("              1. tekan A untuk ke kiri");
	gotoxy(textX+5,textY);
	printf("              2. tekan D untuk ke kanan");
	gotoxy(textX+7,textY);
	printf("  Anda akan mendapat skor setiap kali anda berhasil");
	gotoxy(textX+8,textY);
	printf("       menghindari penghalang(+) yang ada");
	gotoxy(textX+10,textY);
	printf("   Keluar rel juga akan membuat permainan berakhir");
	gotoxy(textX+12,textY);
	printf("       Jangan lupa untuk mengisi bensin($)");
	gotoxy(textX+14,textY);
	printf(" Bensin habis(*) juga akan membuat permainan berakhir");
	gotoxy(textX+16,textY);
	printf("         Tekan tombol esc untuk berhenti");
	gotoxy(textX+18,textY);
	printf("     Anda akan mendapat bonus \"Super Car\" jika");
	gotoxy(textX+19,textY);
	printf("         poin anda mencapai kelipatan 100");
	gotoxy(textX+21,textY);
	printf("     Game ini disertai dengan suara sederhana");
	gotoxy(textX+23,textY);
	printf("   (Tekan tombol apapun jika telah selesai membaca)");
	gotoxy(textX+24,textY);
	printf("------------------------------------------------------");
	getch();
}

void printKeterangan()
{
	gotoxy(textX, relKanan+10);
	printf("Control");
	gotoxy(textX+1, relKanan+10);
	printf("A - kiri");
	gotoxy(textX+2, relKanan+10);
	printf("D - kanan");
	gotoxy(textX+4, relKanan+10);
	printf("Press esc to pause");
	gotoxy(textX+6, relKanan+10);
	printf("Score: %u", mobil.point);
	gotoxy(textX+8, relKanan+10);
	printf("Bensin: (%d) ", mobil.isiBensin);
	int i;
	if(mobil.isiBensin>0)
	{
		for(i=0;i<mobil.isiBensin;i++)
			printf("*");
	}
}

void textGameOver()
{
	system("cls");
	gotoxy(textX,textY);
	printf("----------------------------------");
	gotoxy(textX+2,textY);
	printf("       PERMAINAN BERAKHIR");
	gotoxy(textX+4,textY);
	printf("         SCORE ANDA : %d", mobil.point);
	gotoxy(textX+6,textY);
	printf("(Tekan tombol enter untuk keluar)");
	gotoxy(textX+8,textY);
	printf("----------------------------------");
	getch();
}
