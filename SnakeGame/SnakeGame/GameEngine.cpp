#include "GameEngine.h"

GameEngine::GameEngine(int w, int h)
{
	this->w = w;
	this->h = h;
	this->total_pixels = (w + 3) * (h + 2);
	this->screen.resize(total_pixels, '*');
	for (int pixel = 0; pixel < this->total_pixels;pixel++)
	{
		int pX = pixel%(w+3);
		int pY = pixel / (w + 3);
		
		if (pX > 0 && pX < this->w + 1 && pY != 0 && pY != this->h + 1)
		{
			this->screen[pixel] = ' ';
		}
		else
		{
			this->screen[pixel] = '*';
		}
		if (pX == (this->w + 2))
		{
			this->screen[pixel] = '\n';
		}
	}
}

void GameEngine::Init(int w, int h)
{
	this->w = w;
	this->h = h;
	this->total_pixels = (w + 3) * (h + 2);
	this->screen.resize(total_pixels, '*');
	for (int pixel = 0; pixel < this->total_pixels; pixel++)
	{
		int pX = pixel % (w + 3);
		int pY = pixel / (w + 3);

		if (pX > 0 && pX < this->w + 1 && pY != 0 && pY != this->h + 1)
		{
			this->screen[pixel] = ' ';
		}
		else
		{
			this->screen[pixel] = '*';
		}
		if (pX == (this->w + 2))
		{
			this->screen[pixel] = '\n';
		}
	}
}

void GameEngine::Draw()
{
	cout << this->screen;
}

void GameEngine::Render(int x,int y, char shape)
{
	int pos = (y + 1) * (this->w + 3) + (x + 1);
	this->screen[pos] = shape;
}

void GameEngine::Render(Vector vec, char shape)
{
	int x = vec.x;
	int y = vec.y;
	int pos = (y + 1) * (this->w + 3) + (x + 1);
	this->screen[pos] = shape;

}

void GameEngine::Render(VectorObject vec, char shape)
{
	int x = vec.Get().x;
	int y = vec.Get().y;
	int pos = (y + 1) * (this->w + 3) + (x + 1);
	this->screen[pos] = shape;

}


void GameEngine::Clear()
{
	for (int pixel = 0; pixel < this->total_pixels; pixel++)
	{
		int pX = pixel % (w + 3);
		int pY = pixel / (w + 3);
		if (pX > 0 && pX < this->w + 1 && pY !=0 && pY != this->h+1)
		{
			this->screen[pixel] = ' ';
		}

	}
}
