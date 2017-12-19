#pragma once
#include "GameCharacter.h"
class Brawler
{
private:
	int punchDamage_;
	int strength_;
public:
	Brawler();
	Brawler(int punchDamage, int strength, float health, std::string charactername, int food, float weightlimit, CharacterState state);
	~Brawler();

	void SetPunchDamage(int punchDamage);
	int GetPunchDamage();

	void SetStrength(int strength);
	int GetStrength();

	virtual bool Attack(GameCharacter &character) ;

	virtual void Sleep();

	bool Brawl(GameCharacter &character);
};

