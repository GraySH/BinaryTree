//============================================================================
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree bTree;

	bTree.insertNode(5);
	bTree.insertNode(3);
	bTree.insertNode(1);
	bTree.insertNode(2);
	bTree.insertNode(6);
	bTree.insertNode(8);


	cout << "Inorder: ";
	bTree.inorderTraverse(bTree.getRoot());
	cout << endl;

	cout << "Postorder: ";
	bTree.postorderTraverse(bTree.getRoot());
	cout << endl;

	cout << "Preorder: ";
	bTree.preorderTraverse(bTree.getRoot());
	cout << endl;

	return 0;
}
