#include "pch.h"

int main()
{
    
	Telebook tBook ;

	tBook.addEntry("Pontus", "1234");
	tBook.aliasEntry("Pontus", "Kalle");
	tBook.addEntry("Draken", "666");

	tBook.findEntry("Pontus");

}