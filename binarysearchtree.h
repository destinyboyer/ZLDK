#pragma once
#ifndef binarysearchtree_h
#define binarysearchtree_h

#include <string>
#include <iostream>

using namespace std;

template<class NodeData>
class BinarySearchTree {

private:

	class Node {

	public:

		NodeData* data;
		Node* left;
		Node* right;

		Node(void) : data(nullptr), left(nullptr), right(nullptr) {};
		Node(NodeData* d) : data(d), left(nullptr), right(nullptr) {};
		Node(NodeData* d, Node* l, Node* r) : data(d), left(l), right(r) {};
	};

public:

	BinarySearchTree(void);
	~BinarySearchTree(void);

	bool insert(NodeData* toInsert);
	bool retrieve(const NodeData& target, NodeData*& retrieved) const;
	void display(void) const;
	void clear(void);
	bool isEmpty(void) const;
	void buildTree(ifstream& inFile);

private:

	Node* root = nullptr;

	Node* insertHelper(Node* current, NodeData* toInsert);
	void clearHelper(Node* current);
	void displayHelper(Node* current) const;
	bool retrieveHelper(Node* current, const NodeData& target, NodeData*& retrieved) const;
};

#endif



////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Constructors / Destructors						  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



template <typename NodeData>
BinarySearchTree<NodeData>::BinarySearchTree(void) {
	root = NULL;
};


template <typename NodeData>
BinarySearchTree<NodeData>::~BinarySearchTree() {
	clear();
};



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Public Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



template <typename NodeData>
bool BinarySearchTree<NodeData>::insert(NodeData* toInsert) {
	NodeData* temp;
	NodeData temp2 = *toInsert;

	if (toInsert == NULL) {
		return false;
	}

	if (retrieve(temp2, temp)) {
		return false;
	}

	root = insertHelper(root, toInsert);
	return true;
};


template <typename NodeData>
bool BinarySearchTree<NodeData>::retrieve(const NodeData& target, NodeData*& retrieved) const {
	return retrieveHelper(root, target, retrieved);
};


template <typename NodeData>
void BinarySearchTree<NodeData>::display(void) const {
	if (root == NULL) {
		return;
	}
	displayHelper(root);
};


template <typename NodeData>
void BinarySearchTree<NodeData>::clear(void) {
	if (isEmpty()) {
		return;
	}
	clearHelper(root);
	root = NULL;
};


template <typename NodeData>
bool BinarySearchTree<NodeData>::isEmpty(void) const {
	return root == NULL;
};


template <typename NodeData>
void BinarySearchTree<NodeData>::buildTree(ifstream& infile) {
	NodeData* ptr;
	bool isValid;	

	for (;;) {
		ptr = new NodeData;
		isValid = ptr->setData(infile);

		if (infile.eof()) {
			delete ptr;
			break;
		}

		if (isValid) {
			insert(ptr);
		}
		else {
			delete ptr;
		}
	}
};



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Private Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



template <typename NodeData>
typename BinarySearchTree<NodeData>::Node* BinarySearchTree<NodeData>::insertHelper(Node* current, NodeData* toInsert) {
	if (current == NULL) {
		current = new Node(toInsert, NULL, NULL);
	}
	else if (*current->data > *toInsert) {
		current->left = insertHelper(current->left, toInsert);
	}
	else {
		current->right = insertHelper(current->right, toInsert);
	}
	return current;
};


template <typename NodeData>
void BinarySearchTree<NodeData>::clearHelper(Node* current) {
	if (current != NULL) {
		clearHelper(current->right);
		clearHelper(current->left);
		delete current->data;
		delete current;
	}
};


template <typename NodeData>
void BinarySearchTree<NodeData>::displayHelper(Node* current) const {
	if (current == NULL) {
		return;
	}
	else {
		displayHelper(current->left);
		current->data->toString();
		displayHelper(current->right);
	}
};


template <typename NodeData>
bool BinarySearchTree<NodeData>::retrieveHelper(Node* current, const NodeData& target, NodeData*& retrieved) const {
	bool successful = false;
	if (current == NULL) {
		return false;
	}

	if (target == *current->data) {
		retrieved = current->data;
		successful = true;
	}
	else if (*current->data < target) {
		retrieveHelper(current->right, target, retrieved);
	}
	else {
		retrieveHelper(current->left, target, retrieved);
	}
	return successful;
};
