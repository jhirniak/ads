/**
 * by Jaroslaw Hirniak
 * 13 November 2014
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * in-place replaces all spaces with %20
 */

void htmlifySpaces(string &str) {
    size_t spaces = 0;
    
    for (auto c : str) {
      if (c == ' ') {
        ++spaces;
      }
    }

    int len = str.length();
    int nlen = len + spaces * 2;
    str.resize(nlen, 0);

    for (int i = len - 1; i >= 0; --i) {
      if (str[i] == ' ') {
        str[--nlen] = '0';
        str[--nlen] = '2';
        str[--nlen] = '%';
      } else {
        str[--nlen] = str[i];
      }
    }
}

int main() {
  vector<string> problems {
    "This is a test message.",
    "HereAreNoSpaces",
    "",
    " ",
    "Where went all the spaces. Why we have no more space? No more space?"
  };

  for (auto p : problems) {
    cout << "Before: \"" << p << "\"" << endl;
    htmlifySpaces(p);
    cout << " After: \"" << p << "\"" << endl;
  }
}
