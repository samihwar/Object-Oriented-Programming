//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "Item.h"

Item::~Item()
{
	std::cout << "Throwing away an item" << std::endl;
}

Item::operator std::string() const
{
	return ("id " + std::to_string(id) + ": " + manufacturer + " " + std::to_string(price) + "$");
}

void Item::setPrice(const int _price)
{
	this->price = _price;
}

void Item::setManufacturer(const std::string& _manufacturer)
{
	this->manufacturer = _manufacturer;
}

int Item::getPrice() const
{
	return this->price;
}

int Item::getId() const
{
	return this->id;
}

std::string Item::getManufacturer() const
{
	return this->manufacturer;
}



