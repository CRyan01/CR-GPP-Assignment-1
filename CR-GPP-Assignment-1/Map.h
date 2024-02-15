#pragma once
#include "Libraries.h"

class Map {
private:
	vector<vector<char>> vTileContents; // A 2D vector of characters which will represent the maps contents
	int m_height; // The width of the map
	int m_width; // The height of the map

public:
	// Default constructor
	Map();

	// Parameterized constructor
	Map(int  width, int height);

	// Reset the map to its original state
	void resetMap();

	// Print the map
	void drawMap(bool isNight, int x, int y);

	// Return true if the marker at the specified index is an object marker
	bool isTileOccupied(int x, int y);

	// Return the tile marker stored in a specific index
	char getTileMarker(int x, int y);

	// Set the tile marker at a specific index
	void setTileMarker(int x, int y, char marker);
};