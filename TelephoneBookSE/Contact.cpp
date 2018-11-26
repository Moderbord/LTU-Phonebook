#include "pch.h"

Contact::Contact()
{
	// Constructor
}

void Contact::addName(std::string name)
{
	names.push_back(name);

}

void Contact::setNumber(std::string num)
{
	number = num;
}

std::vector<std::string> Contact::getNames()
{
	return names;
}

std::string Contact::getNumber()
{
	return number;
}

