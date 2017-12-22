#include "stdafx.h"
#include "Blackwitch.h"
#include <time.h>

Blackwitch::Blackwitch()
{
}
//Constructor
Blackwitch::Blackwitch(std::string name, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower) :
	GameCharacter{ name, health, weightLimit, food, state }, magicProficiency_{ magicProficiency }, darkPower_{ darkPower } {
	SetEquippedArmour(-1);
	SetEquippedWeapon(-1);
}


Blackwitch::~Blackwitch()
{
}
//Getters / Setters
void Blackwitch::SetMagicProficiency(int magicProficiency)
{
	magicProficiency_ = magicProficiency;
}

int Blackwitch::GetMagicProfiency()
{
	return magicProficiency_;
}

void Blackwitch::SetDarkPower(int darkPower)
{
	darkPower_ = darkPower;
}

int Blackwitch::GetDarkPower()
{
	return darkPower_;
}

bool Blackwitch::Attack(GameCharacter & character)
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
			//Check Blackwitch bonus
			int HitBonus = 0;
			int darkPower = GetDarkPower();
			if (darkPower == 100) {
				HitBonus = 20;
			}
			//Using Rosa's switch idea
			float totalHealth = character.GetHealth();
			float damage;
			switch (character.GetState())
			{
				//Check if the state..If defending do 10% damage + Blackwitch bonus damage
			case Defending:
				damage = (totalHealth / 100) * 10 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
				//Sleeping insta kill
			case Sleeping:
				character.SetHealth(0);
				//If the person is dead...Any point dropping their armour?
				break;
				//Idle 20% damage
			case Idle:
				damage = (totalHealth / 100) * 20 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
				//running  20% damage
			case Running:
				damage = (totalHealth / 100) * 20 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
				//walking  20% damage
			case Walking:
				damage = (totalHealth / 100) * 20 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
			}

			//Attack successful
			return true;
		}
	}
	return false;
}

void Blackwitch::Sleep()
{
	//Set to sleeping..
	GameCharacter::Sleep();
	// char health updated by 15% as a BlackWitch
	float updated_health = GetHealth() + (GetHealth()*0.15);
	//  resets health to 100 if it exceeds 100
	if (updated_health > 100)
	{
		updated_health = 100;
	}
	SetHealth(updated_health);

}

//Attempt to put target to sleep
void Blackwitch::Bewitch(GameCharacter & character)
{
	//Set success chance
	int success = 20;
	int magicBonus = GetMagicProfiency() * 5;
	success + magicBonus;
	//seed
	srand(time(NULL));
	int hitchance = rand() % 100 + 1;
	//Check hit
	if (hitchance < success) {
		//put to sleep
		character.Sleep();
	}
}
