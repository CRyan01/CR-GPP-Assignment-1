#include "GameCharacter.h"

// Function to create an object
void GameCharacter::spawn(string typeID, int health, int speed, int x, int y, int attack, int defense) {
	// Initialize variables
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_attack = attack;
	m_defense = defense;
	m_x = x;
	m_y = y;
}

// Function to output the typeID at its x and y coordinates
void GameCharacter::render() {
	cout << "Type: " << m_typeID << " Location: (" << m_x << ", " << m_y << ")" << endl;
}

// Virtual update function - will define in subclasses
void GameCharacter::update() {

}

// Print stats relevant to the object
void GameCharacter::stats() {
	cout << "Type: " << m_typeID << " Health: " << m_health << " Speed: " << m_speed << endl;
}

// Return true if its health is greater than zero
bool GameCharacter::isAlive() {
	return m_health > 0;
}

// Function to check if the character hit a perimeter
bool GameCharacter::hitPerimeter() {
	if ((m_y < 1) || (m_y > 10) || (m_x < 1) || (m_x > 10)) {
		return true; // The character hit a perimeter
	} else {
		return false; // The character didn't hit a perimeter
	}
}

// Returna the characters X coordinate
int GameCharacter::getXPosition() {
	return m_x;
}

// Returns the characters Y coordinate
int GameCharacter::getYPosition() {
	return m_y;
}

// Returns a characters typeID
string GameCharacter::getTypeID() {
	return m_typeID;
}

// Returns a characters health value
int GameCharacter::getHealth() {
	return m_health;
}

// Sets a characters health value
void GameCharacter::setHealth(int health) {
	m_health = health;
}

// Returns a characters speed value
int GameCharacter::getSpeed() {
	return m_speed;
}

// Sets a characters speed value
void GameCharacter::setSpeed(int speed) {
	m_speed = speed;
}

// Returns a characters attack value
int GameCharacter::getAttack() {
	return m_attack;
}

// Sets a characters attack value
void GameCharacter::setAttack(int attack) {
	m_attack = attack;
}

// Returns a characters defense value
int GameCharacter::getDefense() {
	return m_defense;
}

// Sets a characters defense value
void GameCharacter::setDefense(int defense) {
	m_defense = defense;
}
