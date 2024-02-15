#pragma once
#include "Item.h"

class DefenseItem : public Item {
public:
	// Function to apply the defense items effect
	void applyEffect() override;
};