#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Node
{
protected:

	string mData;
	Node* mpLeft;
	Node* mpRight;

private:


public:

	//Constructor and Destructor
	Node(string newData = "");
	virtual ~Node();
		
	//getters
	string getData() const;
	Node*& getLeft();
	Node*& getRight();


	//setters
	void setData(const string& newData);
	void setLeft(Node*  newLeft);
	void setRight(Node*  newRight);

	//members
	virtual void printData() = 0;



};
