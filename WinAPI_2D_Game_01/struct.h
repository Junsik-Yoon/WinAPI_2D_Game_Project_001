#pragma once

struct iPoint
{
	int x;
	int y;
};


struct fVec2
{
	float x;
	float y;

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

	fVec2 Normalize()
	{
		float z = sqrt(x * x + y * y);
		assert(z != 0.f);
		x = x / z;
		y = y / z;
		return fVec2(x / z, y / z);
	}
};
