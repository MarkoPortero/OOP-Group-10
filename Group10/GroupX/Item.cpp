#include "Item.h"

Item::Item()
{
}

Item::Item(std::string itemName, int itemValue, float weight)
{
}

Item::~Item()
{
}

void Item::SetItemName(std::string itemName)
{
	itemName_ = itemName;
}

std::string Item::GetItemName()
{
	return itemName_;
}

void Item::SetItemValue(int itemValue)
{
	itemValue_ = itemValue;
}

int Item::GetItemValue()
{
	return itemValue_;
}

void Item::SetWeight(float weight)
{
	weight_ = weight;
}

float Item::GetWeight()
{
	return weight_;
}
