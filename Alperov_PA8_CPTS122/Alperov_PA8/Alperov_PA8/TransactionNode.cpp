#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData)
{
	mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{
	//cout << "Destructor Activated" << endl; //Remember to delete this
}

int TransactionNode::getUnits() const
{
	return this->mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

void TransactionNode::printData()
{
	cout << mData << ": " << mUnits << endl;
}
