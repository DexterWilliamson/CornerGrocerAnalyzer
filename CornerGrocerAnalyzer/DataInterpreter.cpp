#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "DataInterpreter.h"

using namespace std;

// Constructor: initializes rawFileData with inputData and calls DataCalculator()
DataInterpreter::DataInterpreter(vector<string> inputData) {
    this->rawFileData = inputData;
    DataInterpreter::DataCalculator(); // Calculate parsed data frequencies
}

// DisplayRawData method: prints each item in rawFileData
void DataInterpreter::DisplayRawData() {
    for (int i = 0; i < rawFileData.size(); i++) {
        cout << rawFileData[i] << endl;
    }
}

// GetParsedData method: returns parsedFileData (map of item frequencies)
map<string, int> DataInterpreter::GetParsedData() {
    return parsedFileData;
}

// ItemSearch method: searches for itemToSearch in parsedFileData and prints its quantity
void DataInterpreter::ItemSearch(string itemToSearch) {
    map<string, int>::iterator it = parsedFileData.find(itemToSearch);

    if (it != parsedFileData.end()) {
        cout << "Item: " << it->first << " || Quantity: " << it->second;
    }
    else {
        cout << "Item not found in list";
    }
    cout << endl;
}

// DataCalculator method: calculates frequencies of items in rawFileData
void DataInterpreter::DataCalculator() {
    for (int i = 0; i < rawFileData.size(); i++) {
        if (parsedFileData.find(rawFileData[i]) != parsedFileData.end()) {
            parsedFileData[rawFileData[i]] += 1; // Increment count if item exists
        }
        else {
            parsedFileData[rawFileData[i]] = 1;  // Initialize count if item does not exist
        }
    }
}
