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
	int direction;		//���� ���� �Ӹ��� ���ϴ� ����. (����:0, ��:1,����:2,������:3,�Ʒ�:4)
	int last_direction;	//���� ���ۿ��� ������ ����	//�ѽ��ۿ��� ������ �ι��ٲܽ� �浹 ������� ����
	POINT tmp;
	BODY *p_tail = NULL;
	//int abs_x, abs_y;

private:

};

#pragma endregion