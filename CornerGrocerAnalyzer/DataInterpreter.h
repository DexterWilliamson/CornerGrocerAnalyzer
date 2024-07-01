#ifndef DATAINTERPRETER_H
#define DATAINTERPRETER_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
class DataInterpreter {
private:
	map<string, int> parsedFileData;
	vector<string> rawFileData;
	string filePath;


public:
	DataInterpreter(vector<string> inputData);
	void DisplayRawData();
	map<string, int> GetParsedData();
	void ItemSearch(string itemToSearch);
	void DataCalculator();
};


#endif