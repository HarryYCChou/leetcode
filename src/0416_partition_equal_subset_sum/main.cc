/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

class Solution {
 public:
  bool canPartition(const vector<int>& nums) {
    int sum = 0;
    for (const auto& n : nums) {
      sum += n;
    }

    if (sum % 2 == 1) return false;

    int goal = sum / 2;
    unordered_set<int> dp;
    dp.insert(0);

    for (const auto n : nums) {
      unordered_set<int> next_dp;
      for (auto it = dp.begin(); it != dp.end(); it++) {
        if (*it + n == goal) return true;
        next_dp.insert(*it);
        next_dp.insert(*it + n);
      }
      dp = next_dp;
    }
    return false;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;

  vector<int> nums;
  bool ret;

  // example 1
  nums = {1, 5, 11, 5};
  ret = s.canPartition(nums);
  print_ret(ret);

  // example 2
  nums = {1, 2, 3, 5};
  ret = s.canPartition(nums);
  print_ret(ret);

  return 0;
}
