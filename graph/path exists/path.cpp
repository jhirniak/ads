#define DEBUG

#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
struct node {
  T item;
  vector<node<T>*> out;
};

/**
 * Use DFS using activation stack and list of visited vertices
 */
template <typename T>
bool connected(node<T> *start, node<T> *end, set<node<T>*> *visited = new set<node<T>*>) {
  if (visited->find(start) != visited->end()) {
    return false;

  } else if (start == end) {
    return true;

  } else {
    for (auto n : start->out) {
      bool conn = connected(n, end, visited);
      visited->insert(n);
      if (conn) {
        return true;
      }
    }
    return false;
  }
}

#ifdef DEBUG

int main() {
  /**
   * 1 -> 2 -> 3 -> 4
   */

  node<int>* start = new node<int>{ .item = 1 };
  node<int>* n2 = new node<int>{ .item = 2 };
  node<int>* n3 = new node<int>{ .item = 3 };
  node<int>* end = new node<int>{ .item = 4 };
  start->out.push_back(n2);
  n2->out.push_back(n3);
  n3->out.push_back(end);
  cout << "Graph 0 connected? " << connected(start, end) << " (expected yes) " << endl;

  /**
   * augment previous graph to
   *
   *   9
   *
   *        6 <- 8 -> 10
   *       /    /
   * 1 -> 2 -> 3 -> 4
   *  \    \       /
   *   7 -> 5 -----
   */
  node<int>* n4 = end;
  node<int>* n5 = new node<int>{ .item = 5};
  node<int>* n6 = new node<int>{ .item = 6};
  node<int>* n7 = new node<int>{ .item = 7};
  node<int>* n8 = new node<int>{ .item = 8};
  node<int>* n9 = new node<int>{ .item = 9};
             end = new node<int>{ .item = 10};

  start->out.push_back(n7);
  n2->out.push_back(n5);
  n7->out.push_back(n5);
  n5->out.push_back(n4);
  n2->out.push_back(n6);
  n3->out.push_back(n8);
  n8->out.push_back(n6);
  n8->out.push_back(end);

  cout << "Graph 1 connected? " << connected(start, end) << " (expected yes) " << endl;
  cout << "Graph 2 connected? " << connected(start, n9) << " (expected no) " << endl;
}

#else

int main() {
}

#endif
