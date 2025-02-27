#pragma once
#include <string>
#include <iostream>

using namespace std;


// Make sure the numbers are 2 digits long
string twoDigitString(int n) {
    string digits;
    if (n <= 9 && n >= 0) {
        digits = "0" + to_string(n);
        return digits;
    }
    return to_string(n);
}

// 
string nCharString(int n, char c) {
    return string(n, c);
}

// Output time in 24 hour format
string formatTime24(int h, int m, int s) {
    string clock24;

    clock24 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
    return clock24;
}

// Output time in 12 hour format
string formatTime12(int h, int m, int s) {
    string clock12;
    string timePeriod;

    if (h == 0 || h == 24) {
        timePeriod = "A M";
        h = 12;
    }
    else if (h > 12) {
        timePeriod = "P M";
        h = h - 12;
    }
    else if (h == 12) {
        timePeriod = "P M";
    }
    else {
        timePeriod = "A M";
    }
    clock12 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + timePeriod;

    return clock12;
}

// Prints out the menu
void printMenu(string strings[], int numStrings, int width) {
    cout << nCharString(width, '*') << endl;
    for (int i = 0; i < numStrings; ++i) {
        int contentLength = 6 + strings[i].length();

        cout << "* " << i + 1 << " - " << strings[i];
        for (int j = 0; j < (width - contentLength - 1); ++j) {
            cout << " ";
        }
        cout << "*" << endl;
    }
    cout << nCharString(width, '*') << endl;
}


// Menu Choice
int getMenuChoice(int maxChoice) {
    int choice = 0;

    while (choice < 1 || choice > 4) {
        cin >> choice;
        if (choice >= 1 || choice <= maxChoice) 
        return choice;
    }
}


// Display both clocks
void displayClocks(int h, int m, int s) {
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << "*      12-HOUR CLOCK      *   ";
    cout << "*      24-HOUR CLOCK      *" << endl;
    cout << endl;
    cout << "*      " << formatTime12(h, m, s) << "       *   ";
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}


// add an hour
void addOneHour(int& h) {

    int currentHour = h;

    if (currentHour >= 0 && currentHour <= 22) {
        h = (currentHour + 1);
    }
    else if (currentHour == 23) {
        h = 0;
    }
}

// add a minute
void addOneMinute(int& h, int& m) {

    int currentMinute = m;

    if (currentMinute >= 0 && currentMinute <= 58) {
        m = (currentMinute + 1);
    }
    else if (currentMinute == 59) {
        m = 0;
        addOneHour(h);
    }
}

// add a second
void addOneSecond(int& h, int& m, int& s) {

    int currentSecond = s;

    if (currentSecond >= 0 && currentSecond <= 58) {
        s = (currentSecond + 1);
    }
    if (currentSecond == 59) {
        s = 0;
        addOneMinute(h, m);
    }
}


