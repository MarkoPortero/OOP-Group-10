#include "Cleric.h"
#include <random>
#include <vector>

// Default Constructor 
Cleric::Cleric()
{
}
// Custom Constructor 
Cleric::Cleric(int pietyLevel, float health, std::string charactername, int food, float weightlimit, CharacterState state)
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

bool Cleric::Attack(GameCharacter&character)
{
	bool HitEglibile = true;
	bool CharacterHit = true;

	if (this->GetEquippedWeapon() == -1 || character.GetState() == Dead || this->GetHealth() <= 20)
	{
		HitEglibile = false;			//hit requirements aren't met
		return false;
	}

	else if (HitEglibile == true)
	{
		int outcome = dis(gen);
		int prospecttohit;
		int weaponindicator = this->GetEquippedWeapon();
		bool charwearingarmour = true;
		int indicator = character.GetEquippedArmour();

		std::random_device num;
		std::mt19937 gen(num());
		std::uniform_real_distribution<> dis(1, 100);				//generates random number between 1 and 100

	}

	if (GameCharacter::GetEquippedArmour() == -1)
	{

		prospecttohit = 80;
	}

	else if (this->GetWeapon(character.GetEquippedWeapon().GetWeaponHitStrength() < character.GetArmour(indicator).Defend())
	{
		prospecttohit = 20;
	}

	else if (this->GetWeapon(GetEquippedWeapon()).GetWeaponHitStrength() > character.GetArmour(indicator).Defend())
	{
		prospecttohit = 60;
	}


	else if (outcome <= prospecttohit)
	{
		// if the attack hits
		float updatedcharhealth;
		switch: (character.GetState())
		{
		case 1 charDefending:
			updatedcharhealth = character.GetHealth() - (10);
			character.SetHealth(updatedcharhealth);
			break;

		case 2 charSleeping:
			updatedcharhealth = character.GetHealth() - (100);
			character.SetHealth(updatedcharhealth);
			break;

		case 3 charDead:
			break;

		default:
			updatedcharhealth = character.GetHealth() - (20);
			character.SetHealth(updatedcharhealth);
			break;
		}

	}
	if (indicator > -1)
	{
		int originalarmour = character.GetArmour(indicator).GetArmourHealth();
		int updatedarmour = originalarmour - 10;
		std::cout << "The updated armour health: " << character.GetArmour(indicator).GetArmourHealth() << std::endl;


		Armour armour1a = character.GetArmour(indicator);
		armour1a.SetArmourHealth(newarmourhealth);
		GameCharacter::SetArmour(indicator, armour1a);
		std::cout << "The armour health: " << character.GetArmour(indicator).GetArmourHealth() << std::endl;
	}

	if (character.GetArmour(indicator).GetArmourHealth() <= 0 && indicator > -1)
	{
		character.DropItem(character.GetArmour(indicator)); //removes armour from vector
	}
}
else
{
	// if the attack is unsuccessful 
	CharacterHit = false;
}
if (armour_on = true)
{ //if character is wearing armour deal damage to weapon
	std::random_device num2;
	std::mt19937 gen(num2));

	std::uniform_real_distribution<> dis(10, 20);
	int outcome = dis(gen);

	int updatedweaponhealth = (this->GetWeapon(weaponindicator).GetWeaponHealth() - outcome);
	Weapon 1b = this->GetWeapon(indicator);
	this->SetWeapon(indicator, 1b);
}

if (this->GetWeapon(weaponindicator).GetWeaponHealth() <= 0)
{
	this->DropItem(this->GetWeapon(weaponindicator));
}
return CharacterHit; //temporary value
}


void Cleric::Sleep()
{
	int updatedhealth = (this->GetHealth() + 20);
	GameCharacter::Sleep();

	if (updatedhealth > 100)
	{
		updatedhealth = 100;
	}
	this->SetHealth(updatedhealth);

}



void Cleric::PrayFor(GameCharacter &character)
{
	std::mt19937 gen(num());
	std::uniform_real_distribution<> dis(1, 100);
	std::random_device num;

	int outcome = dis(gen);

	if (outcome <= 50)
	{
		// if the number <=  50 then heal character
		int updatedhealth = character.GetHealth() + (5 * this->GetPietyLevel());
		character.SetHealth(updatedhealth);
		if (character.GetHealth() > 100)
		{
			// if the heal makes health exceed 100 set health to 100
			character.SetHealth(100);
		}
	}
}

