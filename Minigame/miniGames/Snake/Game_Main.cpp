//*****************************************************************
//	������ũ ��ü����
//	20151736 �ֽ�ȯ
//*****************************************************************
//////////////////////////////////////////////////////////////////
#include "HEADER_GROUP.h"
#include "CGAME_SYSTEM.h"
#include "SNAKE_GAME_CLASS.h"
#include "FOOTBALL_GAME_CLASS.h"
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

int main()
{
	int Inp = 0;
	CGAME_SYSTEM * game;
	
	while (1)
	{
		printf("������ �������ּ���.\n1. ������ũ ����\m2.ǲ�� ����\n�Է� : ");
		scanf("%d",Inp);
		switch (Inp)
		{
		case 1:
			game = new SNAKE_GAME_CLASS;
			game->Run();
			free(game);
			break;
		case 2:
			game = new FOOTBALL_GAME_CLASS;
			game->Run();
			free(game);
			break;
		default:
			break;
		}
	}
	/*	SNAKE_GAME_CLASS Game1;
		Game1.Run();

		FOOTBALL_GAME_CLASS Game2;
		Game2.Run();*/
}

