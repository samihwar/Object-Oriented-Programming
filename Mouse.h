//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include "PeripheralDevice.h"
class Mouse :public PeripheralDevice
{
private:
	int dpi;

public:
	void setDpi(const int dpi);
	int getDpi() const;

	Mouse(const int price, const std::string& manufacturer, const std::string& color, bool is_wireless, int dpi) : // constructor
		PeripheralDevice(price, manufacturer, color, is_wireless), dpi(dpi) {};

	virtual ~Mouse() {};//destructor

	virtual std::string ItemNameIs()const { return "a mouse"; };
	virtual operator std::string()const;
};