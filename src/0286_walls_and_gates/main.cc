/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int m, n;
  void islandsAndTreasure(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          dfs(grid, i - 1, j, 1);
          dfs(grid, i + 1, j, 1);
          dfs(grid, i, j - 1, 1);
          dfs(grid, i, j + 1, 1);
        }
      }
    }
  }

  void dfs(vector<vector<int>>& grid, int row, int col, int val) {
    if (row < 0 || col < 0 || row >= m || col >= n) return;
    if (grid[row][col] > val) {
      grid[row][col] = val;
      // 4 dir
      dfs(grid, row - 1, col, val + 1);
      dfs(grid, row + 1, col, val + 1);
      dfs(grid, row, col - 1, val + 1);
      dfs(grid, row, col + 1, val + 1);
    }
  }
};

void print_ret(const vector<vector<int>>& ret) {
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& n : v) {
      cout << n << ",";
    }
    cout << "]" << endl;
  }
  cout << endl;
}

int main() {
  Solution s;

  vector<vector<int>> grid;

  // example 1
  grid = {{2147483647, -1, 0, 2147483647},
          {2147483647, 2147483647, 2147483647, -1},
          {2147483647, -1, 2147483647, -1},
          {0, -1, 2147483647, 2147483647}};
  s.islandsAndTreasure(grid);
  print_ret(grid);

  // example 2
  grid = {{0, -1},
          {2147483647, 2147483647}};
  s.islandsAndTreasure(grid);
  print_ret(grid);

  return 0;
}
