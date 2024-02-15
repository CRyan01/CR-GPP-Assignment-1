#pragma once
#include "Item.h"

class StaminaItem : public Item {
public:
	// Function to apply the stamina items effect
	void applyEffect() override;
};