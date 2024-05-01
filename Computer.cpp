//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "Computer.h"
#include "PeripheralDevice.h"

Computer::~Computer() //distructor
{
	for (int i = 0; i < usbArr.size(); i++)
		usbArr[i]->disconnect();
	usbArr.clear();
}

std::string Computer::getCpu() const
{
	return this->cpu;
}

void Computer::setCpu(const std::string& _cpu)
{
	this->cpu = _cpu;
}


int Computer::getPorts() const
{
	return this->ports;
}

void Computer::print_connected() const
{
	std::cout << "There are " + std::to_string(usbArr.size()) +" connection to " + Computer::operator std::string();
	for (int i = 0; i < usbArr.size(); i++)
		std::cout << std::endl << usbArr[i]->operator std::string();
	std::cout << std::endl;
}

Computer::operator std::string() const
{
	return (Item::operator std::string() + ", " + (isLaptop == true ? "Laptop" : "Desktop") + ", " + cpu);
}
