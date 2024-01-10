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
  int search(const vector<int>& nums, const int target) {
    // binary search
    // left, right index
    // min => (left+right)/2 index
    // 
    // check mid == target => return mid
    // if mid < target => left = mid
    // if mid > target => right = mid
    // left == right, mid != target => return -1
    int left = 0, right = nums.size() - 1, mid;

    while (left <= right) {
      mid = (left + right) / 2;
      
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) left = mid + 1;
      if (nums[mid] > target) right = mid - 1;
    }

    return -1;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  std::vector<int> nums;

  // example 1
  nums.clear();
  nums = {-1, 0, 3, 5, 9, 12};
  ret = s.search(nums, 9);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {-1, 0, 3, 5, 9, 12};
  ret = s.search(nums, 2);
  print_ret(ret);

  return 0;
}
