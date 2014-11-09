/**
 * by Jaroslaw Hirniak
 * 08 November 2014
 */

#include <iostream>
#include <queue>

using namespace std;

struct node {
  int item;
  struct node *left, *right;
};

void levelOrderTraversal(node *root) {
  queue<node*> q;

  while (root != nullptr) {
    cout << root->item << " ";

    if (root->left != nullptr) {
      q.push(root->left);
    }
    
    if (root->right != nullptr) {
      q.push(root->right);
    }

    if (!q.empty()) {
      root = q.front();
      q.pop();
    } else {
      root = nullptr;
    }
  }

  cout << endl;
}

struct node* newNode(int item) {
  node* node = new struct node;
  node->item = item;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

int main() {
  node *root = newNode(0);
  root->left = newNode(1);
  root->right = newNode(2);
  root->left->right = newNode(3);
  root->right->left = newNode(4);
  root->right->right = newNode(5);

  levelOrderTraversal(root);
}
