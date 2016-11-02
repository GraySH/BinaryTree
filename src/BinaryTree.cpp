/*
 * BinaryTree.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: gray
 */

#include "BinaryTree.h"
#include <stack>
#include <queue>

BinaryTree::BinaryTree() : root(NULL)
{
	init();
};

BinaryTree::~BinaryTree()
{
	freeMemory(root); //free memeory with postorder iteration.
};

void BinaryTree::freeMemory(Node* node)
{
	//delete nodes.
	if(node == NULL)
	{
		return;
	}
	freeMemory(node->left);
	freeMemory(node->right);
	delete node;
}

void BinaryTree::init()
{
	root = NULL;
}

BinaryTree::Node* BinaryTree::makeNewNode(Data num)
{
	Node* newNode = new Node;
	newNode->data = num;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void BinaryTree::setLeftChild(Node* parentNode, Node* newNode)
{
	parentNode->left = newNode;
}

void BinaryTree::setRightChild(Node* parentNode, Node* newNode)
{
	parentNode->right = newNode;
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

BinaryTree::Node* BinaryTree::findInsertionPoint(Node* node, Data num)
{
	Node* insertionPoint = num < node->data ? node->left : node->right;
	return insertionPoint ? findInsertionPoint(insertionPoint, num) : node;
}

void BinaryTree::insertNode(Data num)
{
	if(root == NULL)
	{
		root = makeNewNode(num);
		return;
	}

	Node* parentNode = root;
	Node* currentNode = parentNode;

	while(currentNode != NULL)
	{
		if(currentNode->data == num)
			return;

		parentNode = currentNode;
		pathStack.push(parentNode);
		//pathQueue.push(parentNode);

		if(num < currentNode->data)
		{
			currentNode = currentNode->left;

		}
		else if(num > currentNode->data)
		{
			currentNode = currentNode->right;
		}
	}
	//cout << endl;

	if(num < parentNode->data)
	{
		parentNode->left = makeNewNode(num);
	}
	else if(num > parentNode->data)
	{
		parentNode->right = makeNewNode(num);
	}

	postOrderBalance(root);

}//insertNode

void BinaryTree::makeBalanceTree(Node* node)
{
	if(node == NULL)
		return;

	makeBalanceTree(node->left);
	makeBalanceTree(node->right);
	rebalance(node);
}


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

void BinaryTree::postorderTraverse(Node* node)
{
	if(node == NULL)
	{
		return;
	}
	postorderTraverse(node->left);
	postorderTraverse(node->right);
	cout << node->data << " ";
}


void BinaryTree::preorderTraverse(Node* node)
{
	if(node == NULL)
	{
		return;
	}
	cout << node->data << " ";
	preorderTraverse(node->left);
	preorderTraverse(node->right);
}

BinaryTree::Node* BinaryTree::searchNode(Data num)
{
	//find where to set the Node.
	Node* iterator = root;
	while(iterator != NULL)
	{
		if(iterator->data == num) //if Node is found return the node.
		{
			return iterator;
		}
		else if (iterator->data >= num) //if currentNode value is greater or equal than a value to search
		{
			//move to left child
			iterator = iterator->left;
		}
		else if(iterator->data < num) //if currentNode value is less than a value to search
		{
			//move to right child
			iterator = iterator->right;
		}
	}//while

	//if node isn't found, return NULL
	return NULL;
}

bool BinaryTree::searchNodeByValue(Data num)
{
	Node* node = searchNode(num);
	if(node == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

BinaryTree::Node* BinaryTree::searchParentNode(Data num, Node* head)
{
	if(head == NULL)
	{
		return NULL;
	}
	//start from root node.
	Node* iterator = head->right;
	Node* parent = head;

	while(iterator != NULL)
	{
		if(iterator->data == num)
		{
			return parent;
		}
		else if (iterator->data >= num) //if currentNode value is greater or equal than a value to search
		{
			//assign current node as parent node before move to a left child of current node
			parent = iterator;
			//move to left child
			iterator = iterator->left;
		}
		else if(iterator->data < num) //if currentNode value is less than a value to search
		{
			//assign current node as parent node before move to a left child of current node
			parent = iterator;
			//move to right child
			iterator = iterator->right;
		}
	}
	return NULL;
}

void BinaryTree::deleteNode(Data num)
{
	//make virtual root node to padding root.
	Node* virtualRootNode = new Node;

	//assign virtual root node right child to root
	virtualRootNode->right = root;

	//find node from a tree
	Node* parentNodeOfDeleteNode = searchParentNode(num, virtualRootNode);

	if(parentNodeOfDeleteNode != NULL)
	{
		//left Node need to be deleted.
		if( (parentNodeOfDeleteNode->left != NULL) && (parentNodeOfDeleteNode->left->data == num) )
		{
			//if delete Node is terminal node, simply delete it
			if( (parentNodeOfDeleteNode->left->right == NULL) && (parentNodeOfDeleteNode->left->left == NULL) )
			{
				//delete right child of parent node.
				delete parentNodeOfDeleteNode->left;

				//assign NULL
				parentNodeOfDeleteNode->left = NULL;
				delete virtualRootNode;
				return;
			}

			//find smallest node from right child tree to replace number value of a node, which is go far left.
			Node* smallestNode = parentNodeOfDeleteNode->left->right;
			Node* smallestNodeparent = parentNodeOfDeleteNode->left;
			while(smallestNode->left != NULL)
			{
				smallestNodeparent = smallestNode;
				smallestNode = smallestNode->left;
			}
			//copy node value from smallest node value to node to be deleted.
			parentNodeOfDeleteNode->left->data = smallestNode->data;

			//delete smallest Node
			if(smallestNodeparent->left == smallestNode) // smallest node is left child of parentNode
			{
				smallestNodeparent->left = smallestNode->right;
			}
			else if(smallestNodeparent->right == smallestNode) // smallest node is right child of parentNode
			{
				smallestNodeparent->right = smallestNode->right;
			}

			//delete smallest Node
			delete smallestNode;

			parentNodeOfDeleteNode = rebalance(parentNodeOfDeleteNode); //reblalance tree after delete a node.

		}//if(parentNodeOfDeleteNode->left == num)
		else if( (parentNodeOfDeleteNode->right != NULL) && (parentNodeOfDeleteNode->right->data == num) ) //right Node need to be deleted.
		{
			//if delete Node is terminal node, simply delete it
			if( (parentNodeOfDeleteNode->right->right == NULL) && (parentNodeOfDeleteNode->right->left == NULL) )
			{
				//delete right child of parent node.
				delete parentNodeOfDeleteNode->right;

				//assign NULL
				parentNodeOfDeleteNode->right = NULL;
				delete virtualRootNode;
				return;
			}

			//find smallest node from right child tree to replace number value of a node, which is go far left.
			Node* smallestNode = parentNodeOfDeleteNode->right->right;
			Node* smallestNodeparent = parentNodeOfDeleteNode->right;

			while(smallestNode->left != NULL)
			{
				smallestNodeparent = smallestNode;
				smallestNode = smallestNode->left;
			}
			//copy node value from smallest node value to node to be deleted.
			parentNodeOfDeleteNode->right->data = smallestNode->data;

			//delete smallest Node
			if(smallestNodeparent->left == smallestNode) // smallest node is left child of parentNode
			{
				smallestNodeparent->left = smallestNode->right;
			}
			else if(smallestNodeparent->right == smallestNode) // smallest node is right child of parentNode
			{
				smallestNodeparent->right = smallestNode->right;
			}
			delete smallestNode;
			parentNodeOfDeleteNode = rebalance(parentNodeOfDeleteNode); //reblalance tree after delete a node.
		}
	}//if(parentNodeOfDeleteNode != NULL)

	//delete virtualRootNode
	delete virtualRootNode;
}

int BinaryTree::getHeight(Node* node)
{
	if(node == NULL)
	{
		return -1;
	}

	int left = getHeight(node->left);
	int right = getHeight(node->right);

	return 1 + max(left, right);
}

int BinaryTree::getHeightDifferece(Node* node)
{
	if(node == NULL)
		return 0;

	int left = getHeight(getLeftChild(node));
	int right = getHeight(getRightChild(node));

	return left - right;

}

BinaryTree::Node* BinaryTree::rotateLL(Node*& node)
{
	Node* parentNode;
	Node* childNode;

	parentNode = node;
	childNode = getLeftChild(parentNode);

	//roate LL
	setLeftChild(parentNode, getRightChild(childNode));
	setRightChild(childNode, parentNode);

	node = childNode;

	//return address of changed root node.
	return node;
}


BinaryTree::Node* BinaryTree::rotateRR(Node*& node)
{
	Node* parentNode = node;
	Node* childNode = getRightChild(parentNode);

	//roate RR
	setRightChild(parentNode, getLeftChild(childNode));
	setLeftChild(childNode, parentNode);

	node = childNode;
	//return address of changed root node.

	return node;
}

BinaryTree::Node* BinaryTree::rotateLR(Node*& node)
{
	Node* parentNode = node;
	Node* childNode = getLeftChild(parentNode);

	childNode = rotateRR(childNode);
	//parent node of child node is now need to be changed.
	setLeftChild(parentNode, childNode);
	parentNode = rotateLL(parentNode);

	node = parentNode;

	return node;
}

BinaryTree::Node* BinaryTree::rotateRL(Node*& node)
{
	Node* parentNode = node;
	Node* childNode = getRightChild(parentNode);

	childNode = rotateLL(childNode);
	//parent node of child node is now need to be changed.
	setRightChild(parentNode, childNode);
	parentNode = rotateRR(parentNode);

	node = parentNode;

	return node;
}

BinaryTree::Node* BinaryTree::rebalance(Node*& node)
{
	int heightDifference =  getHeightDifferece(node);

	if(heightDifference > 1) // case of LL or LR
	{
		if( getHeightDifferece(getLeftChild(node)) > 0 ) // case of LL
		{
			rotateLL(node);
		}
		else //case of LR
		{
			rotateLR(node);
		}
	}

	if(heightDifference < -1 ) //case of RR or RL
	{
		if( getHeightDifferece(getRightChild(node)) > 0 ) // case of RL
		{
			rotateRL(node);
		}
		else //case of RR
		{
			rotateRR(node);
		}
	}
	return node;
}

void BinaryTree::postOrderBalance(Node*& node)
{
	if(node == NULL)
	{
		return;
	}

	postOrderBalance(node->left);
	postOrderBalance(node->right);
	rebalance(node);
}

