#include <random>
#include <iostream>

using namespace std;

int roll_a_fair_die() {
  static default_random_engine e{};
  static uniform_int_distribution<int> d{1, 6};
  return d(e);
}

int main() {
  for (int i = 0; i < 10; ++i) {
    cout << "Rolled a 6K and got: " << roll_a_fair_die() << endl;
  }
}
