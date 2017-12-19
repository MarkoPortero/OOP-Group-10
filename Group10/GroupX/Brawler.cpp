#include "Brawler.h"


//Default Constructor
Brawler::Brawler()
{
}

Brawler::Brawler(int punchDamage, int strength, float health, std::string charactername, int food, float weightlimit, CharacterState state)
{
	punchDamage_ = punchDamage;
	strength_ = strength;
}


void Brawler::SetPunchDamage(int punchDamage)
{
	punchDamage_ = punchDamage;
}

int Brawler::GetPunchDamage()
{
	return punchDamage_;
}


void Brawler::SetStrength(int strength)
{
	strength_ = strength;
}

int Brawler::GetStrength()
{
	return strength_;
}

bool Brawler::Attack(GameCharacter &character)
{
	
	bool hitSuccess = false;
	bool weaponDamagePossible = false;
	//Rosas failure check
	if (GetEquippedWeapon() == -1 || character.GetState() == Dead || GetHealth() <= 20)
	{
		if (GetEquippedWeapon() == -1) {
			//Brawl if there is no weapon equipped!
			this->Brawl;
		}
		//Else return false 
		return false;
	}
	if (GetEquippedWeapon() != -1) {
		//Temp weap / Armour 

		Weapon CurrentWeapon = GetWeapon(GetEquippedWeapon());
		Armour DefenderArmour;
		//Make a random hit chance - Needs to be seeded 
		int hitchance = rand() % 100 + 1;

		//check if character has no armour
		if (character.GetEquippedArmour == -1) {
			if (hitchance <= 80) {
				hitSuccess = true;
			}
		}
		//If character has armour equipped, get the details of that armour - Maybe needs refactoring
		if (character.GetEquippedArmour != -1) {
			DefenderArmour = character.GetArmour(GetEquippedArmour());
			//If Armour is better than weapon..
			if (CurrentWeapon.GetWeaponHitStrength < DefenderArmour.GetDefence) {
				if (hitchance <= 20) {
					hitSuccess = true;
				}
				else {
					//Keep track of if weapon damage is possible - Rather than damaging the weapon at every miss.
					weaponDamagePossible = true;
				}
			}
			//Less than/equal to? Assuming attacker has the advantage
			else if (CurrentWeapon.GetWeaponHitStrength >= DefenderArmour.GetDefence) {
				if (hitchance <= 60) {
					hitSuccess = true;
				}
				else {
					//Keep track of if weapon damage is possible - Rather than damaging the weapon at every miss.
					weaponDamagePossible = true;
				}
			}

		}
		//Damage weapon
		if (weaponDamagePossible == true) {
			int damageAmount = rand() % (21 - 10) + 10;
			//Take weapon damage if the enemy is wearing armour.
			int wepHealth = this->GetWeapon(GetEquippedWeapon()).GetWeaponHealth();
			int newhealth;
			newhealth -= (wepHealth / 100)*damageAmount;
			this->GetWeapon(GetEquippedWeapon()).SetWeaponHealth_(newhealth);

			//Check if the weapon should be dropped
			if (newhealth < 0) {
				this->DropItem(GetWeapon(GetEquippedWeapon()));
			}

		}
		//Deal damage
		if (hitSuccess == true)
		{
			//Hit was successful..Take away armour health
			int curArmourHealth = character.GetArmour(GetEquippedArmour()).GetArmourHealth() - 10;
			character.GetArmour(GetEquippedArmour()).SetArmourHealth(curArmourHealth);
			if (curArmourHealth <= 0) {
				character.DropItem(GetArmour(GetEquippedArmour()));
			}
			//Check brawler strength bonus
			int strength = this->GetStrength;
			strength = (strength / 10) * 5;
			//Using Rosa's switch idea
			switch (character.GetState())
			{
				//Check if the state..If defending do 10% damage + Brawler strength damage
			case Defending:
				float totalHealth = character.GetHealth();
				float damage = (totalHealth / 100) * 10 + strength;
				character.SetHealth(totalHealth - damage);
				break;
				//Sleeping insta kill
			case Sleeping:
				character.SetHealth(0);
				//If the person is dead...Any point dropping their armour?
				break;
				//Idle 20% damage
			case Idle:
				float totalHealth = character.GetHealth();
				float damage = (totalHealth / 100) * 20 + strength;
				character.SetHealth(totalHealth - damage);
				break;
				//running  20% damage
			case Running:
				float totalHealth = character.GetHealth();
				float damage = (totalHealth / 100) * 20 + strength;
				character.SetHealth(totalHealth - damage);
				break;
				//walking  20% damage
			case Walking:
				float totalHealth = character.GetHealth();
				float damage = (totalHealth / 100) * 20 + strength;
				character.SetHealth(totalHealth - damage);
				break;
			}

			//Attack successful
			return true;
		}
	}
	return false;
}

void Brawler::Sleep()
{
	//Set to sleeping..
	GameCharacter::Sleep();
	//Get health
	float totalHealth = GetHealth();
	//Get 20% of health - Add 20% to total health
	totalHealth*0.2; totalHealth += GetHealth();
	//If total is above 100, set to 100
	if (totalHealth > 100) {
		SetHealth(100);
	} // else set to value of total health
	else {
		SetHealth(totalHealth);
	}

}

bool Brawler::Brawl(GameCharacter &character)
{

}




Brawler::~Brawler()
{

	//std::cout << "Brawler destructor called"" << std::endl;
}
