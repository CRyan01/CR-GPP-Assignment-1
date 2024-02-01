#include "Enemy.h"

// Function to update an enemy
void Enemy::update() {
	// Generate a random number between 1 and 10
	int r = (rand() % 10) + 1;

	bool moveUp = false; // Boolean to indicate direction of movement

	// Check the random number and decide movement direction
	if (r <= 5) {
		moveUp = true; // Enable boolean to move upwards
	} else {
		moveUp = false; // Disable boolean to move downwards
	}

	// Generate a second random number
	r = (rand() % 10) + 1;

	// Check the second random number
	if (r <= 8) {
		if (moveUp) {
			++m_y; // Increment the characters Y coordinate
		} else {
			--m_y; // Decrement the characters Y coordinate
		}
	}

	// Check if the character hit a perimeter
	if (hitPerimeter()) {
		if (moveUp) {
			--m_y; // Reverse the characters direction
		} else {
			++m_y; // Reverse the characters direction
		}
		m_health = m_health - (m_speed * 3); // Reduce the characters health
	}
}