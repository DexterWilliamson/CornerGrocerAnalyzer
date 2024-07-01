#pragma once // Header guard to ensure this header is included only once

#ifndef READFILE_H // Include guard start
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileReader {
private:
    ifstream fileStream;    // Create a file stream to read from a file
    string fileToRead;      // File path to the file
    vector<string> fileData; // Vector to store the data from the file

public:
    // Constructor: to initialize the FileReader with a filepath
    FileReader(string filePath);

    // Eetrieve the file path
    string GetFilePath() {
        return this->fileToRead;
    }

    // Read data from the file
    void ReadFileData();

    // Retrieve the file data vector
    vector<string> GetFileData() const {
        return fileData;
    }

};

#endif 
