#pragma once
#include"HEADER_GROUP.h"
#include"SNAKE_DATA_CLASS.h"
#include"Screen_CLASS.h"

#pragma region BODY_CLASS

class BODY : public SH_POINT
{
public:
	BODY();
	~BODY();
	void Init();

	int strike_check(int x, int y, SH_POINT* food);
	int strike_check(int x, int y);
	int move_snake(int dir, SH_POINT *abs, SNAKE_DATA_CLASS * _DATA, SCREEN_CLASS *scr, SH_POINT *food);
	int make_tail(int dir, SH_POINT *abs, SNAKE_DATA_CLASS * _DATA, SCREEN_CLASS *scr, SH_POINT *food);

	void set_next(BODY * _pBODY)
	{
		this->next = _pBODY;
	}
	BODY * get_next()
	{
		return this->next;
	}
	BODY * get_tail()
	{
		BODY * now = this;
		while (!now->next == NULL)
		{
			now = now->next;
		}
		return now;
	}
private:
	BODY * next;
};


#pragma endregion