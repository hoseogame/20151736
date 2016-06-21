#pragma once

#include"HEADER_GROUP.h"

class CGAME_SYSTEM
{
public:

	virtual void Init() = 0;
	virtual void Run();
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Set_State(state State);

protected:

	state m_state = STATE_DEFAULT;

};
