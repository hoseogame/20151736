#pragma once
#include"HEADER_GROUP.h"
#pragma region Screen_CLASS

class SCREEN_CLASS
{
public:
	SCREEN_CLASS();
	~SCREEN_CLASS();

	static int gotoxy(int x, int y);
	static void SetColor(int color);
	static int show_gameover();
	static int show_game_frame(int abs_y);

private:
	char screen[20][35];
};

#pragma endregion