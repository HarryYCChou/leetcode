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
  int getSum(int a, int b) {
    while (b != 0) {
      // a for addition, b for carry over one place
      int c = a & b;
      a = a ^ b;
      b = (unsigned)c << 1;
    }
    return a;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.getSum(1, 2);
  print_ret(ret);

  // example 2
  ret = s.getSum(2, 3);
  print_ret(ret);

  return 0;
}
