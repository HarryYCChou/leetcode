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
  int longestConsecutive(const vector<int>& nums) {
    // check null vector case
    if (nums.size() == 0) return 0;

    // sort
    vector<int> nums_s = nums; 
    sort(nums_s.begin(), nums_s.end());  // ascending
    // debug
    //for (const auto& n : nums_s) {
    //  cout << n << ",";
    //}
    //cout << endl;

    // find
    int longest_num = 0;
    int len = 1;
    for (int i = 0; i < nums_s.size()-1; i++) {
      if ((nums_s[i]+1) == nums_s[i+1]) {
        len++;
      } else if (nums_s[i] == nums_s[i+1]) {
        // do not add len when the two number are the same.
        continue;
      } else {
        // debug
        //cout << "check:" << nums_s[i] << "," << nums_s[i+1] << endl;
        // update longest num
        if (len > longest_num) longest_num = len;
        // set len to default
        len = 1;
      }
    }
    // in case the sequence is consecutive
    if (len > longest_num) longest_num = len;

    return longest_num;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  std::vector<int> nums;
  int ret;

  // example 1
  nums.clear();
  nums = {100, 4, 200, 1, 3, 2};
  ret = s.longestConsecutive(nums);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  ret = s.longestConsecutive(nums);
  print_ret(ret);

  // example 3
  // null vector case
  nums.clear();
  ret = s.longestConsecutive(nums);
  print_ret(ret);

  return 0;
}
