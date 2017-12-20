#pragma once
#include "Item.h"
#include <string>
class Weapon : public Item
{
private:
	int weaponHitStrength_;
	int weaponHealth_;
public:
	Weapon();
	Weapon(std::string weaponName, int value, float weight, int weaponHitStrength, int weaponHealth);
	~Weapon();

	void SetWeaponHitStrength(int weaponHitStrength);
	int GetWeaponHitStrength();

	void SetWeaponHealth_(int weaponHealth);
	int GetWeaponHealth();
};

