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

	root = NULL;
//	root = new Node();
//	root->data = 0;
//	root->left = NULL;
//	root->right = NULL;
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


void BinaryTree::insertNode(Data num)
{
	//make new node with num
	Node* newNode = makeNewNode(num);

	//if root is null, add newNode as root node.
	if(root == NULL)
	{
		root = newNode;
		return;
	}

	//find where to set the Node.
	Node* iterator = root;
	while(iterator != NULL)
	{
		if(iterator->data >= newNode->data) //if currentNode is greater or equal than newNode data
		{
			//if child node is NULL, add new data to the child position of current node
			if(iterator->left == NULL)
			{
				iterator->left = newNode;
				return;
			}
			else
			{
				iterator = iterator->left;
			}

		}
		else if(iterator->data < newNode->data ) //currentNode value is less than newNode value
		{
			//if child node is NULL, add new data to the child position of current node
			if(iterator->right == NULL)
			{
				iterator->right = newNode;
				return;
			}
			else
			{
				iterator = iterator->right;
			}
		}
	}//while
}//insertNode



void BinaryTree::inorderTraverse(Node* node)
{
	if(node == NULL)
	{
		return;
	}
	inorderTraverse(node->left);
	cout << node->data << " ";
	inorderTraverse(node->right);
}




