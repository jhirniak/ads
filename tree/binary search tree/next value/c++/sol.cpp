/**
 * By Jaroslaw Hirniak
 * 08 November 2014
 */

#include <iostream>
using namespace std;

#define DEBUG

struct node {
  int item;
  struct node *left, *right, *parent;
};

struct node* newNode(struct node* parent, int val) {
  struct node* node = new struct node;
  node->item = val;
  node->parent = parent;
  node->left = nullptr;
  node->right = nullptr;
  return node;
};

/** next value algorithm
  * given root node and value
  * returns next largest value after val in root
  * and if none exists the val itself
  */
int nextVal(node *root, int val) {
  // find val
  node *myNode = root;

  while(myNode) {
    if (myNode->item > val) {
      myNode = myNode->left;
    } else if (myNode->item < val) {
      myNode = myNode->right;
    } else {
      break;
    }
  }

  // find the next value

  if (myNode->parent->right->left) {
    myNode = myNode->parent->right->left;
    while (myNode->left) {
      myNode = myNode->left;
    }
  } else {
    myNode = myNode->parent;
  }

  return myNode->item;
}

int main() {
  struct node* root = newNode(nullptr, 6);
  root->left = newNode(root, 5);
  root->left->left = newNode(root->left, 1);
  root->left->right = newNode(root->left, 7);
  root->right = newNode(root, 12);
  root->right->left = newNode(root->right, 11);
  root->right->right = newNode(root->right, 15);

  cout << nextVal(root, 11);

  return 0;
}
