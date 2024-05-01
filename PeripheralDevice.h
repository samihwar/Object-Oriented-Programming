//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Computer.h"
#include "HWExceptions.h"

class PeripheralDevice :public Item
{
private:
	std::string color;
	bool isWireless;
	Computer* compPort = NULL;
public:
	PeripheralDevice(const int price_, const std::string& manufacturer_, const std::string& color, bool is_wireless) :
		Item(price_, manufacturer_), color(color), isWireless(is_wireless) {
	};

	virtual ~PeripheralDevice() 
	{
		disconnect();
	};

	std::string getColor() const;
	bool getIsWireless() const;

	void setColor(const std::string);
	void setIsWireless(const bool);
	void connect(Computer* computer);
	virtual std::string ItemNameIs()const =0; // "a/an Item.name"

	virtual void disconnect();

	virtual operator std::string()const;
};

