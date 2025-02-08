#pragma once

#include <raylib.h>

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
	}

	~Apple() {
		UnloadTexture(texture);
	}

	int getCellSize() {
		return cellSize;
	}

	void setFoodPosition(Vector2 fP) {
		foodPosition = fP;
	}

	Vector2 getFoodPosition() {
		return foodPosition;
	}

	void drawFood() {
		DrawTexture(texture, static_cast<int>(foodPosition.x * cellSize), static_cast<int>(foodPosition.y * cellSize), WHITE);
	}
};