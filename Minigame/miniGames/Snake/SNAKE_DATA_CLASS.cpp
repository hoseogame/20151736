#include"SNAKE_DATA_CLASS.h"
SNAKE_DATA_CLASS::SNAKE_DATA_CLASS()
{
	this->Init();
}

SNAKE_DATA_CLASS::~SNAKE_DATA_CLASS()
{

}

void SNAKE_DATA_CLASS::Init()
{
	length = 1;
	speed = 25;
	direction = 3;
	last_direction = direction;

}

