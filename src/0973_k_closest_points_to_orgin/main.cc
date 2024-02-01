/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

class Compare {
 public:
  Compare() {}
  bool operator() (const vector<int>& p1, const vector<int>& p2) {
    return (distance(p1) > distance(p2));
  }

  int distance(const vector<int>& p) {
    return (p[0] * p[0] + p[1] * p[1]);
  }
};

class Solution {
 public:
  vector<vector<int>> kClosest(const vector<vector<int>>& points,
                                const int& k) {
    vector<vector<int>> ret;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    for (const auto& v : points) {
      pq.push(v);
    }

    for (int i = 0; i < k; i++) {
      ret.push_back(pq.top());
      pq.pop();
    }

    return ret;
  }
};

void print_ret(const vector<vector<int>>& ret) {
  for (const auto& v : ret) {
    cout << "[" << v[0] << "," << v[1] << "],";
  }
  cout << endl;
}

int main() {
  Solution s;
  vector<vector<int>> points;
  vector<vector<int>> ret;

  // example 1
  points = {{1, 3}, {-2, 2}};
  ret = s.kClosest(points, 1);
  print_ret(ret);

  // example 2
  points = {{3, 3}, {5, -1}, {-2, 4}};
  ret = s.kClosest(points, 2);
  print_ret(ret);

  // example 3

  return 0;
}
