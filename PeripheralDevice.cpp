//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "PeripheralDevice.h"

std::string PeripheralDevice::getColor() const
{
	return this->color;
}

bool PeripheralDevice::getIsWireless() const
{
	return this->isWireless;
}

void PeripheralDevice::setColor(const std::string _color)
{
	this->color = _color;
}

void PeripheralDevice::setIsWireless(const bool _isWirless)
{
	this->isWireless = _isWirless;
}

void PeripheralDevice::disconnect()
{
	if (compPort) // if its not connected
	{
		std::vector<PeripheralDevice*>::iterator newEnd;
		compPort->usbArr.erase(std::remove(compPort->usbArr.begin(), compPort->usbArr.end(),this));
		compPort = NULL;
	}
}

PeripheralDevice::operator std::string() const
{
	return (Item::operator std::string() + ", " + (isWireless == true ? "Wireless" : "Wired") + ", " + color);
}


void PeripheralDevice::connect(Computer* computer)
{
	std::cout << "Connecting ";
	std::cout << ItemNameIs() << std::endl; // keyboard or mouse or webcam

	if (compPort != computer) //if its not already connected
	{
		if (compPort)
			throw ConnectError();       //the usb is already connected to another computer
		else
		{
			std::cout << operator std::string();
			std::cout << " is Connecting to computer: " + computer->Computer::operator std::string(); std::cout << std::endl;

			for (int i = 0; i < computer->usbArr.size(); i++)
				if (typeid(computer->usbArr[i]) == typeid(*this)) // the computer have another Device from the same type
					throw ConnectError();

				if (computer->usbArr.size() == computer->getPorts()) // the ports are full
					throw ConnectError();
				else
				{
					computer->usbArr.push_back(this); //add the device to the ports
					compPort = computer; //update the port in device
				}
		}
	}
}
