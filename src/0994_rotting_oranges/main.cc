/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

class Solution {
 public:
  int m;
  int n;
  queue<vector<int>> rotted;

  int orangesRotting(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int ret = 0;
    int f_count = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) rotted.push({i, j});
        if (grid[i][j] == 1) f_count++;
      }
    }

    while (!rotted.empty() && f_count != 0) {
      int count = rotted.size();
      for (int i = 0; i < count; i++) {
        int x = rotted.front()[0];
        int y = rotted.front()[1];
        rotting(grid, x - 1, y, f_count);
        rotting(grid, x + 1, y, f_count);
        rotting(grid, x, y - 1, f_count);
        rotting(grid, x, y + 1, f_count);
        rotted.pop();
      }
      ret++;
    }

    return (f_count == 0) ? ret : -1;
  }

  void rotting(vector<vector<int>>& grid,
              int row, int col, int& f_count) {
    if (row < 0 || col < 0 || row >= m || col >= n || f_count == 0) return;
    if (grid[row][col] == 1) {
      grid[row][col] = 2;
      rotted.push({row, col});
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
