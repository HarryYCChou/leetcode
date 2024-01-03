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
    vector<int> twoSum(vector<int>& nums, int target) {
      int len = nums.size();
      std::vector<int> ret;

      for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
          if ((nums[i]+nums[j]) == target) {
            ret.push_back(i);
            ret.push_back(j);
            break;
          }
        }
      }

      return ret;
    }
};

void print_ret(vector<int>& ret) {
  cout << "[" << ret[0] << "," << ret[1] << "]" << endl;
}

int main() {
  Solution s;

  std::vector<int> ret;
  std::vector<int> nums;

  // example 1
  nums.clear();
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(15);
  ret = s.twoSum(nums, 9);
  print_ret(ret);

  // example 2
  nums.clear();
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);
  ret = s.twoSum(nums, 6);
  print_ret(ret);

  // example 3
  nums.clear();
  nums.push_back(3);
  nums.push_back(3);
  ret = s.twoSum(nums, 6);
  print_ret(ret);

  return 0;
}
