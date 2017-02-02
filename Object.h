#pragma once
#include <iostream>
#include <string>

using namespace std;

class Object {
public:
	Object();
	Object(string n, string d);
	Object(string n, string d, bool k1, bool k2, bool k3);
	string name;
	string descript;
	string altDesc;
	bool isKey1, isKey2, isKey3;

};