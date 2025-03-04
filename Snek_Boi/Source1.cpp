#include <iostream>
using namespace std;
bool gameOver;
const int width = 20, const int height = 20; //The size of the map
int x, y, FruitX, FruitY, score; // x & y is the position of snake while FruitX and FruitY is the position of the fruit
enum eDirection = { STOP = 0, UP, DOWN, LEFT, RIGHT }; // The direction where the snake is going
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

}
void Draw()
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		printf("#\n");
	}
}
void Logic()
{

}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
}