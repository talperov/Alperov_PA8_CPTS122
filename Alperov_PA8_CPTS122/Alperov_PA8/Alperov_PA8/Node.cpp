#include "Node.h"

Node::Node(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
	//cout << "Destructor Activated" << endl; //Remember to delete this
}

string Node::getData() const
{
	return this->mData;
}

Node*& Node::getLeft()
{
	return this->mpLeft;
}

Node*& Node::getRight()
{
	return this->mpRight;
}

void Node::setData(const string& newData)
{
	mData = newData;
}

void Node::setLeft(Node* newLeft)
{
	mpLeft = newLeft;
}

void Node::setRight(Node* newRight)
{
	mpRight = newRight;
}
