/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    dp = vector<vector<int>>(nums.size() + 2, vector<int>(nums.size() + 2, -1));

    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    return dfs(nums, 1, nums.size() - 2);
  }

 private:
  vector<vector<int>> dp;

  int dfs(const vector<int>& nums, int i, int j) {
    if (j < i) return 0;

    if (dp[i][j] >= 0) return dp[i][j];

    int ret = 0;
    for (int k = i; k <= j; k++) {
      int new_ret = nums[i - 1] * nums[k] * nums[j + 1]
                  + dfs(nums, i, k - 1)
                  + dfs(nums, k + 1, j);
      ret = max(ret, new_ret);
    }
    dp[i][j] = ret;
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> nums;

  // example 1
  nums = {3, 1, 5, 8};
  ret = s.maxCoins(nums);
  print_ret(ret);

  // example 2
  nums = {1, 5};
  ret = s.maxCoins(nums);
  print_ret(ret);

  return 0;
}
