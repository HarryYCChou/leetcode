/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::greater;

class MedianFinder {
 public:
  int count_l = 0;
  int count_r = 0;
  priority_queue<int> pql;
  priority_queue<int, vector<int>, greater<int>> pqr;
  MedianFinder() {}

  void addNum(int num) {
    if (count_l == 0 && count_r == 0) {
      pql.push(num);
      count_l++;
    } else if (pql.top() >= num) {
      pql.push(num);
      count_l++;
    } else {
      pqr.push(num);
      count_r++;
    }
    if (count_r > count_l) {
      pql.push(pqr.top());
      pqr.pop();
      count_l++;
      count_r--;
    } else if (count_l > count_r + 1) {
      pqr.push(pql.top());
      pql.pop();
      count_l--;
      count_r++;
    }
  }

  double findMedian() {
    if (count_l == count_r) {
      return static_cast<double>(pql.top()+pqr.top()) / 2;
    } else {
      return static_cast<double>(pql.top());
    }
  }
};

void print_ret(const double& ret) {
  cout << ret << endl;
}

int main() {
  MedianFinder s;
  double ret;

  // example 1
  s.addNum(1);
  s.addNum(2);
  ret = s.findMedian();
  print_ret(ret);
  s.addNum(3);
  ret = s.findMedian();
  print_ret(ret);

  return 0;
}
