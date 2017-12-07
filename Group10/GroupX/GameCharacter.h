#pragma once
#include <string>
#include <vector>
#include "Armour.h"
#include "Weapon.h"

using namespace std;
enum CharacterState{Idle, Running, Sleeping, Walking, Defending, Dead};
class GameCharacter
{
private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int weapon_;
	int armour_;
	std::vector<Weapon>weapons_;
	std::vector<Armour>armours_;
	int food_;
	CharacterState state_;
public:
	GameCharacter();

	GameCharacter(std::string characterName, float health, float weightLimit, int weapon, int armour,
		std::vector<Weapon>weapons, std::vector<Armour>armours);
	~GameCharacter();

	void SetCharacterName(std::string characterName);
	std::string GetCharacterName();

	void SetHealth(float health);
	float GetHealth();

	void SetWeightLimit(float weightLimit);
	float GetWeightLimit();

	void SetWeapon(int weapon);
	int GetWeapon();

	void SetArmour(int armour);
	int GetArmour();

	void SetWeapons(vector<Weapon>weapons);
	vector<Weapon> GetWeapons();

	void SetArmours(vector<Armour>armours);
	vector<Armour> GetArmours();

	virtual bool Attack(GameCharacter&character);

	void Defend(int armour);

	void Walk();

	void Run();

	virtual void Sleep();

	Weapon 
};

