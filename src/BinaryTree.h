//Binary Tree
#include <iostream>

using namespace std;
typedef int Data;

class BinaryTree
{
public:
	struct Node
	{
		Data data;
		Node* left;
		Node* right;
	};
	Node* root;
private:

public:
	BinaryTree();
	~BinaryTree();

	void init();
	//Node* insertNode(Node*& node, Data num);
	void insertNode(Data num);
	Node* findInsertionPoint(Node* node, Data num);

	Node* makeNewNode(Data num);

	void setLeftChild(Node* parentNode, Node* newNode);
	void setRightChild(Node* parentNode, Node* newNode);

	Node* getRoot();
	Node* getLeftChild(Node* node);
	Node* getRightChild(Node* node);

	void inorderTraverse(Node* node);
	void postorderTraverse(Node* node);
	void preorderTraverse(Node* node);

	void makeBalanceTree(Node* node);

	Node* searchNode(Data num);

	//find parent node of a node that has a value to search
	Node* searchParentNode(Data num, Node* head);

	bool searchNodeByValue(Data num);

	//delete nodes, free memeory.
	void freeMemory(Node* node);

	//find height of a tree
	int getHeight(Node* node);

	void deleteNode(Data num);

	//================================
	//AVL tree functions.
	//get height difference for AVL tree
	int getHeightDifferece(Node* node);
	Node* rotateLL(Node*& node);
	Node* rotateRR(Node*& node);

	Node* rotateLR(Node*& node);
	Node* rotateRL(Node*& node);

	Node* rebalance(Node*& node);

	void postOrderBalance(Node*& node);


};


