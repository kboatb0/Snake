#include "Game.h"



int main()
{
	// Window dimenshing
	const int cellNumber = 30;
	const int cellSize = 30;
	const int grid = cellNumber * cellSize;

	// control snake speed
	const float moveInterval = 0.1f;
	float moveTimer = 0.0f;

	// Track if snake has turned
	bool hasTurned = false;

	// Open window
	InitWindow(grid, grid, "Snake");

	// Create game object
	Game game(cellSize);

	SetTargetFPS(60);

	// Main Loop
	while (!WindowShouldClose()) {

		// Set timer to record the frame time
		moveTimer += GetFrameTime();

		// Adjust snake speed and move snake
		if (moveTimer >= moveInterval) {
			game.update();
			moveTimer = 0.0f;
			hasTurned = false;
		}

		// Checks for user input and moves snake
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

		// Draw components
		BeginDrawing();
		ClearBackground(DARKGREEN);
		game.draw();
		DrawText(TextFormat("%i" , game.getScore()), 5, (grid - cellSize), 20, WHITE);
		EndDrawing();
	}

	CloseWindow();
}