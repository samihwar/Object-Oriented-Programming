//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "Webcam.h"

void Webcam::setResolution(const std::string& resolution)
{
	this->resolution = resolution;
}

std::string Webcam::getResolution() const
{
	return this->resolution;
}

Webcam::operator std::string() const
{
	return (PeripheralDevice::operator std::string() + ", Webcam with " + resolution + " resolution");
}