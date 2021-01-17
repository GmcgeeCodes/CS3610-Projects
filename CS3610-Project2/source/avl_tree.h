/*
Name: Gerald McGee
*/

#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode {
  BinaryNode(const int key) : key(key), left(NULL), right(NULL) {}

  ~BinaryNode() {
    delete left;
    delete right;
    left = right = NULL ;
  }

  int key;
  BinaryNode *left, *right;
};

class AVLTree {

public:
  AVLTree() : node(NULL) {}
  ~AVLTree() { 
    delete node;
  }
	BinaryNode* insert(const int num, BinaryNode* node);
	BinaryNode* remove(const int num, BinaryNode* node);


	BinaryNode* find_left(BinaryNode* node);
	BinaryNode* find_right(BinaryNode* node);
	BinaryNode* leftright_rotate(BinaryNode *node);
	BinaryNode* rightleft_rotate(BinaryNode *node);
	BinaryNode* right_rotate(BinaryNode *node);
	BinaryNode* left_rotate(BinaryNode *node);
	


	int height(BinaryNode* node);
	int maximum(int x, int y);

	int balance_subtree(BinaryNode* node);
	BinaryNode* balance_factor(BinaryNode* node);	
	
	void inorder(char c, BinaryNode *node);

	BinaryNode* node;
	
private:

};

#endif
