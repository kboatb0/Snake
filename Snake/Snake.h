#pragma once

#include <raylib.h>
#include <raymath.h>
#include <deque>

class Snake {
private:
	std::deque<Vector2> snakePosition = { Vector2{ 4, 4 }, Vector2{ 5, 4 }, Vector2{ 6, 4 } };
	int cellSize;

public:
	Snake(int cell) : cellSize(cell) {}
	void drawSnake() {
		for (int i = 0; i < snakePosition.size(); i++) {
			DrawRectangle((int)snakePosition[i].x * cellSize, (int)snakePosition[i].y * cellSize, 30, 30, WHITE);
		}
	}
};