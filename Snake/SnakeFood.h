#pragma once

#include <raylib.h>

class Apple {
private:
	Vector2 foodPosition;										// Track food position
	int cellSize;												

	Texture2D texture;											// Define texture	

public:
	// Constructor
	Apple(int cell) : cellSize(cell) {
		Image image = LoadImage("apple.png");					// Load image
		texture = LoadTextureFromImage(image);					// Load texture from the image
		UnloadImage(image);										// Discard imge
	}


	//Destructor
	~Apple() {
		UnloadTexture(texture);									// Discard texture
	}

	// Getter for cell size
	int getCellSize() {
		return cellSize;
	}

	// Setter for food position
	void setFoodPosition(Vector2 fP) {
		foodPosition = fP;
	}

	// Getter for food position
	Vector2 getFoodPosition() {
		return foodPosition;
	}

	// Draw the food from the texture
	void drawFood() {
		DrawTexture(texture, static_cast<int>(foodPosition.x * cellSize), static_cast<int>(foodPosition.y * cellSize), WHITE);
	}
};