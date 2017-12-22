#include "Brawler.h"
#include <time.h>

//Default Constructor
Brawler::Brawler()
{
}
//Custom Constructor
Brawler::Brawler(std::string name, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength) :
	GameCharacter{ name, health, weightLimit, food, state }, punchDamage_{ punchDamage }, strength_{ strength } {
	SetEquippedArmour(-1);
	SetEquippedWeapon(-1);
}

//Set Punch damage
void Brawler::SetPunchDamage(int punchDamage)
{
	punchDamage_ = punchDamage;
}
//Get Punch Damage
int Brawler::GetPunchDamage()
{
	return punchDamage_;
}

//Set Strength
void Brawler::SetStrength(int strength)
{
	strength_ = strength;
}
//Get Strength
int Brawler::GetStrength()
{
	return strength_;
}
//Brawler Attack Function
bool Brawler::Attack(GameCharacter &character)
{

	bool hitSuccess = false;
	bool weaponDamagePossible = false;
	//Rosas failure check
	if (GetEquippedWeapon() == -1 || character.GetState() == Dead || GetHealth() <= 20)
	{
		if (GetEquippedWeapon() == -1) {
			//Brawl if there is no weapon equipped!
			Brawl(character);
		}
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
			//Check brawler strength bonus
			int strength = GetStrength();
			int HitBonus = (strength / 10) * 5;
			//Using Rosa's switch idea
			float totalHealth = character.GetHealth();
			float damage;
			switch (character.GetState())
			{
				//Check if the state..If defending do 10% damage + Brawler strength damage
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
//Brawler go to sleep function
void Brawler::Sleep()
{
	//Set to sleeping..
	GameCharacter::Sleep();
	// char health updated by 20% as Brawler
	float updated_health = GetHealth() + (GetHealth()*0.2);
	//  resets health to 100 if it exceeds 100
	if (updated_health > 100)
	{
		updated_health = 100;
	}
	SetHealth(updated_health);

}
//Brawler Brawl function ASSUMES THAT BRAWL ALSO ADDS STRENGTH DAMAGE
bool Brawler::Brawl(GameCharacter &character)
{
	bool hitSuccess = false;

	//Rosas failure check
	if (character.GetState() == Dead || GetHealth() <= 20)
	{
		//Else return false 
		return false;
	}
	if (GetEquippedWeapon() == -1) {
		//Temp weap / Armour 

		Armour DefenderArmour;
		//Make a random hit chance - Needs to be seeded 
		srand(time(NULL));
		int hitchance = rand() % 100 + 1;

		//check if character has no armour
		if (character.GetEquippedArmour() == -1) {
			if (hitchance >= 20) {
				hitSuccess = true;
			}
		}
		//If character has armour equipped, get the details of that armour - Maybe needs refactoring
		if (character.GetEquippedArmour() >= 0) {
			DefenderArmour = character.GetArmour(character.GetEquippedArmour());
			//If Armour is better than weapon..
			if (GetPunchDamage() < DefenderArmour.GetDefence()) {
				if (hitchance >= 80) {
					hitSuccess = true;
				}
			}
			//Less than/equal to? Assuming attacker has the advantage
			else if (GetPunchDamage() >= DefenderArmour.GetDefence()) {
				if (hitchance >= 40) {
					hitSuccess = true;
				}
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
			//Check brawler strength bonus
			int strength = GetStrength();
			int HitBonus = (strength / 10) * 5;
			//Using Rosa's switch idea
			float totalHealth = character.GetHealth();
			float damage;
			switch (character.GetState())
			{
				//Check if the state..If defending do 10% damage + Brawler strength damage
			case Defending:
				damage = (totalHealth / 100) * 5 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
				//Assuming that brawl only does 50% damage to sleeping target
			case Sleeping:
				damage = (totalHealth / 100) * 50 + HitBonus;
				character.SetHealth(totalHealth - damage);
				//If the person is dead...Any point dropping their armour?
				break;
				//Idle 10% damage
			case Idle:
				damage = (totalHealth / 100) * 10 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
				//running  10% damage
			case Running:
				damage = (totalHealth / 100) * 10 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
				//walking 10% damage
			case Walking:
				damage = (totalHealth / 100) * 10 + HitBonus;
				character.SetHealth(totalHealth - damage);
				break;
			}

			//Attack successful
			return true;
		}
	}
	return false;

}



//Brawler destructor
Brawler::~Brawler()
{
}
