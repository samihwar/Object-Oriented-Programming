//yara shamali   yara.sham.ys@gmail.com   315892141
//samih warwar  samih.warwar@gmail.com   3248881555

#pragma once
#include <iostream>
#include <string>
class ConnectError:public std::exception
{
public:
	const char* what() const throw()
	{
		return( "Failed connection attempt");
	}
};

class ExistingItemError:public std::exception
{
public:
	const char* what() const throw()
	{
		return("Trying to add an item with an id already in the catalog");
	}
};

class NonExistingItemError :public std::exception
{
public:
	const char* what() const throw()
	{
		return("Trying to delete an item with a non existing id");
	}
};

class NonExistingItemTypeError :public std::exception
{
public:
	const char* what() const throw()
	{
		return("Trying to get an item with a non existing type");
	}
};

class FullCatalogError :public std::exception
{
public:
	const char* what() const throw()
	{
		return("Trying to add an item to a full catalog");
	}
};
