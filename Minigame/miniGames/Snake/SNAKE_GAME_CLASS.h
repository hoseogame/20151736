#pragma once
#include"HEADER_GROUP.h"
#include"SNAKE_DATA_CLASS.h"
#include"BODY_CLASS.h"
#include"FOOD_CLASS.h"
#include "CGAME_SYSTEM.h"

#pragma region SNAKE_GAME_CLASS

class SNAKE_GAME_CLASS : public CGAME_SYSTEM
{
public:
	SNAKE_GAME_CLASS();
	~SNAKE_GAME_CLASS();
	int free_all();
	virtual void Init();
	virtual void Update();
	virtual void Render();

	SH_POINT *get_abs() { return &abs; }
	SCREEN_CLASS * use_SCREEN() { return &Scr; }
	BODY * set_snake_head(BODY *_head) { snake_head = _head; }
	//friend FOOD;

private:
	SCREEN_CLASS Scr;
	SNAKE_DATA_CLASS m_data;

	BODY *snake_head;
	BODY *snake_tail;
	FOOD Food;
	SH_POINT abs;

	int return_tmp = 0;
	char keytemp;
	int m_speedi;
};


#pragma endregion