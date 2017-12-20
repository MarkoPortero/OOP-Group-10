#include "Cleric.h"
#include <random>
#include <vector>

// Default Constructor
Cleric::Cleric()
{
}
// Custom Constructor
Cleric::Cleric(int pietyLevel, float health, std::string characterName, int food, float weightlimit, CharacterState state)
{
	pietyLevel_ = pietyLevel;
}
// Default Deconstructor
Cleric::~Cleric()
{
}
// Setters and Getters
void  Cleric::SetPietyLevel(int pietyLevel)
{
	pietyLevel_ = pietyLevel;
}

int Cleric::GetPietyLevel()
{
	return pietyLevel_;
}

// The Attack Logic
bool Cleric::Attack(GameCharacter&character)
{

	bool successfulattack = true;
	bool hitSuccess = true;
	bool weaponDamagePossible = true;
	int weapon_index = this->GetEquippedWeapon();
	//Rosas failure check .. attacks not possible
	if (GetEquippedWeapon() == -1 || character.GetState() == Dead || GetHealth() <= 20)
	{
		hitSuccess = false;
		weaponDamagePossible = false;
		//Else return false
		return false;
	}
	if (hitSuccess = true)
	{
		//Temp weap / Armour
		//Make a random hit chance - Needs to be seeded
		int hitchance;
		int outcome = rand() % 100 + 1; // generates a random number between 1 and 100
		bool charhasarmour = true;
		int armour_index = character.GetEquippedArmour();

		//check if character has no armour
		if (character.GetEquippedArmour() == -1)
		{
			hitchance = 80;
		}
		else if (this->GetWeapon(GetEquippedWeapon()).GetWeaponHitStrength() < character.GetArmour(armour_index).GetDefence()) {
			hitchance = 20;
		}
		else if (this->GetWeapon(GetEquippedWeapon()).GetWeaponHitStrength() > character.GetArmour(armour_index).GetDefence()) {
			hitchance = 60;
		}

		if (outcome <= hitchance)
		{
			float totalHealth;
			switch (character.GetState())
			{
				//Hit was successful..Take away armour health
			case Defending:
				// Health decreased by 10%
				totalHealth = character.GetHealth() - (10);
				character.SetHealth(totalHealth);
				break;
			case Sleeping:
				// health decreased by 100%
				totalHealth = character.GetHealth() - (100);
				character.SetHealth(totalHealth);
				break;
			case Dead:
				// no effect
				break;
			default:
				// All other states health decreases by 20%
				totalHealth = (character.GetHealth() - (20));
				character.SetHealth(totalHealth);
				break;
			}

			if (armour_index > -1)
			{

				int armour_health = character.GetArmour(armour_index).GetArmourHealth();
				int totalahealth = (armour_health - 10);
				Armour bc;
				bc.SetArmourHealth(totalahealth);
			}
			if (character.GetArmour(armour_index).GetArmourHealth() <= 0 && armour_index > -1)
			{
				character.DropItem(character.GetArmour(armour_index)); //removes from item from armour vector
			}

		}
		else
		{
			//Damage weapon
			if (successfulattack == false) {
				int outcome = rand() % (21 - 10) + 1;
				//Take weapon damage if the enemy is wearing armour.
				int wepHealth = GetWeapon(GetEquippedWeapon()).GetWeaponHealth();
				int newhealth = 0;
				newhealth -= (wepHealth / 100)*outcome;
				GetWeapon(GetEquippedWeapon()).SetWeaponHealth_(newhealth);

				//Check if the weapon should be dropped
				if (newhealth < 0) {
					this->DropItem(GetWeapon(GetEquippedWeapon()));
				}
			}
		}
	}
}

void Cleric::PrayFor(GameCharacter &character)
{
	int outcome = (rand() % 100 + 1);

	if (outcome <= 50) // if success <= 50 heal the character
	{
		int updated_health = character.GetHealth() + (5 * GetPietyLevel());
		character.SetHealth(updated_health); // updates the health
	}
	else if (character.GetHealth() > 100) // resets health to 100 if it exceeds 100
	{
		character.SetHealth(100);
	}
}

void Cleric::Sleep()
{
	GameCharacter::Sleep();
	// char health updated by 20% as cleric
	int updated_health = this->GetHealth() + 20;
	//  resets health to 100 if it exceeds 100
	if (updated_health > 100)
	{
		updated_health = 100;
	}
	this->SetHealth(updated_health);
}