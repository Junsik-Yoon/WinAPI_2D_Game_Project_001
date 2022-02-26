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

	float Length()//��������
	{
		return sqrt(x * x + y * y);
	}
	fPoint& Normalize()
	{//1���� �۾����� 1�̵ǰ� 1���� �Ǿ 1�̵ǰ�
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

struct Vec2
{
	float x;
	float y;

	float Length()//��������
	{
		return sqrt(x * x + y * y);
	}
	Vec2& Normalize()
	{//1���� �۾����� 1�̵ǰ� 1���� �Ǿ 1�̵ǰ�
		float fLen = Length();
		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}

	Vec2& operator= (POINT _fPoint)
	{
		x = (float)_fPoint.x;
		y = (float)_fPoint.y;
	}

	Vec2()
	{
		x = 0;
		y = 0;
	}

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2(const POINT& _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};

