#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

const kiriArena = 0;
const kananArena = 30;
const bawahArena = 30;
const maksMusuh = 4;
const textX = 5;
const textYinGame = 40;
const textYpreGame = 10;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delay(float number_of_seconds)
{
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

struct position
{
	int x;
	int y;
};

struct pemain
{
	struct position posisiPlayer; // badannya
	struct position posisiPeluruPlayer[5];
	int peluruPlayer[5], bonus, poinAwalBonus;
	long int akhirBonus;
	unsigned int life, point;
}player;

struct lawan
{
	struct position posisiMusuh[4]; // badannya
	int peluruMusuh[4];
	struct position posisiPeluruMusuh[4];
	int adaMusuh[4];
}musuh;

void predefined(); // predefined game sebelum game dimulai
void countdown(); // countdown sebelum game dimulai
long int bonus(); // random bonus dari 3 macam
void printBonus(); // print bonus di layar
void awalBonus(); // memanggil bonus in game
void akhirBonus(); // waktu bonus berakhir
void textPreGame(); // menu utama
int inputMenu(); // input untuk menu utama
void textInstruksi(); // display instruksi
void textPilihKesulitan(); // display macam-macam level game
int pilihKesulitan(); // input level kesulitan
void textInGame(); // keterangan saat game jalan
void textGameOver(); // display setelah game over
void printBoard();
void printPlayer();
long int gerakPlayer();
void playerNembak();
void peluruPlayer(); // print posisi peluru player
void playerTertembak();
void spawnMusuh(int i); // dipanggil di fungsi tambahMusuh()
void tambahMusuh();
void printMusuh();
void musuhNembak(); // menentukan apakah musuh menembak/tidak
void peluruMusuh(); // print posisi peluru musuh
void hapusMusuh(); // kalau musuh tertembak
void inGame(int kesulitan); // yang dijalankan selama main game

int main()
{
	srand((unsigned)time(NULL));
	int input, kesulitan;
	do{
		input = inputMenu();
		switch(input)
		{
			case 1:
				kesulitan = pilihKesulitan();
				if(kesulitan!= 4)
				{
					inGame(kesulitan);
					textGameOver();
				}
				break;
			case 2:
				textInstruksi();
				break;
		}
	}while(input!=3);
	
	return 0;
}

void predefined(int kesulitan)
{
	int i;
	for(i=0;i<5;i++)
	{
		player.peluruPlayer[i] = 0;
		player.posisiPeluruPlayer[i].x = 0;
		player.posisiPeluruPlayer[i].y = 0;
	}
	for(i=0;i<4;i++)
	{
		musuh.peluruMusuh[i] = 0;
		musuh.posisiPeluruMusuh[i].x = 0;
		musuh.posisiPeluruMusuh[i].y = 0;
		musuh.posisiMusuh[i].x = 1;
		musuh.posisiMusuh[i].y = 0;
		musuh.adaMusuh[i] = 0;
	}
	player.posisiPlayer.x = 28;
	player.posisiPlayer.y = 15;
	player.point = 0;
	player.bonus = 0;
	player.akhirBonus = 0;
	player.life = 6 - kesulitan;
}

void countdown()
{
	Beep(530,150);
	delay(0.1);
    Beep(530,150);
	delay(0.3);
    Beep(530,150);
	delay(0.3);
    Beep(462,150);
	delay(0.1);
    Beep(510,150);
	delay(0.3);
    Beep(592,150);
	delay(0.7);
    Beep(296,150);
	delay(0.7);
}

long int bonus()
{
	int bns = 1 + rand()%3;
	long int code;
	switch(bns)
	{
		case 1: // bonus lives
			player.bonus = 1;
			player.life++;
			code = 0;
			break;
		case 2: //bonus shotgun
			player.bonus = 2;
			code = clock();
			break;
		case 3: //bonus invinsible
			player.bonus = 3;
			code = clock();
			break;
	}
	return code;
}

void printBonus()
{
	switch(player.bonus)
	{
		case 1:
			gotoxy(textX+12, textYinGame);
			printf("BONUS LIFE");
			break;
		case 2:
			gotoxy(textX+12, textYinGame);
			printf("SHOTGUN");
			break;
		case 3:
			gotoxy(textX+12, textYinGame);
			printf("INVISIBLE");
			break;
	}
}

void awalBonus()
{
	if(player.point%20 == 0 && player.point != 0 && player.point != player.poinAwalBonus)
	{
		player.poinAwalBonus = player.point;
		long int temp = bonus();
		if(temp != 0)
		{
			player.akhirBonus = temp + 15000;
		}
		printBonus();
		Beep(1200, 50);
		Beep(1300, 50);
	}
}

void akhirBonus()
{
	if(player.bonus != 0)
	{
		printBonus();
		if(player.bonus==2 || player.bonus==3)
		{
			if(player.akhirBonus<clock())
			{
				player.bonus = 0;
				gotoxy(textX+12, textYinGame);
				printf("          ");
			}
		}
		else if(player.bonus == 1 && player.point%10 != 0)
		{
			player.bonus = 0;
		}
	}
}

void textPreGame()
{
	system("cls");
	gotoxy(textX, textYpreGame);
	printf("--------------------------");
	gotoxy(textX+2, textYpreGame);
	printf("  SELAMAT DATANG DI GAME  ");
	gotoxy(textX+4, textYpreGame);
	printf("     \"BULLET WAR\"  ");
	gotoxy(textX+6, textYpreGame);
	printf("--------------------------");
	gotoxy(textX+8, textYpreGame);
	printf("  1. mulai permainan");
	gotoxy(textX+10, textYpreGame);
	printf("  2. instruksi");
	gotoxy(textX+12, textYpreGame);
	printf("  3. keluar permainan");
	gotoxy(textX+14, textYpreGame);
	printf("  Ketikkan nomor >> ");
}

int inputMenu()
{
	int input;
	do{
		textPreGame();
		scanf("%d", &input);
	}while(input<1 || input>3);
	return input;
}

void textInstruksi()
{
	system("cls");
	gotoxy(textX, textYpreGame);
	printf("----------------------------------------------------");
	gotoxy(textX+2, textYpreGame);
	printf("                 Control player:");
	gotoxy(textX+3, textYpreGame);
	printf("                 1. A - kiri");
	gotoxy(textX+4, textYpreGame);
	printf("                 2. D - kanan");
	gotoxy(textX+5, textYpreGame);
	printf("                 3. W - atas");
	gotoxy(textX+6, textYpreGame);
	printf("                 4. S - bawah");
	gotoxy(textX+7, textYpreGame);
	printf("                 5. L - tembak");
	gotoxy(textX+9, textYpreGame);
	printf(" Poin akan bertambah jika berhasil menembak musuh");
	gotoxy(textX+11, textYpreGame);
	printf("        Jika player tertembak, maka akan");
	gotoxy(textX+12, textYpreGame);
	printf("           mengurangi life player");
	gotoxy(textX+14, textYpreGame);
	printf("  Player akan dapat bonus jika poin yang didapat");
	gotoxy(textX+15, textYpreGame);
	printf("          telah mencapai kelipatan 20");
	gotoxy(textX+17, textYpreGame);
	printf("      Game akan berakhir jika life player 0");
	gotoxy(textX+19, textYpreGame);
	printf("  Game ini juga disertai dengan suara sederhana");
	gotoxy(textX+21, textYpreGame);
	printf("        (Tekan tombol apapun untuk keluar)");
	gotoxy(textX+23, textYpreGame);
	printf("----------------------------------------------------");
	getch();
}

void textPilihKesulitan()
{
	system("cls");
	gotoxy(textX, textYpreGame);
	printf("----------------------------------");
	gotoxy(textX+1, textYpreGame);
	printf("    Pilih level kesulitan:");
	gotoxy(textX+2, textYpreGame);
	printf("          1. Mudah");
	gotoxy(textX+3, textYpreGame);
	printf("          2. Sedang");
	gotoxy(textX+4, textYpreGame);
	printf("          3. Sulit");
	gotoxy(textX+5, textYpreGame);
	printf("      4. Kembali ke menu");
	gotoxy(textX+6, textYpreGame);
	printf("----------------------------------");
	gotoxy(textX+8, textYpreGame);
	printf("     Ketikkan nomor >> ");
}

int pilihKesulitan()
{
	int kesulitan;
	do{
		textPilihKesulitan();
		scanf("%d", &kesulitan);
	}while(kesulitan<1 || kesulitan>4);
	return kesulitan;
}

void textInGame()
{
	gotoxy(textX, textYinGame);
	printf("Control");
	gotoxy(textX+1, textYinGame);
	printf("A - kiri");
	gotoxy(textX+2, textYinGame);
	printf("D - kanan");
	gotoxy(textX+3, textYinGame);
	printf("W - atas");
	gotoxy(textX+4, textYinGame);
	printf("S - bawah");
	gotoxy(textX+5, textYinGame);
	printf("L - tembak");
	gotoxy(textX+6, textYinGame);
	printf("ESC - pause");
	gotoxy(textX+8, textYinGame);
	printf("Point: %u", player.point);
	gotoxy(textX+9, textYinGame);
	printf("Life: %u", player.life);
}

void textGameOver()
{
	system("cls");
	gotoxy(textX, textYpreGame);
	printf("------------------------------------");
	gotoxy(textX+2, textYpreGame);
	printf("        PERMAINAN BERAKHIR");
	gotoxy(textX+4, textYpreGame);
	printf("          SCORE ANDA : %u", player.point);
	gotoxy(textX+6, textYpreGame);
	printf(" (tekan tombol apapun untuk keluar)");
	gotoxy(textX+8, textYpreGame);
	printf("------------------------------------");
	getch();
}

void printBoard()
{
	int i;
	gotoxy(0,5);
	printf("( )"); // keluar dari posisi 0,6
	gotoxy(0,14);
	printf("( )"); // keluar dari posisi 0,15
	gotoxy(0,23);
	printf("( )"); // keluar dari posisi 0,24
	gotoxy(3,1);
	for(i=0;i<28;i++) // print pagar musuh
		printf("-");
	for(i=0;i<bawahArena-1;i++)
	{
		gotoxy(i,0);
		printf("-");
		gotoxy(i,kananArena);
		printf("-\n");
	}
	for(i=0;i<kananArena;i++) //bagian bawah
		printf("-");
}

void printPlayer()
{
	gotoxy(player.posisiPlayer.x, player.posisiPlayer.y);
	printf("0");
	gotoxy(player.posisiPlayer.x-1, player.posisiPlayer.y);
	printf("1");
}

long int gerakPlayer()
{
	long int awal,akhir;
	while(kbhit())
	{
		char input = getch();
		switch(input)
		{
			case 'L':
			case 'l':
				playerNembak();
				break;
			case 'A':
			case 'a':
				if(player.posisiPlayer.y - 1 > 0)
					player.posisiPlayer.y--;
				break;
			case 'D':
			case 'd':
				if(player.posisiPlayer.y + 1 < 30)
					player.posisiPlayer.y++;
				break;
			case 'W':
			case 'w':
				if(player.posisiPlayer.x - 1 > 4)
					player.posisiPlayer.x--;
				break;
			case 'S':
			case 's':
				if(player.posisiPlayer.x + 1 < 29)
					player.posisiPlayer.x++;
				break;
			case 27:
				gotoxy(textX+10, textYinGame);
				printf("Paused");
				gotoxy(textX+12, textYinGame);
				printf("Press any key to continue");
				awal = clock();
				getch();
				gotoxy(textX+10, textYinGame);
				printf("      ");
				gotoxy(textX+12, textYinGame);
				printf("                         ");
				Beep(540, 500);
				akhir = clock();
				break;
		}
	}
	return akhir-awal;
}

void playerNembak()
{
	int i;
	for(i=0;i<5;i++)
	{
		if(player.peluruPlayer[i] == 0)
		{
			player.posisiPeluruPlayer[i].x = player.posisiPlayer.x-2;
			player.posisiPeluruPlayer[i].y = player.posisiPlayer.y;
			player.peluruPlayer[i] = 1;
			Beep(1700, 20);
			Beep(1800, 20);
			break;
		}
	}
}

void peluruPlayer()
{
	int i;
	for(i=0;i<5;i++)
	{
		if(player.posisiPeluruPlayer[i].x < 1)
		{
			player.peluruPlayer[i] = 0;
			player.posisiPeluruPlayer[i].x = 0;
			player.posisiPeluruPlayer[i].y = 0;
		}
		else if(player.peluruPlayer[i] == 1)
		{
			if(player.bonus == 2)
			{
				gotoxy(player.posisiPeluruPlayer[i].x, player.posisiPeluruPlayer[i].y-1);
				printf("o");
				gotoxy(player.posisiPeluruPlayer[i].x, player.posisiPeluruPlayer[i].y+1);
				printf("o");
			}
			gotoxy(player.posisiPeluruPlayer[i].x, player.posisiPeluruPlayer[i].y);
			printf("o");
			player.posisiPeluruPlayer[i].x--;
		}
	}
}

void playerTertembak()
{
	int i;
	for(i=0;i<4;i++)
	{
		if(musuh.posisiPeluruMusuh[i].x == player.posisiPlayer.x && musuh.posisiPeluruMusuh[i].y == player.posisiPlayer.y)
		{
			if(player.bonus != 3)
			{
				player.life--;
				musuh.peluruMusuh[i] = 0;
				musuh.posisiPeluruMusuh[i].x = 0;
				musuh.posisiPeluruMusuh[i].y = 0;
				Beep(750, 100);
			}
		}
	}
}

void spawnMusuh(int i)
{
	musuh.posisiMusuh[i].x = 1;
	musuh.posisiMusuh[i].y = rand()%3;
	if(musuh.posisiMusuh[i].y == 0)
		musuh.posisiMusuh[i].y = 6;
	else if(musuh.posisiMusuh[i].y == 1)
		musuh.posisiMusuh[i].y = 15;
	else
		musuh.posisiMusuh[i].y = 24;
	musuh.adaMusuh[i] = 1;
}

void tambahMusuh()
{
	int i, jumlah=0;
	for(i=0;i<maksMusuh;i++)
	{
		if(musuh.adaMusuh[i] == 1)
		{
			jumlah++;
		}
	}
	if(jumlah < maksMusuh)
	{
		for(i=0;i<maksMusuh;i++)
		{
			if(musuh.adaMusuh[i] == 0)
			{
				spawnMusuh(i);
				break;
			}
		}
	}
}

void printMusuh()
{
	int i;
	for(i=0;i<4;i++)
	{
		if(musuh.adaMusuh[i] == 1)
		{
			gotoxy(musuh.posisiMusuh[i].x, musuh.posisiMusuh[i].y);
			printf("@");
			gotoxy(musuh.posisiMusuh[i].x+1, musuh.posisiMusuh[i].y);
			printf("!");
			int random = rand()%3;
			if(random==0 && musuh.posisiMusuh[i].y>1)
				musuh.posisiMusuh[i].y--;
			else if(random==2 && musuh.posisiMusuh[i].y<29)
				musuh.posisiMusuh[i].y++;
		}
	}
}

void musuhNembak()
{
	int i, random=rand()%2;
	for(i=0;i<4;i++)
	{
		if(musuh.peluruMusuh[i] == 0 && random == 1)
		{
			musuh.posisiPeluruMusuh[i].x = musuh.posisiMusuh[i].x+2;
			musuh.posisiPeluruMusuh[i].y = musuh.posisiMusuh[i].y;
			musuh.peluruMusuh[i] = 1;
			break;
		}
	}
}

void peluruMusuh()
{
	int i;
	for(i=0;i<4;i++)
	{
		if(musuh.posisiPeluruMusuh[i].x > 29)
		{
			musuh.peluruMusuh[i] = 0;
			musuh.posisiPeluruMusuh[i].x = 0;
			musuh.posisiPeluruMusuh[i].y = 0;
		}
		else if(musuh.peluruMusuh[i])
		{
			gotoxy(musuh.posisiPeluruMusuh[i].x, musuh.posisiPeluruMusuh[i].y);
			printf("*");
			musuh.posisiPeluruMusuh[i].x++;
		}
	}
}

void hapusMusuh()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(player.bonus == 2)
			{
				if(musuh.posisiMusuh[i].x == player.posisiPeluruPlayer[j].x)
				{
					if(musuh.posisiMusuh[i].y == player.posisiPeluruPlayer[j].y || musuh.posisiMusuh[i].y == player.posisiPeluruPlayer[j].y+1 || musuh.posisiMusuh[i].y == player.posisiPeluruPlayer[j].y-1)
					{
						musuh.adaMusuh[i] = 0;
						player.peluruPlayer[j] = 0;
						player.point++;
						Beep(600, 10);
						Beep(650, 10);
						Beep(625, 10);
					}
				}
			}
			else
			{
				if(musuh.posisiMusuh[i].x == player.posisiPeluruPlayer[j].x && musuh.posisiMusuh[i].y == player.posisiPeluruPlayer[j].y)
				{
					musuh.adaMusuh[i] = 0;
					player.peluruPlayer[j] = 0;
					player.point++;
					Beep(600, 10);
					Beep(650, 10);
					Beep(625, 10);
				}
			}
		}
	}
}

void inGame(int kesulitan)
{
	long int paused;
	predefined(kesulitan);
	system("cls");
	printBoard();
	printPlayer();
	countdown();
	do{
		system("cls");
		awalBonus();
		akhirBonus();
		printBoard();
		printPlayer();
		paused = gerakPlayer();
		if(paused != 0 && player.bonus==2 || player.bonus==3)
		{
			player.akhirBonus+=paused;
			printBonus();
		}
		peluruPlayer();
		playerTertembak();
		tambahMusuh();
		printMusuh();
		musuhNembak();
		peluruMusuh();
		hapusMusuh();
		textInGame();
		delay(0.08);
	}while(player.life>0);
	Beep(750, 500);
	textGameOver();
}
