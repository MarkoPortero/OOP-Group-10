#pragma once
#include "GameCharacter.h"
class Orc
{
private:
	int ferociousness_;
	int strength_;
public:
	Orc();
	Orc(int ferociousness, int strength);
	~Orc();

	void SetFerociousness(int ferociousness);
	int GetFerociousness();

	void SetStrength(int strength);
	int GetStrength();

	virtual bool Attack(GameCharacter&character);

	virtual void Sleep();

	void Scream(GameCharacter&character);
};

