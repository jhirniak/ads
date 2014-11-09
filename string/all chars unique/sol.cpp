/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 */

#define DEBUG

#include <iostream>
#include <string>
#include <set>

using namespace std;

bool allUnique(string str) {
  set<char> seen;

  for (auto c : str) {
    if (seen.find(c) != seen.end()) {
      return false;
    } else {
      seen.insert(c);
    }
  }

  return true;
}

int main() {
  #ifdef DEBUG
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
