#pragma once
#include <iostream>
#include <string>


using namespace std;

//takes the full input, returns the command portion of the input as a string
string getCommand(string c);

//takes the full input and the command, returns the players answer as a string
string getAnswer(string i, string c);