#include "SnakeFood.h"
#include "Snake.h"

const int cellNumber = 30;
const int cellSize = 30;
const int grid = cellNumber * cellSize;


const float moveInterval = 0.1f;
float moveTimer = 0.0f;


int main()
{
	InitWindow(grid, grid, "Snake");

	Snake snake(cellSize);
	Apple apple(cellSize);

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		moveTimer += GetFrameTime();

		if (moveTimer >= moveInterval) {
			snake.updateSnakePos();
			moveTimer = 0.0f;
		}

		if (IsKeyPressed(KEY_UP) && snake.getMove().y != 1){
			snake.setMove({ 0 , -1 });
		}
		else if (IsKeyPressed(KEY_DOWN) && snake.getMove().y != -1) {
			snake.setMove({ 0 , 1 });
		}
		else if (IsKeyPressed(KEY_LEFT) && snake.getMove().x != 1) {
			snake.setMove({ -1, 0 });
		}
		else if (IsKeyPressed(KEY_RIGHT) && snake.getMove().x != -1) {
			snake.setMove({ 1, 0 });
		}

		

		BeginDrawing();
		ClearBackground(DARKGREEN);
		snake.drawSnake();
		apple.drawFood();
		EndDrawing();
	}

	CloseWindow();
}