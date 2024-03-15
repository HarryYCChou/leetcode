/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>

using std::cout;
using std::endl;

class Solution {
 public:
  int hammingWeight(const uint32_t& n) {
    uint32_t nn = n;
    int ret = 0;

    while (nn > 0) {
      if (nn & 1) ret++;
      nn >>= 1;
    }
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.hammingWeight(0b00000000000000000000000000001011);
  print_ret(ret);

  // example 2
  ret = s.hammingWeight(0b00000000000000000000000010000000);
  print_ret(ret);

  // example 3
  ret = s.hammingWeight(0b11111111111111111111111111111101);
  print_ret(ret);

  return 0;
}
