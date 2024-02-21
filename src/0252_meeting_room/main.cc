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

class Interval {
 public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
 public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
          [] (const Interval& a, const Interval& b) {
      return a.start < b.start;
    });

    int n = intervals.size() - 1;
    for (int i = 0; i < n; ++i) {
      if (intervals[i].end > intervals[i + 1].start) {
        return false;
      }
    }
    return true;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;

  vector<Interval> intervals;
  bool ret;

  // example 1
  intervals = {Interval{0, 30}, Interval{5, 10}, Interval{15, 20}};
  ret = s.canAttendMeetings(intervals);
  print_ret(ret);

  // example 2
  intervals = {Interval{5, 8}, Interval{9, 15}};
  ret = s.canAttendMeetings(intervals);
  print_ret(ret);

  // example 3
  intervals = {};
  ret = s.canAttendMeetings(intervals);
  print_ret(ret);

  return 0;
}
