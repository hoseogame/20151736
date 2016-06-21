#pragma once
#include"HEADER_GROUP.h"

class PLAYER : public POINT
{
public:
	int nCenterX, nCenterY;
	//int nMoveX, nMoveY;
	int nX, nY;
	friend class FOOTBALL_GAME_CLASS;
};

class BALL : public POINT
{
public:
	int nIsReady;        // 준비 상태(1), 슛상태(0)
						 //int nMoveX, nMoveY;  // 이동 좌표
	clock_t MoveTime;    // 이동 시간 간격
	clock_t OldTime;     // 이전 이동 시각
	friend class FOOTBALL_GAME_CLASS;
};

class GOAL_DAE : public POINT
{
public:
	//int nMoveX, nMoveY;     // 이동 좌표 
	int nLength;			// 골대 길이	
	int nLineX[7];			// 골인 라인 x 좌표 (7개)
	clock_t	MoveTime;		// 이동 시간 간격
	clock_t	OldTime;	    // 이전 이동 시간
	int	nDist;				// 이동 거리
	friend class FOOTBALL_GAME_CLASS;
};
