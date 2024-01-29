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
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> curr;
    vector<vector<int>> ret;
    dfs(nums, 0, curr, ret);
    return ret;
  }

 private:
  void dfs(const vector<int>& nums, int start,
            vector<int>& curr, vector<vector<int>>& ret) {
    ret.push_back(curr);
    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }
      curr.push_back(nums[i]);
      dfs(nums, i + 1, curr, ret);
      curr.pop_back();
    }
  }
};

void print_ret(vector<vector<int>>& ret) {
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
  nums = {1, 2, 2};
  ret = s.subsetsWithDup(nums);
  print_ret(ret);

  // example 2
  nums = {0};
  ret = s.subsetsWithDup(nums);
  print_ret(ret);

  // example 3

  return 0;
}
