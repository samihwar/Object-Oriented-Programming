//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include "PeripheralDevice.h"
class Keyboard :public PeripheralDevice
{
private:
	int number_of_keys;

public:
	void setNumOfKeys(const int number_of_keys);
	int getNumOfKeys() const;

	Keyboard(const int price_, const std::string& manufacturer_, const std::string& color, bool is_wireless, int number_of_keys) :  // constructor
		PeripheralDevice(price_, manufacturer_, color, is_wireless), number_of_keys(number_of_keys) {};

	virtual ~Keyboard() {}; //destructor

	virtual std::string ItemNameIs()const { return "a keyboard"; };
	virtual operator std::string()const;

};