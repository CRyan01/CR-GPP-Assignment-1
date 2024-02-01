#include "Libraries.h"
#include "Game.h"
//test
// Main Method - return type: 0
int main() {
	// Seed the random number generator
	srand(time(0));

	Game game; // Create the game object
	game.init(); // Initialize the game

	for (int i = 0; i < 100; ++i) {
		game.render();
		game.update();
		game.updateMap();
		game.printMapToConsole();
		game.battle();
		game.stats();
		game.clean();
	}

	return 0;
}