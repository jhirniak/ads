/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 *
 * Check if all characters in string are unique
 * without using additional data structures.
 *
 * Here using implented BST.
 * TODO: Add self-balancing (AVL).
 */

#define DEBUG

#include <iostream>
#include <string>
#include <queue>
#include <utility> // std::pair

using namespace std;

struct node {
  char item;
  struct node *left, *right;
};

void printTree(node* root);

node* newNode(char item) {
  node *node = new struct node;
  node->item = item;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

/**
 * returns true if new node was inserted
 * returns false if node with item already existed
 * (and hence did not insert)
 */
bool insert(node* root, char item) {
  while (root) {
    if (item < root->item) {
      if (root->left) {
        root = root->left;
      } else {
        root->left = newNode(item);
        return true;
      }
    } else if (item > root->item) {
      if (root->right) {    
        root = root->right;
      } else {
        root->right = newNode(item);
        return true;
      }
    } else {
      return false;
    }
  }

  root = newNode(item);
  return false;
}

void printTree(node* root) {
  typedef pair<const node*, int> node_level;
  const node* node;
  queue<node_level> q;
  q.push(node_level(root, 0));
  int level = -1;

  while(!q.empty()) {
    node_level nl = q.front();
    q.pop();

    if ((node = nl.first)) {
      if (level != nl.second) {
        level = nl.second;
        cout << endl << level << ": ";
      }
    
      if (node->left) {
        q.push(node_level(node->left, level+1));
      }

      if (node->right) {
        q.push(node_level(node->right, level+1));
      }

      cout << node->item << " ";
    }
  }
  cout << endl;
}

bool allUnique(string str) {
  if (str.empty()) {
    return true;
  } else {
    node* root = newNode(str[0]);

    for (auto it = str.begin() + 1; it != str.end(); ++it) {
      if (!insert(root, *it)) {
          return false;
      } 
    }

    return true;
  }
}

int main() {
  #ifdef DEBUG
    node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');

    printTree(root);

    if (freopen("input.txt", "r", stdin) == 0) {
      cout << "Loading test file failed!" << endl;
    } else {
      string str;
      while (cin >> str) {
        cout << "All characters unique in " << str << "?\n"
             << allUnique(str) << endl;
      }
    }
  #endif

  return 0;
}
