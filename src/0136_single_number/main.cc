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
  int singleNumber(const vector<int>& nums) {
    int ret = 0;

    for (const auto& n : nums) {
      ret ^= n;
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
  ret = s.singleNumber({2, 2, 1});
  print_ret(ret);

  // example 2
  ret = s.singleNumber({4, 1, 2, 1, 2});
  print_ret(ret);

  // example 3
  ret = s.singleNumber({1});
  print_ret(ret);

  return 0;
}
