/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::greater;
using std::make_pair;

class Solution {
 public:
  int findCheapestPrice(const int& n, const vector<vector<int>>& flights,
                        const int& src, const int& dst, const int& k) {
    vector<vector<pair<int, int>>> station(n);
    // station, cost, stops
    unordered_map<int, pair<int, int>> visited;
    for (const auto& f : flights) {
      int s = f[0];
      int t = f[1];
      int p = f[2];
      station[s].push_back(make_pair(t, p));
    }

    // total cost, station, stops
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, -1});

    int ret = INT_MAX;
    while (!pq.empty()) {
      int cost = pq.top()[0];
      int sta = pq.top()[1];
      int stops = pq.top()[2];
      pq.pop();
      if (cost > ret || stops > k) continue;
      if (sta == dst) {
        ret = cost;
      } else {
        if (visited.find(sta) != visited.end()) {
          if (visited[sta].first >= cost &&
              visited[sta].second >= stops) {
              visited[sta] = make_pair(cost, stops);
          } else if (visited[sta].first <= cost &&
              visited[sta].second <= stops) {
              continue;
          }
        } else {
          visited[sta] = make_pair(cost, stops);
        }
        for (const auto& next_sta : station[sta]) {
          pq.push({cost + next_sta.second, next_sta.first, stops + 1});
        }
      }
    }

    if (ret == INT_MAX) return -1;
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<vector<int>> flights;

  // example 1
  flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  ret = s.findCheapestPrice(4, flights, 0, 3, 1);
  print_ret(ret);

  // example 2
  flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  ret = s.findCheapestPrice(3, flights, 0, 2, 1);
  print_ret(ret);

  // example 3
  flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  ret = s.findCheapestPrice(3, flights, 0, 2, 0);
  print_ret(ret);

  return 0;
}
