#pragma once
#include "Item.h"

class HealthItem : public Item {
public:
	// Function to apply the health items effect
	void applyEffect() override;
};