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
  // exclusive or method
  int missingNumber(const vector<int>& nums) {
    int ret = nums.size();

    for (int i = 0; i < nums.size(); i++) {
      ret = ret ^ nums[i] ^ i;
    }

    return ret;
  }

  // sum method
  int missingNumber2(const vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      ret = ret -nums[i] + i + 1;
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
  ret = s.missingNumber({3, 0, 1});
  print_ret(ret);

  // example 2
  ret = s.missingNumber({0, 1});
  print_ret(ret);

  // example 3
  ret = s.missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1});
  print_ret(ret);

  return 0;
}
