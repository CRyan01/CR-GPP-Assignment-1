#pragma once
#include "Item.h"

class SpeedItem : public Item {
public:
	// Function to apply the speed items effect
	void applyEffect() override;
};