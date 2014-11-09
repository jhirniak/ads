/**
 * by Jaroslaw Hirniak
 * 09 November 2014
 */

#define DEBUG

#include <iostream>
#include <string>

using namespace std;

/**
 * To reverse at the original string location just
 * replace argument string str with reference, i.e.
 * string &str and remove return statement.
 */
string reverse(string str) {
  for (int i = 0, j = str.length() - 1; i < j; ++i, --j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }

  return str;
}

int main() {
  string s0 = "Ala ma kota!";
  cout << s0 << endl << reverse(s0) << endl << reverse(reverse(s0)) << endl; 
}
