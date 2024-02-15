#pragma once
#include "Libraries.h"

class Item {
protected:
	string m_name; // The items name
	string m_description; // A description of the items effect
	int m_level; // The magnitude of the item

public:
	// Default constructor
	Item();

	// Parameterized Constructor
	Item(string name, string description, int level);

	// Virtual applyEffect function - will define in subclasses
	virtual void applyEffect();

	// Returns the items name
	string getName();

	// Returns the items description
	string getDescription();

	// Returns the items level
	int getLevel();

	// Sets the items name
	void setName(string name);

	// Sets the items description
	void setDescription(string description);

	// Sets the items level
	void setLevel(int level);

};