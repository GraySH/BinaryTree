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

	bTree.setLeftChild(bTree.getRoot(), bTree.makeNewNode(1));
	bTree.setRightChild(bTree.getRoot(), bTree.makeNewNode(2));



	return 0;
}
