/**
 * by Jaroslaw Hirniak
 * 08 November 2014
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<vector<int>> subsets(vector<int> vals, size_t n) {
  if (n >= vals.size()) {
    return vector<vector<int>> {vals};
  } else {
    vector<vector<int>> permsWithX = subsets(vals, n+1);
    vector<int> withoutX = vals;
    withoutX.erase(withoutX.begin() + n);
    vector<vector<int>> permsWithoutX = subsets(withoutX, n);
    permsWithX.insert(permsWithX.end(), permsWithoutX.begin(), permsWithoutX.end());
    return permsWithX;
  }
}

int main() {
  vector<vector<int>> mySubsets = subsets(vector<int> {1, 2, 3}, 0);
  for (auto it: mySubsets) {
    cout << "{";
    for (auto el = it.begin(); el < it.end();) {
      cout << *el;
      if (++el != it.end()) {
        cout << ", ";
      }
    }
    cout << "}" << endl;
  }

  return 0;
}
