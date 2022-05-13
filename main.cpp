#include<iostream>
#include<ctime>
#include<string>
using namespace std;

//global variables---------------------------------------------------------------------------
int health = 100;
string inventory[8];

//function declarations---------------------------------------------------------------------
void Puzzle();
void Dropper();

//start of main---------------------------------------------------------------------------------
int main() {
	cout << "what? where am I? ugh!" << endl;
	cout << "You say to yourself as you wake up, in a confused dazed. you're in a strange room with one window and no door. you analize the room for anythimg to break the window or some other posible way to get out." << endl;
	cout << "You notice a small crak in the wall and start to mess with it. Eventually the wall starts to open like a door and escape the room." << endl;
	cout << "Yay! I'm finaly out!" << endl;
	cout << "Your so happy you escaped that you do a little dancey dance" << endl; 
	cout << "But you are not outside. you are in another room!?" << endl << endl;

	//local variables-----------------------------------------------------------------------------------
		int room = 1;
		string input;
		
	//stuff here happens EVERY turn----------------------------------------------------------------------------------------
		do {
			cout << "Your health is now " << health << endl;
			cout << "inventory ";

			for (int i = 0; i < 8; i++)//for loop that prints out inventory slots
				cout << inventory[i] << " | ";

			if (inventory[2] == "potion") {
				cout << "Press p to use a potion, any other key to continue" << endl;
				getline(cin, input);
				if (input == "p")
					cout << "You drink the potion for 20 health" << endl;
					health += 20;
					inventory[2] = " ";
			}

			if (inventory[5] == "water bottle") {
				cout << "Press w to use a water bottle, any other key to continue." << endl;
				getline(cin, input);
				if (input == "w")
					cout << "You drink the water bottle for 10 health." << endl;
				health += 10;
				inventory[5] = " ";
			}

			if (inventory[6] == "sandwich") {
				cout << "Press s to use the sandwich, any other key to continue." << endl;
				getline(cin, input);
				if (input == "s")
					cout << "You eat the sandwich for 30 health." << endl;
				health += 30;
				inventory[6] = " ";
			}
			
			
			Dropper();

			//Rooms------------------------------------------------------------------------------------------------------------------------------
			switch (room) {
			case 1:
				Puzzle();
				cout << "You are in a wet old looking dungeon. You can go south." << endl;
				getline(cin, input);
				if (input == "s")
					room = 3;
				else
					cout << "That not a option!" << endl;
				break;
			case 2:
				Puzzle();
				cout << "You are in crusty nasty looking bathroom. You can go east." << endl;
				if (inventory[0] != "key") {
					cout << "You pick up a key you found on the ground." << endl;
					inventory[0] = "key";
				}
				getline(cin, input);
				if (input == "e")
					room = 3;
				else
					cout << "That not a option!" << endl;
				break;
			case 3:
				Puzzle();
				cout << "You are in an hallway looking room. You can go south, west, east or back north." << endl;
				getline(cin, input);
				if (input == "e")
					room = 4;
				else if (input == "s") {
					if (inventory[0].compare("key") != 0) {
						cout << "You can not enter without a key!" << endl;
					}
					else {
						cout << "You unlocked the door with the key" << endl;
						room = 5;
					}
				}
				else if (input == "w")
					room = 2;
				else if (input == "n")
					room = 1;
				else
					cout << "That not a option!" << endl;
				break;
			case 4:
				Puzzle();
				cout << "You are in the kitchen with food all over the walls and floor. You can go west or southwest." << endl;
				getline(cin, input);
				if (input == "w")
					room = 3;
				else if (input == "sw")
					room = 5;
				else
					cout << "That is not an option!" << endl;
				break;
			case 5:
				Puzzle();
				cout << "You are in emty room with bright pink walls. You can go south or north." << endl;
				getline(cin, input);
				if (input == "s")
					room = 3;
				else if (input == "n")
					room = 6;
				else
					cout << "That is not an option!" << endl;
				break;
			case 6:
				Puzzle();
				cout << "You are in a living room that has slimy looking red stuff oozing from the walls. You can go east, west or north." << endl;
				getline(cin, input);
				if (input == "e")
					room = 7;
				else if (input == "w")
					room = 8;
				if (input == "n")
					room = 5;
				else
					cout << "That is not an option!" << endl;
				break;
			case 7:
				Puzzle();
				cout << "You are in a room full of teddy bears. You can go south or west" << endl;
				getline(cin, input);
				if (input == "w")
					room = 6;
				else if (input == "s") {
					if (inventory[0].compare("kitten") != 0) {
						cout << "The gremlin bloking the door tells you." << endl;
						cout << "You can not enter without a kitten!" << endl;
					}
					else {
						cout << "You gave the gremlin blocking the door a kitten and they let you through." << endl;
						room = 10;
					}
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 8:
				Puzzle();
				cout << "You are in a bouncy castle room. You can go southeast or north." << endl;
				getline(cin, input);
				if (input == "n")
					room = 2;
				else if (input == "se")
					room = 9;
				else
					cout << "That is not an option!" << endl;
				break;
			case 9:
				Puzzle();
				cout << "You are in an old creepy laboratory. You can go east south or west north." << endl;
				getline(cin, input);
				if (input == "wn")
					room = 8;
				else if (input == "es") {
					if (inventory[0].compare("mini doll") != 0) {
						cout << "You can not enter without your mini doll!" << endl;
					}
					else {
						cout << "You put the mini doll in the box next to the door and the door opens." << endl;
						room = 10;
					}
				}
				else
					cout << "That is not an option!" << endl;
				break;
			case 10:
				Puzzle();
				cout << "You are in a normal looking room that has a big red door. You can go northwest, north or go through the door." << endl;
				getline(cin, input);
				if (input == "nw")
					room = 9;
				else if (input == "n")
					room = 7;
				else if (input == "d")
					room = 11;
				else
					cout << "That is not an option!" << endl;
				break;
			case 11:
				cout << "You made it out and kiss the ground. So happy to be outside. But are you really outside." << endl;
				cout << "Game over!" << endl;
				break;
			}//end of rooms
		} while (input != "q" && health >= 0);
		//end of the game!
		if (health >= 0)
			cout << "you died." << endl;
	}//end of main


	//function definitions-------------------------------------------------------------------------------------------------------------------
	void Puzzle() {
		string input;
		cout << "A mysterious little doll appears in the coner of the room and talks to you!?" << endl;
		int num = rand() % 100 + 1; //gets a number between 1-100

		if (num < 20) {
			cout << "What has to be broken before you can use it?" << endl;
			getline(cin, input);
			if (input.compare("an egg") == 0 || input.compare("egg") == 0)
				cout << "darn you got it!";
			else {
				cout << "Oh Nooo! You got it wrong. The doll attacks you for 10 health!" << endl;
				health -= 10;
			}
		}
		else if (num < 40) {
			cout << "I am scary, and when you have more of me, you will see only less. What am I?" << endl;
			getline(cin, input);
			if (input.compare("the dark") == 0 || input.compare("darkness") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "Oh Nooo! You got it wrong. The doll attacks you for 20 health!" << endl;
				health -= 20;
			}
		}
		else if (num < 50) {
			cout << "What tastes better than it smells?" << endl;
			getline(cin, input);
			if (input.compare("a tongue") == 0 || input.compare("the tongue") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "Oh Nooo! You got it wrong. The doll attacks you for 30 health!" << endl;
				health -= 30;
			}
		}
		else if (num < 70) {
			cout << "When is a door no longer a door?" << endl;
			getline(cin, input);
			if (input.compare("when it's ajar") == 0 || input.compare("when the door is ajar") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "Oh Nooo! You got it wrong. The doll attacks you for 40 health!" << endl;
				health -= 40;
			}
		}
		else if (num < 90) {
			cout << "What has 13 hearts but no other organs?" << endl;
			getline(cin, input);
			if (input.compare("a deck of cards") == 0 || input.compare("deck of cards") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "Oh Nooo! You got it wrong. The doll attacks you for 50 health!" << endl;
				health -= 50;
			}
		}
		else {
			cout << "Which word in the dictionary is spelled incorrectly?" << endl;
			getline(cin, input);
			if (input.compare("incorrectly") == 0 || input.compare("the word incorrectly") == 0)
				cout << "how'd you figure its out!";
			else {
				cout << "Oh Nooo! You got it wrong. The doll attacks you for 20 health!" << endl;
				health -= 20;
			}
		}
	}//end of puzzle

	void Dropper() {
		int num = rand() % 100 + 1; //gets a number between 1-100

		if (num < 30) {
			cout << "You got a mini doll of you!" << endl;
			inventory[1] = "mini doll";
		}
		else if (num < 40) {
			cout << "You got a potion!" << endl;
			inventory[2] = "potion";
		}
		else if (num < 50) {
			cout << "You got a kitten!" << endl;
			inventory[3] = "kitten";
		}
		else if (num < 60) {
			cout << "You got a tv remote!" << endl;
			inventory[4] = "tv remote";
		}
		else if (num < 70) {
			cout << "You got a water bottle!" << endl;
			inventory[5] = "water bottle";
		}
		else if (num < 80) {
			cout << "You got a sandwich!" << endl;
			inventory[6] = "sandwich";
		}
		else if (num < 90) {
			cout << "You got a poisoned apple!" << endl;
			inventory[7] = "poisoned apple";
			health -= 10;
		}
		else {
			cout << "You got nothing! :p" << endl;
		}
	}//end of dropper 
