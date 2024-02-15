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
	int m_Time; // Counter variable to control when it should be day or night
	bool m_isNight; // Bool to indicate if it is day or night

public:
	// Parameterized constructor
	Game(int numEnemies);

	// Function to initialize the game
	void init();

	// Function display each characters typeID, x coord and y coord
	void render();

	// Function to call update() for each cahracter
	void update();

	// Function to detect, initiate and resolve battles
	void battle();

	// A function to simulate a battle between two characters
	void simulateBattle(GameCharacter* characterOne, GameCharacter* characterTwo);

	// Function to display each characters stats
	void stats();

	// Function to remove "dead" characters
	void clean();

	// Function to update the map with the positions of each character
	void updateMap();

	// Function to track and update the time of day
	void updateTime();

	// A function to check if victory or defeat conditions have been met
	bool isGameOver();

	// Returns the time counter value
	int getTime();

	// Returns true if it is night ingame
	bool isNight();

	// Sets the time counter value
	void setTime(int time);

	// Sets the day or night flag to a specific value
	void setIsNight(bool value);
};