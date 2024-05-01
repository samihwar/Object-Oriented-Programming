//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
class PeripheralDevice;
//#include "PeripheralDevice.h"

class Computer :public Item
{
private:
	std::string cpu;
	bool isLaptop;
	const int ports;

public:
	std::vector<PeripheralDevice*> usbArr;

	Computer(const int price, const std::string& manufacturer, const std::string& cpu, bool isLaptop, int portsNum) :
		Item(price, manufacturer), cpu(cpu), isLaptop(isLaptop), ports(portsNum) {};

	~Computer();

	std::string getCpu() const;
	void setCpu(const std::string&);

	int getPorts() const;
	void print_connected() const;
	virtual operator std::string() const;

};