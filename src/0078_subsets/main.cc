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
  vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> ret;
    for (const auto& n : nums) {
      if (ret.empty()) {
        ret.push_back({n});
        ret.push_back({});
        continue;
      }
      int count = ret.size();
      for (int i = 0; i < count; i++) {
        // choose
        vector<int> tmp = ret[i];
        tmp.push_back(n);
        ret.push_back(tmp);
      }
    }
    return ret;
  }
};

void print_ret(const vector<vector<int>>& ret) {
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& n : v) {
      cout << n << ",";
    }
    cout << "],";
  }
  cout << endl;
}

int main() {
  Solution s;

  std::vector<vector<int>> ret;
  std::vector<int> nums;

  // example 1
  nums = {1, 2, 3};
  ret = s.subsets(nums);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
