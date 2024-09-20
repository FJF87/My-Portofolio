#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD c;
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
	gotoxy(10,10);
	printf("di sini");;
	gotoxy(11,10);
	printf("ada lagi");
	return 0;
}
