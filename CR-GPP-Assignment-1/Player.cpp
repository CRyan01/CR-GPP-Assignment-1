#include "Player.h" // Include header

// Function to update the player
void Player::update() {
	// Ask for input - Print menu
	cout << "Choose a direction to move in:" << endl << "1. North" << endl <<
		"2. South" << endl << "3. East" << endl << "4. West" << endl;

	// Get & store user input
	int userInput = 0;
	cin >> userInput;

	// Check user input, print context, alter player position
	switch (userInput) {
	case 1:
		++m_y; // Increment the players Y coordinate
		// Check if the player hit a perimeter & print context
		if (hitPerimeter()) {
			--m_y; // Decrement the players Y coordinate
			m_health = m_health - (m_speed * 2); // Reduce the players health
			cout << "You search for a path Northwards, seeing only mountains you try to make the climb but fall in the process" << endl;
		} else {
			cout << "You move Northwards" << endl;
		}
		break;
	case 2:
		--m_y; // Increment the players Y coordinate
		// Check if the player hit a perimeter & print context
		if (hitPerimeter()) {
			++m_y; // Decrement the players Y coordinate
			m_health = m_health - (m_speed * 2); // Reduce the players health
			cout << "You search for a path Southwards, seeing only mountains you try to make the climb but fall in the process" << endl;
		} else {
			cout << "You move Southwards" << endl;
		}
		break;
	case 3:
		++m_x; // Increment the players X coordinate
		// Check if the player hit a perimeter & print context
		if (hitPerimeter()) {
			--m_x; // Decrement the players X coordinate
			m_health = m_health - (m_speed * 2); // Reduce the players health
			cout << "You search for a path Eastwards, seeing only mountains you try to make the climb but fall in the process" << endl;
		} else {
			cout << "You move Eastwards" << endl;
		}
		break;
	case 4:
		--m_x; // Increment the players X coordinate
		// Check if the player hit a perimeter & print context
		if (hitPerimeter()) {
			++m_x; // Decrement the players X coordinate
			m_health = m_health - (m_speed * 2); // Reduce the players health
			cout << "You search for a path Westwards, seeing only mountains you try to make the climb but fall in the process" << endl;
		} else {
			cout << "You move Westwards" << endl;
		}
		break;
	}
}