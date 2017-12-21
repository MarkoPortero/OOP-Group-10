#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment_UnitTests
{
	TEST_CLASS(CharacterManagement)
	{
	public:

		TEST_METHOD(TestBrawlerConstructor)
		{
			//Arrange the data
			std::string expectedName{ "Jim" };
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			std::string characterName = brawler.GetCharacterName();

			//Assert
			Assert::AreEqual(expectedName, characterName);
		}

		TEST_METHOD(TestClericConstructor)
		{
			//Arrange the data
			std::string expectedName{ "Jim" };
			float expectedHealth{ 100.0f };
			float expectedWeightLim{ 120.0f };
			int expectedfood{ 50 };
			int expectedPiety{ 60 };
			//Cleric(std::string name, float health, float weightLimit, int food,CharacterState state, int piety level);
			Cleric cleric{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60,};

			//Act
			std::string characterName = cleric.GetCharacterName();
			float health = cleric.GetHealth();
			float weightLimit = cleric.GetWeightLimit();
			int food = cleric.GetFood();
			CharacterState state = cleric.GetState();
			int piety = cleric.GetPietyLevel();

			int expectedState{ 0 }, actualState;
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			

			actualState = cleric.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
			//Assert
			Assert::AreEqual(expectedName, characterName);
			Assert::AreEqual(expectedHealth, health);
			Assert::AreEqual(expectedWeightLim, weightLimit);
			Assert::AreEqual(expectedfood, food);
			Assert::AreEqual(expectedState, actualState);
			Assert::AreEqual(expectedPiety, piety);
		}

		TEST_METHOD(TestEatConsumesFood)
		{
			//Tests that food gets consumed by eat function
			//Arrange the data
			int expectedFood{ 16 }, actualFood;
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 20, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Eat();
			actualFood = brawler.GetFood();

			//Assert
			Assert::AreEqual(expectedFood, actualFood);
		}

		TEST_METHOD(TestEatIncreasesHealth)
		{

			//	Consumes 20% of the available food. Each unit (1) of food consumed will add 0.25 units of health to the character.
			//Tests that health increases correctly by eat function 
			//Arrange the data
			float expectedHealth{ 52.5f }, actualHealth; //(health should not exceed 100)
														 //Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 50.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Eat();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}

		TEST_METHOD(TestHealthCapped)
		{
			//Tests that health does not exceed 100 by eat function 
			//Arrange the data
			float expectedHealth{ 100.0f }, actualHealth; //(health should not exceed 100)
														  //Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Eat();
			actualHealth = brawler.GetHealth();

			//Assert
			Assert::AreEqual(expectedHealth, actualHealth);
		}

	};

}


namespace Conflict_UnitTests
{
	TEST_CLASS(Conflict)
	{
	public:
		TEST_METHOD(Defend1)
		{
			//Test that the character enters defending state
			//Arrange the data
			int expectedState{ 4 }, actualState;
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Defend(1); //invalid index! no armour in vector
			actualState = brawler.GetState();

			//Assert
			Assert::AreEqual(expectedState, actualState);
		}

		TEST_METHOD(Defend2)
		{
			//Test that the character selected armour remains -1 
			//Arrange the data
			int expectedIndex{ -1 }, actualIndex;
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 50, CharacterState::Idle, 60, 80 };

			//Act
			brawler.Defend(0); //invalid index! no armour in vector
			actualIndex = brawler.GetEquippedArmour();

			//Assert
			Assert::AreEqual(expectedIndex, actualIndex);
		}
	};
}

namespace Inventory_UnitTests
{
	TEST_CLASS(InventoryManagement)
	{
	public:

		TEST_METHOD(TestAddItemWeight)
		{
			//Test that adding items above weight limit fails
			//Arrange the data
			bool addItemResult;
			//No point initialising vectors as character should start off with no items.
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 10.0f, 0, CharacterState::Idle, 60, 80 };

			//Weapon(std::string name, int value, float weight, int hitStrength, int health);
			Weapon spear{ "spear", 15, 6.0f, 25, 100 };

			//Armour(std::string itemName, int itemValue, float itemWeight, int defence, int armourHealth, ArmourType ArmourType);
			Armour glove{ "Leather glove", 3, 0.25f, 1, 100, ArmourType::Leather };

			Armour chainMail{ "Chain Mail", 45, 85.0f, 200, 100, ArmourType::Steel };


			//Act
			addItemResult = brawler.PickUpWeapon(spear);
			addItemResult = brawler.PickUpArmour(glove);
			addItemResult = brawler.PickUpArmour(chainMail);
			
			//Assert - add weapon should be false as the weight exceeds the limit
			Assert::IsFalse(addItemResult);
		}

		TEST_METHOD(TestAddWeaponWeight)
		{
			//Test that adding items above weight limit fails
			//Arrange the data
			bool addWeaponResult;
			//No point initialising vectors as character should start off with no items.
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 10.0f, 0, CharacterState::Idle, 60, 80 };
			//Weapon(std::string name, int value, float weight, int hitStrength, int health);
			Weapon spear{ "spear", 15, 6.0f, 25, 100 };
			Weapon bow{ "bow", 15, 6.0f, 25, 100 };

			//Act
			addWeaponResult = brawler.PickUpWeapon(spear);
			addWeaponResult = brawler.PickUpWeapon(bow);

			//Assert - add weapon should be false as the weight exceeds
			Assert::IsFalse(addWeaponResult);
		}

		TEST_METHOD(TestAddArmourWeight)
		{
			//Test that adding items above weight limit fails
			//Arrange the data
			bool addArmourResult;
			//No point initialising vectors as character should start off with no items.
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 40.0f, 0, CharacterState::Idle, 60, 80 };

			//Armour(std::string itemName, int itemValue, float itemWeight, int defence, int armourHealth, ArmourType ArmourType);
			Armour shield{ "Shield", 40, 40.0f, 50, 100, ArmourType::Leather };
			Armour hat{ "Tinfoil Hat", 2, 0.5f, 1, 100, ArmourType::Cardboard };

			//Act
			addArmourResult = brawler.PickUpArmour(shield);
			addArmourResult = brawler.PickUpArmour(hat);

			//Assert - add weapon should be false as the weight exceeds
			Assert::IsFalse(addArmourResult);
		}

		TEST_METHOD(TestAddWeapons)
		{
			//Arrange the data
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 0, CharacterState::Idle, 60, 80 };
			//Weapon(std::string name, int value, float weight, int hitStrength, int health);
			Weapon spear{ "spear", 15, 6.0f, 25, 100 };
			Weapon bow{ "bow", 15, 6.0f, 25, 100 };
			Weapon spear2{ "Lance of Longinus", 10, 2.0f, 70, 100 };
			Weapon arrow{ "arrow", 15, 6.0f, 25, 100 };

			brawler.PickUpWeapon(spear);
			brawler.PickUpWeapon(bow);
			brawler.PickUpWeapon(spear2);
			brawler.PickUpWeapon(arrow);
			brawler.PickUpWeapon(arrow);
			brawler.PickUpWeapon(arrow);
			brawler.PickUpWeapon(arrow);

			std::string expectedWeaponName{ "Lance of Longinus" };

			//Act
			Weapon tempWeapon = brawler.GetWeapon(2);
			std::string weaponName = tempWeapon.GetItemName();

			//Assert
			Assert::AreEqual(expectedWeaponName, weaponName);
		}

		TEST_METHOD(TestDropWeapon)
		{
			//Test Drop weapon
			//Arrange the data
			std::string expectedWeaponName{ "spear" };
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 0, CharacterState::Idle, 60, 80 };
			//Weapon(std::string name, int value, float weight, int hitStrength, int health);
			Weapon spear1{ "spear", 15, 6.0f, 25, 100 };
			Weapon bow{ "bow", 15, 3.0f, 25, 100 };
			Weapon spear2{ "spear", 10, 2.0f, 70, 2 };


			brawler.PickUpWeapon(spear1);
			brawler.PickUpWeapon(bow);
			brawler.PickUpWeapon(spear2);

			//Act

			brawler.DropItem(spear2); //Weapon spear2 should be removed not spear - same name different attributes!

			Weapon tempWeapon = brawler.GetWeapon(0);
			std::string actualWeaponName = tempWeapon.GetItemName();

			//Assert
			Assert::AreEqual(expectedWeaponName, actualWeaponName);
		}

		TEST_METHOD(TestDropArmour)
		{
			//Test Drop weapon
			//Arrange the data
			std::string expectedArmourName{ "Cardboard suit of armour" };
			//Brawler(std::string name, float health, float weightLimit, int food,CharacterState state, int punchDamage, int strength);
			Brawler brawler{ "Jim", 100.0f, 120.0f, 0, CharacterState::Idle, 60, 80 };

			//Armour(std::string itemName, int itemValue, float itemWeight, int defence, int armourHealth, ArmourType ArmourType);
			Armour shield{ "Shield", 40, 40.0f, 50, 100, ArmourType::Leather };
			Armour hat{ "Tinfoil Hat", 2, 0.5f, 1, 100, ArmourType::Cardboard };
			Armour glove1{ "Leather glove", 1, 0.23f, 1, 100, ArmourType::Leather };
			Armour suit{ "Cardboard suit of armour", 10, 2.0f, 15, 100, ArmourType::Cardboard };
			Armour glove2{ "Leather glove", 1, 0.2f, 1, 75, ArmourType::Leather };

			brawler.PickUpArmour(shield);
			brawler.PickUpArmour(hat);
			brawler.PickUpArmour(glove1);
			brawler.PickUpArmour(suit);
			brawler.PickUpArmour(glove2);

			//Act
			brawler.DropItem(glove1);

			Armour tempArmour = brawler.GetArmour(2);
			std::string actualArmourName = tempArmour.GetItemName();

			//Assert
			Assert::AreEqual(expectedArmourName, actualArmourName);

		}
		TEST_METHOD(TestBrawlerAttack)
		{

			// Arange the data
			bool expectedResult{ true }, actualResult;

			//Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState characterState, int ferociousness, int strength);
			Brawler brawler{ "Phil", 100.0f, 110.0f, 30, CharacterState::Idle, 45, 40 };

			//Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState characterState, int pietyLevel);
			Cleric cleric{ "Clarence", 100.0f, 120.0f, 50, CharacterState::Idle, 60 };

			//Weapon(std::string name, int value, float weight, int hitStrength, int health);
			Weapon spear{ "spear", 15, 6.0f, 25, 100 };

			//Armour(std::string itemName, int itemValue, float itemWeight, int defence, int armourHealth, ArmourType ArmourType);
			Armour chainMail{ "Chain Mail", 45, 85.0f, 200, 100, ArmourType::Steel };

			//Act
			brawler.PickUpWeapon(spear);
			brawler.EquipWeapon(0);
			cleric.PickUpArmour(chainMail);
			cleric.Defend(0);
			cleric.Run(); //Sets the cleric's state to running.

			while (cleric.GetHealth() == 100) {
				actualResult = brawler.Attack(cleric);
			}

			//Assert
			Assert::AreEqual(expectedResult, actualResult);
		}

	};
}