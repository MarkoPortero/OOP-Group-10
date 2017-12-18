#pragma once
#include "Item.h"
class Weapon : Item
{
private:
	int weaponHitStrength_;
	int weaponHealth_;
public:
	Weapon();
	Weapon(int weaponHitStrength, int weaponHealth);
	~Weapon();

	void SetWeaponHitStrength(int weaponHitStrength);
	int GetWeaponHitStrength();

	void SetWeaponHealth_(int weaponHealth_);
	int GetWeaponHealth();
};

