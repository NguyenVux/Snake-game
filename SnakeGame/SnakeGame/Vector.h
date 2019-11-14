#pragma once
#include <math.h>

struct Vector
{
	int x = 0;
	int y = 0;
};

class VectorObject
{
private:
	Vector vector;
public:
	void Set(int x, int y)
	{
		this->vector.x = x;
		this->vector.y = y;
	}
	void Set(Vector vec)
	{
		this->vector.x = vec.x;
		this->vector.y = vec.y;
	}
	void Set(VectorObject vec)
	{
		this->vector.x = vec.Get().x;
		this->vector.y = vec.Get().y;
	}

	Vector Get()
	{
		return this->vector;
	}

	void Add(VectorObject input)
	{
		this->vector.x += input.Get().x;
		this->vector.y += input.Get().y;
	}
	void Add(Vector input)
	{
		this->vector.x += input.x;
		this->vector.y += input.y;
	}

	void Add(int x, int y)
	{
		this->vector.x +=x;
		this->vector.y +=y;
	}



	void Subtract(VectorObject input)
	{
		this->vector.x -= input.Get().x;
		this->vector.y -= input.Get().y;
	}

	void Subtract(Vector input)
	{
		this->vector.x -= input.x;
		this->vector.y -= input.y;
	}

	void Subtract(int x, int y)
	{
		this->vector.x -= x;
		this->vector.y -= y;
	}

	void Multiply(int k)
	{
		this->vector.x *= k;
		this->vector.y *= k;
	}

	bool Divide(int k)
	{
		if (k != 0)
		{
			this->vector.x /= k;
			this->vector.y /= k;
			return true;
		}
		return false;
	}

	double length()
	{
		int length = pow(this->vector.x, 2) * pow(this->vector.y, 2);
		length = sqrt(length);
		return length;
	}
	
};

