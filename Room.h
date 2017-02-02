#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room {
public:
	Room();
	Room(string n);
	Room(string n, string d, int i);
	void setDescript(string d);
	void setKey(int i);
	void addObjects(vector<Object> *v);

	string name;
	string roomDescript;
	bool needKey1, needKey2, needKey3;
	vector<Object> roomContents;
	Room *northR , *southR, *eastR, *westR;
};