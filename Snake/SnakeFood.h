#pragma once

#include <raylib.h>
#include <random>

class Apple {
private:
	Vector2 foodPosition;
	int cellSize;

	Texture2D texture;

public:
	Apple(int cell) : cellSize(cell) {
		Image image = LoadImage("food.png");
		texture = LoadTextureFromImage(image);
		UnloadImage(image);
		foodPosition = generateRandomPosition();
	}

	~Apple() {
		UnloadTexture(texture);
	}

	int getCellSize() {
		return cellSize;
	}

	void draw() {
		DrawTexture(texture, static_cast<int>(foodPosition.x * getCellSize()), static_cast<int>(foodPosition.y * getCellSize()), WHITE);
	}

	Vector2 generateRandomPosition() {
		float x = GetRandomValue(0, getCellSize() - 1);
		float y = GetRandomValue(0, getCellSize() - 1);
		return Vector2{ x, y };
	}
};