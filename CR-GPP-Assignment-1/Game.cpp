#include "Game.h"

Game::Game(int numOfEnemies) {
	m_numOfEnemies = numOfEnemies;
}

// Function to initialize the game
void Game::init() {
	// Initialize a vector used to store pointers to enemy objects
	vpEnemies = vector<Enemy*>(m_numOfEnemies);

	// Create two vectors to store unique but random X and Y coordinates for all
	// enemies and the player
	vector<int> randomXCoordinates(vpEnemies.size() + 1);
	vector<int> randomYCoordinates(vpEnemies.size() + 1);

	int newX, newY; // Decalre variables to store newly generated coordinates
	bool isUnique; // Decalre boolean variable to indicate if each newly generated coordinate is unique

	// Generate a unique X and Y coordinate for each enemy and the player
	for (int i = 0; i <= vpEnemies.size(); ++i) {
		do {
			isUnique = true; // Set isUnique to true initially
			// Generate a random X and Y coordinate
			newX = (rand() % 10) + 1;
			newY = (rand() % 10) + 1;

			// Check previously generated coordinates for duplicates
			for (int j = 0; j < i && isUnique; ++j) {
				if (randomXCoordinates[j] == newX && randomYCoordinates[j] == newY) {
					isUnique = false; // Set isUnique to false if a duplicate is found
				}
			}
		} while (!isUnique); // Loop until both coordinates are unique

		// Assign the new unique coordinates to their respective vectors
		randomXCoordinates[i] = newX;
		randomYCoordinates[i] = newY;
	}
	// Print debug info
	cout << "Debug: Finished generation of unique coordinates for each character" << endl;

	// Create a player object and assign its address to pPlayer
	pPlayer = new Player;
	// Call spawn() on the player object pPlayer points to set its properties
	pPlayer->spawn("Player", (rand() % 170) + 140, (rand() % 4) + 2, randomXCoordinates[vpEnemies.size()], randomYCoordinates[vpEnemies.size()], (rand() % 31) + 20, (rand() % 20) + 10);
	// Print debug info
	cout << "Debug: Finished creation and initialization of a player object" << endl;

	// Create four enemy objects and assign their addresses to the vector of enemy pointers
	for (int i = 0; i < vpEnemies.size(); ++i) {
		vpEnemies[i] = new Enemy;
		vpEnemies[i]->spawn("Enemy", (rand() % 150) + 90, (rand() % 4) + 2, randomXCoordinates[i], randomYCoordinates[i], (rand() % 30) + 20, (rand() % 20) + 10);
	}
	// Print debug info
	cout << "Debug: Finished creation and initialization of " << vpEnemies.size() << " enemy objects" << endl;

	// Print debug info
	cout << "Debug: Number of pointers to enemy objects to add to the list of character pointers: " << vpEnemies.size() << endl;

	// Add the player to the list of game characters
	lpGameCharacters.push_back(pPlayer);
	// Print debug info
	cout << "Debug: A pointer to a player object was added to the list of character pointers" << endl;

	// Add all enemies to the list of game characters & print debug info
	for (int i = 0; i < vpEnemies.size(); ++i) {
		lpGameCharacters.push_back(vpEnemies[i]);
		cout << "Debug: A pointer to an enemy object was added to the list of character pointers" << endl;
	}

	// Initialize the time of day settings to start in the morning
	setTime(0);
	setIsNight(0);
}

// Function display every characters typeID, X coord and Y coord
void Game::render() {
	// Range based for loop which iterates through the lpGameCharacters list
	// storing the pointer in 'character' each iteration
	for (GameCharacter* character : lpGameCharacters) {
		character->render(); // Call render() on the object character points to
	}
}

// Function to call update() for each cahracter
void Game::update() {
	// Range based for loop which iterates through the lpGameCharacters list
	// storing the pointer in 'character' each iteration
	for (GameCharacter* character : lpGameCharacters) {
		character->update(); // Call update() on the object character points to
	}

	updateMap(); // Update the map with the new game state
	updateTime(); // Update ingame time
}

// Function to detect, initiate and resolve battles
void Game::battle() {
	// Iterate through the list of game characters, starts from the beginning of the list and runs to the end
	// storing the relevant pointer to a character object in 'firstIterator'
	for (list<GameCharacter*>::iterator firstIterator = lpGameCharacters.begin(); firstIterator != lpGameCharacters.end(); ++firstIterator) {
		// Dereference and store the pointer to the character object in 'firstCharacter' for better clarity
		GameCharacter* firstCharacter = *firstIterator;

		// Iterate through the list of game characters, starts at the list item ahead of the first iterator and runs to the end
		// storing the relevant pointer to a character object in 'secondIterator'
		for (list<GameCharacter*>::iterator secondIterator = next(firstIterator); secondIterator != lpGameCharacters.end(); ++secondIterator) {
			// Dereference and store the pointer to the second character object in 'secondCharacter' for better clarity
			GameCharacter* secondCharacter = *secondIterator;
			
			// Compare the X and Y coordinate values of the character objects pointed to by 'firstCharacter' and 'secondCharacter'
			// to determine if a battle should be initiated
			if ((firstCharacter->getXPosition() == secondCharacter->getXPosition()) && (firstCharacter->getYPosition() == secondCharacter->getYPosition())) {
				// Print context
				cout << "Battle initiated at: (" << firstCharacter->getXPosition() << ", " << firstCharacter->getYPosition()<< ") Participants: (" << firstCharacter->getTypeID() << " Vs " << secondCharacter->getTypeID() << ")" << endl;
				simulateBattle(firstCharacter, secondCharacter); // Call simulatebattle() to simulate the battle
			}
		}
	}
}

// A function to simulate a battle between two characters
void Game::simulateBattle(GameCharacter* characterOne, GameCharacter* characterTwo) {
	// Determine who attacks first based on speed
	if (characterOne->getSpeed() < characterTwo->getSpeed()) {
		swap(characterOne, characterTwo); // Swap the characters if the second character is faster
		cout << characterOne->getTypeID() << " closed the gap faster and will land strike first" << endl;
	} else {
		cout << characterOne->getTypeID() << " closed the gap faster and will land strike first" << endl;
	}

	// Simulate the battle while both characters are alive
	while (characterOne->isAlive() && characterTwo->isAlive()) {
		// Calculate the how much damage the second character recieves
		int damageTaken = characterOne->getAttack() - characterTwo->getDefense();

		// Reduce the second characters health
		characterTwo->setHealth(characterTwo->getHealth() - damageTaken);

		// Print Context
		cout << characterOne->getTypeID() << " hit " << characterTwo->getTypeID() << " for " << damageTaken << " damage" << endl;

		if (!characterTwo->isAlive()) {
			cout << characterTwo->getTypeID() << " was defeated by " << characterOne->getTypeID() << endl;
		}
		swap(characterOne, characterTwo); // Swap the characters in preparation for the next turn
	}
}

// Function to display each characters stats
void Game::stats() {
	// Range based for loop which iterates through the lpGameCharacters list
	// storing the pointer in 'character' each iteration
	for (GameCharacter* character : lpGameCharacters) {
		character->stats(); // Call stats() on the object character points
	}
}

// Function to remove "dead" characters
void Game::clean() {
	// Iterate through the list of game characters, starts from the beginning of the list and runs to the end
	// storing the relevant pointer to a character object in 'firstIterator'
	for (list<GameCharacter*>::iterator iterator = lpGameCharacters.begin(); iterator != lpGameCharacters.end();) {
		// Dereference and store the pointer to the character object in 'character' for better clarity
		GameCharacter* character = *iterator;

		// Check if the object character points to has a health value greater than zero
		if (!character->isAlive()) {
			// Print debug
			cout << "Debug: Beginning removal of " << character->getTypeID() << " object" << endl;
			delete character; // Delete the object character points to
			// Remove the pointer from the list using erase and assign the
			// return value (the next pointer in the list) to 'it'
			iterator = lpGameCharacters.erase(iterator);
		} else {
			++iterator; // Iterate if nothing was erased
		}
	}
}

// Function to update the map with the positions of each character then print to console
void Game::updateMap() {
	map.resetMap(); // Call reset map to clear the map of old markers

	// Range based for loop which iterates through the list of game character pointers
	for (GameCharacter* character : lpGameCharacters) {
		// Check if the character is alive
		if (character->isAlive()) {
			// Print debug
			cout << "Adding " << character->getTypeID() << " object marker to map to position(" << character->getXPosition() << ", " << character->getYPosition() << ")" << endl;
			// Check which type of character object it is and mark the map accordingly, Player = 'P', Enemy = 'E'
			if (character->getTypeID() == "Enemy") {
				map.setTileMarker(character->getXPosition(), character->getYPosition(), 'E');
			} else if (character->getTypeID() == "Player") {
				map.setTileMarker(character->getXPosition(), character->getYPosition(), 'P');
			}
		}
	}
	// Call draw map to output the updated map to the console
	map.drawMap(isNight(), pPlayer->getXPosition(), pPlayer->getYPosition()); 
}

// A function to track the number of turns taken and change time of day every five turns
void Game::updateTime() {
	setTime(getTime() + 1); // Increment the time counter

	// Check if the time counter has reached five
	if (getTime() == 5) {
		setTime(0); // Reset the time counter
		setIsNight(!isNight()); // Toogle the boolean to change time of day
		if (isNight()) {
			cout << "The sky grows darker, its getting harder to see" << endl;
		} else {
			cout << "The sun rises, you can see clearly now" << endl;
		}
	}
}

// A function to check if victory or defeat conditions have been met
bool Game::isGameOver() {
	if (!pPlayer->isAlive()) { // Check if the player is dead
		cout << "Defeat" << endl;
		return true; // Return true if the player is dead
	} else {
		for (Enemy* enemy : vpEnemies) { // Check if there are any enemies alive
			if (enemy->isAlive()) {
				return false; // Return false if there is an enemy still alive
			}
		}
		cout << "Victory" << endl;
		return true; // If none of the enemies are alive return true
	}
}

// Returns the time counter value
int Game::getTime() {
	return m_Time;
}

// Returns true if it is night ingame
bool Game::isNight() {
	return m_isNight;
}

// Sets the time counter value
void Game::setTime(int time) {
	m_Time = time;
}

// Sets the day or night flag to a specific value
void Game::setIsNight(bool value) {
	m_isNight = value;
}
