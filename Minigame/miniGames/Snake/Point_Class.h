#pragma once

class SH_POINT
{
public:
	SH_POINT(int _x = 0 ,int _y = 0) : x(_x) , y (_y)
	{
	}
	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}
	void set_x(int ix)
	{
		x = ix;
	}
	void set_y(int iy)
	{
		y = iy;
	}
	void set_point(int ix, int iy)
	{
		x = ix;
		y = iy;
	}
	void plus_x(int px)
	{
		x += px;
	}
	void plus_y(int py)
	{
		y += py;
	}
	void plus_point(int px, int py)
	{
		x += px;
		y += py;
	}

private:
	int x, y;
};