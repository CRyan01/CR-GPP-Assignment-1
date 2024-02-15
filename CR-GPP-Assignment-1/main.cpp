#include "Libraries.h"
#include "Game.h"

// Main Method - return type: 0
int main() {
	srand(time(0)); // Seed the random number generator

	char userInput; // Initialize variable to control restarting the game
	bool playGame = true;
	int numEnemies = 0;

	do {
		// Bool to ensure the users input is a valid character
		bool inputValid = false;

		// Ask how many enemies the player wants to fight
		do {
			// Prompt for input
			cout << "How many enemies would you like to play against: Max 9 - Min 1" <<endl;

			// Get & store user input
			int userInput = 0;
			cin >> userInput;

			// Check that the users input is valid
			if ((userInput < 1) || (userInput > 9)) {
				cout << "Invalid Input: Please choose a number between 1 and 9" << endl;
			} else {
				numEnemies = userInput; // Store the number of enemies the player wishes to fight
				inputValid = true;
			}
		} while (!inputValid); // Loop until the input is valid

		inputValid = false; // Reset the flag for the next menu

		Game game(numEnemies); // Create the game object with the specified number of enemies
		game.init(); // Initialize the game
		
		const int maxTurns = 100;
		int turnsTaken = 0; // Variable to track how many turns have passed

		// Loop while until a game over condition is met or 100 turns have passed
		while (!game.isGameOver() && turnsTaken < maxTurns) {
			game.render();
			game.update();
			game.battle();
			game.stats();
			game.clean();

			++turnsTaken; // Increment the turn counter
		}
		if (turnsTaken >= maxTurns) {
			cout << "Game over, turn limit reached" << endl; // Print context
		}

		do {
			// Prompt for input
			cout << "Would you like to play another round:" << endl << "Y. Yes" << endl << "N. No" << endl;

			// Get & store user input
			char userInput = 0;
			cin >> userInput;

			// Check user input and loop 
			switch (userInput) {
			case 'y':
				cout << "Restarting Game..." << endl;
				playGame = true; // Enable to replay the game
				inputValid = true; // Break out of the loop
				break;
			case 'n':
				cout << "Closing game..." << endl;
				playGame = false; // Disable to break out of the game loop
				inputValid = true; // Break out of the loop
				break;
			default:
				cout << "Invalid Input: Please enter y or n" << endl;
				break;
			}
		} while (!inputValid); // Loop until the input is valid

	} while (playGame); // If playGame is true restart the game

	return 0;
}