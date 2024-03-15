/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  uint32_t reverseBits(const uint32_t& n) {
    int ret = 0;

    for (int i = 0; i < 32; i++) {
      ret = ret << 1;
      if (n & (1 << i)) ret += 1;
    }
    return ret;
  }
};

void print_ret(const uint32_t& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  uint32_t ret;

  // example 1
  ret = s.reverseBits(0b00000010100101000001111010011100);
  print_ret(ret);

  // example 2
  ret = s.reverseBits(0b11111111111111111111111111111101);
  print_ret(ret);

  return 0;
}
