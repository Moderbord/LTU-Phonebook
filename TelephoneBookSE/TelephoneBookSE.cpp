#include "pch.h"

int main()
{
    
	Telebook tBook ;

	tBook.addEntry("Pontus", "1234");
	tBook.aliasEntry("Pontus", "Kalle");
	tBook.aliasEntry("Kalle", "Smygaren");
	tBook.addEntry("Draken", "666");

	tBook.changeEntry("Pontus", "4444");



}