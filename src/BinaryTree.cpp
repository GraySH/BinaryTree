/*
 * BinaryTree.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: gray
 */

#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
	init();
};

BinaryTree::~BinaryTree()
{
	//delete &root;
};

void BinaryTree::init()
{
	root = new Node();
	root->data = 777;
	root->left = NULL;
	root->right = NULL;
}

BinaryTree::Node* BinaryTree::makeNewNode(Data num)
{
	Node* newNode = new Node;
	newNode->data = num;
	newNode->left = NULL;
	newNode->right = NULL;
}

void BinaryTree::setLeftChild(Node* parentNode, Node* newNode)
{
	parentNode->left = newNode;
}

void BinaryTree::setRightChild(Node* parentNode, Node* newNode)
{
	parentNode->left = newNode;
}

BinaryTree::Node* BinaryTree::getRoot()
{
	return root;
}

BinaryTree::Node* BinaryTree::getLeftChild(Node* node)
{
	return node->left;
}

BinaryTree::Node* BinaryTree::getRightChild(Node* node)
{
	return node->right;
}

