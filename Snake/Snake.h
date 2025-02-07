#pragma once

#include <raylib.h>
#include <raymath.h>
#include <deque>

class Snake {
private:
	std::deque<Vector2> snakePosition = { Vector2{ 6, 4 }, Vector2{ 5, 4 }, Vector2{ 4, 4 } };
	Vector2 move = { 1, 0 };
	int cellSize;

public:
	Snake(int cell) : cellSize(cell) {}

	void setMove(Vector2 mv) {
		move = mv;
	}

	Vector2 getMove() {
		return move;
	}
	
	void drawSnake() {
		for (int i = 0; i < snakePosition.size(); i++) {
			Rectangle rec = { snakePosition[i].x * cellSize, snakePosition[i].y * cellSize, (float)cellSize, (float)cellSize };
			DrawRectangleRounded(rec, 0.5, 10, WHITE);
		}
		
	}

	void updateSnakePos() {
		
		snakePosition.pop_back();
		snakePosition.push_front(Vector2Add(snakePosition[0], move));
		
	}


};