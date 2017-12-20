#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string weaponName, int value, float weight, int weaponHitStrength, int weaponHealth) :
	Item{ weaponName, value, weight }, weaponHitStrength_{ weaponHitStrength }, weaponHealth_{ weaponHealth } 
{
}

Weapon::~Weapon()
{
}

void Weapon::SetWeaponHitStrength(int weaponHitStrength)
{
	weaponHitStrength_ = weaponHitStrength;
}

int Weapon::GetWeaponHitStrength()
{
	return weaponHitStrength_;
}

void Weapon::SetWeaponHealth_(int weaponHealth)
{
	weaponHealth_ = weaponHealth;
}

int Weapon::GetWeaponHealth()
{
	return weaponHealth_;
}
