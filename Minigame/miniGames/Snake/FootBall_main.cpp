/////////////////////////////////////////////////////////////
//ǲ�� ���� ��ü���� ���α׷���
//�ۼ��� : �ֽ�ȯ
//1 ��ü���� ���ӱ��� Ŭ����ȭ
//2 PointŬ������ �̿��� ������Ʈ�� Ŭ����ȭ
//3 �������� ������ ���� �ɼ� �����ϴ� �������� Ŭ����ȭ
/////////////////////////////////////////////////////////////

#pragma region

#pragma region �������
#include "Point_Class.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
//#include <fmod.h>
#include <windows.h>

#pragma endregion

#pragma region Ÿ�Ը� ���� �� ���� ����

//#define MAX_STAGE_ 2

//////

typedef enum _GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT } GAME_STATE;

//class EFFECT
//{
//public:
//	clock_t StratTime; // ȿ�� �߻� �ð�
//	clock_t StayTime;  // ȿ�� ���� �ð�	
//};
//
//
//class STAGE_OPTION
//{
//public:
//	char g_strPlayer[11];
//	int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage, g_nIsGoal;
//	clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;
//
//
//	STAGE_OPTION::STAGE_OPTION()
//	{
//		g_nStage = -1;
//		strcpy(g_strPlayer, "�����ܦ���");
//	}
//};

#pragma region �������� ���� Ŭ����

//class STAGE_INFO_CLASS
//{
//public:
//	int nGoalBall;			// �����ؾ� �� ���� ���� 
//	clock_t LimitTime;      // ���� �ð� 
//	int nGoalDaeLength;		// ��� ���� 
//	int nGoalDaeX;			// ��� �̵� X ��ǥ
//	int nGoalDaeY;			// ��� �̵� Y ��ǥ 
//	clock_t MoveTime;		// ��� �̵� �ð� ����
//	int nDist;				// ��� �̵� �Ÿ�
//
//	static GAME_STATE g_GameState;
//
//	void Set_Info(int GoalBall, clock_t LT, int GoalDaeLength, int GoalDaeX, int GoalDaeY, clock_t MT, int Dist);
//};
//
//GAME_STATE STAGE_INFO_CLASS::g_GameState = INIT;
//
//void STAGE_INFO_CLASS::Set_Info(int GoalBall, clock_t LT, int GoalDaeLength, int GoalDaeX, int GoalDaeY, clock_t MT, int Dist)
//{
//	nGoalBall = GoalBall;
//	LimitTime = LT;
//	nGoalDaeLength = GoalDaeLength;
//	nGoalDaeX = GoalDaeX;
//	nGoalDaeY = GoalDaeY;
//	MoveTime = MT;
//	nDist = Dist;
//}

STAGE_INFO_CLASS g_sStageInfo[MAX_STAGE_];

STAGE_OPTION g_Opt;

#pragma endregion

//FMOD_SYSTEM *g_System;  // FMOD system ��������
//FMOD_SOUND  *g_Sound[7];          // ��� ����                       ȿ�� ���� 
//char        *g_strFileName[7] = { "init.wav", "run.wav", "fail.wav", "ready.wav", "success.wav", "shoot.wav", "wow.wav" };
//FMOD_CHANNEL *g_Channel[7];

#pragma endregion

#pragma region ������Ʈ ���� Ŭ����

//class Point
//{
//public:
//	Point()
//	{
//		x = 0;
//		y = 0;
//	}
//	int get_x()
//	{
//		return x;
//	}
//	int get_y()
//	{
//		return y;
//	}
//	void set_x(int ix)
//	{
//		x = ix;
//	}
//	void set_y(int iy)
//	{
//		y = iy;
//	}
//	void set_point(int ix, int iy)
//	{
//		x = ix;
//		y = iy;
//	}
//	void plus_x(int px)
//	{
//		x += px;
//	}
//	void plus_y(int py)
//	{
//		y += py;
//	}
//	void plus_point(int px, int py)
//	{
//		x += px;
//		y += py;
//	}
//
//private:
//	int x, y;
//};

//class PLAYER : public POINT
//{
//public:
//	int nCenterX, nCenterY;
//	//int nMoveX, nMoveY;
//	int nX, nY;
//	friend class FOOTBALL_GAME_CLASS;
//};
//
//class BALL : public POINT
//{
//public:
//	int nIsReady;        // �غ� ����(1), ������(0)
//						 //int nMoveX, nMoveY;  // �̵� ��ǥ
//	clock_t MoveTime;    // �̵� �ð� ����
//	clock_t OldTime;     // ���� �̵� �ð�
//	friend class FOOTBALL_GAME_CLASS;
//};
//
//class GOAL_DAE : public POINT
//{
//public:
//	//int nMoveX, nMoveY;     // �̵� ��ǥ 
//	int nLength;			// ��� ����	
//	int nLineX[7];			// ���� ���� x ��ǥ (7��)
//	clock_t	MoveTime;		// �̵� �ð� ����
//	clock_t	OldTime;	    // ���� �̵� �ð�
//	int	nDist;				// �̵� �Ÿ�
//	friend class FOOTBALL_GAME_CLASS;
//};

#pragma endregion

#pragma region Screen Ŭ����

//class FootBall_Screen
//{
//public:
//	static void ScreenInit();
//	static void ScreenFlipping();
//	static void ScreenClear();
//	static void ScreenRelease();
//	static void ScreenPrint(int x, int y, char *string);
//	static void SetColor(unsigned short color);
//
//	static void InitScreen();
//	static void ReadyScreen();
//	static void BackScreen();
//	static void GoalMessage(int nX, int nY);
//	static void SuccessScreen();
//	static void FailureScreen();
//	static void ResultScreen();
//
//	static void Render(GOAL_DAE g_sGoalDae, BALL g_sBall, PLAYER g_sPlayer);
//
//	static int g_nScreenIndex;
//	static HANDLE g_hScreen[2];
//
//private:
//	friend class Football_Game;
//
//};
//
////����ƽ ���� �ʱ�ȭ
//int FootBall_Screen::g_nScreenIndex = 0;
//HANDLE FootBall_Screen::g_hScreen[2] = { NULL,NULL };
//
//#pragma region Screen.c ����-> Screen class ����
//
//void FootBall_Screen::ScreenInit()
//{
//	CONSOLE_CURSOR_INFO cci;
//
//	// ������ �ܼ�â 2���� �����.
//	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//
//	// Ŀ�� �����
//	cci.dwSize = 1;
//	cci.bVisible = FALSE;
//	SetConsoleCursorInfo(g_hScreen[0], &cci);
//	SetConsoleCursorInfo(g_hScreen[1], &cci);
//}
//
//void FootBall_Screen::ScreenFlipping()
//{
//	Sleep(10);
//	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
//	g_nScreenIndex = !g_nScreenIndex;
//}
//
//void FootBall_Screen::ScreenClear()
//{
//	COORD Coor = { 0, 0 };
//	DWORD dw;
//	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
//}
//
//void FootBall_Screen::ScreenRelease()
//{
//	CloseHandle(g_hScreen[0]);
//	CloseHandle(g_hScreen[1]);
//}
//
//
//void FootBall_Screen::ScreenPrint(int x, int y, char *string)
//{
//	DWORD dw;
//	COORD CursorPosition = { x, y };
//	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
//	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
//}
//
//// 1 ~ 15 ���� ���� ���� ����
//void FootBall_Screen::SetColor(unsigned short color)
//{
//	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
//}
//
//#pragma endregion
//
//
//void FootBall_Screen::InitScreen()
//{
//	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
//	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 2, "��             �ব������                   ��");
//	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 4, "��                        ///.   ��~~~      ��");
//	FootBall_Screen::ScreenPrint(0, 5, "��                       (^.^)              ��");
//	FootBall_Screen::ScreenPrint(0, 6, "��                      ���� ����           ��");
//	FootBall_Screen::ScreenPrint(0, 7, "��                         ����             ��");
//	FootBall_Screen::ScreenPrint(0, 8, "��                     ��  ����             ��");
//	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
//	FootBall_Screen::ScreenPrint(0, 12, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
//	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 16, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
//	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 22, "����������������������������������������������");
//}
//
//void FootBall_Screen::ReadyScreen()
//{
//	char string[100];
//
//	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
//	FootBall_Screen::ScreenPrint(0, 1, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 2, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 3, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 4, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 5, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 6, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 7, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 8, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 9, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 10, "��������                    ������᦭");
//	sprintf(string, "��������     %d   ��������   ������᦭", g_Opt.g_nStage + 1);
//	FootBall_Screen::ScreenPrint(0, 11, string);
//	FootBall_Screen::ScreenPrint(0, 12, "��������                    ������᦭");
//	FootBall_Screen::ScreenPrint(0, 13, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 14, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 15, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 16, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 17, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 18, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 19, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 20, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 21, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 22, "�����������������������᦭");
//	FootBall_Screen::ScreenPrint(0, 23, "����������������������������������������������");
//}
//
//void FootBall_Screen::BackScreen()
//{
//	char string[100];
//
//	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
//	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
//	sprintf(string, "��                                          ����������: %d", g_Opt.g_nStage + 1);
//	FootBall_Screen::ScreenPrint(0, 4, string);
//	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
//	sprintf(string, "�������������������������������������������������� �ð�: %d", g_sStageInfo[g_Opt.g_nStage].LimitTime / 1000);
//	FootBall_Screen::ScreenPrint(0, 6, string);
//	FootBall_Screen::ScreenPrint(0, 7, "��                                          ��");
//	sprintf(string, "��                                          ������ �ð�: %d", (clock() - g_Opt.g_GameStartTime) / 1000);
//	FootBall_Screen::ScreenPrint(0, 8, string);
//	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
//	sprintf(string, "��                                          ����ǥ ����: %d ", g_sStageInfo[g_Opt.g_nStage].nGoalBall);
//	FootBall_Screen::ScreenPrint(0, 10, string);
//	FootBall_Screen::ScreenPrint(0, 11, "��                                          ��");
//	sprintf(string, "��                                          ������ �� ����: %d ", g_Opt.g_nBallCount);
//	FootBall_Screen::ScreenPrint(0, 12, string);
//
//	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
//	sprintf(string, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 14, string);
//	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
//	sprintf(string, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 16, string);
//	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 18, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 22, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 23, "����������������������������������������������");
//}
//
//void FootBall_Screen::GoalMessage(int nX, int nY)
//{
//	FootBall_Screen::ScreenPrint(nX, nY, "�� )) ���� (( ��");
//	FootBall_Screen::ScreenPrint(nX, nY + 1, "��(^^')/ ��(\"*')/");
//	FootBall_Screen::ScreenPrint(nX, nY + 2, "   ��       ��");
//	FootBall_Screen::ScreenPrint(nX, nY + 3, "  ����    ����");
//}
//
//void FootBall_Screen::SuccessScreen()
//{
//	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
//	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 4, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 6, "��                ////����                  ��");
//	FootBall_Screen::ScreenPrint(0, 7, "��               q ��  �� p                 ��");
//	FootBall_Screen::ScreenPrint(0, 8, "��               (��������)                 ��");
//	FootBall_Screen::ScreenPrint(0, 9, "��             �� �̼� ���� ��              ��");
//	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 11, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 12, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 14, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 16, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 18, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 22, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 23, "����������������������������������������������");
//}
//
//void FootBall_Screen::FailureScreen()
//{
//	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
//	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 3, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 4, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 6, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 7, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 8, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 11, "��                    �̼� ���� !!!!        ��");
//	FootBall_Screen::ScreenPrint(0, 12, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 13, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 14, "��                 �ܦ�����                 ��");
//	FootBall_Screen::ScreenPrint(0, 15, "��                   ��  ��                 ��");
//	FootBall_Screen::ScreenPrint(0, 16, "��                  �����                ��");
//	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 18, "��        �ٽ� �Ͻðڽ��ϱ�? (y/n)          ��");
//	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 22, "����������������������������������������������");
//}
//
//void FootBall_Screen::ResultScreen()
//{
//	char string[100];
//	FootBall_Screen::ScreenPrint(0, 0, "����������������������������������������������");
//	FootBall_Screen::ScreenPrint(0, 1, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 2, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 3, "��             �ব������                   ��");
//	FootBall_Screen::ScreenPrint(0, 4, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 5, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 6, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 7, "��                                          ��");
//	sprintf(string, "��      ������ �������� :  %2d               ��", g_Opt.g_nStage + 1);
//	FootBall_Screen::ScreenPrint(0, 8, string);
//	FootBall_Screen::ScreenPrint(0, 9, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 10, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 11, "��   ___�ƢƢ�___                           ��");
//	FootBall_Screen::ScreenPrint(0, 12, "��     (*^  ^*)                             ��");
//	FootBall_Screen::ScreenPrint(0, 13, "�� =====��==��=====                         ��");
//	FootBall_Screen::ScreenPrint(0, 14, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 15, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 16, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 17, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 18, "��                      ���ܦ�              ��");
//	FootBall_Screen::ScreenPrint(0, 19, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 20, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 21, "��                                          ��");
//	FootBall_Screen::ScreenPrint(0, 22, "����������������������������������������������");
//}
//
//
//void FootBall_Screen::Render(GOAL_DAE g_sGoalDae, BALL g_sBall, PLAYER g_sPlayer)
//{
//	char string[100] = { 0, };
//	int nLength, i;
//
//	FootBall_Screen::ScreenClear();
//
//	switch (g_sStageInfo->g_GameState)
//	{
//	case INIT:
//		if (g_Opt.g_nStage == 0)
//			InitScreen();
//		break;
//	case READY:
//		ReadyScreen();
//		break;
//	case RUNNING:
//		BackScreen();
//		FootBall_Screen::ScreenPrint(g_sGoalDae.get_x(), g_sGoalDae.get_y(), "��");
//		nLength = g_sGoalDae.nLength * 2 + 1;
//
//		for (i = 0; i < nLength; i++)
//			FootBall_Screen::ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.get_y(), "��");
//
//		FootBall_Screen::ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.get_y(), "��");
//
//		// Note: ȿ�� ���  	
//		if (g_Opt.g_nIsGoal == 1)
//		{
//			GoalMessage(10, 10);
//		}
//
//		// Note: 2 �÷��� Ŭ���� 
//		if (g_sPlayer.nX < 2)  //  ���� Ŭ���� ó��
//			FootBall_Screen::ScreenPrint(2, g_sPlayer.get_y(), &g_Opt.g_strPlayer[(g_sPlayer.nX - 2)*-1]);	 // ��ǥ�� �迭 �ε��� 
//		else if (g_sPlayer.get_x() + (g_Opt.g_nLength - g_sPlayer.nCenterX + 1) > 43) // ������ Ŭ���� ó��
//		{
//			strncat(string, g_Opt.g_strPlayer, g_Opt.g_nLength - ((g_sPlayer.get_x() + g_sPlayer.nCenterX + 1) - 43));
//			FootBall_Screen::ScreenPrint(g_sPlayer.nX, g_sPlayer.get_y(), string);
//		}
//		else { // 1 �÷��� �̵�
//			FootBall_Screen::ScreenPrint(g_sPlayer.nX, g_sPlayer.get_y(), g_Opt.g_strPlayer);
//		}
//
//		FootBall_Screen::ScreenPrint(g_sBall.get_x(), g_sBall.get_y(), "��");
//		break;
//	case SUCCESS:
//		SuccessScreen();
//		break;
//	case FAILED:
//		FailureScreen();
//		break;
//	case RESULT:
//		ResultScreen();
//		break;
//	}
//
//	// Note: ������ �� 
//	FootBall_Screen::ScreenFlipping();
//}


#pragma endregion

#pragma region Football_Game Ŭ���� 

class Football_Game
{
public:
	// �Լ�
	Football_Game();
	virtual void play();
	void Init();
	void Release();
	void Update();


private:
	friend class FootBall_Screen;
	//����

	FootBall_Screen Scr;
	EFFECT g_sEffect;

	GOAL_DAE g_sGoalDae;
	BALL g_sBall;
	PLAYER g_sPlayer;

	int nKey, nRemain;

};

Football_Game::Football_Game()
{
	g_sStageInfo[0].Set_Info(3, 1000 * 20, 1, 20, 3, 300, 1);
	g_sStageInfo[1].Set_Info(10, 1000 * 30, 2, 20, 5, 300, 1);

}

void Football_Game::play()
{


	Scr.ScreenInit();
	Football_Game::Init();        // �ʱ�ȭ

	while (1)
	{
		//if (_kbhit())
		//{
		//	if (g_sStageInfo->g_GameState == RESULT)
		//		break;

		//	nKey = _getch();

		//	switch (nKey)
		//	{
		//	case 'j':
		//		if (g_sPlayer.get_x() > 2) // ���� �浹 ��� ��ǥ üũ
		//		{
		//			g_sPlayer.plus_x(-1);
		//			nRemain = g_Opt.g_nLength - g_sPlayer.nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
		//																// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
		//			if (g_sPlayer.get_x() - g_sPlayer.nCenterX < 2 || g_sPlayer.get_x() + nRemain > 43)
		//				g_sPlayer.plus_x(-1);

		//			g_sPlayer.nX = g_sPlayer.get_x() - g_sPlayer.nCenterX;
		//		}
		//		break;
		//	case 'l':
		//		if (g_sPlayer.get_x() + 1 < 43) // ������ �浹 ��� ��ǥ üũ
		//		{
		//			g_sPlayer.plus_x(1);
		//			nRemain = g_Opt.g_nLength - g_sPlayer.nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
		//																// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
		//			if (g_sPlayer.get_x() + nRemain > 43 || (g_sPlayer.get_x() - g_sPlayer.nCenterX < 2))
		//				g_sPlayer.plus_x(1);

		//			g_sPlayer.nX = g_sPlayer.get_x() - g_sPlayer.nCenterX;
		//		}
		//		break;
		//	case 'k':
		//		if (g_sBall.nIsReady && g_sStageInfo->g_GameState == RUNNING)
		//		{
		//			g_sBall.set_x(g_sPlayer.get_x());
		//			g_sBall.set_y(g_sPlayer.get_y() - 1);
		//			g_sBall.OldTime = clock();
		//			g_sBall.nIsReady = 0;
		//			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // �� ���� �Ҹ� ���
		//		}
		//		break;

		//	case 'y':
		//	case 'Y':
		//		if (g_sStageInfo->g_GameState == FAILED)
		//		{
		//			Init();
		//			g_sStageInfo->g_GameState = READY;
		//			//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ���� 
		//			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);
		//		}
		//		break;
		//	case 'n':
		//	case 'N':
		//		if (g_sStageInfo->g_GameState == FAILED)
		//		{
		//			g_sStageInfo->g_GameState = RESULT;
		//			//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ����							
		//		}
		//		break;

		//	case ' ':
		//		if (g_sStageInfo->g_GameState == INIT && g_Opt.g_nStage == 0)
		//		{
		//			g_sStageInfo->g_GameState = READY;
		//			//FMOD_Channel_Stop( g_Channel[0] ); // ����� ����
		//			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]); // ready ����
		//			g_Opt.g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
		//		}
		//		break;
		//	}
		//}


		Football_Game::Update();// ������ ����
		Scr.Render(g_sGoalDae, g_sBall, g_sPlayer);    // ȭ�� ���
													   //FMOD_System_Update( g_System );		
	}

	Football_Game::Release();   // ����
	FootBall_Screen::ScreenRelease();
}


void Football_Game::Init()
{
	int nLength, i;

	if (g_Opt.g_nStage == -1)
	{
		//SoundInit(); // ���� �ʱ�ȭ
		g_Opt.g_nStage = 0;
		//FMOD_CHANNEL_FREE( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel[0]); // �Ұ� ����� ��ü���� �ѹ��� �����Ѵ�.
	}

	g_Opt.g_LimitTime = g_sStageInfo[g_Opt.g_nStage].LimitTime;  // ���� �ð� ����
	g_Opt.g_nGoalBallCount = g_sStageInfo[g_Opt.g_nStage].nGoalBall; // ��ǥ ���� ����

	g_sPlayer.nCenterX = 4;
	g_sPlayer.nCenterY = 0;
	g_sPlayer.set_x(20);
	g_sPlayer.set_y(22);
	g_sPlayer.nX = g_sPlayer.get_x() - g_sPlayer.nCenterX;
	g_Opt.g_nLength = strlen(g_Opt.g_strPlayer);

	// ���� �ʱ�ȭ
	g_sBall.nIsReady = 1;
	g_sBall.set_x(g_sPlayer.get_x());
	g_sBall.set_y(g_sPlayer.get_y() - 1);
	g_sBall.MoveTime = 100;

	// ��� �ʱ�ȭ

	g_sGoalDae.set_x(g_sStageInfo[g_Opt.g_nStage].nGoalDaeX);
	g_sGoalDae.set_y(g_sStageInfo[g_Opt.g_nStage].nGoalDaeY);
	g_sGoalDae.nLength = g_sStageInfo[g_Opt.g_nStage].nGoalDaeLength;
	g_sGoalDae.MoveTime = g_sStageInfo[g_Opt.g_nStage].MoveTime;
	g_sGoalDae.OldTime = clock();
	g_sGoalDae.nDist = g_sStageInfo[g_Opt.g_nStage].nDist;
	nLength = g_sGoalDae.nLength * 2 + 1; // Note: �迭�� �ִ� ����

	for (i = 0; i < nLength; i++)
	{
		g_sGoalDae.nLineX[i] = g_sGoalDae.get_x() + 2 * (i + 1);
	}

	// ȿ�� 
	g_sEffect.StayTime = 2000; // 2�� ����
	g_Opt.g_nGoal = 0;      // �������� �Ϸ� ����
	g_Opt.g_UpdateOldTime = clock();
	g_Opt.g_nBallCount = 0;  // ������ ���� ����
}

void Football_Game::Release()
{
	//+int i;
	/*for( i = 0 ; i < 7 ; i++ )
	FMOD_Sound_Release( g_Sound[i] );

	FMOD_System_Close( g_System );
	FMOD_System_Release( g_System ); */
}

void Football_Game::Update()
{
	clock_t CurTime = clock();
	int nLength = g_sGoalDae.nLength * 2 + 1; // Note: �迭�� �ִ� ����
	int i;


	switch (g_sStageInfo->g_GameState)
	{
	case READY:
		if (CurTime - g_Opt.g_UpdateOldTime > 2000)  // 2��
		{
			g_sStageInfo->g_GameState = RUNNING;
			g_Opt.g_GameStartTime = CurTime;

			//FMOD_Channel_Stop( g_Channel[3] );  // ready ���� ����
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &g_Channel[1]); // running �����
		}
		break;
	case RUNNING:
		if (CurTime - g_Opt.g_GameStartTime > g_Opt.g_LimitTime) // Note: ���� �ð�
		{
			g_sStageInfo->g_GameState = STOP;
			return;
		}
		else {
			// Note: ���
			if (CurTime - g_sGoalDae.OldTime > g_sGoalDae.MoveTime)
			{
				g_sGoalDae.OldTime = CurTime;
				if (g_sGoalDae.get_x() + g_sGoalDae.nDist >= 2 && ((g_sGoalDae.nLineX[nLength - 1] + 3) + g_sGoalDae.nDist) <= 43)
				{
					g_sGoalDae.plus_x(g_sGoalDae.nDist);
					for (i = 0; i < nLength; i++)
					{
						g_sGoalDae.nLineX[i] = g_sGoalDae.get_x() + 2 * (i + 1);
					}
				}
				else {
					g_sGoalDae.nDist = g_sGoalDae.nDist * -1; // -1 �� ������ �ٲپ� ��.
				}
			}

			if (g_sBall.nIsReady == 0) // �̵� ���� �� 
			{	// �̵� �ð� ���ݿ� ���� �̵�
				if ((CurTime - g_sBall.OldTime) > g_sBall.MoveTime)
				{
					if (g_sBall.get_y() - 1 > 0)
					{
						g_sBall.plus_y(-1);
						g_sBall.OldTime = CurTime; // ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����

												   // ��� ���� �浹
						if (g_sBall.get_x() >= g_sGoalDae.nLineX[0] && g_sBall.get_x() + 1 <= g_sGoalDae.nLineX[nLength - 1] + 1)
						{
							if (g_sBall.get_y() <= g_sGoalDae.get_y())
							{   // �� �ʱ�ȭ
								g_sBall.nIsReady = 1;
								g_sBall.set_x(g_sPlayer.get_x());
								g_sBall.set_y(g_sPlayer.get_y() - 1);
								g_Opt.g_nBallCount++;  // ������ ���� ����										

								if (g_Opt.g_nBallCount == g_Opt.g_nGoalBallCount) // ���� ��ǥ ������ ������ ������ SUCCESS
								{
									g_sStageInfo->g_GameState = STOP;
									g_Opt.g_nGoal = 1;
									return;
								}

								// ȿ�� ���
								if (g_Opt.g_nIsGoal == 0)
								{
									g_Opt.g_nIsGoal = 1;
									g_sEffect.StratTime = CurTime;
								}

								// ���� ���� ���
								//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[6], 0, &g_Channel[6]); // ���� ���� �Ϳ�~
							}
							// ��� �浹 
						}
						else if ((g_sBall.get_x() >= g_sGoalDae.nLineX[0] - 2 && g_sBall.get_x() <= g_sGoalDae.nLineX[0] - 1) ||
							(g_sBall.get_x() + 1 >= g_sGoalDae.nLineX[0] - 2 && g_sBall.get_x() + 1 <= g_sGoalDae.nLineX[0] - 1) ||
							(g_sBall.get_x() >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.get_x() <= g_sGoalDae.nLineX[nLength - 1] + 3) ||
							(g_sBall.get_x() + 1 >= g_sGoalDae.nLineX[nLength - 1] + 2 && g_sBall.get_x() + 1 <= g_sGoalDae.nLineX[nLength - 1] + 3))
						{
							if (g_sBall.get_y() <= g_sGoalDae.get_y())
							{   // �� �ʱ�ȭ
								g_sBall.nIsReady = 1;
								g_sBall.set_x(g_sPlayer.get_x());
								g_sBall.set_y(g_sPlayer.get_y() - 1);
							}
						}
					}
					else { // �� �ʱ�ȭ
						g_sBall.nIsReady = 1;
						g_sBall.set_x(g_sPlayer.get_x());
						g_sBall.set_y(g_sPlayer.get_y() - 1);
					}
				}
			}
			else {
				g_sBall.set_x(g_sPlayer.get_x());
			}

			// ȿ�� 
			if (g_Opt.g_nIsGoal == 1)
			{
				if (CurTime - g_sEffect.StratTime > g_sEffect.StayTime)
					g_Opt.g_nIsGoal = 0;
			}
		}
		break;
	case STOP:
		if (g_Opt.g_nGoal == 1)
		{
			g_sStageInfo->g_GameState = SUCCESS;
			g_Opt.g_UpdateOldTime = CurTime;
			//FMOD_Channel_Stop( g_Channel[1] );  // running ���� ����
			//FMOD_Channel_Stop( g_Channel[1] );  // running ���� ����

			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4]); // �̼� ���� ����
		}
		else {
			g_sStageInfo->g_GameState = FAILED;
			//FMOD_Channel_Stop( g_Channel[1] );  // running ���� ����
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // �̼� ���� ����
		}
		break;
	case SUCCESS:
		if (CurTime - g_Opt.g_UpdateOldTime > 3000)
		{
			g_Opt.g_UpdateOldTime = CurTime;
			++g_Opt.g_nStage;
			Init();
			g_sStageInfo->g_GameState = READY;
			//FMOD_Channel_Stop( g_Channel[4] );  // �̼� ���� ���� ��� ����					
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]); //READY ���� 
		}
		break;
	}
}

#pragma endregion

#pragma region �����Լ�

//int main(void)
//{
//	Football_Game Game1;
//	Game1.play();
//
//	return 0;
//}


#pragma endregion

#pragma endregion