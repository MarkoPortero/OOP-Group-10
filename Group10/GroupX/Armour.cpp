#include "stdafx.h"
#include "Armour.h"


Armour::Armour()
{
}

Armour::Armour(std::string weaponName, int value, float weight, int defence, int armourHealth, ArmourType armourType):
	Item{ weaponName, value, weight }, defence_{ defence }, armourHealth_{ armourHealth }, armourType_{ armourType }
{

}

Armour::~Armour()
{
}

void Armour::SetDefence(int defence)
{
	defence_ = defence;
}

int Armour::GetDefence()
{
	return defence_;
}

void Armour::SetArmourHealth(int armourHealth)
{
	armourHealth_ = armourHealth;
}

int Armour::GetArmourHealth()
{
	return armourHealth_;
}

void Armour::SetArmourType(ArmourType armourType)
{
	armourType_ = armourType;
}

ArmourType Armour::GetArmourType()
{
	return armourType_;
}
