/**
 * by Jaroslaw Hirniak
 * 12 November 2014
 *
 * Check if all characters in string are unique
 * without using additional data structures.
 *
 * Here using implented by representing each char as a position
 * in int.
 */

#define DEBUG

#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool allUnique(string str) {
  int seen = 0;

  for (auto c : str) {
    int i = c - 'a';

    if (seen & (1 << i)) {
      return false;
    } else {
      seen |= 1 << i;
    }
  }

  return true;
}

int main() {
  #ifdef DEBUG
  vector<string> problems {
    "abcdefghijklmnopqrstuwxyz",
    "abcdefghijklmnoapqrstuwxyz",
    "a",
    "aa"
  };

  for (auto p : problems) {
    cout << "All chars in " << p << " unique? " << allUnique(p) << endl;
  }
  #endif

  return 0;
}
