//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "Mouse.h"

void Mouse::setDpi(const int dpi)
{
	this->dpi = dpi;
}

int Mouse::getDpi() const
{
	return this->dpi;
}

Mouse::operator std::string() const
{
	return (PeripheralDevice::operator std::string() + ", Mouse with dpi : " + std::to_string(dpi));
}

