#include "DataAnalysis.h"

void DataAnalysis::OpenStream()
{
	mCsvStream.open("data.csv");

	if (!mCsvStream.is_open())
	{
		cout << "Error Opening data.csv" << endl;
		return;
	}
	else
	{
		cout << "data.csv Opened Successfuly" << endl;
	}
}

void DataAnalysis::OneLineReader(int& units, string& type, string& transaction)
{
	char line[100];

	mCsvStream.getline(line, 100, ',');
	units = atoi(line);

	mCsvStream.getline(line, 100, ',');
	type = line;

	mCsvStream.getline(line, 100, ',');
	transaction = line;	

}

void DataAnalysis::AllLineReader()
{
	int units;
	string type;
	string transaction;
	string line;

	// Skip header line
	getline(mCsvStream, line);

	while (getline(mCsvStream, line))
	{
		InitializeVariables(units, type, transaction);

		stringstream lineStream(line);
		string token;

		if (getline(lineStream, token, ','))
		{
			units = stoi(token);
		}

		if (getline(lineStream, token, ','))
		{
			type = token;
		}

		if (getline(lineStream, token, ','))
		{
			transaction = token;
		}

		if (transaction == "Purchased" || transaction == "Sold")
		{
			TreeInserter(units, type, transaction);
		}
	}
}

void DataAnalysis::TreeInserter(int units, string& type, string& transaction)
{
	if (transaction == "Purchased")
	{
		mTreePurchased.insert(units, type);
	}
	else if (transaction == "Sold")
	{
		mTreeSold.insert(units, type);
	}
	
}

void DataAnalysis::DisplayTree()
{
	cout << "Purchased Order Transaction: In Order" << endl;
	mTreePurchased.inOrderTraversal();

	cout << "Sold Order Transaction: In Order" << endl;
	mTreeSold.inOrderTraversal();
}

void DataAnalysis::InitializeVariables(int& units, string& type, string& transaction)
{
	units = 0;
	type = "";
	transaction = "";
}

void DataAnalysis::runAnalysis()
{
	OpenStream();

	AllLineReader();

	DisplayTree();

	cout << "Trends for the Time Wanted: " << endl;

	cout << "Most Purchased: "; mTreePurchased.findLargest().printData();

	cout << "Least Purchased: "; mTreePurchased.findSmallest().printData();

	cout << "Most Sold: "; mTreeSold.findLargest().printData();

	cout << "Least Sold: "; mTreeSold.findSmallest().printData();
}
