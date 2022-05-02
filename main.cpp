#include<iostream>
#include<ctime>
using namespace std;


string inventory[4];
int main() {
	cout << "what? where am I? ugh!" << endl;
	cout << "You say to yourself as you wake up, in a confused dazed. you're in a strange room with one window and no door. you analize the room for anythimg to break the window or some other posible way to get out." << endl;
	cout << "You notice a small crak in the wall and start to mess with it. Eventually the wall starts to open like a door and escape the room." << endl;
	cout << "Yay! I'm finaly out!" << endl;
	cout << "Your so happy you escaped that you do a little dancey dance" << endl; 
	cout << "But you are not outside. you are in another room!?" << endl << endl;

		int room = 1;
		char input;
		do {

			switch (room) {
			case 1:
				cout << "You are in room 1. You can go south." << endl;
				cin >> input;
				if (input == 's')
					room = 3;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That not a option!" << endl;
				break;
			case 2:
				cout << "You are in room 2. You can go east." << endl;
				if (inventory[0] != "key") {
					cout << "You pick up a key you found on the ground." << endl;
					inventory[0] = "key";
				}
				cin >> input;
				if (input == 'e')
					room = 3;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That not a option!" << endl;
				break;
			case 3:
				cout << "You are in room 3. You can go south, west, east or back north." << endl;
				cin >> input;
				if (input == 's')
					room = 5;
				else if (input == 'e') {
					if (inventory[0].compare("key") != 0) {
						cout << "You can not enter without a key!" << endl;
					}
					else {
						cout << "You unlocked the door with the key" << endl;
						room = 4;
					}
				}
				else if (input == 'w')
					room = 2;
				else if (input == 'n')
					room = 1;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That not a option!" << endl;
				break;
			case 4:
				cout << "You are in room 4. You can go west." << endl;
				cin >> input;
				if (input == 'w')
					room = 3;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 5:
				if (inventory[1] != "water bottle") {
					cout << "You pick up a water botle you found on the ground." << endl;
					inventory[1] = "water bottle";
				}
				cout << "You are in room 5. You can go back north or forward." << endl;
				cin >> input;
				if (input == 'n')
					room = 3;
				else if (input == 'f')
					room = 6;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 6:
				cout << "You are in room 6. You can go right, left or back." << endl;
				cin >> input;
				if (input == 'r')
					room = 7;
				else if (input == 'l')
					room = 8;
				if (input == 'b')
					room = 5;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 7:
				if (inventory[1] != "Pizza") {
					cout << "You pick up pizza you found on a table in the room." << endl;
					inventory[1] = "Pizza";
				}
				cout << "You are in room 7. You can go forward or right." << endl;
				cin >> input;
				if (input == 'r')
					room = 9;
				else if (input == 'f')
					room = 8;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 8:
				cout << "You are in room 8. You can go left or right." << endl;
				cin >> input;
				if (input == 'l')
					room = 9;
				else if (input == 'r')
					room = 10;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 9:
				cout << "You are in room 9. You can go forward." << endl;
				cin >> input;
				if (input == 'f')
					room = 10;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 10:
				cout << "You are in room 10. You can go back or go through the door." << endl;
				cin >> input;
				if (input == 'b')
					room = 9;
				else if (input == 'd')
					cout << "Your outside!" << endl;
				else if (input == 'i') {
					cout << "inventory ";
					for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
						cout << inventory[i] << " | ";
				}
				else
					cout << "That is not an option!" << endl;
				break;
			}
		} while (input != 'q');
	}
