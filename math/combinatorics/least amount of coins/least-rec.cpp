/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 *
 * Find least amount of coins for change.
 * This solution is inefficient and is much improved
 * in the dynamic programming version (much of the
 * computation here is repeated).
 */
#include <iostream>
#include <set>
#include <utility>

using namespace std;

int least(int change, set<int> coins) {
  if (change <= 0) {
    return 0;
  }

  if (coins.find(change) != coins.end()) {
    return 1;
  } else {
    int min = change;
    for (auto c : coins) {  
      if (c > change) {
        continue;
      }

      int numCoins  = 1 + least(change - c, coins);

      if (numCoins < min) {
        min = numCoins;
      }
    }

    return min;
  }
}

int main() {
  typedef pair<int, set<int>> problem;
  set<problem> problems { 
    problem(17, set<int> {1, 2, 5, 10, 25}),
    problem(21, set<int> {1, 2, 5, 7}),
    problem(23, set<int> {1, 2, 3, 6})
  };

  for (auto p : problems) {
    cout << least(p.first, p.second) << endl;
  }
}
