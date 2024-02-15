#pragma once
#include "Item.h"

class AttackItem : public Item {
public:
	// Function to apply the attack items effect
	void applyEffect() override;
};