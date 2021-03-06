#include "pch.h"

int main()
{
	Telebook tBook;

	while (true)
	{
		string input = "";
		char buffer[100];

		scanf_s("%[^\n]%*c", buffer, std::size(buffer));
		input = buffer;

		istringstream istream(input);
		istream_iterator<string> start(istream), end;

		vector<string> params(start, end);

		if (params[0] == "add") {
			tBook.addEntry(params[1], params[2]);
		}
		else if (params[0] == "lookup")
		{
			tBook.findEntry(params[1]);
		}
		else if (params[0] == "change")
		{
			tBook.changeEntry(params[1], params[2]);
		}
		else if (params[0] == "alias")
		{
			tBook.aliasEntry(params[1], params[2]);
		}
		else if (params[0] == "quit")
		{
			printf_s("closing..");
			return false;
		}

	}
}