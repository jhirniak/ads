/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 *
 * Queue implemented using two stacks:
 *  - rare stack for equeueing new items
 *  - front stack, which if empty for copying all items from
 *    rare stack (then they are in the right queue order)
 *    and then returning them (and if once again empty then
 *    copying again)
 */

#define DEBUG

#include <string>
#include <stack>

#ifdef DEBUG
  #include <iostream>
  #include <sstream>
#endif

using namespace std;

struct queue {
  stack<int> rare, front;
};

void enqueue(queue &q, int item) {
  q.rare.push(item);
}

int dequeue(queue &q) {
  if (q.front.empty()) {
    if (q.rare.empty()) {
      cout << "Queue is empty!" << endl;
      throw 1;
    } else {
      while (!q.rare.empty()) {
        q.front.push(q.rare.top());
        q.rare.pop();
      }
    }
  }

  int val = q.front.top();
  q.front.pop();
  return val;
}

int main() {
  #ifdef DEBUG
    if (freopen("input.txt", "r", stdin) == 0) {
      cout << "Loading test file failed!" << endl;
    } else {
      string expr;
      queue *q = new queue;
      while (cin >> expr) {
        if(expr == "get") {
          cout << dequeue(*q) << " ";
        } else {
          int item;
          istringstream(expr) >> item;
          enqueue(*q, item);
        }
      }
    }
  #endif

  return 0;
}
