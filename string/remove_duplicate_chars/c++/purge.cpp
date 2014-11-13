/**
 * by Jaroslaw Hirniak
 * 13 November 2014
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * remove all char duplicates without using any additional memory
 */
void purify(string &str) {
  for (size_t i = 0; i < str.length(); ++i) {
    for (size_t j = i + 1; j < str.length(); ++j) {
      if (str[i] == str[j]) {
        str.erase(j--, 1);
      }
    }
  }
}

int main() {
  vector<string> problems {
    "abcd",
    "aaaa",
    "aaabbbcc",
    "abadeaabcaabcaacad",
    ""
  };

  for (auto p : problems) {
    cout << "Before: \"" << p << "\"" << endl;
    purify(p);
    cout << " After: \"" << p << "\"" << endl;
  }

  return 0;
}
