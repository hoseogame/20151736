#include "CGAME_SYSTEM.h"

void CGAME_SYSTEM::Run()
{
	this->Init();
	while (m_state != STATE_GAME_OFF)
	{
		this->Render();
		this->Update();
	}
}

void CGAME_SYSTEM::Set_State(state State)
{
	this->m_state = State;
}
