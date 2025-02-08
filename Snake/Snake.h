#pragma once

#include <raylib.h>
#include <raymath.h>
#include <deque>

class Snake {
private:
	std::deque<Vector2> snakeBody = { { 6, 4 }, { 5, 4 }, { 4, 4 } };			// Coordinates for snake body
	Vector2 move = { 1, 0 };													// Initial movement direction
	int cellSize;																// Size of each cell
	bool addSegment = false;													// Track snake growth

public:
	Snake(int cell) : cellSize(cell) {}

	//Setter for move
	void setMove(Vector2 mv) {
		move = mv;
	}

	// Getter for cellSize
	int getCellSize() {
		return cellSize;
	}


	// Getter for move
	Vector2 getMove() {
		return move;
	}


	// Getter for first snake segment or head
	Vector2 getHead() {
		return snakeBody[0];
	}


	// Setter for the snake body
	void setSnakeBody(std::deque<Vector2> body) {
		snakeBody = body;
	}


	// Getter for the snake body
	std::deque<Vector2> getSnakeBody() {
		return snakeBody;
	}


	// Setter for the segment
	void setAddSegment(bool segment) {
		addSegment = segment;
	}
	

	// Draw the snake
	void drawSnake() {
		for (const auto& segment : snakeBody) {
			Rectangle rec = { segment.x * cellSize, segment.y * cellSize, (float)cellSize, (float)cellSize };
			DrawRectangleRounded(rec, 0.5, 10, BLACK);
		}
	}


	// Update Snake movement
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