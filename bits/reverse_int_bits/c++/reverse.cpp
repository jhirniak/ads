#define CHAR_BIT 8 // number of bits per byte (normally 8)
#define DEBUG

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

/**
 * Reverses all bits in int
 *
 * Based on
 * https://graphics.stanford.edu/~seander/bithacks.html#BitReverseObvious
 */

unsigned int reverseBits(unsigned int n) {
  unsigned int r = n;
  unsigned int s = sizeof(n) * CHAR_BIT - 1;

  for (n >>= 1; n; n >>= 1) {
    r <<= 1;
    r |= n & 1;
    --s;
  }

  r <<= s;

  return r;
}

int main() {

  #ifdef DEBUG

  typedef pair<unsigned int, unsigned int> test; // (input, expected output)
  vector<test> tests {
    test(0, 0),
    test(0xFFFFFFFF, 0xFFFFFFFF),
    test(0x00000001, 0x80000000),
    test(0xF0000000, 0x0000000F),
    // in: 1010 0001 0011 0101 1111 0000 0010 0100
    //exp: 0010 0100 0000 1111 1010 1100 1000 0101
    test(0xA135F024, 0x240FAC85)
  };

  cout << hex << showbase;

  for (test &t : tests) {
    unsigned int r = reverseBits(t.first);
    cout << "   Input: " << t.first << endl;
    cout << "  Output: " << r << endl;
    cout << "Expected: " << t.second << endl;
    cout << "  Passed: " << (t.second == r ? "Y" : "N") << endl << endl;
  }

  #endif

  return 0;
}
