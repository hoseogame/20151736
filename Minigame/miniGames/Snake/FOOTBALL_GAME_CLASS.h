#pragma once

#include"HEADER_GROUP.h"
#include "CGAME_SYSTEM.h"

class FOOTBALL_GAME_CLASS : public CGAME_SYSTEM
{
public:
	FOOTBALL_GAME_CLASS();
	~FOOTBALL_GAME_CLASS();

	virtual void Init();
	virtual void Update();
	virtual void Render();

private:

};

FOOTBALL_GAME_CLASS::FOOTBALL_GAME_CLASS()
{
}

FOOTBALL_GAME_CLASS::~FOOTBALL_GAME_CLASS()
{
}

inline void FOOTBALL_GAME_CLASS::Init()
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

