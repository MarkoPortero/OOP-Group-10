#pragma once
#include <string>
class Item
{
	std::string itemName_;
	int itemValue_;
	float weight_;
	
public:
	Item();
	Item(std::string itemName, int itemValue, float weight);
	~Item();

	void SetItemName(std::string itemName);
	std::string GetItemName();

	void SetItemValue(int itemValue);
	int GetItemValue();

	void SetWeight(float weight);
	float GetWeight();
};