#pragma once

#include <raylib.h>
#include <raymath.h>
#include <deque>

class Snake {
private:
	std::deque<Vector2> snakeBody = { { 6, 4 }, { 5, 4 }, { 4, 4 } };
	Vector2 move = { 1, 0 };
	int cellSize;
	bool addSegment = false;

public:
	Snake(int cell) : cellSize(cell) {}

	void setMove(Vector2 mv) {
		move = mv;
	}

	int getCellSize() {
		return cellSize;
	}

	Vector2 getMove() {
		return move;
	}

	Vector2 getHead() {
		return snakeBody[0];
	}

	void setSnakeBody(std::deque<Vector2> body) {
		snakeBody = body;
	}

	std::deque<Vector2> getSnakeBody() {
		return snakeBody;
	}

	void setAddSegment(bool segment) {
		addSegment = segment;
	}
	
	void drawSnake() {
		for (const auto& segment : snakeBody) {
			Rectangle rec = { segment.x * cellSize, segment.y * cellSize, (float)cellSize, (float)cellSize };
			DrawRectangleRounded(rec, 0.5, 10, BLACK);
		}
	}

	void updateSnakePos() {
		if (addSegment) {
			snakeBody.push_front(Vector2Add(snakeBody[0], move));
			addSegment = false;
		}
		else {
			snakeBody.pop_back();
			snakeBody.push_front(Vector2Add(snakeBody[0], move));
		}
	}
};