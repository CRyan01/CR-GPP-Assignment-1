#include "Map.h"

Map::Map() {
	// Initialize instance variables
	m_width = 10;
	m_height = 10;

	// Create a 2D vector with a specified size and set the default element to '*'
	vTileContents = vector<vector<char>>(m_height, vector<char>(m_width, '*'));
}

// Parameterized constructor
Map::Map(int width, int height) {
	// Initialize instance variables
	m_width = width;
	m_height = height;

	// Create a 2D vector with a specified size and set the default element to '*'
	vTileContents = vector<vector<char>>(height, vector<char>(width, '*'));
}

// Reset the map to its original state
void Map::resetMap() {
	// Nested loops which iterate through each row and column of the 2D vector
	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {
			// Set the tile marker at the specified index to its default value
			vTileContents[y][x] = '*';
		}
	}
}

// Print the map
void Map::drawMap() {
	cout << endl; // Move to the next line

	// Nested loops which iterate through each row and column of the 2D vector
	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {
			// Print the tile marker at the specified index
			cout << " " << vTileContents[y][x];
		}
		cout << endl; // Move to the next line
	}
	cout << endl; // Move to the next line
}

// Return true if the marker at the specified index is an object marker
bool Map::isTileOccupied(int x, int y) {
	return vTileContents[y][x] != '*';
}

// Return the tile marker stored in a specific index
char Map::getTileMarker(int x, int y) {
	return vTileContents[y][x];
}

// Set the tile marker at a specific index
void Map::setTileMarker(int x, int y, char marker) {
	vTileContents[y][x] = marker;
}
