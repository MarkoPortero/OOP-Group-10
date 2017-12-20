#include "stdafx.h"
#include "Orc.h"


Orc::Orc()
{
}

Orc::Orc(int ferociousness, int strength)
{
}


Orc::~Orc()
{
}

void Orc::SetFerociousness(int ferociousness)
{
	ferociousness_ = ferociousness;
}

int Orc::GetFerociousness()
{
	return ferociousness_;
}

void Orc::SetStrength(int strength)
{
	strength_ = strength;
}

int Orc::GetStrength()
{
	return strength_;
}

bool Orc::Attack(GameCharacter & character)
{
	return false;
}

void Orc::Sleep()
{
}

void Orc::Scream(GameCharacter & character)
{
}
