//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include "Item.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Webcam.h"
#include <string>
#include <vector>
#include<algorithm>
#include "HWExceptions.h"


class Branch
{
private:
	std::vector<Item*> catalog;
	std::string location;
	int capacity;

public:
	Branch(const std::string& location="~", int capacity = 0) :location(location), capacity(capacity) {};
	Branch(const Branch& another) // copy constructor
	{
		location = another.location;
		capacity = another.capacity;
	};
	~Branch()	//destructor
	{
		for (int i = 0; i < catalog.size(); i++)
			delete catalog[i];
		catalog.clear();
	};

	Item* deleteItem(int id);
	void addItem(Item* item);

	std::vector<Item*> getCatalog(void)const;

	template<class T>
	T* retrieveFinest(T* item)const
	{
		int highest = 0;
		T* highItem = NULL;
		for (int i = 0; i < catalog.size(); i++)
		{
			if (typeid(*catalog[i])==typeid(*item)) // if its the same type
				if (catalog[i]->getPrice() > highest)
				{
					highest = catalog[i]->getPrice();
					(highItem) = (dynamic_cast<T*>(catalog[i]));
				}
		}
		if (highItem) {
			if (dynamic_cast<T*>(highItem))
				return highItem;
		}
		else
			throw NonExistingItemTypeError();
	}

	void setLocation(const std::string& location);
	std::string getLocation()const;
	int getCapacity()const;
	int getCatalogValue() const;

	void print(std::vector<Item*>) const;

	void print_catalog_by_id() const;
	void print_catalog_by_price() const;
};