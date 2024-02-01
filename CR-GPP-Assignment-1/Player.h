#pragma once
#include "Libraries.h"
#include "GameCharacter.h"

// Class: Player - Inherits GameCharacter class
class Player : public GameCharacter {
public:
	// Function to update the player
	void update() override;
};