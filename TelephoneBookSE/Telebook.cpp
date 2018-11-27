#include "pch.h"

Telebook::Telebook()
{
	// Constructor;
}

void Telebook::addEntry(std::string name, std::string number)
{
	Contact ct;
	ct.addName(name);
	ct.setNumber(number);

	std::pair<std::map<std::string, Contact>::iterator, bool> hit;

	hit = entries.insert(std::pair<std::string, Contact>(number, ct));

	if (!hit.second)
	{
		printf_s("Contact already exists\n");
	}
}

void Telebook::addEntry(std::string number, Contact ct)
{
	ct.setNumber(number);
	std::pair<std::map<std::string, Contact>::iterator, bool> hit;

	hit = entries.insert(std::pair<std::string, Contact>(number, ct));

	if (!hit.second)
	{
		printf_s("Occupied number\n");
		return;
	}
}

void Telebook::findEntry(std::string name)
{
	Contact (*ct) = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	std::cout << (*ct).getNumber() << std::endl;
}

Contact* Telebook::getEntry(std::string name)
{
	std::map<std::string, Contact>::iterator outer;

	for (outer = entries.begin(); outer != entries.end(); outer++)
	{
		for (std::string value : outer->second.getNames())
		{
			if (name == value) {
				return &(outer->second); // Sends reference
			}
		}
	}
	return false;
}

void Telebook::aliasEntry(std::string name, std::string alias)
{
	Contact* ct = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	(*ct).addName(alias);
	
}

void Telebook::changeEntry(std::string name, std::string number)
{
	Contact(*ct) = getEntry(name);
	if (!ct)
	{
		printf_s("Contact not found\n");
		return;
	}
	addEntry(number, *ct);
	removeEntry(ct->getNumber());
}

void Telebook::removeEntry(string number)
{
	map<string, Contact>::iterator hit = entries.find(number);
	entries.erase(hit);
}