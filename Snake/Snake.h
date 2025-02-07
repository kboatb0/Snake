#pragma once

#include <raylib.h>
#include <deque>
#include <vector>


class Snake {
private:
	std::deque<Vector2> snakePosition = { Vector2{ 4, 4 }, Vector2{ 5, 4 }, Vector2{ 6, 4 } };
	int cellSize;
public:
	Snake(int c) : cellSize(c) {}
	void draw() {
		for (int i = 0; i < snakePosition.size(); i++) {
			DrawRectangle((int)snakePosition[i].x * cellSize, (int)snakePosition[i].y * cellSize, 30, 30, WHITE);
		}
	}
};