/*
Name: Gerald McGee
*/


#include <iostream>
#include "avl_tree.h"

int AVLTree::height(BinaryNode *node){
	int y = 0;

	if(node != NULL) {

		int lh = height(node->left);
		int rh = height(node->right);

		int highest = maximum(lh, rh);

		y = highest + 1;
	}
	return y;
}

int AVLTree::maximum(int x, int y){
	if(x > y)
		return x;
	if(y > x)	
		return y;
	
	return x;
}

int AVLTree::balance_subtree(BinaryNode *node){

	int left_height = height(node->left);
	int right_height = height(node->right);

	int balance_factor = left_height - right_height;

	return balance_factor;
}

BinaryNode* AVLTree::balance_factor(BinaryNode *node){

	int balance_factor = balance_subtree(node);

	if(balance_factor > 1)
	{
		if(balance_subtree(node->left) > 0)
			node = left_rotate(node);
		else
			node = leftright_rotate(node);
	}
	else if(balance_factor < -1)
	{
		if(balance_subtree(node->right) > 0)
			node = rightleft_rotate(node);
		else
			node = right_rotate(node);
	}
	return node;
}

BinaryNode* AVLTree::left_rotate(BinaryNode *node){
	BinaryNode *tmp;

	tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	return tmp;
}

BinaryNode* AVLTree::leftright_rotate(BinaryNode* node){	
	BinaryNode *tmp;

	tmp = node->left;
	node->left = right_rotate(tmp);
	return left_rotate(node);
}

BinaryNode* AVLTree::rightleft_rotate(BinaryNode* node){	
	BinaryNode *tmp;

	tmp = node->right;
	node->right = left_rotate(tmp);
	return right_rotate(node);
}

BinaryNode* AVLTree::right_rotate(BinaryNode* node){	
	BinaryNode *tmp;

	tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	return tmp;
}

BinaryNode* AVLTree::insert(const int num, BinaryNode *node){	
	if(node == NULL){	

		node = new BinaryNode(num);

		node->key = num;
		node->right = NULL;
		node->left = NULL;

		return node;
	}
	else if(num < node->key){
		node->left = insert(num, node->left);
		node = balance_factor(node);
	}
	else if(num > node->key){
		node->right = insert(num, node->right);
		node = balance_factor(node);
	}
	else {
		std::cout << "Extra" << std::endl;
	}

	node = balance_factor(node);

	return node;
}

BinaryNode* AVLTree::remove(const int num, BinaryNode *node){	
	BinaryNode *tmp;
	
	if(node == NULL){
		return NULL;
	}
	else if(num < node -> key){
		node ->left = remove(num, node -> left);
	}
	else if(num > node->key){
		node -> right = remove(num,node -> right);
	}
	else if(node ->left && node -> right){
		tmp = find_left(node -> right);
		node -> key = tmp -> key;
		node -> right = remove(node -> key, node -> right);
	}
	else {
		tmp = node;
	
		if(node -> left == NULL)
			node = node -> right;

		else if(node -> right == NULL)
			node = node -> left;
		else	
			std::cout << "No Node" << std::endl;
		delete tmp;
	}
	
	if(node == NULL)
		return node;

	
	node = balance_factor(node);

	if(height(node -> left) - height(node -> right) == 2){	
		if(height(node -> left -> left) - height(node -> left -> right) == 1)
			return (node = left_rotate(node));
		else{
			node = left_rotate(node);
			return (node = left_rotate(node));
		}
	}
	
	else if(height(node->right) - height(node->left) == 2){	
		if(height(node->right->right) - height(node->right->left) == 1)
			return (node = right_rotate(node));
		else
		{
			node = right_rotate(node);
			return (node = right_rotate(node));
		}
	}
	node = balance_factor(node);

	return node;	
}

BinaryNode* AVLTree::find_left(BinaryNode* node){
	if(node == NULL)
		return NULL;
	else if(node->left == NULL)
		return node;
	else
		return find_left(node->left);
}

BinaryNode* AVLTree::find_right(BinaryNode* node){
	if(node == NULL)
		return NULL;
	else if(node -> right == NULL)
		return node;
	else
		return find_right(node -> right);
}

void AVLTree::inorder(char c, BinaryNode* node){
	int b = height(node);

	if(node == NULL){
	return;
	}

	if(c == 'h'){	
		inorder(c, node->left);
		std::cout << b << " ";
		inorder(c, node->right);
	}
	if(c == 'p'){
		inorder(c, node->left);

		std::cout << node->key << " ";
		inorder(c, node->right);
	}
}
