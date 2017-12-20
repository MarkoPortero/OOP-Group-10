#include "GameCharacter.h"
#include "Blackwitch.h"
#include "Brawler.h"
#include "Cleric.h"
#include "Orc.h"


GameCharacter::GameCharacter()
{
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, 
	std::vector<Weapon> weapons, std::vector<Armour> armour, int food, CharacterState state)
{
	characterName_ = characterName;
	health_ = health;
	weightLimit_ = weightLimit;
	equippedWeapon_ = equippedWeapon;
	equippedArmour_ = equippedArmour;
	weapons_ = weapons;
	armour_ = armour;
	food_ = food;
	state_ = state;
}

GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state) : characterName_{ characterName },
health_{ health }, weightLimit_{ weightLimit }, food_{ food }, state_{ state } {
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
	equippedArmour_ = equippedArmour;
}

int GameCharacter::GetEquippedArmour()
{
	return equippedArmour_;
}

void GameCharacter::SetFood(int food)
{
	food_ = food;
}

int GameCharacter::GetFood()
{
	return food_;
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
	Armour Equipped;
	state_ = Defending;
	if (armour > 0 && armour < armour_.size())
	{	
		//May be required?
		Equipped = armour_[armour];
		//Change state..Change equipped..
		equippedArmour_ = armour;
	}
	else {
		equippedArmour_ = -1;
	}
}


void GameCharacter::AddFood(int amount)
{
	food_ = food_ += amount;
}

void GameCharacter::Eat()
{
	float totalFoodConsumed;
	float healthRestored;
	totalFoodConsumed = (food_ * 0.2);

	healthRestored = (totalFoodConsumed / 4);
	health_ = health_ += healthRestored;
	food_ = food_ - totalFoodConsumed;
	if (health_ > 100) {
		health_ = 100;
	}
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
	Weapon weaponReturn = weapons_[index];
	return weaponReturn;
}

Armour GameCharacter::GetArmour(int index)
{
	Armour armourReturn = armour_[index];
	return armourReturn;
}

bool GameCharacter::PickUpWeapon(Weapon &weapon)
{
	int currentTotalWeight = 0;
	for (int x = 0; x < weapons_.size(); x++) {
		currentTotalWeight = currentTotalWeight += weapons_[x].GetWeight();
	}
	for (int x = 0; x < armour_.size(); x++) {
		currentTotalWeight = currentTotalWeight += armour_[x].GetWeight();
	}
	if (currentTotalWeight + weapon.GetWeight() <= GetWeightLimit()) {
		weapons_.push_back(weapon);
		return true;
	}	
	return false;
}

bool GameCharacter::PickUpArmour(Armour &armour)
{
	int currentTotalWeight = 0;
	for (int x = 0; x < weapons_.size(); x++) {
		currentTotalWeight = currentTotalWeight += weapons_[x].GetWeight();
	}
	for (int x = 0; x < armour_.size(); x++) {
		currentTotalWeight = currentTotalWeight += armour_[x].GetWeight();
	}
	if (currentTotalWeight + armour.GetWeight() <= GetWeightLimit()) {
		armour_.push_back(armour);
		return true;
	}
	return false;
}

void GameCharacter::DropItem(Armour &item)
{
	std::string itemName = item.GetItemName();
	bool found = false;
	for (int i = 0; i < armour_.size(); i++) {

		if (armour_[i].GetItemName() == item.GetItemName()) {
			if (item.GetItemValue() == armour_[i].GetItemValue()) {
				if (item.GetWeight() == armour_[i].GetWeight()) {
					if (item.GetArmourHealth() == armour_[i].GetArmourHealth()) {
						if (item.GetArmourType() == armour_[i].GetArmourType()) {
							armour_.erase(armour_.begin() + (i));
						}
					}

				}
			}

		}
	}
}

void GameCharacter::DropItem(Weapon &item)
{
	std::string itemName = item.GetItemName();
	bool found = false;
	for (int i = 0; i < weapons_.size(); i++) {
		
		if (weapons_[i].GetItemName() == item.GetItemName()) {
			if (item.GetItemValue() == weapons_[i].GetItemValue()) {
				if (item.GetWeight() == weapons_[i].GetWeight()) {
					if (item.GetWeaponHealth() == weapons_[i].GetWeaponHealth()) {
						if (item.GetWeaponHitStrength() == weapons_[i].GetWeaponHitStrength()) {
							weapons_.erase(weapons_.begin() + (i));
						}
					}

				}
			}

		}
	}
}

bool GameCharacter::EquipWeapon(int weapon)
{
	if (weapon == -1)
	{
		equippedWeapon_ = -1;	
		return true;
	}
	else if (weapon <= weapons_.size() - 1) {
		return true;
	}
	return false;
}

CharacterState GameCharacter::GetState()
{
	return GameCharacter::state_;
}
