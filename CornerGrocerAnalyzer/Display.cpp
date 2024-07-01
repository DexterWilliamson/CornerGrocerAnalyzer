#include "Display.h"
using namespace std;

// Constructor initializes default values for display properties
Display::Display() {
    maxHeight = 1000;   // Maximum height (not actively used in your current implementation)
    maxWidth = 1000;    // Maximum width (not actively used in your current implementation)
    minWidth = 150;     // Minimum width for headers and other formatting
    minHeight = 200;    // Minimum height (not actively used in your current implementation)
    width = 50;         // Width used for header formatting
    height = maxHeight; // Initial height (not actively used in your current implementation)
    headerSymbol = '*'; // Default character used in headers
}

// Main menu display method
void Display::MainMenu() {
    // Menu options stored in a vector for easy access and modification
    vector<string> menuOptions = { "Search Item", "Item Quantity", "Item Quantity Graphed", "Quit" };

    // Display initial greeting and header using HeaderTemplate method
    cout << HeaderTemplate("Welcome to the Corner Grocer Tracking Program!") << endl << endl;

    // Iterate through menuOptions and display each with a formatted index
    for (int i = 0; i < menuOptions.size(); i++) {
        cout << PrintNTimes(5, ' ') << i + 1 << ". " << menuOptions[i] << endl;
    }
}

// Method to list all items from parsedData map
void Display::ListAllItems(map<string, int> parsedData) {
    cout << HeaderTemplate("All Items!") << endl;
    cout << PrintNTimes(minWidth, '=') << endl;

    // Iterate through parsedData and print each item
    for (auto it = parsedData.begin(); it != parsedData.end(); ++it) {
        cout << it->first << endl;
    }
}

// Display screen for item search prompt
void Display::ItemSearchScreen() {
    cout << HeaderTemplate("Item Search!") << endl;
    cout << PrintNTimes(minWidth, '=') << endl;
    cout << "Search for item (type -l to list all items): ";
}

// Display screen for item frequency numbers
void Display::ItemFrequencyNumberScreen(map<string, int> parsedData) {
    cout << "Item Quantity Screen!" << endl;
    cout << HeaderTemplate("Item Quantity Screen!") << endl;
    cout << PrintNTimes(minWidth, '=') << endl;

    // Iterate through parsedData and print each item with its quantity
    for (auto it = parsedData.begin(); it != parsedData.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

// Display screen for item frequency histogram
void Display::ItemFrequencyAsteriskScreen(map<string, int> parsedData) {
    cout << HeaderTemplate("Histogram Screen!") << endl;
    cout << PrintNTimes(minWidth, '=') << endl;

    // Iterate through parsedData and print each item with a bar of '*' characters based on its quantity
    for (auto it = parsedData.begin(); it != parsedData.end(); ++it) {
        cout << it->first << " " << PrintNTimes(it->second, '*') << endl;
    }
    cout << endl;
}

// Method to format a header string with a centered title
string Display::HeaderTemplate(string title) {
    size_t headerSection = (width - title.size()) / 2;
    return PrintNTimes(headerSection, headerSymbol) + " " + title + " " + PrintNTimes(headerSection, headerSymbol);
}

// Method to repeat a character 'numTimes' and return as a string
string Display::PrintNTimes(size_t numTimes, char repeatSymbol) {
    return string(numTimes, repeatSymbol);
}

// Getter for headerSymbol
char Display::GetHeaderSymbol() {
    return headerSymbol;
}

// Setter for headerSymbol
void Display::SetHeaderSymbol(char newChar) {
    headerSymbol = newChar;
}
