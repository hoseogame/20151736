#include"SNAKE_GAME_CLASS.h"
SNAKE_GAME_CLASS::SNAKE_GAME_CLASS()
{

}

SNAKE_GAME_CLASS::~SNAKE_GAME_CLASS()
{
	free_all();
}

void SNAKE_GAME_CLASS::Init()
{
	srand(time(NULL));

	m_data.Init();

	abs.set_x(2);
	abs.set_y(2);



	snake_tail = (BODY *)malloc(sizeof(BODY));
	snake_tail->set_x(5);
	snake_tail->set_y(3);
	snake_head = snake_tail;
	snake_tail = (BODY *)malloc(sizeof(BODY));
	snake_tail->set_x(4);
	snake_tail->set_y(3);
	snake_tail->set_next(NULL);
	snake_head->set_next(snake_tail);


}


int SNAKE_GAME_CLASS::free_all()
{
	BODY *tmp1, *tmp2;

	tmp1 = snake_head;
	tmp2 = snake_head->get_next();
	while (tmp2 != NULL)
	{
		free(tmp1);
		tmp1 = tmp2;
		tmp2 = tmp2->get_next();
	}
	return 0;
}

void SNAKE_GAME_CLASS::Update()
{
	switch (m_state)
	{
	case STATE_DEFAULT://기본상태
		getche();

		this->Set_State(STATE_INIT);
		break;
	case STATE_INIT://초기화상태
		this->Init();

		this->Food.make_food(this->snake_head, this->get_abs(), &Scr);
		m_speedi = 1;

		this->Set_State(STATE_PLAY);
		break;
	case STATE_PLAY://게임 플레이 부분
		// 키입력
		if (kbhit())
		{
			keytemp = getche();

			if (keytemp == EXT_KEY)
			{
				printf("\b");
				keytemp = getche();
				switch (keytemp)
				{
				case KEY_UP:
					if (m_data.last_direction != 4)
						m_data.direction = 1;

					break;
				case KEY_LEFT:
					if (m_data.last_direction != 3)
						m_data.direction = 2;
					break;
				case KEY_RIGHT:
					if (m_data.last_direction != 2)
						m_data.direction = 3;

					break;
				case KEY_DOWN:
					if (m_data.last_direction != 1)
						m_data.direction = 4;
					break;
				}
			}
		}
		if (m_speedi%m_data.speed == 0)	//게임 계산
		{
			if (return_tmp == 2)	//꼬리가 늘어남
			{
				return_tmp = snake_head->make_tail(m_data.direction, this->get_abs(), &m_data, &Scr, &Food);
				snake_head = m_data.OTB;
			}
			else {
				fflush(stdin);

				return_tmp = snake_head->move_snake(m_data.direction, this->get_abs(), &m_data, &Scr, &Food);	//단순히 이동
				snake_head = m_data.OTB;
			}
			m_data.last_direction = m_data.direction;
			if (return_tmp == 1)		//충돌할때
			{
				this->Set_State(STATE_GAMEOVER);

			}
			if (return_tmp == 2)		//먹이를 먹었을때
			{
				if (m_data.length % 5 == 0)
					m_data.speed--;

				if (m_data.speed < 1)
					m_data.speed = 1;

				m_data.length++;
				this->Food.make_food(this->snake_head, this->get_abs(), &Scr);
				m_speedi = 1;	//스피드관련 변수 초기화
			}
		}
		m_speedi++;


		break;
	case STATE_GAMEOVER:
		free_all();
		this->Set_State(STATE_DEFAULT);
		break;
	default:
		break;
	}

		

			



}

void SNAKE_GAME_CLASS::Render()
{
	switch (m_state)
	{
	case STATE_DEFAULT:

		break;
	case STATE_INIT:
		Scr.gotoxy(77, 23);
		printf(" \b");
		Scr.show_game_frame(abs.get_y());

		break;
	case STATE_PLAY:
		

		//if (return_tmp == 2)
		//{
		//	Scr.gotoxy(77, 23);		//화면 깨짐을 막기위함
		//	fflush(stdout);

		//	Scr.SetColor(GRAY);
		//	Scr.gotoxy((snake_head->get_x() * 2) + abs.get_x(), snake_head->get_y() + abs.get_y());	//이동후의 머리모양 잔상지우기
		//	printf("○");
		//	Scr.gotoxy(m_data.tmp.x * 2 + abs.get_x(), m_data.tmp.y + abs.get_y());	//머리모양 프린트하기
		//	printf("●");
		//	Scr.gotoxy(77, 23);		//화면 깨짐을 막기위함
		//	Scr.SetColor(BLACK);
		//}
		//else
		//{
		//	if (m_data.p_tail != NULL)
		//	{
		//		Scr.gotoxy((m_data.p_tail->get_x() * 2) + abs.get_x(), m_data.p_tail->get_y() + abs.get_y());	//이동후의 잔상지우기
		//		printf("  ");
		//	}
		//	Scr.gotoxy(77, 23);		//화면 깨짐을 막기위함
		//	fflush(stdout);

		//	Scr.SetColor(GRAY);
		//	Scr.gotoxy((snake_head->get_x() * 2) + abs.get_x(), snake_head->get_y() + abs.get_y());	//이동후의 머리모양 잔상지우기
		//	printf("○");
		//	Scr.gotoxy(m_data.tmp.x * 2 + abs.get_x(), m_data.tmp.y + abs.get_y());	//머리모양 프린트하기
		//	printf("●");
		//	Scr.gotoxy(77, 23);		//화면 깨짐을 막기위함
		//	Scr.SetColor(BLACK);
		//}


		Scr.SetColor(BLACK);
		Scr.gotoxy(77, 23);
		Sleep(10);
		Scr.SetColor(BLACK);
		Scr.gotoxy(77, 23);

		break;

	case STATE_GAMEOVER:
		Scr.show_gameover();
		
		break;
	default:
		break;
	}
}
