//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#include "Branch.h"

Item* Branch::deleteItem(int id)
{
	std::vector<Item*>::iterator it=catalog.begin();
	for (int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getId() == id) // search for the id
		{
			Item* returned = catalog[i];
			it += i;
			catalog.erase(it);		//erase it from the catalog
			return returned;
		}
	}
	throw NonExistingItemError();
}

void Branch::addItem(Item* item)
{
	if (catalog.size()==capacity) // if the catalog is full
	{
		throw FullCatalogError();
	}
	else if (std::find(catalog.begin(), catalog.end(), item) != catalog.end()) // if its already there
	{
		throw ExistingItemError();
	}
	else
	{
		catalog.push_back(item);
	}
}

std::vector<Item*> Branch::getCatalog(void) const
{
	return catalog;
}

void Branch::setLocation(const std::string& location)
{
	this->location = location;
}

std::string Branch::getLocation() const
{
	return this->location;
}

int Branch::getCapacity() const
{
	return this->capacity;
}

int Branch::getCatalogValue() const
{
	int sum=0;
	for (int i = 0; i < catalog.size(); i++)
		sum += catalog[i]->getPrice();
	return sum;
}

void Branch::print(std::vector<Item*>tmp)const
{
	std::cout << "Printing KSF branch in " + this->getLocation();
	std::cout << std::endl << "There are " + std::to_string(catalog.size()) + " item in the catalog";
	std::cout << std::endl << "Catalog value is: " + std::to_string(getCatalogValue());
 	for (int i = 0; i < tmp.size(); i++)
	{
		std::cout << std::endl;
		std::cout << tmp[i]->operator std::string();
	}
	std::cout << std::endl;
}

void Branch::print_catalog_by_id() const
{
	std::vector<Item*> tmp=catalog;
	std::sort(tmp.begin(), tmp.end(), [](Item* lhs, Item* rhs)  // compare by id
	{
		return lhs->getId() < rhs->getId();
	});
	print(tmp);
	tmp.clear();
}

void Branch::print_catalog_by_price() const
{
	std::vector<Item*> tmp = catalog;
	std::stable_sort(tmp.begin(), tmp.end(), [](Item* lhs, Item* rhs)  //compare by price
	{
		return lhs->getPrice() < rhs->getPrice();
	});
	print(tmp);
	tmp.clear();
}
