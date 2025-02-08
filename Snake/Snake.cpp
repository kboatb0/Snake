#include "Game.h"



int main()
{
	const int cellNumber = 30;
	const int cellSize = 30;
	const int grid = cellNumber * cellSize;


	const float moveInterval = 0.1f;
	float moveTimer = 0.0f;
	bool hasTurned = false;


	InitWindow(grid, grid, "Snake");

	Game game(cellSize);

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		moveTimer += GetFrameTime();

		if (moveTimer >= moveInterval) {
			game.update();
			moveTimer = 0.0f;
			hasTurned = false;
		}

		if (!hasTurned) {
			if (IsKeyPressed(KEY_UP) && game.getter().y != 1){
				game.setter({ 0 , -1 });
				hasTurned = true;
				game.setIsRuning(true);
			}
			else if (IsKeyPressed(KEY_DOWN) && game.getter().y != -1) {
				game.setter({ 0 , 1 });
				hasTurned = true;
				game.setIsRuning(true);
			}
			else if (IsKeyPressed(KEY_LEFT) && game.getter().x != 1) {
				game.setter({ -1, 0 });
				hasTurned = true;
				game.setIsRuning(true);
			}
			else if (IsKeyPressed(KEY_RIGHT) && game.getter().x != -1) {
				game.setter({ 1, 0 });
				hasTurned = true;
				game.setIsRuning(true);
			}
		}

		BeginDrawing();
		ClearBackground(DARKGREEN);
		game.draw();
		DrawText(TextFormat("%i" , game.getScore()), 5, (grid - cellSize), 20, WHITE);
		EndDrawing();
	}

	CloseWindow();
}