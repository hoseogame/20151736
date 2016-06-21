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

//스태틱 변수 초기화
int FootBall_Screen::g_nScreenIndex = 0;
HANDLE FootBall_Screen::g_hScreen[2] = { NULL,NULL };

#pragma region Screen.c 복붙-> Screen class 정의

void FootBall_Screen::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개룰 만든다.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 숨기기
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

// 1 ~ 15 까지 색상 설정 가능
void FootBall_Screen::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

#pragma endregion


void FootBall_Screen::InitScreen()
{
	FootBall_Screen::ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	FootBall_Screen::ScreenPrint(0, 1, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 2, "┃             □━━━□                   ┃");
	FootBall_Screen::ScreenPrint(0, 3, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 4, "┃                        ///.   슛~~~      ┃");
	FootBall_Screen::ScreenPrint(0, 5, "┃                       (^.^)              ┃");
	FootBall_Screen::ScreenPrint(0, 6, "┃                      ┗┫ ┣┓           ┃");
	FootBall_Screen::ScreenPrint(0, 7, "┃                         ┏┛             ┃");
	FootBall_Screen::ScreenPrint(0, 8, "┃                     ⊙  ┛＼             ┃");
	FootBall_Screen::ScreenPrint(0, 9, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 10, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 11, "┃       슛 골인 게임  Go! Go!              ┃");
	FootBall_Screen::ScreenPrint(0, 12, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 13, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 14, "┃       j :왼쪽 l : 오른쪽 k :슛           ┃");
	FootBall_Screen::ScreenPrint(0, 15, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 16, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 17, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 18, "┃        ┗●┛  space 키를 눌러주세요     ┃");
	FootBall_Screen::ScreenPrint(0, 19, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 20, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 21, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void FootBall_Screen::ReadyScreen()
{
	char string[100];

	FootBall_Screen::ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	FootBall_Screen::ScreenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 2, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 3, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 4, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 5, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 6, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 7, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 8, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 9, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 10, "┃■■■■■                    ■■■■■■┃");
	sprintf(string, "┃■■■■■     %d   스테이지   ■■■■■■┃", g_Opt.g_nStage + 1);
	FootBall_Screen::ScreenPrint(0, 11, string);
	FootBall_Screen::ScreenPrint(0, 12, "┃■■■■■                    ■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 13, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 14, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 15, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 16, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 17, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 18, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 19, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 20, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 21, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	FootBall_Screen::ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void FootBall_Screen::BackScreen()
{
	char string[100];

	FootBall_Screen::ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	FootBall_Screen::ScreenPrint(0, 1, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 2, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 3, "┃                                          ┃");
	sprintf(string, "┃                                          ┃스테이지: %d", g_Opt.g_nStage + 1);
	FootBall_Screen::ScreenPrint(0, 4, string);
	FootBall_Screen::ScreenPrint(0, 5, "┃                                          ┃");
	sprintf(string, "┣━━━━━━━━━━━━━━━━━━━━━┫제한 시간: %d", g_sStageInfo[g_Opt.g_nStage].LimitTime / 1000);
	FootBall_Screen::ScreenPrint(0, 6, string);
	FootBall_Screen::ScreenPrint(0, 7, "┃                                          ┃");
	sprintf(string, "┃                                          ┃현재 시간: %d", (clock() - g_Opt.g_GameStartTime) / 1000);
	FootBall_Screen::ScreenPrint(0, 8, string);
	FootBall_Screen::ScreenPrint(0, 9, "┃                                          ┃");
	sprintf(string, "┃                                          ┃목표 골인: %d ", g_sStageInfo[g_Opt.g_nStage].nGoalBall);
	FootBall_Screen::ScreenPrint(0, 10, string);
	FootBall_Screen::ScreenPrint(0, 11, "┃                                          ┃");
	sprintf(string, "┃                                          ┃골인 공 개수: %d ", g_Opt.g_nBallCount);
	FootBall_Screen::ScreenPrint(0, 12, string);

	FootBall_Screen::ScreenPrint(0, 13, "┃                                          ┃");
	sprintf(string, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 14, string);
	FootBall_Screen::ScreenPrint(0, 15, "┃                                          ┃");
	sprintf(string, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 16, string);
	FootBall_Screen::ScreenPrint(0, 17, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 18, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 19, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 20, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 21, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 22, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void FootBall_Screen::GoalMessage(int nX, int nY)
{
	FootBall_Screen::ScreenPrint(nX, nY, "☆ )) 골인 (( ★");
	FootBall_Screen::ScreenPrint(nX, nY + 1, "＼(^^')/ ＼(\"*')/");
	FootBall_Screen::ScreenPrint(nX, nY + 2, "   ■       ■");
	FootBall_Screen::ScreenPrint(nX, nY + 3, "  ┘┐    ┌└");
}

void FootBall_Screen::SuccessScreen()
{
	FootBall_Screen::ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	FootBall_Screen::ScreenPrint(0, 1, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 2, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 3, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 4, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 5, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 6, "┃                ////＼＼                  ┃");
	FootBall_Screen::ScreenPrint(0, 7, "┃               q ∧  ∧ p                 ┃");
	FootBall_Screen::ScreenPrint(0, 8, "┃               (└──┘)                 ┃");
	FootBall_Screen::ScreenPrint(0, 9, "┃             ♬ 미션 성공 ♪              ┃");
	FootBall_Screen::ScreenPrint(0, 10, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 11, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 12, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 13, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 14, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 15, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 16, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 17, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 18, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 19, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 20, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 21, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 22, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void FootBall_Screen::FailureScreen()
{
	FootBall_Screen::ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	FootBall_Screen::ScreenPrint(0, 1, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 2, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 3, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 4, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 5, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 6, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 7, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 8, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 9, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 10, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 11, "┃                    미션 실패 !!!!        ┃");
	FootBall_Screen::ScreenPrint(0, 12, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 13, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 14, "┃                 ●┳━┓                 ┃");
	FootBall_Screen::ScreenPrint(0, 15, "┃                   ┛  ┗                 ┃");
	FootBall_Screen::ScreenPrint(0, 16, "┃                  ■■■■                ┃");
	FootBall_Screen::ScreenPrint(0, 17, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 18, "┃        다시 하시겠습니까? (y/n)          ┃");
	FootBall_Screen::ScreenPrint(0, 19, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 20, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 21, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void FootBall_Screen::ResultScreen()
{
	char string[100];
	FootBall_Screen::ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	FootBall_Screen::ScreenPrint(0, 1, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 2, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 3, "┃             □━━━□                   ┃");
	FootBall_Screen::ScreenPrint(0, 4, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 5, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 6, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 7, "┃                                          ┃");
	sprintf(string, "┃      성공한 스테이지 :  %2d               ┃", g_Opt.g_nStage + 1);
	FootBall_Screen::ScreenPrint(0, 8, string);
	FootBall_Screen::ScreenPrint(0, 9, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 10, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 11, "┃   ___▒▒▒___                           ┃");
	FootBall_Screen::ScreenPrint(0, 12, "┃     (*^  ^*)                             ┃");
	FootBall_Screen::ScreenPrint(0, 13, "┃ =====○==○=====                         ┃");
	FootBall_Screen::ScreenPrint(0, 14, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 15, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 16, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 17, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 18, "┃                      ┗●┛              ┃");
	FootBall_Screen::ScreenPrint(0, 19, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 20, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 21, "┃                                          ┃");
	FootBall_Screen::ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
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
		FootBall_Screen::ScreenPrint(g_sGoalDae.get_x(), g_sGoalDae.get_y(), "□");
		nLength = g_sGoalDae.nLength * 2 + 1;

		for (i = 0; i < nLength; i++)
			FootBall_Screen::ScreenPrint(g_sGoalDae.nLineX[i], g_sGoalDae.get_y(), "━");

		FootBall_Screen::ScreenPrint(g_sGoalDae.nLineX[nLength - 1] + 2, g_sGoalDae.get_y(), "□");

		// Note: 효과 출력  	
		if (g_Opt.g_nIsGoal == 1)
		{
			GoalMessage(10, 10);
		}

		// Note: 2 컬럼씩 클리핑 
		if (g_sPlayer.nX < 2)  //  왼쪽 클리핑 처리
			FootBall_Screen::ScreenPrint(2, g_sPlayer.get_y(), &g_Opt.g_strPlayer[(g_sPlayer.nX - 2)*-1]);	 // 좌표를 배열 인덱스 
		else if (g_sPlayer.get_x() + (g_Opt.g_nLength - g_sPlayer.nCenterX + 1) > 43) // 오른쪽 클리핑 처리
		{
			strncat(string, g_Opt.g_strPlayer, g_Opt.g_nLength - ((g_sPlayer.get_x() + g_sPlayer.nCenterX + 1) - 43));
			FootBall_Screen::ScreenPrint(g_sPlayer.nX, g_sPlayer.get_y(), string);
		}
		else { // 1 컬럼씩 이동
			FootBall_Screen::ScreenPrint(g_sPlayer.nX, g_sPlayer.get_y(), g_Opt.g_strPlayer);
		}

		FootBall_Screen::ScreenPrint(g_sBall.get_x(), g_sBall.get_y(), "⊙");
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

	// Note: 렌더링 끝 
	FootBall_Screen::ScreenFlipping();
}