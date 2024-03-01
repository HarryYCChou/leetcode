/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::greater;
using std::max;

class Solution {
 public:
  int networkDelayTime(const vector<vector<int>>& times,
                        const int& n,
                        const int& k) {
    unordered_map<int, int> traveled;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int ret = 0;
    int p = k;
    traveled[k] = 0;
    while (traveled.size() < n) {
      for (int i = 0; i < times.size(); i++) {
        if (times[i][0] == p &&
            (traveled.find(times[i][1]) == traveled.end())) {
          pq.push({times[i][2] + traveled[p], times[i][0], times[i][1]});
        }
      }

      int p_next = p;
      while (!pq.empty()) {
        if (traveled.find(pq.top()[2]) == traveled.end()) {
          traveled[pq.top()[2]] = pq.top()[0];
          p_next = pq.top()[2];
          ret = max(ret, traveled[p_next]);
          pq.pop();
          break;
        }
        pq.pop();
      }
      if (p_next == p) return -1;
      p = p_next;
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
  vector<vector<int>> times;

  // example 1
  times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  ret = s.networkDelayTime(times, 4, 2);
  print_ret(ret);

  // example 2
  times = {{1, 2, 1}};
  ret = s.networkDelayTime(times, 2, 1);
  print_ret(ret);

  // example 3

  return 0;
}
