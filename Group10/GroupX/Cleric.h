#pragma once
#include "GameCharacter.h"
class Cleric : public GameCharacter
{
private:
	int pietyLevel_;
public:
	Cleric();
	Cleric(int pietyLevel, float health, std::string charactername, int food, float weightlimit, CharacterState state);

	void SetPietyLevel(int pietyLevel);
	int GetPietyLevel() const;

	virtual bool Attack(GameCharacter&character) ;

	void PrayFor(GameCharacter&character);

	virtual void Sleep();
};

