#pragma once
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

class GameEngine
{
private:
	string screen;
	int w, h;
	int total_pixels;
public:
	GameEngine() {};
	GameEngine(int w,int h);

	void Init(int w, int h);

	void Draw();
	void Render(int x, int y, char shape);
	void Render(Vector vec, char shape);
	void Render(VectorObject vec, char shape);
	void Clear();
	int GetWidth()
	{
		return this->w;
	}

	int GetHeight()
	{
		return this->h;
	}
};

