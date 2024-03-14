/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
 public:
  int longestIncreasingPath(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ret = max(ret, dfs(matrix, dp, i, j, m, n, INT_MIN));
      }
    }
    return ret;
  }

  int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& dp,
          int i, int j, const int& m, const int &n, int cur) {
    if (i < 0 || j < 0 || i >= m || j >= n) {
      return 0;
    }
    if (cur >= matrix[i][j]) return 0;
    if (dp[i][j] > 0) return dp[i][j];

    cur =  matrix[i][j];
    int ret = 0;
    ret = max(ret, dfs(matrix, dp, i + 1, j, m, n, cur));
    ret = max(ret, dfs(matrix, dp, i - 1, j, m, n, cur));
    ret = max(ret, dfs(matrix, dp, i, j + 1, m, n, cur));
    ret = max(ret, dfs(matrix, dp, i, j - 1, m, n, cur));
    dp[i][j] = ret + 1;

    return dp[i][j];
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.longestIncreasingPath({{9, 9, 4}, {6, 6, 8}, {2, 1, 1}});
  print_ret(ret);

  // example 2
  ret = s.longestIncreasingPath({{3, 4, 5}, {3, 2, 6}, {2, 2, 1}});
  print_ret(ret);

  // example 3
  ret = s.longestIncreasingPath({{1}});
  print_ret(ret);

  return 0;
}
