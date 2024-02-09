/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

class Solution {
 public:
  int m;
  int n;
  stack<vector<int>> stk;

  int orangesRotting(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> rotted;
    int ret = 0;
    int f_count = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) rotted.push_back({i, j});
        if (grid[i][j] == 1) f_count++;
      }
    }

    while (f_count > 0) {
      for (const auto& v : rotted) {
        rotting(grid, v[0] - 1, v[1], f_count);
        rotting(grid, v[0] + 1, v[1], f_count);
        rotting(grid, v[0], v[1] - 1, f_count);
        rotting(grid, v[0], v[1] + 1, f_count);
      }

      // new rotted orange not found
      if (stk.empty()) return -1;
      while (!stk.empty()) {
        rotted.push_back({stk.top()[0], stk.top()[1]});
        stk.pop();
      }

      ret++;
    }

    return ret;
  }

  void rotting(vector<vector<int>>& grid,
              int row, int col, int& f_count) {
    if (row < 0 || col < 0 || row >= m || col >= n || f_count == 0) return;
    if (grid[row][col] == 1) {
      grid[row][col] = 2;
      stk.push({row, col});
      f_count--;
    }
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
  grid = {{2, 1, 1},
          {1, 1, 0},
          {0, 1, 1}};
  ret = s.orangesRotting(grid);
  print_ret(ret);

  // example 2
  grid = {{2, 1, 1},
          {0, 1, 1},
          {1, 0, 1}};
  ret = s.orangesRotting(grid);
  print_ret(ret);

  return 0;
}
