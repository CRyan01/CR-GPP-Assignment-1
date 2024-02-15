#pragma once
#include "Libraries.h"

// Class: GameCharacter
class GameCharacter {
protected:
	string m_typeID; // The type of character
	int m_health; // How much health the character has
	int m_speed; // The characters speed
	int m_attack; // The characters attack damage
	int m_defense; // The characters defense
	int m_x; // The characters X coord
	int m_y; // The characters Y coord

public:
	// Function to create an object
	void spawn(string typeID, int health, int speed, int x, int y, int attack, int defense);

	// Function to output the typeID at its x and y coordinates
	void render();

	// Virtual update function - will define in subclasses
	virtual void update();

	// Print stats relevant to the object
	void stats();

	// Return true if its health is greater than zero
	bool isAlive();

	// Return true if the character hit a perimeter
	bool hitPerimeter();

	// Return the characters X coordinate
	int getXPosition();

	// Return the characters Y coordinate
	int getYPosition();

	// Returns a characters typeID
	string getTypeID();

	// Returns a characters health value
	int getHealth();

	// Sets a characters health value
	void setHealth(int health);

	// Returns a characters speed value
	int getSpeed();

	// Sets a characters speed value
	void setSpeed(int speed);

	// Returns a characters attack value
	int getAttack();

	// Sets a characters attack value
	void setAttack(int attack);

	// Returns a characters defense value
	int getDefense();

	// Sets a characters defense value
	void setDefense(int defense);
};