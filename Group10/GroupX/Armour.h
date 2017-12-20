#pragma once
#include "Item.h"
enum ArmourType{Cardboard, Leather, Wood, Iron, Steel};
class Armour : public Item
{
	int defence_;
	int armourHealth_;
	ArmourType armourType_;	
public:
	Armour();
	Armour(std::string weaponName, int value, float weight, int defence, int armourHealth, ArmourType armourType);
	~Armour();
	
	void SetDefence(int defence);
	int GetDefence();

	void SetArmourHealth(int armourHealth);
	int GetArmourHealth();

	void SetArmourType(ArmourType armourType);
	ArmourType GetArmourType();
};

