#pragma once
#include "GameCharacter.h"
class Blackwitch : public GameCharacter
{
private:
	int magicProficiency_;
	int darkPower_;
public:
	Blackwitch();
	Blackwitch(std::string name, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower);
	~Blackwitch();

	void SetMagicProficiency(int magicProficiency);
	int GetMagicProfiency();

	void SetDarkPower(int darkPower);
	int GetDarkPower();

	virtual bool Attack(GameCharacter&character) override;

	virtual void Sleep() override;

	void Bewitch(GameCharacter&character);
};

