#pragma once
#ifndef WRITEFILE_H
#define WRITEFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileWriter {
private:
	ofstream outFileStream;
	string fileToWrite;
	map<string, int> fileMapData;
public:
	string GetFilePath() {

		return this->fileToWrite;
	}
	void WriteFileData();
	map<string, int> GetFileData() {
		return fileMapData;

	}
	FileWriter(string filePath, map<string, int> mapData);


};




#endif