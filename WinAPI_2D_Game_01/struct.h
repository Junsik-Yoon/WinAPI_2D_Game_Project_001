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
};

struct fVec2
{
	float x;
	float y;

	float Length()//빗변길이
	{
		return sqrt(x * x + y * y);
	}
	fVec2& Normalize()
	{//1보다 작았으면 1이되고 1보다 컸어도 1이되게
		float fLen = Length();
		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}

	fVec2& operator= (POINT _other)
	{
		x = (float)_other.x;
		y = (float)_other.y;
	}

	fVec2 operator+ (fVec2 _vOther)
	{
		return fVec2(x + _vOther.x, y + _vOther.y);
	}
	fVec2 operator- (fVec2 _vOther)
	{
		return fVec2(x - _vOther.x, y - _vOther.y);
	}
	fVec2 operator* (fVec2 _vOther)
	{
		return fVec2(x * _vOther.x, y * _vOther.y);
	}
	fVec2 operator/ (fVec2 _vOther)
	{
		if (0.f == _vOther.x || 0.f == _vOther.y)
			assert(nullptr);
		return fVec2(x + _vOther.x, y + _vOther.y);
	}

	fVec2()
	{
		x = 0;
		y = 0;
	}

	fVec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	fVec2(const POINT& _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};
