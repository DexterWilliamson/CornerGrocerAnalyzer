#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
//Including Investment.h so we can use it in our display parameters
using namespace std;
class Display {
public:
	//Defining the different screens in the application
	void MainMenu();
	void ListAllItems(map<string, int> parsedData);
	void ItemSearchScreen();
	
	void ItemFrequencyNumberScreen(map<string, int> parsedData);
	void ItemFrequencyAsteriskScreen(map<string, int>);

	//These are more for helping
	string HeaderTemplate(string title);
	string PrintNTimes(size_t numTimes, char repeatSymbol);
	char GetHeaderSymbol();
	void SetHeaderSymbol(char newChar);
	Display();
	//Display variables to adjust size
	//(not implemented currently) 
private:

	int width;
	int height;
	int minWidth;
	int maxWidth;
	int minHeight;
	int maxHeight;
	char headerSymbol;
};






#endif
