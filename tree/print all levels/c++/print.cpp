/**
 * by Jaroslaw Hirniak
 * 08 November 2014
 */

#include <iostream>
#include <queue>
#include <utility> // std::pair

using namespace std;

struct node {
  int item;
  struct node *left, *right;
};

/**
 * level order traversal is same as breath first search
 * queue is used to put and take off elements in order
 */
void levelOrderTraversal(node *root) {
  typedef pair<const node*, int> node_level;
  queue<node_level> q;
  q.push(node_level(root, 0));
  int level = -1;

  while (!q.empty()) {
    const node *node;
    node_level nl = q.front();
    q.pop();

    if ((node = nl.first)) {
      if (level != nl.second) {
        ++level;
        cout << endl << level << ": ";
      }

      cout << node->item << " ";

      if (node->left) {
        q.push(node_level(node->left, level+1));
      }

      if (node->right) {
        q.push(node_level(node->right, level+1));
      }
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
