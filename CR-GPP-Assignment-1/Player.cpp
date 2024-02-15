#include "Player.h" // Include header

// Function to update the player
void Player::update() {
	// Bool to control looping
	bool inputValid = false;

	do {
		// Ask for input - Print menu
		cout << "Choose a direction to move in:" << endl << "N. North" << endl <<
			"S. South" << endl << "E. East" << endl << "W. West" << endl;

		// Get & store user input
		char userInput;
		cin >> userInput;

		// Check user input, print context, alter player position
		switch (userInput) {
		case 'n':
		case 'N':
			--m_y; // Increment the players Y coordinate
			// Check if the player hit a perimeter & print context
			if (hitPerimeter()) {
				++m_y; // Decrement the players Y coordinate
				m_health = m_health - (m_speed * 2); // Reduce the players health
				cout << "You search for a path Northwards, seeing only mountains you try to make the climb but fall in the process" << endl;
			} else {
				cout << "You move Northwards" << endl;
			}
			inputValid = true; // Break out of the loop
			break;
		case 's':
		case 'S':
			++m_y; // Increment the players Y coordinate
			// Check if the player hit a perimeter & print context
			if (hitPerimeter()) {
				--m_y; // Decrement the players Y coordinate
				m_health = m_health - (m_speed * 2); // Reduce the players health
				cout << "You search for a path Southwards, seeing only mountains you try to make the climb but fall in the process" << endl;
			} else {
				cout << "You move Southwards" << endl;
			}
			inputValid = true; // Break out of the loop
			break;
		case 'e':
		case 'E':
			++m_x; // Increment the players X coordinate
			// Check if the player hit a perimeter & print context
			if (hitPerimeter()) {
				--m_x; // Decrement the players X coordinate
				m_health = m_health - (m_speed * 2); // Reduce the players health
				cout << "You search for a path Eastwards, seeing only mountains you try to make the climb but fall in the process" << endl;
			} else {
				cout << "You move Eastwards" << endl;
			}
			inputValid = true; // Break out of the loop
			break;
		case 'w':
		case 'W':
			--m_x; // Increment the players X coordinate
			// Check if the player hit a perimeter & print context
			if (hitPerimeter()) {
				++m_x; // Decrement the players X coordinate
				m_health = m_health - (m_speed * 2); // Reduce the players health
				cout << "You search for a path Westwards, seeing only mountains you try to make the climb but fall in the process" << endl;
			} else {
				cout << "You move Westwards" << endl;
			}
			inputValid = true; // Break out of the loop
			break;
		default:
			cout << "Invalid Input: Please enter n, s, e, or w" << endl;
			break;
		}
	} while (!inputValid); // Loop until the input is valid
}