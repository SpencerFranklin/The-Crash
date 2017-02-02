#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player::Player() {
}

Player::Player(string n, Room curr, Room last) {
	name = n;
	key1 = false;
	key2 = false;
	key3 = false;
	currentRoom = curr;
	lastRoom = last;
}