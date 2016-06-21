#include"FOOD_CLASS.h"
#include"SNAKE_DATA_CLASS.h"

FOOD::FOOD()
{
}

FOOD::~FOOD()
{
}
int FOOD::make_food(BODY * head,SH_POINT* abs, SCREEN_CLASS* Scr)
{
	this->set_y(rand() % 20);
	this->set_x(rand() % 35);

	while (head->strike_check(this->get_x(), this->get_y(), this) == 1)
	{
		this->set_y(rand() % 20);
		this->set_x(rand() % 35);
	}

	Scr->gotoxy(77, 23);		//È­¸é ±úÁüÀ» ¸·±âÀ§ÇÔ
	fflush(stdout);

	Scr->SetColor(RED);
	Scr->gotoxy(this->get_x() * 2 + abs->get_x(), this->get_y() + abs->get_y());
	printf("¡ß");
	Scr->SetColor(BLACK);
	return 0;
}

#pragma endregion