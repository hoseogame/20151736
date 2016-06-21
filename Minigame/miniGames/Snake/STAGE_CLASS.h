#pragma once
#include"HEADER_GROUP.h"

class EFFECT
{
public:
	clock_t StratTime; // 효과 발생 시각
	clock_t StayTime;  // 효과 지속 시간	
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
		strcpy(g_strPlayer, "┗━●━┛");
	}
};

class STAGE_INFO_CLASS
{
public:
	int nGoalBall;			// 골인해야 할 볼의 개수 
	clock_t LimitTime;      // 제한 시간 
	int nGoalDaeLength;		// 골대 길이 
	int nGoalDaeX;			// 골대 이동 X 좌표
	int nGoalDaeY;			// 골대 이동 Y 좌표 
	clock_t MoveTime;		// 골대 이동 시간 간격
	int nDist;				// 골대 이동 거리

	void Set_Info(int GoalBall, clock_t LT, int GoalDaeLength, int GoalDaeX, int GoalDaeY, clock_t MT, int Dist);
};