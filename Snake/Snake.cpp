#include "SnakeFood.h"
#include "Snake.h"

const int cellNumber = 30;
const int cellSize = 30;
const int grid = cellNumber * cellSize;

int main()
{
	Snake snake(cellSize);

	InitWindow(grid, grid, "Snake");

	Apple apple(cellSize);

	SetTargetFPS(60);

	while (!WindowShouldClose()) {



		BeginDrawing();
		ClearBackground(DARKGREEN);
		apple.drawFood();
		snake.drawSnake();
		EndDrawing();
	}

	CloseWindow();
}
