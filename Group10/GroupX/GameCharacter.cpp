#include "GameCharacter.h"



GameCharacter::GameCharacter()
{
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, std::vector<Weapon> weapons, std::vector<Armour> armour)
{
	characterName_ = characterName;
	health_ = health;
	weightLimit_ = weightLimit;
	equippedWeapon_ = equippedWeapon;
	equippedArmour_ = equippedArmour;
	weapons_ = weapons;
	armour_ = armour;
}

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
	weightLimit_ = weightLimit;
}

float GameCharacter::GetWeightLimit()
{
	return weightLimit_;
}

void GameCharacter::SetEquippedWeapon(int equippedWeapon)
{
	equippedWeapon_ = equippedWeapon;
}

int GameCharacter::GetEquippedWeapon()
{
	return equippedWeapon_;
}

void GameCharacter::SetEquippedArmour(int equippedArmour)
{
	equippedArmour_
}

int GameCharacter::GetEquippedArmour()
{
	return equippedArmour_;
}

void GameCharacter::SetWeapons(vector<Weapon> weapons)
{
	weapons_ = weapons;
}

vector<Weapon> GameCharacter::GetWeapons()
{
	return weapons_;
}

void GameCharacter::SetArmour(vector<Armour> armour)
{
	armour_ = armour;
}

vector<Armour> GameCharacter::GetArmour()
{
	return armour_;
}

bool GameCharacter::Attack(GameCharacter & character)
{
	return false;
}

void GameCharacter::Defend(int armour)
{
}

GameCharacter GameCharacter::GetState()
{
	return GameCharacter();
}

void GameCharacter::AddFood(int amount)
{
	food_ = food_ += amount;
}

void GameCharacter::Eat()
{
	int totalFoodConsumed;
	float healthRestored;
	totalFoodConsumed = (food_ * 0.2);
	healthRestored = (totalFoodConsumed / 4);
	health_ = health_ += healthRestored;


}

void GameCharacter::Walk()
{
	state_ = Walking;
}

void GameCharacter::Run()
{
	state_ = Running;
}

void GameCharacter::Sleep()
{
	state_ = Sleeping;
}

Weapon GameCharacter::GetWeapon(int index)
{
	return Weapon();
}

Armour GameCharacter::GetArmour(int index)
{
	return Armour();
}

bool GameCharacter::PickUpWeapon(Weapon &weapon)
{
	
	return false;
}

bool GameCharacter::PickUpArmour(Armour &armour)
{
	return false;
}

void GameCharacter::DropItem(Armour &item)
{
	std::string itemName = item.GetItemName;
	bool found = false;
	for (int i = 0; i < armour_.size(); i++) {
		string search = 
		if(itenmName == )
	}
}

void GameCharacter::DropItem(Weapon & item)
{
}

bool GameCharacter::EquipWeapon(int weapon)
{
	return false;
}
