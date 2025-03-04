#include <iostream>
#include <conio.h>
#include <Windows.h>


using namespace std;
bool gameOver;
const int width = 20;
const int height = 20; //The size of the map
int x, y, FruitX, FruitY, score; // x & y is the position of snake while FruitX and FruitY is the position of the fruit
int TailX[100], TailY[100];
int nTail;
enum eDirection  { STOP = 0, UP , DOWN , LEFT , RIGH }; // The direction where the snake is going
eDirection dir;

void Setup() // Starting Setup for the game
{
	gameOver = false;

	dir = STOP; // The snake does not move during starting postion

	x = width / 2; // The snake starts at the middle of map
	y = height / 2;

	FruitX = rand() % width; // Position of fruit is random
	FruitY = rand() % height;
	score = 0;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			
			case 'w':
				dir = UP;//For hitting 'w' is up movement
				break;

			case 's':
				dir = DOWN; //For hitting 's' is down movement
				break;

			case 'a':
				dir = LEFT; //For hitting 'a' is left movement
				break;
					
			case 'd':
				dir = RIGH; //For hitting 'd' is right movement
				break;


		}
	}

}
void Draw() 
{
	system("cls"); //Clearing console every iteration
	for (int i = 0; i < width + 2; i++)//Top border of map
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) //Height border of map
	{
		
		for (int j = 0; j < width; j++)
		{
			if (j == 0) //Left Border
			{
				cout << "#";
				
			}
			if (i == x && j == y) // Prints Snake instead of space
			{
				cout << "O";

			}
			else if (i == FruitX && j == FruitY) // Prints Fruit instead of space
			{
				cout << "*";
			}
			else
			{
				bool print = false; // To follow movement of the snake
				for (int k = 0; k < nTail; k++) //For drawing the tail
				{
					
					if (TailX[k] == i && TailY[k] == j)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print) 
				{
					cout << " "; //Spaces inbetween the two borders
				}
			}

			
			
			if (j == width - 1)//Right Border
			{
				cout << "#";
			}
		}
		cout << endl;//Next line
	}
	for (int i = 0; i < width + 2; i++)//Bottom border of map
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl; //Score
}
void Logic()
{
	int prevX = TailX[0]; 
	int prevY = TailY[0]; //Position of Tail
	int prev2X, prev2Y; //Previous postion of tail
	TailX[0] = x; 
	TailY[0] = y; //Tail starts at head
	
	for (int i = 1; i < nTail; i++) //For all tail position
	{
		prev2X = TailX[i];
		prev2Y = TailY[i];

		TailX[i] = prevX;
		TailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
		case LEFT: //Left movement
			y--;
			break;

		case RIGH: //Right movement
			y++;
			break;

		case UP: //up movement
			x--;
			break;

		case DOWN: //Down movement
			x++;
			break;

		default:
			break;

	}
	if (x >= width) //If it hits wall it moves snake to opposite end(x axis)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = width - 1;
	}
	else if (y >= height)//If it hits wall it moves snake to opposite end(y axis)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = height - 1;
	}
		
	for (int i = 0; i < nTail; i++) //Ends game if the tail hits itself
	{
		if (TailX[i] == x && TailY[i] == y)
		{
			system("cls");
			cout << "Score: " << score << endl;
			cout << "Game Over!";

			gameOver = true;
		}
	}
	if (x == FruitX && y == FruitY) //If snake eats fruit another segment of tail will appear
	{
		nTail++;
		score += 100;
		FruitX = rand() % width; //Randomises fruit position
		FruitY = rand() % height;

	}

}
int main()
{
	Setup(); //Setting up the map
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(100); //To make snake speed slower
	}
}