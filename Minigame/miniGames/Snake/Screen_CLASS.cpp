#include"Screen_CLASS.h"
SCREEN_CLASS::SCREEN_CLASS()
{
}

SCREEN_CLASS::~SCREEN_CLASS()
{
}


int SCREEN_CLASS::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void SCREEN_CLASS::SetColor(int color)

{
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);

}

int SCREEN_CLASS::show_gameover()
{
	SetColor(RED);
	gotoxy(15, 8);
	printf("������������������������������");
	gotoxy(15, 9);
	printf("��**************************��");
	gotoxy(15, 10);
	printf("��*        GAME OVER       *��");
	gotoxy(15, 11);
	printf("��**************************��");
	gotoxy(15, 12);
	printf("������������������������������");

	Sleep(1000);

	fflush(stdin);
	fflush(stdout);
	system("cls");
	return 0;
}


int SCREEN_CLASS::show_game_frame(int abs_y)
{
	int i;
	SetColor(GRAY);
	system("cls");
	gotoxy(0, 1);
	printf("��������������������������������������������������������������������������");
	for (i = 2; i<22; i++)
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(72, i);
		printf("��");
	}
	gotoxy(0, 20 + abs_y);
	printf("��������������������������������������������������������������������������");

	for (i = 4; i<20; i += 2)
	{
		gotoxy(76, i);
		printf("��");
	}

	for (i = 5; i<20; i += 2)
	{
		gotoxy(75, i);
		printf("��");
	}
	gotoxy(75, 2);
	printf("��");
	gotoxy(75, 3);
	printf("��");

	gotoxy(4, 0);
	printf("Snake Ver 0.1                                    Made By Jae-Dong");
	return 0;
}
