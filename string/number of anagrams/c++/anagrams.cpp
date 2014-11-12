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
  sort(word.begin(), word.end());
  return word;
}

/**
 * Given list of words returns the number of words
 * that are anagrams of some previously seen words
 * in a list.
 */
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
    { "zzz", "yyy", "zyz", "yzy" },
    { "zaz", "azz", "zza", "zaz", "azz", "az", "za" }
  };

  for (auto p : problems) {
    cout << anagrams(p) << endl;
  }
}
