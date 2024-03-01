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
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::greater;
using std::max;
using std::make_pair;

class Solution {
 public:
  int networkDelayTime(const vector<vector<int>>& times,
                        const int& n,
                        const int& k) {
    vector<int> minTime(n + 1, INT_MAX);
    // node[node_num] (time, next_node)
    vector<pair<int, int>> node[n + 1];
    // pq(time, next_node)
    priority_queue<pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>>> pq;
    for (int i = 0; i < times.size(); i++) {
      int from = times[i][0];
      int to = times[i][1];
      int time = times[i][2];
      node[from].push_back(make_pair(time, to));
    }
    pq.push(make_pair(0, k));
    minTime[k] = 0;

    while (!pq.empty()) {
      int time = pq.top().first;
      int cur_node = pq.top().second;
      pq.pop();
      if (time > minTime[cur_node]) {
        continue;
      }

      for (int i = 0; i < node[cur_node].size(); i++) {
        int next_time = node[cur_node][i].first;
        int next_node = node[cur_node][i].second;
        if (next_time + minTime[cur_node] < minTime[next_node]) {
          minTime[next_node] = next_time + minTime[cur_node];
          pq.push(make_pair(next_time, next_node));
        }
      }
    }

    int ret = -1;
    for (int i = 1; i <= n; i ++) {
      cout << "i" << i << ":" << minTime[i] << endl;
      ret = max(ret, minTime[i]);
    }
    if (ret == INT_MAX) return -1;

    return ret;
  }

  int networkDelayTime2(const vector<vector<int>>& times,
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
  times = {{1, 2, 1}};
  ret = s.networkDelayTime(times, 2, 2);
  print_ret(ret);

  return 0;
}
