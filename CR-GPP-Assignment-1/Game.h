#pragma once
#include "Libraries.h"
#include "GameCharacter.h"
#include "Enemy.h"
#include "Player.h"
#include "Map.h"


class Game {
private:
	int m_numOfEnemies = 4; // Variable to control the number of enemies in the game
	Player* pPlayer; // A pointer to a player object
	vector<Enemy*> vpEnemies; // A vector containing pointers to enemy objects
	list<GameCharacter*> lpGameCharacters; // A list containing GameCharacter objects
	Map map; // A map object which represents the game state

public:
	// Function to initialize the game
	void init();

	// Function display each characters typeID, x coord and y coord
	void render();

	// Function to call update() for each cahracter
	void update();

	// Function to detect, initiate and resolve battles
	void battle();

	// Function to display each characters stats
	void stats();

	// Function to remove "dead" characters
	void clean();

	// Function to print the map to console
	void printMapToConsole();

	// Function to update the map with the positions of each character
	void updateMap();
};