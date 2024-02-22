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
using std::max;

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
  int minMeetingRooms(vector<Interval>& intervals) {
    int ret = 0;
    vector<int> sv, ev;
    for (const auto& itv : intervals) {
      sv.push_back(itv.start);
      ev.push_back(itv.end);
    }

    int room = 0;
    sort(sv.begin(), sv.end());
    sort(ev.begin(), ev.end());
    int i = 0, j = 0;

    while (i < sv.size()) {
      if (sv[i] < ev[j]) {
        room++;
        ret = max(ret, room);
        i++;
      } else {
        room--;
        j++;
      }
    }

    return ret;
  }

  int minMeetingRooms2(vector<Interval>& intervals) {
      sort(intervals.begin(), intervals.end(),
      [] (const Interval& a, const Interval& b) {
        return (a.start == b.start) ? (a.end < b.end) : (a.start < b.start);
      });
    int ret = 0;
    vector<Interval> new_intervals;

    while (intervals.size() != 0) {
      ret++;
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i - 1].end > intervals[i].start) {
          if (intervals[i - 1].end > intervals[i].end) {
            new_intervals.push_back(intervals[i - 1]);
          } else {
            new_intervals.push_back(intervals[i]);
            intervals[i] = intervals[i - 1];
          }
        }
      }
      intervals = new_intervals;
      new_intervals = {};
    }

    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<Interval> intervals;

  // example 1
  intervals.emplace_back(0, 40);
  intervals.emplace_back(5, 10);
  intervals.emplace_back(15, 20);
  ret = s.minMeetingRooms(intervals);
  print_ret(ret);

  // example 2
  intervals = {};
  intervals.emplace_back(4, 9);
  ret = s.minMeetingRooms(intervals);
  print_ret(ret);

  return 0;
}
