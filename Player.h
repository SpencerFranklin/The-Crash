#pragma once
#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Player {
public:
	Player();
	Player(string n, Room curr, Room last);
	Room currentRoom;
	Room lastRoom;
	string name;
	bool key1, key2, key3;
};