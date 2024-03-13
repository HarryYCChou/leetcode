/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::pair;

class Solution {
 public:
  int findTargetSumWays(const vector<int>& nums, const int& target) {
    map<pair<int, int>, int> dp;
    return dfs(dp, nums, target, 0, 0);
  }

  int dfs(map<pair<int, int>, int>& dp, const vector<int>& nums,
          const int target, int index, int sum) {
    if (index == nums.size()) {
      return (sum == target) ? 1 : 0;
    }
    if (dp.find({index, sum}) != dp.end()) return dp[{index, sum}];

    int ret = dfs(dp, nums, target, index + 1, sum + nums[index])
              + dfs(dp, nums, target, index + 1, sum - nums[index]);

    dp[{index, sum}] = ret;
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
  ret = s.findTargetSumWays({1, 1, 1, 1, 1}, 3);
  print_ret(ret);

  // example 2
  ret = s.findTargetSumWays({1}, 1);
  print_ret(ret);

  // example 3

  return 0;
}
