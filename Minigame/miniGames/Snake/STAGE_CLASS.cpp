#include "STAGE_CLASS.h"

void STAGE_INFO_CLASS::Set_Info(int GoalBall, clock_t LT, int GoalDaeLength, int GoalDaeX, int GoalDaeY, clock_t MT, int Dist)
{
	nGoalBall = GoalBall;
	LimitTime = LT;
	nGoalDaeLength = GoalDaeLength;
	nGoalDaeX = GoalDaeX;
	nGoalDaeY = GoalDaeY;
	MoveTime = MT;
	nDist = Dist;
}