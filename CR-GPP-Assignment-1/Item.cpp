#include "Item.h"

// Default constructor
Item::Item() {
	m_name = "";
	m_description = "";
	m_level = 0;
}

// Parameterized Constructor
Item::Item(string name, string description, int level) {
	m_name = name;
	m_description = description;
	m_level = level;
}

// Virtual applyEffect function - will define in subclasses
void Item::applyEffect() {

}

// Returns the items name
string Item::getName() {
	return m_name;
}

// Returns the items description
string Item::getDescription() {
	return m_description;
}

// Returns the items level
int Item::getLevel() {
	return m_level;
}

// Sets the items name
void Item::setName(string name) {
	m_name = name;
}

// Sets the items description
void Item::setDescription(string description) {
	m_description = description;
}

// Sets the items level
void Item::setLevel(int level) {
	m_level = level;
}