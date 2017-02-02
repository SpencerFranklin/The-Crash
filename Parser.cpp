#include <iostream>
#include <string>
#include "Parser.h"

//takes a string and returns the command at the beginning
string getCommand(string c)
{
	string s;
	if (c.length() <= 4) {
		s = c.substr(0, c.find("\n"));
		return c.substr(0, c.find("\n"));
	}
	else
		return c.substr(0, c.find(" "));
}

//parses the input i from the command point until the end
string getAnswer(string i, string c)
{
	return i.substr(c.length()+1, i.find("\n"));
}
