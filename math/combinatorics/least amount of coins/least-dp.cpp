/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 *
 * Find least amount of coins for change.
 * This solution is optimal in time thanks
 * to the use of dynamic programming.
 */
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int least(int change, set<int> coins, map<int, int> &known) {
  if (known.find(change) != known.end()) {
    return known[change];
  } else if (coins.find(change) != coins.end()) {
    known[change] = 1;
    return 1;
  } else {
    int min = change;

    for (auto c : coins) {  
      if (c > change) {
        continue;
      }

      int numCoins  = 1 + least(change - c, coins, known);

      if (numCoins < min) {
        min = numCoins;
        known[change] = min;
      }
    }

    return min;
  }
}

int getLeast(int change, set<int> coins) {
  map<int, int> known {};
  return least(change, coins, known);
}

int main() {
  typedef pair<int, set<int>> problem;
  set<problem> problems { 
    problem(17, set<int> {1, 2, 5, 10, 25}),
    problem(21, set<int> {1, 2, 5, 7}),
    problem(23, set<int> {1, 2, 3, 6}),
    problem(63, set<int> {1, 2, 5, 21, 25}),
    problem(123, set<int> {1, 2, 5, 10, 25, 100}),
    problem(1232, set<int> {1, 2, 5, 10, 25}),
    problem(3210, set<int> {3, 5, 7, 11, 13})
  };

  for (auto p : problems) {
    cout << getLeast(p.first, p.second) << endl;
  }
}
