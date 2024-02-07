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
  int numIslands(vector<vector<char>>& grid) {
    int ret = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          ret++;
          dfs(grid, i, j);
        }
      }
    }
    return ret;
  }

  void dfs(vector<vector<char>>& grid, int row, int col) {
    if (row >= m || col >= n || row < 0 || col < 0) return;
    if (grid[row][col] == '0') return;
    grid[row][col] = '0';
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<vector<char>> grid;

  // example 1
  grid = {{'1','1','1','1','0'},
          {'1','1','0','1','0'},
          {'1','1','0','0','0'},
          {'0','0','0','0','0'}};
  ret = s.numIslands(grid);
  print_ret(ret);

  // example 2
  grid = {{'1','1','0','0','0'},
          {'1','1','0','0','0'},
          {'0','0','1','0','0'},
          {'0','0','0','1','1'}};
  ret = s.numIslands(grid);
  print_ret(ret);

  return 0;
}
