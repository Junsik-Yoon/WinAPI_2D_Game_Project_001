#pragma once

struct iPoint
{
	int x;
	int y;
};

struct fPoint
{
	float x;
	float y;

	fPoint& operator= (POINT _fPoint)
	{
		x = (float)_fPoint.x;
		y = (float)_fPoint.y;
	}

	fPoint()
	{
		x = 0;
		y = 0;
	}

	fPoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	fPoint(const POINT& _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};
