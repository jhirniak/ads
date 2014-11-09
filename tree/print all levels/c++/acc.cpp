/**
 * by Jaroslaw Hirniak
 * 09 November 2014
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
vector<vector<int>> levelOrderTraversal(node *root) {
  typedef pair<const node*, int> node_level;
  queue<node_level> q;
  q.push(node_level(root, 0));
  int level = -1;

  vector<int> levelElements {};
  vector<vector<int>> allLevels {};

  while (!q.empty()) {
    const node *node;
    node_level nl = q.front();
    q.pop();

    if ((node = nl.first)) {
      if (level != nl.second) {
        ++level;
        if (!levelElements.empty()) {
          allLevels.push_back(levelElements);
          levelElements.clear();
        }
      }

      levelElements.push_back(node->item);

      if (node->left) {
        q.push(node_level(node->left, level+1));
      }

      if (node->right) {
        q.push(node_level(node->right, level+1));
      }
    }
  }

  if (!levelElements.empty()) {
    allLevels.push_back(levelElements);
  }

  return allLevels;
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

  vector<vector<int>> levels = levelOrderTraversal(root);

  int level = 0;
  for (auto lvl : levels) {
    cout << level++ << ": ";
    for (auto el : lvl) {
      cout << el << " ";
    }
    cout << endl;
  }
}
