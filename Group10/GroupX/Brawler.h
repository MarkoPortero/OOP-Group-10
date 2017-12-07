#pragma once
#include "GameCharacter.h"
class Brawler
{
private:
	int punchDamage_;
	int strength_;
public:
	Brawler();
	Brawler(int punchDamage, int strength);
	~Brawler();

	void setPunchDamage(int punchDamage);
	int GetPunchDamage();

	virtual bool Attack(GameCharacter&character);

	virtual void Sleep();

	bool Brawl(GameCharacter&character);
};

