#pragma once
#include <string>
#include <vector>
#include "Armour.h"
#include "Weapon.h"
#include "Item.h"
using namespace std;
enum CharacterState{Idle, Running, Sleeping, Walking, Defending, Dead};
class GameCharacter
{
private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int equippedWeapon_;
	int equippedArmour_;
	std::vector<Weapon>weapons_;
	std::vector<Armour>armour_;
	int food_;
	CharacterState state_;
public:
	GameCharacter();

	GameCharacter(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour,
		std::vector<Weapon>weapons, std::vector<Armour>armour, int food, CharacterState state);

	GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state);
	~GameCharacter();

	void SetCharacterName(std::string characterName);
	std::string GetCharacterName();

	void SetHealth(float health);
	float GetHealth();

	void SetWeightLimit(float weightLimit);
	float GetWeightLimit();

	void SetEquippedWeapon(int equippedWeapon);
	int GetEquippedWeapon();

	void SetEquippedArmour(int equippedArmour);
	int GetEquippedArmour();

	void SetFood(int food);
	int GetFood();

	void SetWeapons(vector<Weapon>weapons);
	vector<Weapon> GetWeapons();

	void SetArmour(vector<Armour>armour);
	vector<Armour> GetArmour();

	virtual bool Attack(GameCharacter&character)=0;

	void Defend(int armour);

	void Walk();

	void Run();

	virtual void Sleep();

	Weapon GetWeapon(int index);

	Armour GetArmour(int index);

	bool PickUpWeapon(Weapon &weapon);

	bool PickUpArmour(Armour &armour);

	void DropItem(Armour &item);

	void DropItem(Weapon &item);

	bool EquipWeapon(int weapon);

	CharacterState GetState();

	void AddFood(int amount);

	void Eat();

	void DamageWeapon(int damage);

	void DamageArmour(int damage);
};

