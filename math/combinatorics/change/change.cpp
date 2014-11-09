/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Computes the number of possible ways to give change of $n
 * assuming change can be given in
 * 1c, 2c, 5c, 10c, 25c, and $1
 */

int count(int n, int denom, map<int, int> next_denom) {
  int ndenom = next_denom[denom];

  if (ndenom == denom) {
    return 1;
  }

  int ways = 0;
  
  for (int i = 0; i * denom <= n; ++i) {
    ways += count(n - i * denom, ndenom, next_denom);
  }

  return ways;
}

int change(int n, map<int, int> next_denom) {
  int first_denom = (--next_denom.end())->first;
  return count(n, first_denom, next_denom);
}

int main() { 
  map<int, int> next_denom;
  next_denom[100] = 25;
  next_denom[25] = 10;
  next_denom[10] = 5;
  next_denom[5] = 1;
  next_denom[1] = 1;

  for (int i = 0; i <= 100; ++i) {
    cout << "Ways to change $" << i / 100.0 << " = " << change(i, next_denom) << endl;
  }

  return 0;
}
