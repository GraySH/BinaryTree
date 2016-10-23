//Binary Tree
#include <iostream>

using namespace std;
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

	void insertNode(Data num);

	Node* makeNewNode(Data num);
	void setLeftChild(Node* parentNode, Node* newNode);
	void setRightChild(Node* parentNode, Node* newNode);

	Node* getRoot();
	Node* getLeftChild(Node* node);
	Node* getRightChild(Node* node);

	void inorderTraverse(Node* node);
	void postorderTraverse(Node* node);
	void preorderTraverse(Node* node);

	Node* searchNode(Data num);

	//find parent node of a node that has a value to search
	Node* searchParentNode(Data num, Node* head);

	bool searchNodeByValue(Data num);

	//delete nodes, free memeory.
	void freeMemory(Node* node);


	void deleteNode(Data num);

};


