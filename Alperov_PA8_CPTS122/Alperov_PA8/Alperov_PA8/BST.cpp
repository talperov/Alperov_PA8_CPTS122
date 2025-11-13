#include "BST.h"

void BST::destroyTree(Node* pT)
{
	if (pT != nullptr)
	{
		destroyTree(pT->getLeft());
		destroyTree(pT->getRight());
		delete pT;
	}
}

void BST::insert(Node*& pT, TransactionNode* newNode)
{
	if (pT == nullptr)
	{
		pT = newNode;
	}
	else
	{
		TransactionNode* pCur = dynamic_cast<TransactionNode*>(pT);

		if (newNode->getUnits() < pCur->getUnits())
		{
			insert(pT->getLeft(), newNode);
		}
		else if (newNode->getUnits() > pCur->getUnits())
		{
			insert(pT->getRight(), newNode);
		}
	}
}

void BST::inOrderTraversal(Node* pT)
{
	if (pT != nullptr)
	{
		inOrderTraversal(pT->getLeft());

		TransactionNode* pCur = dynamic_cast<TransactionNode*>(pT);
		if (pCur)
		{
			pCur->printData();
		}

		inOrderTraversal(pT->getRight());
	}
}


TransactionNode& BST::findSmallest(Node*& pT)
{
	if (pT->getLeft() == nullptr)
	{
		TransactionNode* pCur = dynamic_cast<TransactionNode*>(pT);
		
		return *pCur;
	}
	else
	{
		return findSmallest(pT->getLeft());
	}
}

TransactionNode& BST::findLargest(Node*& pT)
{
	if (pT->getRight() == nullptr)
	{
		TransactionNode* pCur = dynamic_cast<TransactionNode*>(pT);

		return *pCur;
	}
	else
	{
		return findLargest(pT->getRight());
	}
}

BST::BST()
{
	 mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

Node* BST::getRoot() const
{
	return this->mpRoot;
}

void BST::setRoot(Node* const newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(int newUnits, string newData)
{
	TransactionNode* newNode = new TransactionNode(newData, newUnits);
	insert(mpRoot, newNode);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

TransactionNode& BST::findSmallest()
{
	return findSmallest(mpRoot);
}

TransactionNode& BST::findLargest()
{
	return findLargest(mpRoot);
}
