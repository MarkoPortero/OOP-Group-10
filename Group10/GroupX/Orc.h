#pragma once
#include "GameCharacter.h"
class Orc : public GameCharacter
{
private:
	int ferociousness_;
	int strength_;
public:
	Orc();
	Orc(std::string name, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength);
	~Orc();

	void SetFerociousness(int ferociousness);
	int GetFerociousness();

	void SetStrength(int strength);
	int GetStrength();

	//Attack function
	virtual bool Attack(GameCharacter&character) override;
	//Sleep Function
	virtual void Sleep() override;
	//Scream Function
	void Scream(GameCharacter&character);
};

