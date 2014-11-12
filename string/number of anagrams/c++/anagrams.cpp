/**
 * by Jaroslaw Hirniak
 * 12 November 2014
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string sortChars(string word) {
  vector<char> chars;

  for (auto c : word) {
    chars.push_back(c);
  }

  sort(chars.begin(), chars.end());

  string sortedWord;
  
  for (auto c : chars) {
    sortedWord.push_back(c);
  }

  return sortedWord;
}

unsigned int anagrams(vector<string> words) {
  unsigned int anagrams = 0;
  set<string> seen;

  for (auto w : words) {
    string sortedChars = sortChars(w);

    if (seen.find(sortedChars) != seen.end()) {
      // seen before
      ++anagrams;
    } else {
      // seen first time
      seen.insert(sortedChars);
    }
  }

  return anagrams;
}

int main() {
  vector<vector<string>> problems {
    { "abab", "baba", "cyce", "ecyc", "yxz", "zxy" },
    { "abc", "def", "ghi", "jkl", "mno" },
    { "zzz", "yyy", "zyz", "yzy" }
  };

  for (auto p : problems) {
    cout << anagrams(p) << endl;
  }
}
