#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "GameEngine.h"
#include "Vector.h"

using namespace std;

int mod(int a, int b)
{
	a = a % b;
	if (a < 0)
	{
		return a += b;
	}
	else
	{
		return a;
	}
	
}
int main()
{
	srand(time(NULL));
	GameEngine screen(60,20 );
	vector<VectorObject> Snake;
	VectorObject* tmp = new VectorObject;
	tmp->Set(rand()%screen.GetWidth(),rand()%screen.GetHeight());
	Snake.push_back(*tmp);
	delete tmp;
	VectorObject Food;
	Food.Set(rand() % screen.GetWidth(), rand() % screen.GetHeight());
	VectorObject moving_Vector;
	moving_Vector.Set(0, 0);
	bool Lose_Flag = false;
	while (true) //Game Loop
	{
		system("CLS");
		if (Lose_Flag)
		{
			cout << "You Are Lose" << endl <<"Press R to Retry and any others Key to Exit";
			fflush(stdin);
			int a = _getch();
			if (a != 'r')
			{
				return 0;
			}
			else
			{
				Snake.clear();
				tmp = new VectorObject;
				tmp->Set(rand() % screen.GetWidth(), rand() % screen.GetHeight());
				Snake.push_back(*tmp);
				delete tmp;
				Food.Set(rand() % screen.GetWidth(), rand() % screen.GetHeight());
				Lose_Flag = false;
			}
		}
		else
		{
			//================Update============
			if (_kbhit())
			{
				int a = _getch();
				switch (a)
				{
				case'w':
					if (moving_Vector.Get().y != 1)
					{
						moving_Vector.Set(0, -1);
					}
					break;
				case'a':
					if (moving_Vector.Get().x != 1)
					{
						moving_Vector.Set(-1, 0);
					}
					break;
				case's':
					if (moving_Vector.Get().y != -1)
					{
						moving_Vector.Set(0, 1);
					}
					break;
				case'd':
					if (moving_Vector.Get().x != -1)
					{
						moving_Vector.Set(1, 0);
					}
					break;
				case ']':
					cout << "Game Ended";
					return 0;
					break;
				default:
					break;
				}
			}

			for (int i = Snake.size() - 1; i > 0; i--)
			{
				Snake[i].Set(Snake[i - 1]);

			}
			Snake[0].Add(moving_Vector);
			if (Snake[0].Get().x == Food.Get().x && Snake[0].Get().y == Food.Get().y)
			{
				Food.Set(rand() % screen.GetWidth(), rand() % screen.GetHeight());
				tmp = new VectorObject;
				tmp->Set(Snake[0]);
				tmp->Subtract(moving_Vector);
				Snake.push_back(*tmp);
				delete tmp;
			}

			for (int i = 1; i < Snake.size(); i++)
			{
				if (Snake[0].Get().x == Snake[i].Get().x && Snake[0].Get().y == Snake[i].Get().y)
				{
					Lose_Flag = true;
					break;
				}
			}
			Snake[0].Set(mod(Snake[0].Get().x, screen.GetWidth()), mod(Snake[0].Get().y, screen.GetHeight()));
			//===============Render=============
			screen.Clear();
			for (int i = 0; i < Snake.size(); i++)
			{
				screen.Render(Snake[i], 'o');
			}
			screen.Render(Food, 'A');


			//===============Display============
			screen.Draw();
			cout << "Scores: " << Snake.size();
			Sleep(500);
		}
		
	}
	//delete tmp;
	return 0;
}
