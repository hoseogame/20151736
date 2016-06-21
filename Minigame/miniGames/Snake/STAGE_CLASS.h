#pragma once
#include"HEADER_GROUP.h"

class EFFECT
{
public:
	clock_t StratTime; // ȿ�� �߻� �ð�
	clock_t StayTime;  // ȿ�� ���� �ð�	
};


class STAGE_OPTION
{
public:
	char g_strPlayer[11];
	int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage, g_nIsGoal;
	clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;


	STAGE_OPTION::STAGE_OPTION()
	{
		g_nStage = -1;
		strcpy(g_strPlayer, "�����ܦ���");
	}
};

class STAGE_INFO_CLASS
{
public:
	int nGoalBall;			// �����ؾ� �� ���� ���� 
	clock_t LimitTime;      // ���� �ð� 
	int nGoalDaeLength;		// ��� ���� 
	int nGoalDaeX;			// ��� �̵� X ��ǥ
	int nGoalDaeY;			// ��� �̵� Y ��ǥ 
	clock_t MoveTime;		// ��� �̵� �ð� ����
	int nDist;				// ��� �̵� �Ÿ�

	void Set_Info(int GoalBall, clock_t LT, int GoalDaeLength, int GoalDaeX, int GoalDaeY, clock_t MT, int Dist);
};