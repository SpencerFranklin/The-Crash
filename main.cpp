#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "TextVars.h"
#include "Room.h"
#include "Object.h"
#include "Player.h"
#include "Parser.h"
#ifdef _MSC_VER
#define strcasecmp _stricmp
#endif
using namespace std;

//initializes all objects in all rooms
void initializeObjects();

//initializes all rooms with their objects and description fields
void initializeRooms();

//links the rooms together
void initializeMap();

//loop that runs the game
void gameLoop();

//returns the next room based on the inputted direction as a string
Room getNextRoom(string s);

//checks if you can enter the inputted room based on what keys you have
bool canMoveRoom(Room r);

//adds a key to the players inventory
void addKey(Object o);

//displays text saysing if you used a key to open a door
void specialUseKeyText();

//declare all rooms
Room entryRoom;
Room hallway;
Room controlRoom;
Room eastStairsRoom;
Room westStairsRoom;
Room engineRoom;
Room laboratory;
Room redRoom;
Room greenRoom;
Room emptyRoom;
Room storageRoom;
Room medicalBay;
Room compactRoom;
Room nullRoom;

//declare a vector of objects for each room
vector <Object> entryRoomO;
vector <Object> hallwayO;
vector <Object> controlRoomO;
vector <Object> eastStairsRoomO;
vector <Object> westStairsRoomO;
vector <Object> engineRoomO;
vector <Object> laboratoryO;
vector <Object> redRoomO;
vector <Object> greenRoomO;
vector <Object> emptyRoomO;
vector <Object> storageRoomO;
vector <Object> medicalBayO;
vector <Object> compactRoomO;

//list of all rooms
vector <Room*> roomList;

//player and player name declaration
Player player;
string pName;

//input for game loop
string command;
string input;
string answer;

//game over boolean and end game sequence boolean
bool gameOver;
bool pushButton;

//method for altering the description of the control panel object once you beat the game
void ctrlPnlAltText();

//method that initiates the end of the game
void winGameSequence();

int main()
{
	initializeObjects();
	initializeRooms();
	initializeMap();
	player = Player("", entryRoom, nullRoom);
	gameOver = false;
	pushButton = false;

	//intro text
	cout << "Enter your name: ";
	getline(cin, pName); //get input from user
	player.name = pName; //set players name
	cout << "Hello " << player.name << endl;

	cout << part1 << endl << endl;
	system("Pause");
	system("CLS");
	cout << part2 << endl << transition << endl << endl;
	system("Pause");
	system("CLS");
	cout << part3 << endl << transition << endl << endl;
	system("Pause");
	system("CLS");
	cout << transition << endl << "You swim to an opening in the side of the craft and enter." << endl << endl << endl;
	system("Pause");
	system("CLS");
	

	//call the game loop
	gameLoop();
	
	return 0;
}

//creates all the objects in each room and puts them into a vector
void initializeObjects() {

	//entry room
	entryRoomO.push_back(Object("Walls", entryWallsDesc));
	entryRoomO.push_back(Object("Paneling", entryPanelingDesc));
	entryRoomO.push_back(Object("Device", entryDeviceDesc));
	entryRoomO.push_back(Object("North Door", northDoorDesc));
	entryRoomO.push_back(Object("East Stairs", entryEastStairsDesc));
	entryRoomO.push_back(Object("West Stairs", entryWestStairsDesc));

	//hallway
	hallwayO.push_back(Object("Walls", hallWallsDesc));
	hallwayO.push_back(Object("Wiring", hallWiringDesc));
	hallwayO.push_back(Object("North Door", northDoorDesc));
	hallwayO.push_back(Object("South Door", southDoorDesc));
	hallwayO.push_back(Object("Container", hallContainerDesc));

	//control room
	controlRoomO.push_back(Object("Walls", controlWallsDesc));
	controlRoomO.push_back(Object("Control Panel", controlPanelDesc));
	controlRoomO.at(1).altDesc = controlPanelAlt;
	controlRoomO.push_back(Object("Glass", controlGlassDesc));
	controlRoomO.push_back(Object("South Door", southDoorDesc));
	controlRoomO.push_back(Object("Chair", controlChairDesc));
	controlRoomO.push_back(Object("Dome", controlDomeDesc));

	//east stairs room
	eastStairsRoomO.push_back(Object("Walls", eStairsWallsDesc));
	eastStairsRoomO.push_back(Object("Canister", eStairsCanisterDesc));
	eastStairsRoomO.push_back(Object("Device", eStairsDeviceDesc));
	eastStairsRoomO.push_back(Object("East Stairs", eStairsEastStairsDesc));
	eastStairsRoomO.push_back(Object("West Door", westDoorDesc));
	eastStairsRoomO.push_back(Object("North Door", northDoorDesc));


	//red room
	redRoomO.push_back(Object("Walls", bareWalls));
	redRoomO.push_back(Object("Bulb", redRoomBulbDesc));
	redRoomO.push_back(Object("Device", redRoomDeviceDesc));
	redRoomO.push_back(Object("East Door", eastDoorDesc));
	redRoomO.push_back(Object("South Door", southDoorDesc));
	redRoomO.push_back(Object("North Door", northDoorDesc));

	//med bay
	medicalBayO.push_back(Object("Walls", medBayWallsDesc));
	medicalBayO.push_back(Object("Container", medBayBoxDesc, true, false, false));
	medicalBayO.at(1).altDesc = keyBoxAlt;
	medicalBayO.push_back(Object("Table", medBayTableDesc));
	medicalBayO.push_back(Object("Surgical Equipment", medBaySurgEqupDesc));
	medicalBayO.push_back(Object("South Door", southDoorDesc));

	//west stairs room
	westStairsRoomO.push_back(Object("Walls", wStairsWallsDesc));
	westStairsRoomO.push_back(Object("West Stairs", wStairsWestStairsDesc));
	westStairsRoomO.push_back(Object("Pipes", wStairsPipesDesc));
	westStairsRoomO.push_back(Object("North Door", northDoorDesc));
	westStairsRoomO.push_back(Object("East Door", eastDoorDesc));

	//green room
	greenRoomO.push_back(Object("Walls", greenRoomWallsDesc));
	greenRoomO.push_back(Object("Bulb", greenRoomBulbDesc));
	greenRoomO.push_back(Object("Circut Board", greenRoomCircutBoardDesc));
	greenRoomO.push_back(Object("Strip", greenRoomStripDesc));
	greenRoomO.push_back(Object("North Door", northDoorDesc));
	greenRoomO.push_back(Object("South Door", southDoorDesc));
	greenRoomO.push_back(Object("West Door", westDoorDesc));

	//empty room
	emptyRoomO.push_back(Object("Walls", bareWalls));
	emptyRoomO.push_back(Object("East Door", eastDoorDesc));
	emptyRoomO.push_back(Object("South Door", southDoorDesc));
	emptyRoomO.push_back(Object("West Door", westDoorDesc));

	//engine room
	engineRoomO.push_back(Object("Walls", engineRoomWallsDesc));
	engineRoomO.push_back(Object("Machine", engineRoomMachineDesc));
	engineRoomO.push_back(Object("Piston", engineRoomPistonDesc));
	engineRoomO.push_back(Object("Device", engineRoomDeviceDesc));
	engineRoomO.push_back(Object("North Door", northDoorDesc));

	//storage room
	storageRoomO.push_back(Object("Walls", storageRoomWallsDesc));
	storageRoomO.push_back(Object("Canister", storageRoomCanisterDesc));
	storageRoomO.push_back(Object("Container", storageRoomContainerDesc, false, true, false));
	storageRoomO.at(2).altDesc = keyBoxAlt;
	storageRoomO.push_back(Object("Shelves", storageRoomShelvesDesc));
	storageRoomO.push_back(Object("East Door", eastDoorDesc));

	//laboratory
	laboratoryO.push_back(Object("Walls", labRoomWallsDesc));
	laboratoryO.push_back(Object("Container", labRoomContainerDesc, false, false, true));
	laboratoryO.at(1).altDesc = keyBoxAlt;
	laboratoryO.push_back(Object("Glass Dish", labRoomGlassDishDesc));
	laboratoryO.push_back(Object("Glass Vial", labRoomGlassVialDesc));
	laboratoryO.push_back(Object("Storage", labRoomStorageUnitDesc));
	laboratoryO.push_back(Object("West Door", westDoorDesc));

	//compact room
	compactRoomO.push_back(Object("Walls", bareWalls));
	compactRoomO.push_back(Object("Device", compactRoomDeviceDesc));
	compactRoomO.push_back(Object("Button", compactRoomButtonDesc));
	compactRoomO.push_back(Object("East Stairs", compactRoomEastStairsDesc));
}

//creates each room with its respective vector of objects
void initializeRooms() {
	
	//entry room
	entryRoom = Room("Entry Room", entryDesc, 0); //declare the room. Set name, description, and if access is restricted by a key
	vector<Object> *v = &entryRoomO; //create a pointer to a vector of objects and set it equal to the the address of the list of objects for this room
	entryRoom.addObjects(v); //add the vector of objects to the rooms vector of objects field by passing the pointer to a vector
	roomList.push_back(&entryRoom); //add the address of this room to the list of all rooms
	
	//hallway
	hallway = Room("Hallway", hallDesc, 0);
	v = &hallwayO;
	hallway.addObjects(v);
	roomList.push_back(&hallway);
	
	//control room
	controlRoom = Room("Control Room", controlDesc, 0);
	v = &controlRoomO;
	controlRoom.addObjects(v);
	roomList.push_back(&controlRoom);
	
	//east stairs room
	eastStairsRoom = Room("East Stairs Room", eStairsDesc, 0);
	v = &eastStairsRoomO;
	eastStairsRoom.addObjects(v);
	roomList.push_back(&eastStairsRoom);

	//red room
	redRoom = Room("Red Room", redRoomDesc, 0);
	v = &redRoomO;
	redRoom.addObjects(v);
	roomList.push_back(&redRoom);
	
	//med bay
	medicalBay = Room("Medical Bay", medBayDesc, 0);
	v = &medicalBayO;
	medicalBay.addObjects(v);
	roomList.push_back(&medicalBay);
	
	//west stairs room
	westStairsRoom = Room("West Stairs Room", wStairsDesc, 0);
	v = &westStairsRoomO;
	westStairsRoom.addObjects(v);
	roomList.push_back(&westStairsRoom);
	
	//green room
	greenRoom = Room("Green Room", greenRoomDesc, 1);
	v = &greenRoomO;
	greenRoom.addObjects(v);
	roomList.push_back(&greenRoom);

	//empty room
	emptyRoom = Room("Empty Room", emptyRoomDesc, 0);
	v = &emptyRoomO;
	emptyRoom.addObjects(v);
	roomList.push_back(&emptyRoom);
	
	//engine room
	engineRoom = Room("Engine Room", engineRoomDesc, 0);
	v = &engineRoomO;
	engineRoom.addObjects(v);
	roomList.push_back(&engineRoom);
	
	//storage room
	storageRoom = Room("Storage Room", storageRoomDesc, 0);
	v = &storageRoomO;
	storageRoom.addObjects(v);
	roomList.push_back(&storageRoom);
	
	//laboratory
	laboratory = Room("Laboratory", labRoomDesc, 2);
	v = &laboratoryO;
	laboratory.addObjects(v);
	roomList.push_back(&laboratory);
	
	//compact room
	compactRoom = Room("Compact Room", compactRoomDesc, 3);
	v = &compactRoomO;
	compactRoom.addObjects(v);
	roomList.push_back(&compactRoom);

	//nullRoom
	nullRoom = Room("Null Room"); //room used to represent unavailable room connections
}

//connects all the rooms
void initializeMap() {

	//set every rooms adjacent rooms to a null room
	for (int i = 0; i < roomList.size(); i++) {
		roomList.at(i)->northR = &nullRoom;
		roomList.at(i)->southR = &nullRoom;
		roomList.at(i)->westR = &nullRoom;
		roomList.at(i)->eastR = &nullRoom;
	}

	//set entry room neighbours
	entryRoom.northR = &hallway;
	entryRoom.westR = &westStairsRoom;
	entryRoom.eastR = &eastStairsRoom;

	//set hallway neighbours
	hallway.northR = &controlRoom;
	hallway.southR = &entryRoom;

	//set control room neighbours
	controlRoom.southR = &hallway;

	//set east stairs room neighbours
	eastStairsRoom.northR = &redRoom;
	eastStairsRoom.westR = &westStairsRoom;
	eastStairsRoom.eastR = &entryRoom;

	//set west stairs room neighbours
	westStairsRoom.northR = &greenRoom;
	westStairsRoom.westR = &entryRoom;
	westStairsRoom.eastR = &eastStairsRoom;

	//set red room neighbours
	redRoom.northR = &medicalBay;
	redRoom.southR = &eastStairsRoom;
	redRoom.eastR = &laboratory;

	//set green room neighbours
	greenRoom.northR = &compactRoom;
	greenRoom.southR = &westStairsRoom;
	greenRoom.westR = &emptyRoom;

	//set empty room neightbours
	emptyRoom.eastR = &greenRoom;
	emptyRoom.southR = &engineRoom;
	emptyRoom.westR = &storageRoom;

	//set engine room neighbours
	engineRoom.northR = &emptyRoom;

	//set storage room neighbours
	storageRoom.eastR = &emptyRoom;

	//set compact room neightbours
	compactRoom.southR = &greenRoom;
	compactRoom.eastR = &hallway;

	//set laboratory neighbours
	laboratory.westR = &redRoom;

	//set medical bay neighbours
	medicalBay.southR = &redRoom;
}

//game loop
void gameLoop() {
	
	cout << player.currentRoom.name << endl << player.currentRoom.roomDescript << endl;
	
	//main game loop. exits when you win or quit
	while (!gameOver) {
		cout << endl << "COMMAND: ";
		getline(cin, input);
		
		//check for empty command
		while (input.empty()) {
			cout << "COMMAND: ";
			getline(cin, input);
		}
		//sets command to the command string parsed from input
		command = getCommand(input);

		//check if command is not the only thing in input. If it isn't the only thing, parse the rest and save it in answer
		if (input.compare(command) != 0)
			answer = getAnswer(input, command);

		//check if command entered matches one of the preset commands
		//go command moves the player from one room to the next and displays the new room name and info
		if (strcasecmp(command.c_str(), "go") == 0) {
			Room tmp;
			for (int i = 0; i < player.currentRoom.roomContents.size(); i++) {
				//if the doorway the player inputted is in the current room, make previous room equal to the current room 
				//then make the current room equal to the room in the direction of the inputted answer
				if (strcasecmp(answer.c_str(), player.currentRoom.roomContents.at(i).name.c_str()) == 0 ) {
					//checks for rooms that require keys and if you have the key to enter
					if (canMoveRoom(getNextRoom(answer))) {
						specialUseKeyText();
						tmp = player.currentRoom;
						player.currentRoom = getNextRoom(answer);
						player.lastRoom = tmp;
						break;
					}
					else {
						cout << needKey << endl;
						tmp.name = "-"; //because of the way I check for invalid input, I need to add some value to tmp.name so it doesn't display 'no such passage exists'
						break;
					}
				}
			}

			//if the door you tried to go through doesnt exist in that room
			if (tmp.name.empty())
				cout << "No such passage exitst" << endl;
			else if (tmp.name.compare("-") != 0)
				cout << player.currentRoom.name << endl << player.currentRoom.roomDescript << endl;
		}
		//displays the description of inputted item
		else if (strcasecmp(command.c_str(), "look") == 0) {
			bool valid = false;
			for (int i = 0; i < player.currentRoom.roomContents.size(); i++) {
				//if the object inputted is in this rooms list of objects, display the description
				if (strcasecmp(answer.c_str(), player.currentRoom.roomContents.at(i).name.c_str()) == 0) {
					valid = true;
					cout << player.currentRoom.roomContents.at(i).descript << endl;
					//if the object contains a key, change the text so next time the key is no longer there and add it to your inventory
					//once you take the key, looking at its container provides the alternative text
					if (player.currentRoom.roomContents.at(i).isKey1 ||
							player.currentRoom.roomContents.at(i).isKey2 ||
								player.currentRoom.roomContents.at(i).isKey3) {
						addKey(player.currentRoom.roomContents.at(i));
						player.currentRoom.roomContents.at(i).descript = player.currentRoom.roomContents.at(i).altDesc;
						break;
					}

					//if the object is the final button, initiate the end game sequence
					if (player.currentRoom.roomContents.at(i).name.compare("Button") == 0) {
						pushButton = true;
					}

					//if the object is the control panel and you have already pushed the final button
					if ((player.currentRoom.roomContents.at(i).name.compare("Control Panel") == 0) && pushButton)
						winGameSequence();
				}
			}

			if (!valid)
				cout << "No such object exists in this room" << endl;
		}
		//displays room name and info
		else if (strcasecmp(command.c_str(), "room") == 0) {
			cout << player.currentRoom.name << endl << player.currentRoom.roomDescript << endl;
		}
		//counts current keys and displays that number
		else if (strcasecmp(command.c_str(), "keys") == 0) {
			int i = 0;
			if (player.key1)
				i++;
			if (player.key2)
				i++;
			if (player.key3)
				i++;
			if (i == 1)
				cout << "You have " << i << " key." << endl;
			else
				cout << "You have " << i << " keys." << endl;
		}
		//opens help table
		else if (strcasecmp(command.c_str(), "help") == 0) {
			cout << helpTable << endl;
		}
		//displays the list of interactable objects in the current room
		else if (strcasecmp(command.c_str(), "obj") == 0) {
			int i;
			for (i = 0; i < player.currentRoom.roomContents.size() - 1; i++) {
				cout << player.currentRoom.roomContents.at(i).name << ", ";
			}
			cout << player.currentRoom.roomContents.at(i).name << endl;
		}
		//clears the screen
		else if (strcasecmp(command.c_str(), "clr") == 0) {
			system("CLS");
		}
		//quite the game
		else if (strcasecmp(command.c_str(), "quit") == 0) {
			gameOver = true;
		}
		//displays wrong command message
		else {
			cout << "command not found, try 'help' for a list of available commands" << endl;
		} 

		//if the last button has been pushed, change the description of the control panel in the control room
		if (pushButton)
			ctrlPnlAltText();

	}
}

//splits the players movement answer, saving only the cardinal direction
//returns the room attached to the current room that is in that direction
Room getNextRoom(string s) {

	string sTmp = s.substr(0, s.find(" "));

	if (strcasecmp(sTmp.c_str(), "north") == 0)
		return *player.currentRoom.northR;
	else if (strcasecmp(sTmp.c_str(), "south") == 0)
		return *player.currentRoom.southR;
	else if (strcasecmp(sTmp.c_str(), "east") == 0)
		return *player.currentRoom.eastR;
	else
		return *player.currentRoom.westR;
}

//checks if the room r requires any keys and if you have those keys
bool canMoveRoom(Room r) {

	if (r.needKey1)
		return player.key1;
	else if (r.needKey2)
		return player.key2;
	else if (r.needKey3)
		return player.key3;
	else
		return true;
}

//adds the key in object o to players inventory and removes the key status from object o
//changes the description of the key object to permanently be the alternative text (persists through room changes)
void addKey(Object o) {
	if (o.isKey1) {
		player.key1 = true;
		o.isKey1 = false;
	}
	else if (o.isKey2) {
		player.key2 = true;
		o.isKey2 = false;
	}
	else if (o.isKey3) {
		player.key3 = true;
		o.isKey3 = false;
	}

	//changes the description of the key object to be its alt description by finding that object in the list of 
	//pointers to all rooms and setting the description to alt description.
	//for each room in roomList
	for (int i = 0; i < roomList.size(); i++){
		//if the current room name equals the name of the room in roomList
		if (player.currentRoom.name.compare(roomList.at(i)->name) == 0) {
			//for each object in the list of objects in the room in roomList
			for (int j = 0; j < roomList.at(i)->roomContents.size(); j++) {
				//if object o.name equals the name of the object in the room in roomList
				if (o.name.compare(roomList.at(i)->roomContents.at(j).name) == 0) {
					roomList.at(i)->roomContents.at(j).descript = roomList.at(i)->roomContents.at(j).altDesc;
					break;
				}
			}
		}
	}

}

//checks to see if you are about to enter a room that requires a key to open, and if you are, display that you used your key
void specialUseKeyText() {

	//if you are entering the room that requires key 1 from the outside
	if ((player.currentRoom.name.compare("West Stairs Room") == 0) &&
		(getNextRoom(answer).name.compare("Green Room") == 0))
		cout << "You use key 1 to open the door" << endl;
	//if you are entering the lab
	else if (getNextRoom(answer).name.compare("Laboratory") == 0)
		cout << "You use key 2 to open the door" << endl;
	//if you are entering the compact room
	else if (getNextRoom(answer).name.compare("Compact Room") == 0)
		cout << "You use key 3 to open the door" << endl;
	//if you are entering the hallway from the secret passage in the compact room
	else if ((player.currentRoom.name.compare("Compact Room") == 0) &&
		(getNextRoom(answer).name.compare("Hallway") == 0))
		cout << "The door shuts behind you as you enter the next room. The door seems to vanish into the wall, you cannot go back the way you came." << endl;
}

//will go into the control panel object and change its description to its alt description
void ctrlPnlAltText() {
	//for each room in roomList
	for (int i = 0; i < roomList.size(); i++) {
		//if the current room equals the control room
		if (roomList.at(i)->name.compare("Control Room") == 0) {
			//for each object in the list of objects in the control room
			for (int j = 0; j < roomList.at(i)->roomContents.size(); j++) {
				//if object name equals control panel, change the description
				if (roomList.at(i)->roomContents.at(j).name.compare("Control Panel") == 0) {
					roomList.at(i)->roomContents.at(j).descript = roomList.at(i)->roomContents.at(j).altDesc;
					break;
				}
			}
		}
	}
}

//displays the end game text and decision
void winGameSequence() {
	string in;
	bool done = false;
	cout << endGameQuestion << endl;
	while (!done) {
		cout << "RESPONSE: ";
		getline(cin, in);
		while (in.empty()) {
			cout << endl << "RESPONSE: ";
			getline(cin, in);
		}
		if (strcasecmp(in.c_str(), "take") == 0) {
			done = true;
			system("CLS");
			cout << takeEnd << endl;
			system("Pause");
		}
		else if (strcasecmp(in.c_str(), "leave") == 0) {
			done = true;
			system("CLS");
			cout << leaveEnd << endl;
			system("Pause");
		}
		else
			cout << "Not a valid response" << endl;
	}
	gameOver = true;


}