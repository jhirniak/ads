/**
 * by Jaroslaw Hirniak
 * 07 November 2014
 */

#define DEBUG

#include <iostream>
#include <string>
#include <set>

using namespace std;

/**
 * creates permutation by iterating over existing permutations
 * and inserting char c in each possible position
 */
set<string> permute(char c, set<string> perms) {
  set<string> newPerms {};
  
  for (auto it: perms) {
    for (size_t i = 0; i <= it.size(); ++i) {
      newPerms.insert(it.substr(0, i) + c + it.substr(i));
    }
  }
  
  return newPerms;
}

/**
 * initializes recursive permutation function
 */
set<string> getPermutations(string str) {
    if(!str[0]) {
          return set<string> {""};
            }
      return permute(str[0], getPermutations(str.substr(1)));
}

int main() {
  #ifdef DEBUG
    if (freopen("input.txt", "r", stdin) == 0) {
      cout << "Loading test file failed" << endl;
    } else {
      string str;
      while (cin >> str) {
        set<string> permutations = getPermutations(str);
        cout << "***\n";
        for (auto it: permutations) {
          cout << "\t" << it << endl;
        }
      }
      cout << "***\n";
    }
  #endif

  return 0;
}
