// Peter Saye
// CS-210 Programming Languages
// Corner Grocer
// Faisal Shakeel

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const int MAX_ITEMS = 100;

// Create the backup file
void createBackupFile(string items[], int frequencies[], int size) {

    // Output file stream
    ofstream outFS;

    // Open file
    outFS.open("frequency.dat");

    if (!outFS.is_open()) {
        cout << "Could not open file frequency.dat." << endl;
        return;
    }

    // Write to file
    for (int i = 0; i < size; i++) {
        outFS << items[i] << " " << frequencies[i] << endl;
    }

    // Close file
    outFS.close();
}

// load data from file into arrays
void loadItemData(string items[], int frequencies[], int& size) {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile.is_open()) {
        cout << "Unable to open input file." << endl;
        return;
    }

    string item;
    
    while (inputFile >> item) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (items[i] == item) {
                frequencies[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            items[size] = item;
            frequencies[size] = 1;
            size++;
        }
    }

    inputFile.close();
}

// search for an item frequency
int getItemFrequency(string item, string items[], int frequencies[], int& size) {
    for (int i = 0; i < size; i++) {
        if (items[i] == item) {
            return frequencies[i];
        }
    }
    return 0;
}

// display all items and there frequencies
void printItemList(string items[], int frequencies[], int& size) {
    cout << endl << "Item Frequency List: " << endl;
    for (int i = 0; i < size; i++) {
        cout << items[i] << " " << frequencies[i] << endl;
    }
}

// display histogram
void printHistogram(string items[], int frequencies[], int& size) {
    cout << endl << "Item Frequency Histogram : " << endl;
    for (int i = 0; i < size; i++) {
        cout << items[i] << " ";
        for (int j = 0; j < frequencies[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to display menu
void displayMenu() {
    cout << endl << "Corner Grocer Item Tracker" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Search for an item's frequency" << endl;
    cout << "2. Display all items and their frequency" << endl;
    cout << "3. Display histogram of item frequencies" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: " << endl;
}

int main() {
    string items[MAX_ITEMS];
    int frequencies[MAX_ITEMS] = { 0 };
    int size = 0;

  
    loadItemData(items, frequencies, size);
    createBackupFile(items, frequencies, size);

    int choice;
    string item;

    while (true) {
        displayMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();                 // Clear error
            cin.ignore(10000, '\n');     // Ignore invalid input
            cout << "Wrong input. Please enter a number between 1 and 4." << endl;
            continue;
        }


        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;

            if (!item.empty()) {
                item[0] = toupper(item[0]);
            }
            cout << endl << "Frequency of " << item << ": " << 
                getItemFrequency(item, items, frequencies, size) << endl;
            break;
        case 2:
            printItemList(items, frequencies, size);
            break;
        case 3:
            printHistogram(items, frequencies, size);
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Wrong input. Please enter a number between 1 and 4." << endl;
            break;
        }
		if (choice == 4) {
			break;
		}
    }

    return 0;
}