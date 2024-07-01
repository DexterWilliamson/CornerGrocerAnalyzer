#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ReadFile.h" // Assuming this header defines FileReader

using namespace std;

// Constructor to initialize with a file path and then read the path
FileReader::FileReader(string filePath)
{
    this->fileToRead = filePath; // Store the file path
    FileReader::ReadFileData();  // Read the file
}

//Read data from the file
void FileReader::ReadFileData() {
    string item; // Variable for each item read from the file

    fileStream.open(this->fileToRead); // Open the file

    if (!fileStream.is_open()) { // Check if the file opening failed
        cout << "Could not open file " << this->fileToRead << "." << endl;
        return; // Exit if file failed
    }

    while (!fileStream.fail()) { // Loop until end of file or read failure
        fileStream >> item; // Read an item from the file into the 'item' variable

        if (fileStream.fail()) { // Check if reading the item failed
            cout << item << " not found" << endl; // Output error message
        }
        else {
            fileStream.ignore(); // Ignore any characters after the word
        }

        fileData.push_back(item); // Store the item into the vector 'fileData'
    }

    fileStream.close(); // Close the fileg

}


// Note: Make sure 'fileData' and other private members are properly declared in your header file (ReadFile.h)
