#pragma once
#include"HEADER_GROUP.h"

#include"Screen_CLASS.h"
class BODY;

#pragma region SNAKE_DATA_CLASS

class SNAKE_DATA_CLASS
{
public:
	SNAKE_DATA_CLASS();
	~SNAKE_DATA_CLASS();
	void Init();
	int * get_length() { return &length; }
	int * get_speed() { return &speed; }
	int * get_score() { return &score; }
	int * get_direction() { return &direction; }
	int * get_last_direction() { return &last_direction; }
	void SAVE_OTB(BODY * _BODY) { OTB = _BODY; }
	friend class BODY;
	friend class SNAKE_GAME_CLASS;

protected:
	BODY* OTB;
	int length;
	int speed;
	int score;
	int direction;		//현재 뱀의 머리가 향하는 방향. (멈춤:0, 위:1,왼쪽:2,오른쪽:3,아래:4)
	int last_direction;	//이전 스템에서 움직인 방향	//한스템에서 방향을 두번바꿀시 충돌 디버깅을 위함
	POINT tmp;
	BODY *p_tail = NULL;
	//int abs_x, abs_y;

private:

};

#pragma endregion