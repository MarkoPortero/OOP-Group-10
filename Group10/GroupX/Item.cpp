#include "Item.h"
#include <string>
#include <iostream>



Item::Item()
{
}

Item::Item(std::string itemName, int itemValue, float weight) :
	itemName_{ itemName }, itemValue_{ itemValue }, weight_{ weight }
{
}

Item::~Item()
{
}

//Setters and Getters
void Item::SetItemName(std::string itemName) {
	itemName_ = itemName;
}
std::string Item::GetItemName() {
	return itemName_;
}

void Item::SetItemValue(int itemValue) {
	itemValue_ = itemValue;
}
int Item::GetItemValue() {
	return itemValue_;
}

void Item::SetWeight(float weight) {
	weight_ = weight;
}
float Item::GetWeight() {
	return weight_;
}