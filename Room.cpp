#include <iostream>
#include <string>
#include <vector>

#include "Room.h"
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

Room::Room() {}

Room::Room(string n) {
	name = n;
	needKey1 = false;
	needKey2 = false;
	needKey3 = false;
}

Room::Room(string n, string d, int i) {
	name = n;
	roomDescript = d;
	needKey1 = false;
	needKey2 = false;
	needKey3 = false;
	setKey(i);
}

void Room::setDescript(string d){
	roomDescript = d;
}

void Room::setKey(int i){
	if (i == 1)
		needKey1 = true;
	else if (i == 2)
		needKey2 = true;
	else if (i == 3)
		needKey3 = true;
}

void Room::addObjects(vector<Object> *v) {
	for (int i = 0; i < v->size(); i++) {
		roomContents.push_back(v->at(i));
		//cout << roomContents.at(i).descript << endl << endl;
	}
}


//destructor
//Room::~Room() {}