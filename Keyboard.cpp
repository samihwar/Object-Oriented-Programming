//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "Keyboard.h"

void Keyboard::setNumOfKeys(const int number_of_keys)
{
	this->number_of_keys = number_of_keys;
}

int Keyboard::getNumOfKeys() const
{
	return this->number_of_keys;
}

Keyboard::operator std::string() const
{
	return (PeripheralDevice::operator std::string() + ", Keyboard with " + std::to_string(number_of_keys) + " keys");
}
