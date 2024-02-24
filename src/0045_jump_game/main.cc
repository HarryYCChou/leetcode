/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
 public:
  int jump(const vector<int>& nums) {
    int goal = nums.size() - 1;
    int max_pos = 0;
    int cur_pos = 0;
    int step = 0;
    while (max_pos < goal) {
      int stop_pos = max_pos;
      for (; cur_pos <= stop_pos; cur_pos++) {
        max_pos = max(max_pos, nums[cur_pos] + cur_pos);
      }
      step++;
    }
    return step;
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
  nums = {2, 3, 1, 1, 4};
  ret = s.jump(nums);
  print_ret(ret);

  // example 2
  nums = {2, 3, 0, 1, 4};
  ret = s.jump(nums);
  print_ret(ret);

  return 0;
}
