#pragma once
#include "GameCharacter.h"
class Blackwitch : GameCharacter
{
private:
	int magicProficiency_;
	int darkPower_;
public:
	Blackwitch();
	Blackwitch(int magicProficiency, int darkPower);
	~Blackwitch();

	void SetMagicProficiency(int magicProficiency);
	int GetMagicProfiency();

	void SetDarkPower(int darkPower);
	int GetDarkPower();

	virtual bool Attack(GameCharacter&character);

	virtual void Sleep();

	void Bewitch(GameCharacter&character);
};

