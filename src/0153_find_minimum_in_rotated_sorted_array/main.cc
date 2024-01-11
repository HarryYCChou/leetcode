/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min_element;

class Solution {
 public:
  int findMin2(const vector<int>& nums) {
    // find left right index
    // mid index
    // while left <= right
    // mid_value <= right value --> right = mid
    // mid_value > left value --> left = mid + 1

    if (nums.front() <= nums.back()) return nums.front();

    int left = 0, right = nums.size()-1, mid;

    while (left < right) {
      mid = (left + right) / 2;
      if (nums[mid] <= nums[right]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return nums[right];
  }

  int findMin(const vector<int>& nums) {
    auto e = min_element(nums.begin(), nums.end());
    int ret = *e;

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
  nums.clear();
  nums = {3, 4, 5, 1, 2};
  ret = s.findMin2(nums);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {4, 5, 6, 7, 0, 1, 2};
  ret = s.findMin2(nums);
  print_ret(ret);

  // example 3

  return 0;
}
