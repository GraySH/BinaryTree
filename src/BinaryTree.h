//Binary Tree
#include <iostream>


typedef int Data;

class BinaryTree
{
private:
	struct Node
	{
		Data data;
		Node* left;
		Node* right;
	};

	Node* root;

public:

	BinaryTree();
	~BinaryTree();

	void init();

	Node* makeNewNode(Data num);
	void setLeftChild(Node* parentNode, Node* newNode);
	void setRightChild(Node* parentNode, Node* newNode);

	Node* getRoot();
	Node* getLeftChild(Node* node);
	Node* getRightChild(Node* node);

};


