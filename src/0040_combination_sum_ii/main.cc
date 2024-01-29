/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Solution {
 public:
  vector<vector<int>> combinationSum2(
        vector<int> candidates, const int& target) {
    vector<vector<int>> ret;
    vector<int> curr;
    int sum = 0;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, ret, curr, sum, 0);
    return ret;
  }

 private:
  void dfs(const vector<int>& nums, const int& target,
            vector<vector<int>>& ret, vector<int>& curr, int& sum, int start) {
    if (sum == target) {
      ret.push_back(curr);
      return;
    }
    if (sum > target) return;

    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }
      curr.push_back(nums[i]);
      sum += nums[i];
      dfs(nums, target, ret, curr, sum, i + 1);
      curr.pop_back();
      sum -= nums[i];
    }
  }
};

void print_ret(const vector<vector<int>>& ret) {
  cout << "[";
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& n : v) {
      cout << n << ",";
    }
    cout << "],";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<vector<int>> ret;
  vector<int> nums;

  // example 1
  nums = {10, 1, 2, 7, 6, 1, 5};
  ret = s.combinationSum2(nums, 8);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
