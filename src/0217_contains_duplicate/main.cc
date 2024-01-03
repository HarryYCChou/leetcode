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
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++) {
      if (s.find(nums[i]) != s.end()) {
        return true;
      }
      s.insert(nums[i]);
    }

    return false;
  }
};

void print_ret(bool ret) {
  if (ret)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}

int main() {
  Solution s;

  bool ret;
  std::vector<int> nums;

  // example 1
  nums.clear();
  nums = {1, 2, 3, 1};
  ret = s.containsDuplicate(nums);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {1, 2, 3, 4};
  ret = s.containsDuplicate(nums);
  print_ret(ret);

  // example 3
  nums.clear();
  nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  ret = s.containsDuplicate(nums);
  print_ret(ret);

  return 0;
}
