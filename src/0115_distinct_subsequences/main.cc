/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
 public:
  int numDistinct(const string& s, const string& t) {
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

    return dfs(dp, s, t, 0, 0);
  }

  int dfs(vector<vector<int>>& dp,
          const string& s, const string& t, int i, int j) {
    if (j == t.size()) return 1;
    if (i == s.size()) return 0;

    if (dp[i][j] >= 0) return dp[i][j];

    dp[i][j] = dfs(dp, s, t, i + 1, j);
    if (s[i] == t[j]) dp[i][j] += dfs(dp, s, t, i + 1, j + 1);

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
  ret = s.numDistinct("rabbbit", "rabbit");
  print_ret(ret);

  // example 2
  ret = s.numDistinct("babgbag", "bag");
  print_ret(ret);

  return 0;
}
