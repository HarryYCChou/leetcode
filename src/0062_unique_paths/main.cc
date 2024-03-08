/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
 public:
  int uniquePaths(const int& m, const int& n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[m - 1][n - 1] = 1;
    return check(dp, m, n, 0, 0);
  }

  int check(vector<vector<int>>& dp, const int& m, const int& n, int x, int y) {
    if (x >= m || y >= n || x < 0 || y < 0) return 0;
    if (dp[x][y] >= 0) return dp[x][y];
    int sum = check(dp, m, n, x + 1, y) + check(dp, m, n, x, y + 1);
    dp[x][y] = sum;
    return sum;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.uniquePaths(3, 7);
  print_ret(ret);

  // example 2
  ret = s.uniquePaths(3, 2);
  print_ret(ret);

  return 0;
}
