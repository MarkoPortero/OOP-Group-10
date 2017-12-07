#pragma once
#include "GameCharacter.h"
class Cleric
{
private:
	int pietyLevel_;
public:
	Cleric();
	Cleric(int pietyLevel);
	~Cleric();

	void SetPietyLevel(int pietyLevel);
	int GetPietyLevel();

	virtual bool Attack(GameCharacter&character);

	void PrayFor(GameCharacter&character);

	virtual void Sleep();
};

