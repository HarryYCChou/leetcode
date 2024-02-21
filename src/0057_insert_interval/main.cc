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
using std::min;

class Solution {
 public:
  vector<vector<int>> insert(const vector<vector<int>>& intervals,
                             const vector<int> newInterval) {
    int start = newInterval[0];
    int end = newInterval[1];

    vector<vector<int>> ret;

    for (int i = 0; i < intervals.size(); i++) {
      if (end < intervals[i][0]) {
        ret.push_back({start, end});
        ret.insert(ret.end(), intervals.begin() + i, intervals.end());
        return ret;
      } else if (start > intervals[i][1]) {
        ret.push_back(intervals[i]);
      } else {
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
      }
    }
    ret.push_back({start, end});

    return ret;
  }
};

void print_ret(const vector<vector<int>>& ret) {
  cout << "[";
  for (const auto& v : ret) {
    cout << "[" << v[0] << ", " << v[1] << "], ";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<vector<int>> ret;
  vector<vector<int>> nums;

  // example 1
  nums = {{1, 3}, {6, 9}};
  ret = s.insert(nums, {2, 5});
  print_ret(ret);

  // example 2
  nums = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  ret = s.insert(nums, {4, 8});
  print_ret(ret);

  return 0;
}
