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
		//check delete node is left child or right children
		if( (parentNodeOfDeleteNode->left != NULL) && (parentNodeOfDeleteNode->left->data == num) ) //left Node need to be deleted.
		{
			//if delete Node is terminal node, simply delete it
			if( (parentNodeOfDeleteNode->left->right == NULL) && (parentNodeOfDeleteNode->left->left == NULL) )
			{
				//delete right child of parent node.
				delete parentNodeOfDeleteNode->left;

				//assign NULL
				parentNodeOfDeleteNode->left = NULL;
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
		}
	}//if(parentNodeOfDeleteNode != NULL)

	//delete virtualRootNode
	delete virtualRootNode;
}









