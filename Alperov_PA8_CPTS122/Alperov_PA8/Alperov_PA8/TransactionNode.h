#pragma once
#include "Node.h"

class TransactionNode : public Node
{

private:

	int mUnits;


public:

	//Constructor and Destructor
	TransactionNode(string newData = "", int newUnits = 0);
	virtual ~TransactionNode();

	//getters
	int getUnits() const;

	//setters
	void setUnits(int newUnits);

	//members

	void printData() override;
};
