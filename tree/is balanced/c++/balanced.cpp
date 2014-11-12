/**
 * by Jaroslaw Hirniak
 * 12 November 2014
 */

#define DEBUG

#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

struct node {
  int item;
  node *left,
       *right;
};

inline int max(int a, int b) {
  return a >= b ? a : b;
}

inline int min(int a, int b) {
  return a <= b ? a : b;
}

int maxDepth(node* root) {
  if (!root) {
    return 0;
  } else {
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
}

int minDepth(node* root) {
  if (!root) {
    return 0;
  } else {
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }
}

bool isBalanced(node* root) {
  return maxDepth(root) - minDepth(root) <= 1;
}

#ifdef DEBUG

node *newNode(int item) {
  node *root = new node;
  root->item = item;
  root->left = nullptr;
  root->right = nullptr;
  return root;
}

int main() {
  
  queue<node*> q {};
  int val = -1;
  node *balanced = newNode(++val);
  q.push(balanced);
  for (int h = 0; h < 5; ++h) {
    for (int l = 0; l < (2 << h); ++l) {
      node *root = q.front();
      q.pop();
      node *left = newNode(++val);
      node *right = newNode(++val);
      root->left = left;
      root->right = right;
      q.push(left);
      q.push(right);
    }
  }

  val = -1;
  node *unbalanced = newNode(++val);
  node *current = unbalanced;
  for (int h = 0; h < 5; ++h) {
    current->left = newNode(++val);
    current = current->left;
  }

  cout << "Is *balanced balanced? " << isBalanced(balanced) << endl;
  cout << "Is *unbalanced balanced? " << isBalanced(unbalanced) << endl;

}

#else
int main() {
  return 0;
}
#endif
