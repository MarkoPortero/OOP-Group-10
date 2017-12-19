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
	return 0;
}


void Brawler::SetStrength(int strength)
{
	strength_ = strength;
}

int Brawler::GetStrength()
{
	return 0;
}

bool Brawler::Attack(GameCharacter &character)
{
	return false;
}

void Brawler::Sleep()
{
}

bool Brawler::Brawl(GameCharacter &character)
{
	return false;
}




Brawler::~Brawler()
{

	//std::cout << "Brawler destructor called"" << std::endl;
}
