#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "WriteFile.h"

using namespace std;

// Constructor: initializes the filePath and mapData, then calls WriteFileData()
FileWriter::FileWriter(string filePath, map<string, int> mapData)
{
    this->fileToWrite = filePath; // Store the file path
    this->fileMapData = mapData;  // Store the map data

    WriteFileData(); // Call the function to write data to file
}

// Function to write data from map to file
void FileWriter::WriteFileData()
{
    outFileStream.open(this->fileToWrite); // Open the file specified by filePath

    // Check if file opened successfully
    if (!outFileStream.is_open()) {
        cout << "Could not open file " << this->fileToWrite << "." << endl;
    }
    else {
        // Iterate through the map and write each pair to the file
        map<string, int>::iterator it = this->fileMapData.begin();

        while (it != this->fileMapData.end() && !outFileStream.fail()) {
            // Check for write failures
            if (outFileStream.fail()) {
                cout << "Couldn't write item name" << endl;
            }
            else {
                // Write the current pair (key and value) to the file
                outFileStream << it->first << " " << it->second << endl;
            }
            ++it; // Move to the next pair in the map
        }
    }

    outFileStream.close(); // Close the file stream
}
