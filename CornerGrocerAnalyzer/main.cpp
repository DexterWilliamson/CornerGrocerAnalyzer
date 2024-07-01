#include <iostream>
#include <string>
#include "Display.h"
#include "DataInterpreter.h"
#include "ReadFile.h"
#include "WriteFile.h"
using namespace std;

int main() {
    // Setting the filePath and backupFilePath for easy reference.
    string filePath = "CS210_Project_Three_Input_File.txt";
    string backupFilePath = "frequency.dat";

    // Create a new Display instance that will control the menus
    Display newDisplay;

    // Create objects for file reading, data interpretation, and file writing
    FileReader* fileReader;
    DataInterpreter* newInterpreter;
    FileWriter* fileWriter;

    // Initialize fileReader with filePath
    fileReader = new FileReader(filePath);

    // Initialize newInterpreter with data from fileReader
    newInterpreter = new DataInterpreter(fileReader->GetFileData());

    // Initialize fileWriter with backupFilePath and parsed data from newInterpreter
    fileWriter = new FileWriter(backupFilePath, newInterpreter->GetParsedData());

    // Clean up resources
    delete fileReader;
    delete fileWriter;

    int userIntInput = 0;
    string userStringInput;

    // Main loop for menu interaction
    while (userIntInput != 4) {
        newDisplay.MainMenu();

        cin >> userIntInput;

        // Validate user input and display a message about the failure.
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            //Clear cin and ignore the rest of the stream
            cin.clear();
            cin.ignore();

            //Reset userIntInput to 0
            userIntInput = 0;
        }

        switch (userIntInput) {
        case 1:
            // Case for Item Search
            newDisplay.ItemSearchScreen();
            cin >> userStringInput;

            //Just some help for the user so they can see the available items
            //This will also keep asking for the userInput as long as they
            //Input -l
            while (userStringInput == "-l") {
                
                newDisplay.ListAllItems(newInterpreter->GetParsedData());
                
                newDisplay.ItemSearchScreen();
                cin >> userStringInput;
            }

            //Use the DataIntepreter to search for the item
            newInterpreter->ItemSearch(userStringInput);
            
            break;

        case 2:
            // Case for Item Frequency Number
            newDisplay.ItemFrequencyNumberScreen(newInterpreter->GetParsedData());
           
            break;

        case 3:
            // Case for Item Frequency Asterisk
            newDisplay.ItemFrequencyAsteriskScreen(newInterpreter->GetParsedData());
            break;

        case 4:
            // Exit case
            break;

        default:
            // Default case for unrecognized input
            cout << "Input not recognized" << endl;
            break;
        }

        cin.clear(); // Clear any error flags on cin
    }

    return 0;
}
