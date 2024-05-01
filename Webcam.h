//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include "PeripheralDevice.h"
class Webcam :public PeripheralDevice
{
private:
	std::string resolution;

public:
	void setResolution(const std::string& number_of_keys);
	std::string getResolution() const;

	Webcam(const int price_, const std::string& manufacturer_, const std::string& color, bool is_wireless, const std::string& resolution_) : //constructor
		PeripheralDevice(price_, manufacturer_, color, is_wireless), resolution(resolution_) {};

	virtual ~Webcam() {};//destructor

	virtual std::string ItemNameIs()const { return "a webcam"; };
	virtual operator std::string()const;
};

