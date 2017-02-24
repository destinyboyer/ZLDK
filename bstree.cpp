#include "stdafx.h"
#include "bstree.h"

BSTree::BSTree()
{
}

BSTree::~BSTree()
{
	Empty();
}

bool BSTree::Add(DVD * acc)
{
	if (root == nullptr)
	{
		root = new Node;
		root->pAcct = acc;
		return true;
	}
	else
	{
		return insert(root, acc);
	}
}

bool BSTree::Retrieve(const int & id, DVD *& acc) const
{
	if (root == nullptr)
	{
		return false;
	}
	if (root->pAcct->getId() == id)
	{
		acc = root->pAcct;
		return true;
	}
	if (root->pAcct->getId() > id)
	{
		return retriever(root->left, id, acc);
	}
	else
	{
		return retriever(root->right, id, acc);
	}
}

bool BSTree::Contains(const int & id) const
{
	if (root == nullptr)
	{
		return false;
	}
	if (root->pAcct->getId() == id)
	{
		return true;
	}
	if (root->pAcct->getId() > id)
	{
		return find(root->left, id);
	}
	else
	{
		return find(root->right, id);
	}
}

void BSTree::Display() const
{
	if (root != nullptr)
	{
		displayer(root->left);
		root->pAcct->Display();
		displayer(root->right);
	}
}

void BSTree::Empty()
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left != nullptr)
	{
		clear(root->left);
	}
	if (root->right != nullptr)
	{
		clear(root->right);
	}
	delete root->pAcct;
	delete root;
	root = nullptr;
}

bool BSTree::isEmpty() const
{
	return root == nullptr;
}

bool BSTree::insert(Node *& subTree, DVD * acc)
{
	if (subTree == nullptr)
	{
		subTree = new Node;
		subTree->pAcct = acc;
		return true;
	}
	if (*(subTree->pAcct) == *(acc))
	{
		return false;
	}
	if (*(subTree->pAcct) > *(acc))
	{
		return insert(subTree->left, acc);
	}
	else
	{
		return insert(subTree->right, acc);
	}
	return false;
}

bool BSTree::retriever(Node *& subTree, const int & id, DVD *& acc) const
{
	if (subTree == nullptr)
	{
		return false;
	}
	if (subTree->pAcct->getId() == id)
	{
		acc = subTree->pAcct;
		return true;
	}
	if (subTree->pAcct->getId() > id)
	{
		return retriever(subTree->left, id, acc);
	}
	else
	{
		return retriever(subTree->right, id, acc);
	}
	return false;
}

bool BSTree::find(Node *& subTree, const int & id) const
{
	if (subTree == nullptr)
	{
		return false;
	}
	if (subTree->pAcct->getId() == id)
	{
		return true;
	}
	if (subTree->pAcct->getId() > id)
	{
		return find(subTree->left, id);
	}
	else
	{
		return find(subTree->right, id);
	}
}

void BSTree::displayer(Node * &currentNode) const
{
	if (currentNode != nullptr)
	{
		displayer(currentNode->left);
		root->pAcct->Display();
		displayer(currentNode->right);
	}
}

void BSTree::clear(Node *& currentNode)
{
	if (currentNode == nullptr)
	{
		return;
	}
	if (currentNode->left != nullptr)
	{
		clear(currentNode->left);
	}
	if (currentNode->right != nullptr)
	{
		clear(currentNode->right);
	}
	delete currentNode->pAcct;
	delete currentNode;
	currentNode = nullptr;
}
