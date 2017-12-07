#include "stdafx.h"
#include "GameCharacter.h"


GameCharacter::GameCharacter()
{
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int weapon, int armour,
	std::vector<Weapon>weapons, std::vector<Armour>armours){}

GameCharacter::~GameCharacter()
{

}

void GameCharacter::SetCharacterName(std::string characterName)
{
	characterName_ = characterName;
}

std::string GameCharacter::GetCharacterName()
{
	return characterName_;
}

void GameCharacter::SetHealth(float health)
{
	health_ = health;
}

float GameCharacter::GetHealth()
{
	return health_;
}

void GameCharacter::SetWeightLimit(float weightLimit)
{
	weightLimit = weightLimit;
}

float GameCharacter::GetWeightLimit()
{
	return weightLimit_;
}

void GameCharacter::SetWeapon(int weapon)
{
	weapon_ = weapon;
}

int GameCharacter::GetWeapon()
{
	return weapon_;
}

void GameCharacter::SetArmour(int armour)
{
	armour_ = armour;
}

int GameCharacter::GetArmour()
{
	return armour_;
}

void GameCharacter::SetWeapons(vector<Weapon> weapons)
{
	weapons_ = weapons;
}

vector<Weapon> GameCharacter::GetWeapons()
{
	return weapons_;
}

void GameCharacter::SetArmours(vector<Armour> armours)
{
	armours_ = armours;
}

vector<Armour> GameCharacter::GetArmours()
{
	return armours_;
}