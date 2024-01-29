/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    dfs(nums, 0, ret);
    return ret;
  }

 private:
  void dfs(vector<int>& nums, int index, vector<vector<int>>& ret) {
    if (index == nums.size()) {
      ret.push_back(nums);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      swap(nums[index], nums[i]);
      dfs(nums, index + 1, ret);
      swap(nums[index], nums[i]);
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
  vector<int> nums;
  vector<vector<int>> ret;

  // example 1
  nums = {1, 2, 3};
  ret = s.permute(nums);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
