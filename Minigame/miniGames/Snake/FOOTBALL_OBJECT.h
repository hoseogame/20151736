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
	int nIsReady;        // �غ� ����(1), ������(0)
						 //int nMoveX, nMoveY;  // �̵� ��ǥ
	clock_t MoveTime;    // �̵� �ð� ����
	clock_t OldTime;     // ���� �̵� �ð�
	friend class FOOTBALL_GAME_CLASS;
};

class GOAL_DAE : public POINT
{
public:
	//int nMoveX, nMoveY;     // �̵� ��ǥ 
	int nLength;			// ��� ����	
	int nLineX[7];			// ���� ���� x ��ǥ (7��)
	clock_t	MoveTime;		// �̵� �ð� ����
	clock_t	OldTime;	    // ���� �̵� �ð�
	int	nDist;				// �̵� �Ÿ�
	friend class FOOTBALL_GAME_CLASS;
};
