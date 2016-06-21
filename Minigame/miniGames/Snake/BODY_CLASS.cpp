#include"BODY_CLASS.h"
#include"SNAKE_DATA_CLASS.h"
#
BODY::BODY()
{
	this->next = NULL;
}

BODY::~BODY()
{
}

void BODY::Init()
{

}

int BODY::strike_check(int x, int y, SH_POINT* food)
{
	BODY *tmp_body;
	if (x<0 || x>34 || y<0 || y>19)		//머리가 벽에 부닥침
		return 1;
	tmp_body = this;
	while (tmp_body != NULL)
	{
		if ((tmp_body->get_x() == x) && (tmp_body->get_y() == y))
			return 1;
		tmp_body = tmp_body->next;
	}
	if (food->get_x() == x && food->get_y() == y)	//먹이를 물었음
		return 2;
	return 0;
}

int BODY::strike_check(int x, int y)
{
	BODY *tmp_body;
	if (x<0 || x>34 || y<0 || y>19)		//머리가 벽에 부닥침
		return 1;
	tmp_body = this;
	while (tmp_body != NULL)
	{
		if ((tmp_body->get_x() == x) && (tmp_body->get_y() == y))
			return 1;
		tmp_body = tmp_body->next;
	}
	return 0;
}

int BODY::move_snake(int dir, SH_POINT *abs, SNAKE_DATA_CLASS* _DATA, SCREEN_CLASS* scr, SH_POINT *food)
{
	
	int i;
	BODY *tmp_body;
	_DATA->p_tail = this->get_tail();

	_DATA->tmp.x = this->get_x();
	_DATA->tmp.y = this->get_y();
	switch (*(_DATA->get_direction()))
	{
	case 1:
		_DATA->tmp.y--;
		break;
	case 2:
		_DATA->tmp.x--;
		break;
	case 3:
		_DATA->tmp.x++;
		break;
	case 4:
		_DATA->tmp.y++;
		break;
	}
	i = strike_check(_DATA->tmp.x, _DATA->tmp.y,food);
	if (i == 1)	//충돌할때
	{
		return 1;
	}

	
	scr->gotoxy((_DATA->p_tail->get_x() * 2) + abs->get_x(), _DATA->p_tail->get_y() + abs->get_y());	//이동후의 잔상지우기
	printf("  ");

	scr->gotoxy(77, 23);		//화면 깨짐을 막기위함
	fflush(stdout);

	scr->SetColor(GRAY);
	scr->gotoxy((this->get_x() * 2) + abs->get_x(), this->get_y() + abs->get_y());	//이동후의 머리모양 잔상지우기
	printf("○");
	scr->gotoxy(_DATA->tmp.x * 2 + abs->get_x(), _DATA->tmp.y + abs->get_y());	//머리모양 프린트하기
	printf("●");
	scr->gotoxy(77, 23);		//화면 깨짐을 막기위함
	scr->SetColor(BLACK);


	tmp_body = (BODY *)malloc(sizeof(BODY));	//머리부분의 새로운 노드만들기
	tmp_body->set_x(_DATA->tmp.x);
	tmp_body->set_y(_DATA->tmp.y);
	tmp_body->next = this;
	_DATA->SAVE_OTB(tmp_body);
	//snake_head = tmp_body;


	while (tmp_body->next != _DATA->p_tail)		//꼬리노드 지우기
		tmp_body = tmp_body->next;

	tmp_body->next = NULL;
	free(_DATA->p_tail);
	_DATA->p_tail = this->get_tail();
	_DATA->p_tail = tmp_body;
	return i;
}

int BODY::make_tail(int dir, SH_POINT *abs, SNAKE_DATA_CLASS *_DATA, SCREEN_CLASS *scr, SH_POINT *food)
{
	int tmp_x, tmp_y;
	int i;
	BODY *tmp_body;


	tmp_x = this->get_x();
	tmp_y = this->get_y();
	switch (*(_DATA->get_direction()))
	{
	case 1:
		tmp_y--;
		break;
	case 2:
		tmp_x--;
		break;
	case 3:
		tmp_x++;
		break;
	case 4:
		tmp_y++;
		break;
	}
	i = strike_check(tmp_x, tmp_y,food);
	if (i == 1)	//충돌할때
	{
		return 1;
	}





	scr->gotoxy(77, 23);		//화면 깨짐을 막기위함
	fflush(stdout);

	scr->SetColor(GRAY);
	scr->gotoxy((this->get_x() * 2) + abs->get_x(), this->get_y() + abs->get_y());	//이동후의 머리모양 잔상지우기
	printf("○");
	scr->gotoxy(tmp_x * 2 + abs->get_x(), tmp_y + abs->get_y());	//머리모양 프린트하기
	printf("●");
	scr->gotoxy(77, 23);		//화면 깨짐을 막기위함
	scr->SetColor(BLACK);


	tmp_body = (BODY *)malloc(sizeof(BODY));	//머리부분의 새로운 노드만들기
	tmp_body->set_x(tmp_x);
	tmp_body->set_y(tmp_y);
	tmp_body->next = this;
	_DATA->SAVE_OTB(tmp_body);



	return i;
}