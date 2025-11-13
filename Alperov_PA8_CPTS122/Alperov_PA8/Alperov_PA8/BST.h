#pragma once

#include "TransactionNode.h"


class BST
{
private:

	Node* mpRoot;

	void destroyTree(Node* pT);//helper function
	void insert(Node*& pT, TransactionNode* newNode); //helper function
	void inOrderTraversal(Node* pT); // helper function
	TransactionNode& findSmallest(Node*& pT);
	TransactionNode& findLargest(Node*& pT);


public:

	//Constructor and Destructor
	BST();
	~BST();

	//getters
	Node* getRoot() const;

	//setters
	void setRoot(Node* const newRoot);

	//members
	void insert(int newUnits, string newData);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

};