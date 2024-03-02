/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::greater;
using std::max;

class Solution {
 public:
  int swimInWater(const vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    // cost, pos
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    cost[0][0] = grid[0][0];
    pq.push(make_pair(cost[0][0], 0));

    while (!pq.empty()) {
      int i = pq.top().second / n;
      int j = pq.top().second % n;
      int t = pq.top().first;
      pq.pop();
      if (i == n - 1 && j == n - 1) break;
      // 4 direction
      search(grid, n, t, cost, i - 1, j, pq);
      search(grid, n, t, cost, i + 1, j, pq);
      search(grid, n, t, cost, i, j - 1, pq);
      search(grid, n, t, cost, i, j + 1, pq);
    }
    return cost[n - 1][n - 1];
  }

  void search(const vector<vector<int>>& grid,
              const int& n,
              const int& ori_cost,
              const vector<vector<int>>& cost,
              int i,
              int j,
              priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>& pq) {
    // out of range
    if (i < 0 || j < 0 || i >= n || j >= n || cost[i][j] != INT_MAX) return;

    int new_cost = max(grid[i][j], ori_cost);
    cost[i][j] = new_cost;
    pq.push(make_pair(new_cost, i * n + j));
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<vector<int>> grid;

  // example 1
  grid = {{0, 2}, {1, 3}};
  ret = s.swimInWater(grid);
  print_ret(ret);

  // example 2
  grid = {{0, 1, 2, 3, 4},
          {24, 23, 22, 21, 5},
          {12, 13, 14, 15, 16},
          {11, 17, 18, 19, 20},
          {10, 9, 8, 7, 6}};
  ret = s.swimInWater(grid);
  print_ret(ret);

  return 0;
}
