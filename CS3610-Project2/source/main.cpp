/*
Name: Gerald McGee
*/

#include <iostream>
#include "avl_tree.h"
using namespace std;

int main(int argc, char** argv) {
  AVLTree tree;

  char opt;
  int key;
  cout << "Choose i - insert, r - remove , h - display height, ";
  cout << endl << "p - print and q - quit" << endl << "Choose an option: ";
 
  do {
    cin >> opt;
    switch(opt){
      case 'i':
        cin >> key;
        tree.node = tree.insert(key, tree.node);
      break;

      case 'r':
        cin >> key;
	      if(tree.node == NULL){
		      cout << "No Node" << endl;
		      break;
	      }
        tree.node = tree.remove(key, tree.node);
      break;
    
      case 'h':
	      if(tree.node == NULL){
		      cout << "N/A" << endl;
		    break;
	      }

        tree.inorder('h', tree.node);
	      cout << endl;
      break;

      case 'p':
	      if(tree.node == NULL){
		      cout << " N/A" << endl;
		      break;
	      }
        tree.inorder('p', tree.node);
	      cout << endl;
      break;

      default:
      
      break;
    }
  } while(opt != 'q');
}
