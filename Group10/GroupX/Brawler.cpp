#include "Brawler.h"


//Default Constructor
Brawler::Brawler()
{
}

Brawler::Brawler(int punchDamage, int strength)
{
	punchDamage_ = punchDamage;
	strength_ = strength;
}

void Brawler::SetPunchDamage(int punchDamage)
{
	PunchDamage_ = punchDamage;
}

int Brawler::GetPunchDamage()const
{
	return punchDamage_;
}

void Brawler::SetStrength(int strength)
{
	strength_ = strength;
}

int Brawler::GetStrength() const
{
	return strength_;
}

/
virtual bool Attack(GameCharacter&character)
{



}

virtual void Sleep()
{
}

bool Brawl(GameCharacter&character)
{





}

Brawler::~Brawler()
{

	//std::cout << "Brawler destructor called"" << std::endl;
}
