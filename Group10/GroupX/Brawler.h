#pragma once
#include "GameCharacter.h"
class Brawler : public GameCharacter
{
private:
	int punchDamage_;
	int strength_;
public:
	Brawler();
	Brawler(std::string name, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength);
	~Brawler();

	void SetPunchDamage(int punchDamage);
	int GetPunchDamage();

	void SetStrength(int strength);
	int GetStrength();

	virtual bool Attack(GameCharacter &character) override;

	virtual void Sleep() override;

	bool Brawl(GameCharacter &character);
};

