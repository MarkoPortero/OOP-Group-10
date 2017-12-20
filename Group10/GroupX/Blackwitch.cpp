#include "stdafx.h"
#include "Blackwitch.h"

Blackwitch::Blackwitch()
{
}

Blackwitch::Blackwitch(int magicProficiency, int darkPower)
{
}

Blackwitch::~Blackwitch()
{
}

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
	return false;
}

void Blackwitch::Sleep()
{
}

void Blackwitch::Bewitch(GameCharacter & character)
{
}
