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
  int search(const vector<int>& nums, const int& target) {
    int left = 0, right = nums.size()-1, mid;

    while (left <= right) {
      // check mid
      mid = left + (right - left) / 2;
      if (nums[mid] ==  target) return mid;

      // mid belong to left part
      if (nums[mid] > nums[right]) {
        if (nums[left] <= target && target <= nums[mid]) {
          right = mid -1;
        } else {
          left = mid + 1;
        }
      } else {
        // mid belong to right part
        if (nums[mid] <= target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid -1;
        }
      }
    }

    return -1;
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
  nums = {4, 5, 6, 7, 0, 1, 2};
  ret = s.search(nums, 0);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {4, 5, 6, 7, 0, 1, 2};
  ret = s.search(nums, 3);
  print_ret(ret);

  // example 3
  nums.clear();
  nums = {1};
  ret = s.search(nums, 0);
  print_ret(ret);

  // example 4
  nums.clear();
  nums = {3, 1};
  ret = s.search(nums, 1);
  print_ret(ret);
  return 0;
}
