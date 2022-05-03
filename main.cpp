#include<iostream>
#include<ctime>
using namespace std;

//global variables
int health = 100;
string inventory[4];

//function declarations
void Puzzle();


int main() {
	cout << "what? where am I? ugh!" << endl;
	cout << "You say to yourself as you wake up, in a confused dazed. you're in a strange room with one window and no door. you analize the room for anythimg to break the window or some other posible way to get out." << endl;
	cout << "You notice a small crak in the wall and start to mess with it. Eventually the wall starts to open like a door and escape the room." << endl;
	cout << "Yay! I'm finaly out!" << endl;
	cout << "Your so happy you escaped that you do a little dancey dance" << endl; 
	cout << "But you are not outside. you are in another room!?" << endl << endl;

	//local variables
		int room = 1;
		char input;
		do {
			//stuff here happens EVERY turn
			cout << "Your health is now " << health << endl;
			cout << "inventory ";
			for (int i = 0; i < 4; i++)//for loop that prints out inventory slots
				cout << inventory[i] << " | ";

			switch (room) {
			case 1:
				cout << "You are in room 1. You can go south." << endl;
				cin >> input;
				if (input == 's')
					room = 3;
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
				else
					cout << "That not a option!" << endl;
				break;
			case 4:
				cout << "You are in room 4. You can go west." << endl;
				cin >> input;
				if (input == 'w')
					room = 3;
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
				else
					cout << "That is not an option!" << endl;
				break;
			case 9:
				cout << "You are in room 9. You can go forward." << endl;
				cin >> input;
				if (input == 'f')
					room = 10;
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
				else
					cout << "That is not an option!" << endl;
				break;
			}
		} while (input != 'q' || health <= 0);
		//end of the game!
		if (health <= 0)
			cout << "you died." << endl;
	}//end of main


	//function definitions
	void Puzzle() {
		string input;
		cout << "A mysterious little doll appears in the coner of the room and talks to you!?" << endl;
		int num = rand() % 100 + 1; //gets a number between 1-100
		if (num < 20) {
			cout << "What has to be broken before you can use it?" << endl;
			cin >> input;
			if (input.compare("an egg") == 0 || input.compare("egg") == 0)
				cout << "darn you got it";
			else {
				cout << "WRONG!" << endl;
				health -= 10;
			}
		}
		else if (num < 40) {
			cout << "I am scary, and when you have more of me, you will see only less. What am I?" << endl;
			cin >> input;
			if (input.compare("the dark") == 0 || input.compare("darkness") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "HAAAAAAA! You got it wrong!" << endl;
				health -= 20;
			}
		}
		else if (num < 50) {
			cout << "What tastes better than it smells?" << endl;
			cin >> input;
			if (input.compare("the tongue") == 0 || input.compare("your tongue") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "HAAAAAAA! You got it wrong!" << endl;
				health -= 30;
			}
		}
		else if (num < 70) {
			cout << "When is a door no longer a door?" << endl;
			cin >> input;
			if (input.compare("when it's ajar") == 0 || input.compare("when the door is ajar") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "HAAAAAAA! You got it wrong!" << endl;
				health -= 40;
			}
		}
		else if (num < 90) {
			cout << "What has 13 hearts but no other organs?" << endl;
			cin >> input;
			if (input.compare("a deck of cards") == 0 || input.compare("deck of cards") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "HAAAAAAA! You got it wrong!" << endl;
				health -= 50;
			}
		}
		else
			cout << "Which word in the dictionary is spelled incorrectly?" << endl;
			cin >> input;
			if (input.compare("incorrectly") == 0 || input.compare("the word incorrectly") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "HAAAAAAA! You got it wrong!" << endl;
				health -= 20;
			}
	}
