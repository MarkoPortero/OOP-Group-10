#pragma once
#include "GameCharacter.h"
class Cleric : public GameCharacter
{
private:
	//Variables
	int pietyLevel_;
public:
	Cleric(); // default constructor
	Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel); // custom constructor
	~Cleric(); // default deconstructor
			   //Setters and Getters
	void SetPietyLevel(int pietyLevel);
	int GetPietyLevel();
	// Member Functions
	virtual bool Attack(GameCharacter&character) override;
	void PrayFor(GameCharacter&character);
	virtual void Sleep() override;
};