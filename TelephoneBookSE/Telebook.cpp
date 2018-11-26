#include "pch.h"

Telebook::Telebook()
{
	// Constructor TEST;
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
		printf_s("Contact already exists");
	}
}

void Telebook::findEntry(std::string name)
{
	Contact (*ct) = getEntry(name);
	if ((*ct).getNumber() == "")
	{
		printf_s("Contact not found");
		return;
	}
	std::cout << (*ct).getNumber();
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
}

void Telebook::aliasEntry(std::string name, std::string alias)
{
	Contact* ct = getEntry(name);
	if ((*ct).getNumber() == "")
	{
		printf_s("Contact not found");
		return;
	}
	(*ct).addName(alias);
}

void Telebook::changeEntry(std::string name, std::string number)
{
	Contact(*ct) = getEntry(name);
	if ((*ct).getNumber() == "")
	{
		printf_s("Contact not found");
		return;
	}

}
