/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
 public:
  int maxProfit(const vector<int>& prices) {
    int n = prices.size();
    int dp[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
      for (int j = 0; j < n + 2; j++) {
        dp[i][j] = 0;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        dp[i][j] = max(dp[i][j + 1], prices[j] - prices[i] + dp[j + 2][j + 2]);
      }
      dp[i][i] = max(dp[i + 1][i + 1], dp[i][i + 1]);
    }
    return dp[0][0];
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> prices;

  // example 1
  ret = s.maxProfit({1, 2, 3, 0, 2});
  print_ret(ret);

  // example 2
  ret = s.maxProfit({1});
  print_ret(ret);

  return 0;
}
