#pragma once

#include"HEADER_GROUP.h"

class FootBall_Screen
{
public:
	static void ScreenInit();
	static void ScreenFlipping();
	static void ScreenClear();
	static void ScreenRelease();
	static void ScreenPrint(int x, int y, char *string);
	static void SetColor(unsigned short color);

	static void InitScreen();
	static void ReadyScreen();
	static void BackScreen();
	static void GoalMessage(int nX, int nY);
	static void SuccessScreen();
	static void FailureScreen();
	static void ResultScreen();

	static void Render(GOAL_DAE g_sGoalDae, BALL g_sBall, PLAYER g_sPlayer);

	static int g_nScreenIndex;
	static HANDLE g_hScreen[2];

private:
	friend class Football_Game;

};

//����ƽ ���� �ʱ�ȭ
int FootBall_Screen::g_nScreenIndex = 0;
HANDLE FootBall_Screen::g_hScreen[2] = { NULL,NULL };

#pragma region Screen.c ����-> Screen class ����

void FootBall_Screen::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// ������ �ܼ�â 2���� �����.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// Ŀ�� �����
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void FootBall_Screen::ScreenFlipping()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void FootBall_Screen::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void FootBall_Screen::ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}


void FootBall_Screen::ScreenPrint(int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// 1 ~ 15 ���� ���� ���� ����
void FootBall_Screen::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

#pragma endregion


void FootBall_Screen::InitScreen()
{
	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 2, "��             �ব������                   ��");
	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 4, "��                        ///.   ��~~~      ��");
	FootBall_Screen::ScreenPrint(0, 5, "��                       (^.^)              ��");
	FootBall_Screen::ScreenPrint(0, 6, "��                      ���� ����           ��");
	FootBall_Screen::ScreenPrint(0, 7, "��                         ����             ��");
	FootBall_Screen::ScreenPrint(0, 8, "��                     ��  ����             ��");
	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
	FootBall_Screen::ScreenPrint(0, 12, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 16, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 22, "����������������������������������������������");
}

void FootBall_Screen::ReadyScreen()
{
	char string[100];

	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
	FootBall_Screen::ScreenPrint(0, 1, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 2, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 3, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 4, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 5, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 6, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 7, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 8, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 9, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 10, "��������                    ������᦭");
	sprintf(string, "��������     %d   ��������   ������᦭", g_Opt.g_nStage + 1);
	FootBall_Screen::ScreenPrint(0, 11, string);
	FootBall_Screen::ScreenPrint(0, 12, "��������                    ������᦭");
	FootBall_Screen::ScreenPrint(0, 13, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 14, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 15, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 16, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 17, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 18, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 19, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 20, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 21, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 22, "�����������������������᦭");
	FootBall_Screen::ScreenPrint(0, 23, "����������������������������������������������");
}

void FootBall_Screen::BackScreen()
{
	char string[100];

	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
	sprintf(string, "��                                          ����������: %d", g_Opt.g_nStage + 1);
	FootBall_Screen::ScreenPrint(0, 4, string);
	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
	sprintf(string, "�������������������������������������������������� �ð�: %d", g_sStageInfo[g_Opt.g_nStage].LimitTime / 1000);
	FootBall_Screen::ScreenPrint(0, 6, string);
	FootBall_Screen::ScreenPrint(0, 7, "��                                          ��");
	sprintf(string, "��                                          ������ �ð�: %d", (clock() - g_Opt.g_GameStartTime) / 1000);
	FootBall_Screen::ScreenPrint(0, 8, string);
	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
	sprintf(string, "��                                          ����ǥ ����: %d ", g_sStageInfo[g_Opt.g_nStage].nGoalBall);
	FootBall_Screen::ScreenPrint(0, 10, string);
	FootBall_Screen::ScreenPrint(0, 11, "��                                          ��");
	sprintf(string, "��                                          ������ �� ����: %d ", g_Opt.g_nBallCount);
	FootBall_Screen::ScreenPrint(0, 12, string);

	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
	sprintf(string, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 14, string);
	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
	sprintf(string, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 16, string);
	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 18, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 22, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 23, "����������������������������������������������");
}

void FootBall_Screen::GoalMessage(int nX, int nY)
{
	FootBall_Screen::ScreenPrint(nX, nY, "�� )) ���� (( ��");
	FootBall_Screen::ScreenPrint(nX, nY + 1, "��(^^')/ ��(\"*')/");
	FootBall_Screen::ScreenPrint(nX, nY + 2, "   ��       ��");
	FootBall_Screen::ScreenPrint(nX, nY + 3, "  ����    ����");
}

void FootBall_Screen::SuccessScreen()
{
	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 4, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 6, "��                ////����                  ��");
	FootBall_Screen::ScreenPrint(0, 7, "��               q ��  �� p                 ��");
	FootBall_Screen::ScreenPrint(0, 8, "��               (��������)                 ��");
	FootBall_Screen::ScreenPrint(0, 9, "��             �� �̼� ���� ��              ��");
	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 11, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 12, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 14, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 16, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 18, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 22, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 23, "����������������������������������������������");
}

void FootBall_Screen::FailureScreen()
{
	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 4, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 6, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 7, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 8, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 11, "��                    �̼� ���� !!!!        ��");
	FootBall_Screen::ScreenPrint(0, 12, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 14, "��                 �ܦ�����                 ��");
	FootBall_Screen::ScreenPrint(0, 15, "��                   ��  ��                 ��");
	FootBall_Screen::ScreenPrint(0, 16, "��                  �����                ��");
	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 18, "��        �ٽ� �Ͻðڽ��ϱ�? (y/n)          ��");
	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 22, "����������������������������������������������");
}

void FootBall_Screen::ResultScreen()
{
	char string[100];
	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 3, "��             �ব������                   ��");
	FootBall_Screen::ScreenPrint(0, 4, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 6, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 7, "��                                          ��");
	sprintf(string, "��      ������ �������� :  %2d               ��", g_Opt.g_nStage + 1);
	FootBall_Screen::ScreenPrint(0, 8, string);
	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 11, "��   ___�ƢƢ�___                           ��");
	FootBall_Screen::ScreenPrint(0, 12, "��     (*^  ^*)                             ��");
	FootBall_Screen::ScreenPrint(0, 13, "�� =====��==��=====                         ��");
	FootBall_Screen::ScreenPrint(0, 14, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 16, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 18, "��                      ���ܦ�              ��");
	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
	FootBall_Screen::ScreenPrint(0, 22, "����������������������������������������������");
}


void FootBall_Screen::Render(GOAL_DAE g_sGoalDae, BALL g_sBall, PLAYER g_sPlayer)
{
	char string[100] = { 0, };
	int nLength, i;

	FootBall_Screen::ScreenClear();

	switch (g_sStageInfo->g_GameState)
	{
	case INIT:
		if (g_Opt.g_nStage == 0)
			InitScreen();
		break;
	case READY:
		ReadyScreen();
		break;
	case RUNNING:
		BackScreen();
		FootBall_Screen::ScreenPrint(g_sGoalDae.get_x(), g_sGoalDae.get_y(), "��");
		nLength = g_sGoalDae.nLength * 2 + 1;

		for (i = 0; i < nLength; i++)
			FootBall_Screen::ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.get_y(), "��");

		FootBall_Screen::ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.get_y(), "��");

		// Note: ȿ�� ���  	
		if (g_Opt.g_nIsGoal == 1)
		{
			GoalMessage(10, 10);
		}

		// Note: 2 �÷��� Ŭ���� 
		if (g_sPlayer.nX < 2)  //  ���� Ŭ���� ó��
			FootBall_Screen::ScreenPrint(2, g_sPlayer.get_y(), &g_Opt.g_strPlayer[(g_sPlayer.nX - 2)*-1]);	 // ��ǥ�� �迭 �ε��� 
		else if (g_sPlayer.get_x() + (g_Opt.g_nLength - g_sPlayer.nCenterX + 1) > 43) // ������ Ŭ���� ó��
		{
			strncat(string, g_Opt.g_strPlayer, g_Opt.g_nLength - ((g_sPlayer.get_x() + g_sPlayer.nCenterX + 1) - 43));
			FootBall_Screen::ScreenPrint(g_sPlayer.nX, g_sPlayer.get_y(), string);
		}
		else { // 1 �÷��� �̵�
			FootBall_Screen::ScreenPrint(g_sPlayer.nX, g_sPlayer.get_y(), g_Opt.g_strPlayer);
		}

		FootBall_Screen::ScreenPrint(g_sBall.get_x(), g_sBall.get_y(), "��");
		break;
	case SUCCESS:
		SuccessScreen();
		break;
	case FAILED:
		FailureScreen();
		break;
	case RESULT:
		ResultScreen();
		break;
	}

	// Note: ������ �� 
	FootBall_Screen::ScreenFlipping();
}