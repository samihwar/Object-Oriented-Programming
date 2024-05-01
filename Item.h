//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555
#define ID 324888155
#pragma once
#include <iostream>
#include <string>
using std::string;
static int staticId = 1;

class Item
{
private:
	int price;
	std::string manufacturer;
	const int id = staticId++;
public:
	Item(const int price, const std::string& manufacturer) :price(price), manufacturer(manufacturer) {}; //constructor
	virtual ~Item();  //destructor

	virtual operator std::string()const = 0; // overloading op

	void setPrice(const int);
	void setManufacturer(const std::string&);

	int getPrice() const;
	int getId() const;
	std::string getManufacturer() const;
};