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
  int m;
  int n;

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ret = 0;
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int area = 0;
        if (grid[i][j] == 1) area = dfs(grid, i, j);
        if (ret < area) ret = area;
      }
    }

    return ret;
  }

  int dfs(vector<vector<int>>& grid, int row, int col) {
    if (row < 0 || col < 0 || row >= m || col >= n) return 0;
    if (grid[row][col] == 0) return 0;

    grid[row][col] = 0;
    int area = 1;
    area += dfs(grid, row - 1, col);
    area += dfs(grid, row + 1, col);
    area += dfs(grid, row, col - 1);
    area += dfs(grid, row, col + 1);
    return area;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  vector<vector<int>> grid;
  int ret;

  // example 1
  grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
          {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
          {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  ret = s.maxAreaOfIsland(grid);
  print_ret(ret);

  // example 2
  grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
  ret = s.maxAreaOfIsland(grid);
  print_ret(ret);

  return 0;
}
