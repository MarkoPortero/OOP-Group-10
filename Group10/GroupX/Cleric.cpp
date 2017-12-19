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

int Cleric::GetPietyLevel() const
{
	return pietyLevel_;
}

// The Attack Logic
bool Cleric::Attack(GameCharacter&character)
{
	// Attack Variables
	bool HitEglibile = true;
	bool CharacterHit = true;
	int armour_index = this->GetEquippedArmour();
	// If no weapon or dead or health <=20 cannot be hit
	if (this->GetEquippedWeapon() == -1 || character.GetState() == Dead || this->GetHealth() <= 20)
	{
		// Attack is not possible
		bool HitEglibile = false;
		bool CharacterHit = false;
	}
	if (HitEglibile == true || CharacterHit == true)
	{
		//Attack is possbile
		int outcome = (rand() % 100 + 1);     // generates random num in the range of 1 to 100

		int index_weapon = this->GetEquippedWeapon();
		bool charwearingarmour = true;
	}
	// if character has no armour
	if (GameCharacter::GetEquippedArmour() == -1)
	{
		int prospecttohit;
		prospecttohit = 80; // chance of success increases to 80

	}


	/*else if (this->GetWeapon(character.GetEquippedWeapon.GetWeaponHitStrength() < character.GetArmour(armour_index).GetDefence())
	{

	prospecttohit = 20;
	}*/
}

void Cleric::PrayFor(GameCharacter &character)
{
	int outcome = (rand() % 100 + 1);

	if (outcome <= 50) // if success <= 50 heal the character
	{
		int updated_health = character.GetHealth() + (5 * this->GetPietyLevel);
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