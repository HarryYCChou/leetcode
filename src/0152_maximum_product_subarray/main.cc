/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int dp0 = 1;
    int dp1 = 1;
    int ret = nums[0];
    for (const auto& n : nums) {
      int next_p = max(max(dp0 * n, dp1 * n), n);
      int next_n = min(min(dp0 * n, dp1 * n), n);
      ret = max(ret, next_p);
      dp0 = next_p;
      dp1 = next_n;
    }
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  vector<int> nums;
  int ret;

  // example 1
  nums = {2, 3, -2, 4};
  ret = s.maxProduct(nums);
  print_ret(ret);

  // example 2
  nums = {-2, 0, -1};
  ret = s.maxProduct(nums);
  print_ret(ret);

  return 0;
}
