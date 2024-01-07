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
  vector<vector<int>> threeSum(const vector<int>& nums) {
    // sort
    vector<int> s_nums = nums;
    sort(s_nums.begin(), s_nums.end());

    // find
    vector<vector<int>> ret;
    int i = 0, j, k;
    while (i < (s_nums.size() - 2)) {
      // check
      if (s_nums[i] > 0) break;

      j = i + 1;
      k = s_nums.size()-1;
      while (j < k && j < (s_nums.size() -1)) {
        // check
        if (s_nums[k] < 0) break;

        // 3 sum
        if ((s_nums[i] + s_nums[j] + s_nums[k]) == 0) {
          ret.push_back({s_nums[i], s_nums[j], s_nums[k]});
          // shift index
          while (++j) {
            if (j >= (s_nums.size() -1)) break;
            if (s_nums[j] != s_nums[j-1]) break;
          }
          while (--k) {
            if (k <= j) break;
            if (s_nums[k] != s_nums[k+1]) break;
          }
        } else if ((s_nums[i] + s_nums[j] + s_nums[k]) > 0) {
          // too large
          k--;
        } else {
          // too small
          j++;
        }
      }
      i = next_index(s_nums, i);
    }

    return ret;
  }

  int next_index(const vector<int>& nums, const int& index_now) {
    for (int i = index_now+1; i < nums.size(); i++) {
      if (nums[index_now] != nums[i]) return i;
    }

    return nums.size();
  }
};

void print_ret(const vector<vector<int>>& ret) {
  for (const auto& v : ret) {
    for (const auto& e : v) {
      cout << e << ",";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution s;
  std::vector<int> nums;
  std::vector<vector<int>> ret;

  // example 1
  nums.clear();
  nums = {-1, 0, 1, 2, -1, -4};
  ret = s.threeSum(nums);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {0, 1, 1};
  ret = s.threeSum(nums);
  print_ret(ret);

  // example 3
  nums.clear();
  nums = {0, 0, 0};
  ret = s.threeSum(nums);
  print_ret(ret);

  return 0;
}
