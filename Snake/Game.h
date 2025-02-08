#pragma once

#include "Snake.h"
#include "SnakeFood.h"
#include <unordered_set>
#include <string>
#include <thread>
#include <chrono>


class Game {
private:
	Snake snake;
	Apple apple;
	bool isRunning = true;
public:
	Game(int cell) : snake(cell), apple(cell) {
		apple.setFoodPosition(generateRandomPosition(snake.getSnakeBody()));
	}


	void setter(Vector2 move) {
		snake.setMove(move);
	}


	Vector2 getter() {
		return snake.getMove();
	}


	void setIsRuning(bool running) {
		isRunning = running;
	}



	void draw() {
		snake.drawSnake();
		apple.drawFood();
	}



	void update() {
		if (isRunning) {
			snake.updateSnakePos();
			checkFoodCollision(snake.getSnakeBody());
			checkEdgeCollision();
			checkTailCollision();
		}
	}



	bool checkColl(const Vector2& pos, const std::deque<Vector2>& snake) {
		for (const auto& segment : snake) {
			if (Vector2Equals(segment, pos)) {
				return true;
			}
		}
		return false;
	}



	void checkFoodCollision(const std::deque<Vector2>& snakePos) {
		if (Vector2Equals(snake.getHead(), apple.getFoodPosition())) {
			apple.setFoodPosition(generateRandomPosition(snakePos));
			snake.setAddSegment(true);
		}
	}



	void gameOver() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		snake.setSnakeBody({ { 6, 4 }, { 5, 4 }, { 4, 4 } });
		snake.setMove({ 1 , 0 });
		Vector2Add(snake.getHead(), snake.getMove());
		isRunning = false;
	}



	void checkEdgeCollision() {
		int min = -1;
		if (snake.getHead().x == min || snake.getHead().x == snake.getCellSize()) {
			gameOver();
		}
		else if (snake.getHead().y == min || snake.getHead().y == snake.getCellSize()) {
			gameOver();
		}
	}


	void checkTailCollision() {
		std::deque<Vector2> copy = snake.getSnakeBody();
		copy.pop_front();
		if (checkColl(snake.getHead(), copy)) {
			gameOver();
		}
	}



	Vector2 generateRandomPosition(const std::deque<Vector2>& snake) {
		std::unordered_set<std::string> occupiedBySnake;
		for (const auto& segment : snake) {
			occupiedBySnake.insert(std::to_string(segment.x) + "," + std::to_string(segment.y));
		}

		std::vector<Vector2> availableSpace;

		for (int x = 0; x < apple.getCellSize(); x++) {
			for (int y = 0; y < apple.getCellSize(); y++) {
				std::string posKey = std::to_string(x) + ',' + std::to_string(y);
				if (occupiedBySnake.find(posKey) == occupiedBySnake.end()) {
					availableSpace.push_back({ (float)x , (float)y });
				}
			}
		}

		if (availableSpace.empty())
			return { -1, -1 };

		int index = GetRandomValue(0, availableSpace.size() - 1);
		return availableSpace[index];
	}
};