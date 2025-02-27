/*
Peter Saye
CS210
Chada Tech Clock
Project 1
*/

#include "clock.h"
#include<iostream>
#include<string>

using namespace std;

int main() {

	// initialize times to -1 
	int h = -1;
	int m = -1;
	int s = -1;
	
	string menu[] = {
		"Add One Hour",
		"Add One Minute",
		"Add One Second",
		"Exit Program"
	};
	int numStrings = 4;
	int width = 30;

	// user enters time and handles error for if they enter an incorrect value
	cout << "Enter a time." << endl;
	cout << "Enter the hours." << endl;
	while (h < 0 || h > 23) {
		cin >> h;
		if (h < 0 || h > 23) {
			cout << "Please enter hours between 0 and 23" << endl;
		}
	}

	cout << "Enter the minutes." << endl;
	while (m < 0 || m > 59) {
		cin >> m;
		if (m < 0 || m > 59) {
			cout << "Please enter minutes between 0 and 59" << endl;
		}
	}

	cout << "Enter the seconds." << endl;
	while (s < 0 || s > 59) {
		cin >> s;
		if (s < 0 || s > 59) {
			cout << "Please enter seconds between 0 and 59" << endl;
		}
	}

	displayClocks(h, m, s);

	//int choice = getMenuChoice(numStrings);

	while (true) {

		//displayClocks(h, m, s);

		printMenu(menu, numStrings, width);

		int choice = getMenuChoice(numStrings);

		if (choice == 1) {
			addOneHour(h);
			displayClocks(h, m, s);
		}
		else if (choice == 2) {
			addOneMinute(h, m);
			displayClocks(h, m, s);
		}
		else if (choice == 3) {
			addOneSecond(h, m, s);
			displayClocks(h, m, s);
		}
		else if (choice == 4) {
			break; // Exit the program
		}
		else if (choice < 1 || choice > 4) {
			cout << "Please enter a number from 1 to 4" << endl << endl;
		}
	}
	return 0;
}