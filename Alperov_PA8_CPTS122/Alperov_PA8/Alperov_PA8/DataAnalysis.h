#pragma once

#include "BST.h"

#include <fstream>
#include <string>
#include <sstream>

using std::stringstream;
using std::ifstream;
using std::getline;

class DataAnalysis
{
private:

	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	//helpers functions
	void OpenStream(); 
	void OneLineReader(int& units, string& type, string& transaction); 
	void AllLineReader();
	void TreeInserter(int units, string& type, string& transaction);
	void DisplayTree();
	void InitializeVariables(int& units, string& type, string& transaction); //Helper for functions

public:

	//Constructor and Destructor // Not needed
	//DataAnalysis();
	//~DataAnalysis();

	//getters

		//none needed
	
	//setters

		//none needed

	//members
	void runAnalysis();

};
