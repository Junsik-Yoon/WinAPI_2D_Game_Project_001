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

	float Length()//빗변길이
	{
		return sqrt(x * x + y * y);
	}
	fPoint& Normalize()
	{//1보다 작았으면 1이되고 1보다 컸어도 1이되게
		float fLen = Length();
		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}

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

