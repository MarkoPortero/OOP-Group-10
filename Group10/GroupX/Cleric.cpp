#include "Cleric.h"
#include <random>
#include <vector>
#include <time.h>
// Default Constructor
Cleric::Cleric()
{
}
// Custom Constructor
Cleric::Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel) :
	GameCharacter{ characterName, health, weightLimit, food, state }, pietyLevel_{ pietyLevel }
{
	SetEquippedArmour(-1);
	SetEquippedWeapon(-1);
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
	bool hitSuccess = false;
	bool weaponDamagePossible = false;
	//Rosas failure check
	if (GetEquippedWeapon() == -1 || character.GetState() == Dead || GetHealth() <= 20)
	{
		//Else return false 
		return false;
	}
	if (GetEquippedWeapon() != -1) {
		//Temp weap / Armour 

		Weapon CurrentWeapon = GetWeapon(GetEquippedWeapon());
		Armour DefenderArmour;
		//Make a random hit chance - Needs to be seeded 
		srand(time(NULL));
		int hitchance = rand() % 100 + 1;

		//check if character has no armour
		if (character.GetEquippedArmour() == -1) {
			if (hitchance >= 20) {
				hitSuccess = true;
			}
			else if (hitSuccess == false) {
				weaponDamagePossible = true;
			}
		}
		//If character has armour equipped, get the details of that armour - Maybe needs refactoring
		if (character.GetEquippedArmour() >= 0) {
			DefenderArmour = character.GetArmour(character.GetEquippedArmour());
			//If Armour is better than weapon..
			if (CurrentWeapon.GetWeaponHitStrength() < DefenderArmour.GetDefence()) {
				if (hitchance >= 80) {
					hitSuccess = true;
				}
				else if (hitSuccess == false) {
					//Keep track of if weapon damage is possible - Rather than damaging the weapon at every miss.
					weaponDamagePossible = true;
				}
			}
			//Less than/equal to? Assuming attacker has the advantage
			else if (CurrentWeapon.GetWeaponHitStrength() >= DefenderArmour.GetDefence()) {
				if (hitchance >= 40) {
					hitSuccess = true;
				}
				else if (hitSuccess == false) {
					//Keep track of if weapon damage is possible - Rather than damaging the weapon at every miss.
					weaponDamagePossible = true;
				}
			}

		}
		//Damage weapon
		if (weaponDamagePossible == true) {
			int damageAmount = rand() % (21 - 10) + 10;
			//Take weapon damage if the enemy is wearing armour.
			int wepHealth = GetWeapon(GetEquippedWeapon()).GetWeaponHealth();
			int damageTotal = GetWeapon(GetEquippedWeapon()).GetWeaponHealth();;
			damageTotal = damageTotal - (wepHealth / 100)*damageAmount;
			DamageWeapon(damageTotal);

			//Check if the weapon should be dropped
			if (GetWeapon(GetEquippedWeapon()).GetWeaponHealth() < 0) {
				DropItem(GetWeapon(GetEquippedWeapon()));
			}

		}
		//Deal damage
		if (hitSuccess == true)
		{
			//Hit was successful..Take away armour health
			if (character.GetEquippedArmour() != -1) {
				int curArmourHealth = character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10;
				character.DamageArmour(curArmourHealth);
				if (curArmourHealth <= 0) {
					character.DropItem(character.GetArmour(character.GetEquippedArmour()));
				}
			}

			//Using Rosa's switch idea
			float totalHealth = character.GetHealth();
			float damage;
			switch (character.GetState())
			{
				//Check if the state..If defending do 10% damage + Blackwitch bonus damage
			case Defending:
				damage = (totalHealth / 100) * 10;
				character.SetHealth(totalHealth - damage);
				break;
				//Sleeping insta kill
			case Sleeping:
				character.SetHealth(0);
				//If the person is dead...Any point dropping their armour?
				break;
				//Idle 20% damage
			case Idle:
				damage = (totalHealth / 100) * 20;
				character.SetHealth(totalHealth - damage);
				break;
				//running  20% damage
			case Running:
				damage = (totalHealth / 100) * 20;
				character.SetHealth(totalHealth - damage);
				break;
				//walking  20% damage
			case Walking:
				damage = (totalHealth / 100) * 20;
				character.SetHealth(totalHealth - damage);
				break;
			}

			//Attack successful
			return true;
		}
	}
	return false;
}
//Attempt to heal the character
void Cleric::PrayFor(GameCharacter &character)
{
	int outcome = (rand() % 100 + 1);

	if (outcome <= 50) // if success <= 50 heal the character
	{
		int updated_health = character.GetHealth() + (character.GetHealth() / 100)*(5 * GetPietyLevel());
		character.SetHealth(updated_health); // updates the health
	}
	else if (character.GetHealth() > 100) // resets health to 100 if it exceeds 100
	{
		character.SetHealth(100);
	}
}

void Cleric::Sleep()
{
	//Set to sleeping..
	GameCharacter::Sleep();
	// char health updated by 20% as Cleric
	float updated_health = GetHealth() + (GetHealth()*0.2);
	//  resets health to 100 if it exceeds 100
	if (updated_health > 100)
	{
		updated_health = 100;
	}
	SetHealth(updated_health);

}