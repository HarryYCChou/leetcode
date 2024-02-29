/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::priority_queue;
using std::abs;
using std::pair;
using std::greater;

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>> points) {
    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int ret = 0;

    visited.insert(0);
    pq.push(pair(0, 0));

    int next = 0;
    while (visited.size() < points.size()) {
      for (int i = 0; i < points.size(); i++) {
        if (visited.find(i) == visited.end()) {
          pq.push(pair(cal_dis(points[i], points[next]), i));
        }
      }

      while (visited.find(pq.top().second) != visited.end()) {
        pq.pop();
      }
      ret += pq.top().first;
      next = pq.top().second;
      pq.pop();
      visited.insert(next);
    }

    return ret;
  }

  int cal_dis(vector<int> a, vector<int> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);    
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  vector<vector<int>> points;
  int ret;

  // example 1
  points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  ret = s.minCostConnectPoints(points);
  print_ret(ret);

  // example 2
  points = {{3, 12}, {-2, 5}, {-4, 1}};
  ret = s.minCostConnectPoints(points);
  print_ret(ret);

  return 0;
}
