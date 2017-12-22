#include "GameCharacter.h"
#include "Blackwitch.h"
#include "Brawler.h"
#include "Cleric.h"
#include "Orc.h"


GameCharacter::GameCharacter()
{
}
//Constructor <- Don't need?
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
//Custom Constructor..
GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state) : characterName_{ characterName },
health_{ health }, weightLimit_{ weightLimit }, food_{ food }, state_{ state } {
}

GameCharacter::~GameCharacter()
{
}
//set name
void GameCharacter::SetCharacterName(std::string characterName)
{
	characterName_ = characterName;
}
//get name
std::string GameCharacter::GetCharacterName()
{
	return characterName_;
}
//set health
void GameCharacter::SetHealth(float health)
{
	health_ = health;
}
//get health
float GameCharacter::GetHealth()
{
	return health_;
}
//set weight lim
void GameCharacter::SetWeightLimit(float weightLimit)
{
	weightLimit_ = weightLimit;
}
//get weight lim
float GameCharacter::GetWeightLimit()
{
	return weightLimit_;
}
//set equipped
void GameCharacter::SetEquippedWeapon(int equippedWeapon)
{
	equippedWeapon_ = equippedWeapon;
}
//get equipped
int GameCharacter::GetEquippedWeapon()
{
	return equippedWeapon_;
}
//Set equipped
void GameCharacter::SetEquippedArmour(int equippedArmour)
{
	equippedArmour_ = equippedArmour;
}
//Get equipped
int GameCharacter::GetEquippedArmour()
{

	return equippedArmour_;
}
//Set food
void GameCharacter::SetFood(int food)
{
	food_ = food;
}
//Get food
int GameCharacter::GetFood()
{
	return food_;
}
//Set weapon
void GameCharacter::SetWeapons(vector<Weapon> weapons)
{
	weapons_ = weapons;
}
//Get weapon
vector<Weapon> GameCharacter::GetWeapons()
{
	return weapons_;
}
//Set armour
void GameCharacter::SetArmour(vector<Armour> armour)
{
	armour_ = armour;
}
//Get Armour
vector<Armour> GameCharacter::GetArmour()
{
	return armour_;
}
//Attack..Empty
bool GameCharacter::Attack(GameCharacter & character)
{
	return false;
}
//Set to defend - Equip Armour
void GameCharacter::Defend(int armour)
{
	state_ = Defending;
	if (armour_.empty()) {
		SetEquippedArmour(-1);
	}
	else if (armour == -1)
	{
		SetEquippedArmour(-1);
	}
	else if (armour <= armour_.size() - 1) {
		SetEquippedArmour(armour);
	}
}

//Add Food
void GameCharacter::AddFood(int amount)
{
	food_ = food_ += amount;
}
//Tell Char to eat
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

//Damage Weapon
void GameCharacter::DamageWeapon(int damage)
{
	weapons_[equippedWeapon_].SetWeaponHealth_(damage);
}
//Damage Armour
void GameCharacter::DamageArmour(int damage)
{
	armour_[equippedArmour_].SetArmourHealth(damage);
}
//Set state to walk
void GameCharacter::Walk()
{
	state_ = Walking;
}
//Set state to run
void GameCharacter::Run()
{
	state_ = Running;
}
//set state to sleep
void GameCharacter::Sleep()
{
	state_ = Sleeping;
}
//get weapon
Weapon GameCharacter::GetWeapon(int index)
{
	return weapons_[index];
}
//Get armour
Armour GameCharacter::GetArmour(int index)
{
	return armour_[index];
}
//Pickup weapon
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
//Pickup Armour
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
//Drop armour
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
//Drop item
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
//Equip Weapon
bool GameCharacter::EquipWeapon(int weapon)
{
	if (weapon == -1)
	{
		equippedWeapon_ = -1;
		return true;
	}
	else if (weapon <= weapons_.size() - 1) {
		equippedWeapon_ = weapon;
		return true;
	}
	return false;
}
//Get current state.
CharacterState GameCharacter::GetState()
{
	return GameCharacter::state_;
}
