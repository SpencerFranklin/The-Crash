#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

//default constructor
Object::Object() {}

//constructor for regular objects
Object::Object(string n, string d){
	name = n;
	descript = d;
	isKey1 = false;
	isKey2 = false;
	isKey3 = false;
	
}

//constructor for keys and clues
Object::Object(string n, string d, bool k1, bool k2, bool k3){
	name = n;
	descript = d;
	isKey1 = k1;
	isKey2 = k2;
	isKey3 = k3;
	

}
