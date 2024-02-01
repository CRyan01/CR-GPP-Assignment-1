#pragma once
#include "Libraries.h"
#include "GameCharacter.h"

// Class: Enemy - Inherits GameCharacter class
class Enemy : public GameCharacter {
public:

	// Function to update an enemy
	void update() override;
};