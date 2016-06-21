#pragma once
#include"HEADER_GROUP.h"
#include"BODY_CLASS.h"
#include"SNAKE_DATA_CLASS.h"
#include"Screen_CLASS.h"

#pragma region FOOD_CLASS

class FOOD : public SH_POINT
{
public:
	FOOD();
	~FOOD();
	//friend SNAKE_GAME_CLASS;
	int make_food(BODY* head, SH_POINT* abs, SCREEN_CLASS* Scr);

private:

};

