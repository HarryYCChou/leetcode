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
  vector<int> twoSum(const vector<int>& numbers, const int& target) {
    int start = 0, end = numbers.size()-1;

    while (true) {
      if ((numbers[start] + numbers[end]) == target) {
        break;
      } else if ((numbers[start] + numbers[end]) < target) {
        // too small
        start++;
      } else {
        // too large
        end--;
      }
    }
    vector<int> ret{start+1, end+1};
    return ret;
  }
};

void print_ret(const vector<int>& ret) {
  cout << ret[0] << "," << ret[1] << endl;
}

int main() {
  Solution s;
  vector<int> nums;
  vector<int> ret;

  // example 1
  nums.clear();
  nums = {2, 7, 11, 15};
  ret = s.twoSum(nums, 9);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {2, 3, 4};
  ret = s.twoSum(nums, 6);
  print_ret(ret);

  // example 3
  nums.clear();
  nums = {-1, 0};
  ret = s.twoSum(nums, -1);
  print_ret(ret);

  return 0;
}
