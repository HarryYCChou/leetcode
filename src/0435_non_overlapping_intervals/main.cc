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
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    int ret = 0;

    for (int i = 0; i < intervals.size() - 1; i++) {
      if (intervals[i][1] > intervals[i + 1][0]) {
        ret++;
        if (intervals[i + 1][1] > intervals[i][1]) {
          intervals[i + 1] = intervals[i];
        }
      }
    }
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  vector<vector<int>> intervals;
  int ret;

  // example 1
  intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  ret = s.eraseOverlapIntervals(intervals);
  print_ret(ret);

  // example 2
  intervals = {{1, 2}, {1, 2}, {1, 2}};
  ret = s.eraseOverlapIntervals(intervals);
  print_ret(ret);

  // example 3
  intervals = {{1, 2}, {2, 3}};
  ret = s.eraseOverlapIntervals(intervals);
  print_ret(ret);

  return 0;
}
